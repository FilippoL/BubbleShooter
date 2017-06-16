#include "InstructionState.h"



InstructionState::InstructionState(GameStates* current) : GameStates(current)
{
	_isActive = true;
	_isAlive = true;
	
	_instructions_credits.Initialise("INSTRUCTIONS");
	_main_menu_btn.initialise(200, 200, glm::vec2(WIDTH/2-100, HEIGHT/2-100), "MAIN MENU", false);

}


InstructionState::~InstructionState()
{
}

bool InstructionState::update(double dt)
{
	
	_main_menu_btn.update(dt);

	if (_main_menu_btn.Clicked())
	{
		_StatePrevious->isActive() = true;
		_StatePrevious->isAlive() = true;

		_isActive = false;
		_isAlive = false;
	}



	return false;
}

bool InstructionState::Draw()
{
	_instructions_credits.draw();
	_main_menu_btn.draw();
	return false;
}
