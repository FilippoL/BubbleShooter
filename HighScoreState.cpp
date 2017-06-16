#include "HighScoreState.h"
#include "Tools.h"
#include "Game.h"
#include "MainMenuState.h"


HighScoreState::HighScoreState(GameStates * current, bool istemp): GameStates(current)
{
	_hg_normal.Initialise("NORMAL_HG");
	_hg_arcade.Initialise("ARCADE_HG");

	istemporary = istemp;

	_isActive = true;
	_isAlive = true;	

	_main_menu_btn = new Button;
	
	for (size_t i = 0; i < 11; i++)
	{
		_normal_scores[i].Initialise("TEXT",180, 130,glm::vec2(35, ((i)*60)), glm::vec3(250,50,0));
		_arcade_scores[i].Initialise("TEXT", 180, 130, glm::vec2(WIDTH-215, ((i) * 60)), glm::vec3(250, 50, 0));

	}

	_main_menu_btn->initialise(200, 200, glm::vec2(WIDTH/2-100, HEIGHT/2-100), "MAIN MENU", false);

	background = new TansparentLayer;
	
	background->Initialise("TRANSPAR_2"); //background is transparent!
	
}

bool HighScoreState::update(double dt)
{

	_main_menu_btn->update(dt);

	if (_main_menu_btn->Clicked())
	{
		if (istemporary)
		{
			_StatePrevious->isActive() = true;
			_StatePrevious->isAlive() = true;

			_isActive = false;
			_isAlive = false;
		}

		else
		{
			TheGame::Instance()->ChangeState(new MainMenuState(this));

			_isActive = false;
			_isAlive = false;	
		}

	}


	_normal_scores[0].SetLabel("NORMAL MODE");

	_arcade_scores[0].SetLabel("ARCADE MODE");

	for (int i = 1; i < 11; i++)
	{
		
		_normal_scores[i].SetLabel(std::to_string(i) +": " + (std::to_string(int(_hg_normal.GetHighscore()[i-1]))));

		_arcade_scores[i].SetLabel(std::to_string(i) + ": " + (std::to_string(int(_hg_arcade.GetHighscore()[i-1]))));
				
	}

	
	return false;
}

bool HighScoreState::Draw()
{

	background->draw();
	background->draw();
	background->draw();

	for (int i = 0; i < 11; i++)
	{
		_normal_scores[i].draw();
		_arcade_scores[i].draw();
	}

	_main_menu_btn->draw();
	return false;
}


HighScoreState::~HighScoreState()
{
	delete _main_menu_btn;
	delete background;
}
