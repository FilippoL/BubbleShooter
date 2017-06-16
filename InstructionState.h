#pragma once
#include "GameStates.h"
#include "Label.h"
#include "Background.h"
#include "Button.h"

class InstructionState :
	public GameStates
{
public:
	InstructionState(GameStates *current); 
	
	Background _instructions_credits;
	Button 	_main_menu_btn;


	virtual ~InstructionState();

public:
	virtual bool update(double dt);
	virtual bool Draw() ;
};

