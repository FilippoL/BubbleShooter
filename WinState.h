#pragma once
#include "GameStates.h"
#include "RunState.h"
#include "Button.h"
#include "HighScore.h"
#include "Background.h"

class WinState :
	public GameStates
{
public:
	WinState(GameStates * current, float hg, bool isArcade);
	virtual ~WinState();

public:
	virtual bool update(double dt);

	virtual bool Draw();

	HighScore _hg;

	Background background;
	Button *MainMenu;
	Button *SubmitHighscore;
	Text *_scores;
};

