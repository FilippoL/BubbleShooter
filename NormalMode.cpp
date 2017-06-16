#include "NormalMode.h"
#include "Tools.h"
#include "Game.h"

NormalMode::NormalMode(GameStates* current) : RunState(current)
{

	background->Initialise("BACKGROUND");
	_timebar = new TimeBar;
	_lifes.Initialise();

	ballSet->Initialise(250,250,glm::vec2(100,HEIGHT/2), 4);
}

bool NormalMode::update(double dt)
{
	ambient_music.Play(ambient_music.PLAY_ENDLESS);

	////read keyboard state
	keys = TheInput::Instance()->GetKeyStates();  


	_timebar->update(dt);
	hero->update(dt);

	_score = _timebar->GetScore();	
	final_score = NumberToString(int(_score)).str(); //SET THE TIME BAR LENGHT TO GIVE POINTS
	_lifes.update(dt);

	score->SetLabel("Score: " + final_score); //THE TIME BAR WILL DECREASE, giving a time limit
					  
	ballSet->update(dt);
	
	if (ballSet->CheckCollision(hero->GetBulletBound())) //CHECK COLLISION BETWEEN BULLET AND BALL
	{
		hero->ResetBullett(); //BULLETT CANT COLLIDE ANYMORE
	}

	if ( ballSet->GetBallsNumber() < 1 || _timebar->IsOver()) //CHECK COLLISION BETWEEN PLAYER AND BALL
	{
		TheGame::Instance()->AddTempState(new WinState(this, _score + _lifes.GetLifes() * 10 , false));
		_isActive = false;
		_isAlive = true;
	}

	if ( _lifes.GetLifes() < 1)
	{
		TheGame::Instance()->AddTempState(new WinState(this, 0.0 , false));
		_isActive = false;
		_isAlive = true;

	}
	if (ballSet->CheckCollision(hero->GetPlayerBound()))
	{
		_lifes.Damaged();
		_timebar->Reset();
		ballSet->reset(glm::vec2(100,HEIGHT/2),glm::vec2(250,250));
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

bool NormalMode::Draw()
{
	background->draw();
	hero->draw();
	ballSet->draw();
	score->draw();
	_timebar->draw();
	_lifes.draw();
	return false;
}


NormalMode::~NormalMode()
{
	delete  _timebar;

}
