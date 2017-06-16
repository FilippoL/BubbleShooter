#include "Bullet.h"
#include "Sprite.h"
#include "TextureManager.h"
#include <iostream>
#define WIDTH 1024
#define HEIGHT 768

Bullet::Bullet()
{
	_variables_from_file.InitialiseSection("BULLET_SPRITE");

	(!TheTexture::Instance()->GetTexture("Bullet_special"))?
		TheTexture::Instance()->LoadTextureFromFile(_variables_from_file.GetAlphabeticVariable("sprt"), "Bullet_special"):0;

	_width = _variables_from_file.GetNumericVariable("W");
	_height = _variables_from_file.GetNumericVariable("H");
	m_rock.SetAnimationVelocity(1.75f);
	m_rock.SetSpriteDimension(_width, _height);
	m_rock.SetTexture("Bullet_special");
	m_rock.SetTextureCell(0,0);
	m_rock.SetTextureDimension(5, 4, 640/5, 512/4);
	m_rock.IsAnimationLooping() = false;
	an_speed = 0.00;
	radius = _width/2;
	m_bound.canCollide() = false;
	m_bound.SetRadius(radius);
	m_bound.SetPosition(position.x + (_width/2), position.y + (_height/2));	
	
}

void Bullet::update(double dt)
{
	if (position.y < 0)
	{
		isShoot = false;
	}
		
	if (!isShoot)
	{
		m_bound.canCollide() = false;
		m_rock.Reset();
		an_speed = 0.0;
		isShoot = false;
		radius = _width/2;
	}
	

	if (isShoot)
	{
		m_bound.canCollide() = true;
		an_speed = 15 * dt;
		position.y -=  dt *  HEIGHT;
		radius = _width/2;
	}
	
	m_bound.SetRadius(radius);
	m_bound.SetPosition(position.x + (_width/2), position.y + (_height/2));	
}



bool &Bullet::Shoot()
{
	return isShoot;
}

void Bullet::draw()
{
	m_rock.Draw(position.x,position.y, an_speed);
}

Sphere Bullet::GetBound()
{
	return m_bound;
}

Bullet::~Bullet()
{
	
}
