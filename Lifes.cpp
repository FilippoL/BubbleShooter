#include "Lifes.h"
#include "TextureManager.h"


Lifes::Lifes()
{
}


void Lifes::Initialise()
{
	_variables_from_file.InitialiseSection("LIFES");

	(!TheTexture::Instance()->GetTexture("LIFES")) ?
	TheTexture::Instance()->LoadTextureFromFile(_variables_from_file.GetAlphabeticVariable("lifes_texture"), "LIFES"):0;
	
	_lifes_n = 5;
	_width = 35;
	_height = 35;
	_hearth.SetTexture("LIFES");
	_hearth.SetSpriteDimension(_width, _height);
	_hearth.SetTextureDimension(1, 1, 867, 720);
			   
}

void Lifes::update(double dt)
{
	if (_lifes_n < 0)
	{
		_lifes_n = 0;
	}
}

int Lifes::GetLifes()
{
	return _lifes_n;
}

void Lifes::Damaged()
{
	_lifes_n--;
}

void Lifes::draw()
{
	for (int i = 0; i < _lifes_n; i++)
	{
		_hearth.Draw(WIDTH / 1.5 + (i + 1) * _width, HEIGHT - _height);
	}
}

Lifes::~Lifes()
{
}
