#include "Player.h"
#include "TextureManager.h"
#include "InputManager.h"
#define WIDTH 1024
#define HEIGHT 768
#define FLOOR_HEIGHT 25

Player::Player()
{

	_variables_from_file.InitialiseSection("PLAYER_SPRITE");
	
	(!TheTexture::Instance()->GetTexture("HERO"))?
		TheTexture::Instance()->LoadTextureFromFile(_variables_from_file.GetAlphabeticVariable("sprt"), "HERO"):0;


	_bullett = new Bullet;
	_width = 100;
	_height = 200;
	hero.SetTexture("HERO"); //TEXTURE IS GOING TO CHANGE
	hero.SetAnimationVelocity(20.0f);
	hero.SetSpriteDimension(_width, _height);
	hero.SetTextureDimension(8, 1, 125, 250);
	hero.IsAnimationLooping() = true;
	
	position.y = HEIGHT - (_height + FLOOR_HEIGHT);
	position.x = _variables_from_file.GetNumericVariable("initial_pos.x");
	_speed = 450;

	animation_speed = 0.01;
		
	m_bound.SetRadius(25);
	m_bound.SetPosition(position.x, position.y);
	
}

Sphere Player::GetBulletBound()
{
	return _bullett->GetBound();
}

Sphere Player::GetPlayerBound()
{
	return m_bound;
}

void Player::ResetBullett()
{

	_bullett->Shoot() = false;
	_bullett->SetPosition(position + glm::vec2(_width/4, _height/4));

}

void Player::update(double dt)
{
	keys = TheInput::Instance()->GetKeyStates();

	_bullett->update(dt);

	if (!_bullett->Shoot())
	{
		_bullett->SetPosition(position + glm::vec2(_width/4, _height/4));
	}

	if (position.x > WIDTH - _width)
	{
		position.x = WIDTH - _width;
	}

	if (position.x < 0)
	{
		position.x = 0;
	}

	m_bound.SetPosition(position.x + _width/2, position.y + _height/2);

	if (keys[SDL_SCANCODE_RIGHT])
	{
		position.x += _speed * dt;
		animation_speed = 0.01;

		_going_right = true;
	}

	if (keys[SDL_SCANCODE_LEFT])
	{	
		position.x -= _speed * dt;
		animation_speed = 0.01;

		_going_right = false;
	}

	if (!keys[SDL_SCANCODE_RIGHT] && !keys[SDL_SCANCODE_LEFT])
	{
		animation_speed = 0.00;
	}

	if (keys[SDL_SCANCODE_TAB])
	{	
		_bullett->Shoot() = true;
		
	}
	
}


void Player::draw()
{
	if (_going_right)
		{
			hero.Draw(position.x,  position.y, animation_speed, 0.0, Sprite::HORIZONTAL);
		}

	else
		{
			hero.Draw(position.x,  position.y, animation_speed, 0.0, Sprite::NO_FLIP);
		}

	_bullett->draw();
}



Player::~Player()
{
	delete _bullett;
}
