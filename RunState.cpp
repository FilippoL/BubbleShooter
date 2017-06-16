#include <SDL.h> 

#include <iostream>
#include <string>
#include "Tools.h"
#include "AudioManager.h"
#include "InputManager.h"
#include "TextureManager.h"
#include "Sprite.h"
#include "ScreenManager.h"
#include "RunState.h"
#include "GameObject.h"
#include "Animation.h"
#include "Audio.h"
#include "SFX.h"
#include "Player.h"
#include "Bullet.h"
#include "game.h"
#include "MainMenuState.h"
#include "Ball.h"
#include "TimeBar.h"
#include "WinState.h"




RunState::RunState(GameStates* current) : GameStates(current)
{
	_isActive = _isAlive = true;

	TheAudio::Instance()->LoadFromFile("Assets//Audio//Traccia_Darietto_loop.ogg", TheAudio::Instance()->MUSIC_AUDIO, "AMBIENT_M");
	background = new Background;

	hero = new Player;
	ballSet = new Ball;
	score = new Label;

	score->Initialise("TEXT",200, 100,glm::vec2(WIDTH-200,0),glm::vec3(250,50,0));

	ambient_music.SetAudio("AMBIENT_M", ambient_music.MUSIC_AUDIO);
	ambient_music.SetVolume(10);
}


RunState::~RunState()
{

	 delete  background;
	 delete  hero;
	 delete  ballSet;
	 delete  score;

	 TheAudio::Instance()->UnloadFromMemory( TheAudio::Instance()->MUSIC_AUDIO, TheAudio::Instance()->CUSTOM_AUDIO,"AMBIENT_M" ); //WONT NEED IN FUTURE
}

bool RunState::update(double dt)
{
	////read keyboard state
	return true;
}

bool RunState::Draw()
{
	return false;
}

float RunState::GetScore()
{
	return _score;
}