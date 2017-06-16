#pragma once
#include <SDL.h> 

#include <iostream>
#include <string>
#include "Audio.h"
#include "InputManager.h"
#include "TextureManager.h"
#include "Sprite.h"
#include "ScreenManager.h"
#include "GameObject.h"
#include "Animation.h"
#include "GameStates.h"
#include "Audio.h"
#include "SFX.h"
#include "Player.h"
#include "Bullet.h"
#include "Background.h"
 
#include "Ball.h"
#include "TimeBar.h"
#include "WinState.h"
#include "Label.h"


class RunState :
	public GameStates
{
public:
	RunState(GameStates * current);
	virtual ~RunState();


public:

	virtual bool update(double dt);
	virtual bool Draw();

	float GetScore();

protected:
	Background * background;
	Player * hero;
	Ball * ballSet;
	Label * score;
	Audio ambient_music;


public:
	const Uint8* keys = nullptr;
};

