#pragma once
#include "GameStates.h"
#include "Sprite.h"
#include "Button.h"
#include "TansparentLayer.h"

class PauseState :
	public GameStates  
{
public:
	PauseState(GameStates* current);
	virtual ~PauseState();

public:
	virtual bool update(double dt);
	virtual bool Draw();

	/*this whole way of creating gui is not optimised at all, is to be implememented --> see button->initialise*/
	TansparentLayer *background;
	Button *Continue;
	Button *Exit;
	Button *MainMenu;


public:
	const Uint8* keys = nullptr;
};

