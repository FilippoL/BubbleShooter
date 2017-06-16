#include "GameStates.h"

GameStates::GameStates(GameStates * current_state)
{
	_StatePrevious = current_state;
}

bool & GameStates::isAlive()
{
	// TODO: insert return statement here
	return _isAlive;
}

bool & GameStates::isActive()
{
	// TODO: insert return statement here

	return _isActive;
}
