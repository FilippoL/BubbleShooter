#include "WinState.h"
#include "Game.h"
#include "MainMenuState.h"
#include "HighScoreState.h"
#include "Tools.h"
#include "ArcadeMode.h"
#include "NormalMode.h"


WinState::WinState(GameStates * current, float hg, bool isArcade): GameStates(current)
{
	
	(isArcade) ? _hg.Initialise("ARCADE_HG"): _hg.Initialise("NORMAL_HG");

	

	_isActive = _isAlive = true;
	_score = hg;

	background.Initialise("GAMEOVER"); //BACKGROUND WITH A GUI ELEMENT
	

	SubmitHighscore = new Button;
	MainMenu = new Button;
	_scores = new Text;


	SubmitHighscore->initialise(250, 250, glm::vec2(50, HEIGHT -250), "SUBMIT",true);
	MainMenu->initialise(250, 250, glm::vec2(WIDTH - 300, HEIGHT -250), "MAIN MENU", true);
	
	_scores->SetFont("TEXT");

	_scores->SetSize(450, 300);
	_scores->SetColor(250,50,0);
}


WinState::~WinState()
{
	delete SubmitHighscore;
	delete MainMenu;
}


bool WinState::update(double dt)
{
	SubmitHighscore->update(dt);
	MainMenu->update(dt);
	

	
	(_score > _hg.GetHighscore()[0]) ? _scores->SetText("!NEW HIGHSCORE!!: " + NumberToString(_score).str()) :
											_scores->SetText("FINAL SCORE: " + NumberToString(_score).str()); 

	if (SubmitHighscore->Clicked())
	{
		_hg.UpdateHighscore(_score);
		TheGame::Instance()->ChangeState(new HighScoreState(this,false));

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

bool WinState::Draw()
{

	background.draw();
	_scores->Draw(WIDTH/4, 75);
	SubmitHighscore->draw();
	MainMenu->draw();
	return false;
}
