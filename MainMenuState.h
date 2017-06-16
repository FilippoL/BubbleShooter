#pragma once
#include "GameStates.h"
#include "Sprite.h"
#include "Animation.h"
#include "Button.h"
#include "Audio.h"
#include "FileManager.h"
#include "Background.h"
#include "Label.h"

class MainMenuState :
	public GameStates
{
public:
	MainMenuState(GameStates *current); //CLASS CREATED
	virtual ~MainMenuState();

private:
	//CLASS HAS GUI ELEMENTS
	Background * background;

	Animation * decoration;

	Label title;
	Label mode;

	// BUTTONS
	Button btn_PLAY;
	Button btn_HIGHSCORE;
	Button btn_INSTRUCT;
	Button btn_MODE;

	std::string _modes;

	FileManager _settings;


	Audio background_music;
	
public:
	virtual bool update(double dt) ;
	virtual bool Draw() ;

};

