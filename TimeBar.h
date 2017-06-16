#pragma once
#include "GameObject.h"
#include "Sprite.h"

class TimeBar :
	public GameObject
{
public:
	TimeBar();

	void Reset();

	float GetScore();

	bool IsOver();

	virtual void update(double dt);
	virtual void draw();

	float elapsed_t;

	Sprite * life;
	Sprite * life_bar;

	virtual ~TimeBar();
};

