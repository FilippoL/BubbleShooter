#pragma once
#include "RunState.h"
#include "GameStates.h"

class ArcadeMode :
	public RunState
{
public:
	ArcadeMode(GameStates * current);

	virtual bool update(double dt);
	virtual bool Draw();

	virtual ~ArcadeMode();
};

