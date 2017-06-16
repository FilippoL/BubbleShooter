#pragma once
#include "RunState.h"
#include "Lifes.h"

class NormalMode :
	public RunState
{
public:
	NormalMode(GameStates *current);

	virtual bool update(double dt);
	virtual bool Draw();

	TimeBar * _timebar;
	Lifes _lifes;

	virtual ~NormalMode();
};

