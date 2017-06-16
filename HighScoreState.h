#pragma once
#include "GameStates.h"
#include "Button.h"
#include "HighScore.h"
#include "TansparentLayer.h"
#include "Label.h"

class HighScoreState :
	public GameStates
{
public:
	HighScoreState(GameStates * current, bool istemp = true);

	bool update(double dt);
	bool Draw();

	Button *_main_menu_btn;

	Label _normal_scores[11];
	Label _arcade_scores[11];

	

	TansparentLayer *background;

	HighScore _hg_arcade;
	HighScore _hg_normal;
	bool istemporary;

	virtual ~HighScoreState();
};

