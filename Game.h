#ifndef GAME_H
#define GAME_H

#include <SDL.h> 
#include <deque>
#include <iostream>
#include <string>
#include <deque>
#include "AudioManager.h"
#include "InputManager.h"
#include "TextureManager.h"
#include "Sprite.h"
#include "ScreenManager.h"
#include "GameObject.h"
#include "Animation.h"
#include "Text.h"
#include "Audio.h"
#include "SFX.h"

 
#include "GameStates.h"
#include "PauseState.h"
#include "RunState.h"


class Game
{

public:

	friend class Singleton<Game>;

	bool Initialise(std::string GameName, int Width, int Height);
	void Run() ;
	void ShutDown() ;

	void AddTempState(GameStates * my_state);
	void ChangeState(GameStates* my_state);
private:
	void DeleteState();

private:

	Game();
	Game(const Game&);


	Game& operator=(const Game&);

private:
	bool isRunning = true;

private:
	double NOW, DeltaTime, LAST;
	

public: 
	std::deque<GameStates*> m_Gstates;
};

typedef Singleton<Game> TheGame;

#endif