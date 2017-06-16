#pragma once
#include <string>

#define WIDTH 1024
#define HEIGHT 768

class GameStates
{
public:

	GameStates(GameStates* current_state);
	virtual ~GameStates() = 0 {};
	 
public:
	virtual bool update(double dt) = 0 {};
	virtual bool Draw() = 0 {};
	std::string final_score;
	static bool loaded;

public:
	bool &isAlive();
	bool &isActive();

protected:
	GameStates* _StatePrevious;
	 
	float _score;

protected:
	bool _isAlive;
	bool _isActive;

};

