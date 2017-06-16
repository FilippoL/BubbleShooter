#include "TimeBar.h"
#include"TextureManager.h"
#include<iostream>
#include<cstdlib>
#include<windows.h>

#define WIDTH 1024
#define HEIGHT 768


TimeBar::TimeBar()
{

	life = new Sprite;
	life_bar = new Sprite;

	_variables_from_file.InitialiseSection("LIFEBAR_TEXTURES");


	(!TheTexture::Instance()->GetTexture("BAR"))?
		TheTexture::Instance()->LoadTextureFromFile(_variables_from_file.GetAlphabeticVariable("bar"),"BAR"):0; 

	(!TheTexture::Instance()->GetTexture("TIME"))?
		TheTexture::Instance()->LoadTextureFromFile(_variables_from_file.GetAlphabeticVariable("time"), "TIME"):0;

	life->SetTextureCell(0, 0);
	life->SetTextureDimension(1,1,118, 20);
	life->SetTexture("TIME");

	elapsed_t = WIDTH/1.5 - 25;
	
	life->SetTextureCell(0, 0);
	life_bar->SetTextureDimension(1,1,128, 31);
	life_bar->SetSpriteDimension(WIDTH/1.5, 50);
	life_bar->SetTexture("BAR");
}

void TimeBar::Reset()
{
	elapsed_t = WIDTH / 1.5 - 25;
}


float TimeBar::GetScore()
{
	return elapsed_t;
}

bool TimeBar::IsOver()
{
	if (elapsed_t == 0)
	{
		return  true;
	}

	return false;
}


void TimeBar::update(double dt)
{
	#ifdef _DEBUG
	dt = 1;
	#endif // DEBUG

	life->SetSpriteDimension(elapsed_t , 40);
	elapsed_t -= 20 * dt;

	if (elapsed_t<0)
	{
		elapsed_t = 0;
	}
}

void TimeBar::draw()
{
	life_bar->Draw(position.x,position.y);
	life->Draw(position.x + 10,position.y + 5);
}


TimeBar::~TimeBar()
{
	delete life;
	delete life_bar;
}
