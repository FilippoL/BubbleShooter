#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "AABB.h"
#include"Sphere.h"
#include "Bullet.h"
#include "SFX.h"
#include <vector>
#include <list>
#include <algorithm>




class Ball :
	public GameObject
{
public:
	Ball();
	bool CheckCollision(Sphere _coll, bool isfordying = false);
	virtual ~Ball();

public:
	void Initialise(float OriginalWidth, float OriginalHeight, glm::vec2 originalpos, int max_balls);

public:
	virtual void update(double dt);
	virtual void draw();

private:
	void Die();

private:
	int c = 0;
	
	int _totalBalls;

private:
	float _W, _H;
	float _angle;

private:
	int _level;

private:
	bool _dead;

private:
	glm::vec2 _position;
	glm::vec2 _speed;

private:
	std::list<Ball*> _ball;
	
	Sprite * _sprite;
	Sphere * _coll;
	Ball* Generate(Ball *);
	SFX* pop;

	const Uint8* keys = nullptr;

public:
	int _max_number;
	int GetFinalBallsNumber();
	int GetBallsNumber();
	void reset(glm::vec2 pos, glm::vec2 size);
};

