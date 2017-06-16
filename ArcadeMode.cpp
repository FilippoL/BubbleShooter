#include "ArcadeMode.h"
#include "Tools.h"	
#include "Game.h"



ArcadeMode::ArcadeMode(GameStates* current) : RunState(current)
{

	background->Initialise("ARCADE_BACKGROUND");

	ballSet->Initialise(400, 400, glm::vec2(100, HEIGHT / 2), 100);

}


bool ArcadeMode::update(double dt)
{
	keys = TheInput::Instance()->GetKeyStates();

	ambient_music.Play(ambient_music.PLAY_ENDLESS);

	hero->update(dt);


	if (ballSet->GetBallsNumber() != 0)
	{
		_score = (ballSet->GetBallsNumber() * 85);
		final_score = NumberToString(int(_score)).str(); //SET THE TIME BAR LENGHT TO GIVE POINTS
	}
	else
	{
		_score = 0;
	}


	score->SetLabel("Score: " + final_score); //THE TIME BAR WILL DECREASE, giving a time limit

	ballSet->update(dt);

	if (ballSet->CheckCollision(hero->GetBulletBound())) //CHECK COLLISION BETWEEN BULLET AND BALL
	{
		hero->ResetBullett(); //BULLETT CANT COLLIDE ANYMORE
	}

	if (ballSet->CheckCollision(hero->GetPlayerBound())) //CHECK COLLISION BETWEEN PLAYER AND BALL
	{
		TheGame::Instance()->AddTempState(new WinState(this, _score, true));
		_isActive = false;
		_isAlive = true;
	}



	if (keys[SDL_SCANCODE_P])
	{
		TheGame::Instance()->AddTempState(new PauseState(this));

		_isActive = false;
		_isAlive = true;

	}

	if (keys[SDL_SCANCODE_ESCAPE])
	{
		_isActive = false;
		_isAlive = false;
	}

	return false;
}

bool ArcadeMode::Draw()
{
	background->draw();
	hero->draw();
	ballSet->draw();
	score->draw();
	return false;
}

ArcadeMode::~ArcadeMode()
{

}
