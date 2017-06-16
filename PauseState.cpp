#include <iostream>
#include <string>
#include "AudioManager.h"
#include "InputManager.h"
#include "TextureManager.h"
#include "Sprite.h"
#include "ScreenManager.h"
#include "GameObject.h"
#include "Animation.h"
#include "GameStates.h"
#include "Text.h"
#include "Audio.h"
#include "PauseState.h"
#include "SFX.h"
#include "Player.h"
#include "Game.h"
#include "Bullet.h"
#include "MainMenuState.h"
 



PauseState::PauseState(GameStates * current) : GameStates(current)
{
	_isActive = _isAlive = true;
	
	Continue = new Button;
	Exit = new Button;
	MainMenu = new Button;


	Continue->initialise(250, 250, glm::vec2(50, HEIGHT/2), "RESUME",false); //initialise buttons
	Exit->initialise(250, 250, glm::vec2(350,  HEIGHT/4), "EXIT",false);
	MainMenu->initialise(250, 250, glm::vec2(650,  HEIGHT/2), "MAINMENU",false);

	

	background = new TansparentLayer;
	
	background->Initialise("TRANSPAR"); //background is transparent!
	
	
}
 

PauseState::~PauseState()
{
	delete background;  
	delete Continue;
	delete MainMenu;
	delete Exit;
}


bool PauseState::update(double dt)
{	
	keys = TheInput::Instance()->GetKeyStates();

	Continue->update(dt);
	Exit->update(dt);
	MainMenu->update(dt);


	if (Continue->Clicked())
	{
		_StatePrevious->isActive() = true;
		_StatePrevious->isAlive() = true;

		_isActive = false;
		_isAlive = false;
	}

	if (Exit->Clicked())
	{
		_StatePrevious->isActive() = false;
		_StatePrevious->isAlive() = false;

		_isActive = false;
		_isAlive = false;
	}

	if (MainMenu->Clicked())
	{
		TheGame::Instance()->ChangeState(new MainMenuState(this));

		_StatePrevious->isActive() = false;
		_StatePrevious->isAlive() = false;

		_isActive = false;
		_isAlive = false;

	}

	return false;
}


bool PauseState::Draw()
{

	
	background->draw();
	Continue->draw();
	Exit->draw();
	MainMenu->draw();
	

	return false;
}
