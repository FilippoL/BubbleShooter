#pragma once
#include "GameObject.h"
#include "Sprite.h"
class Lifes :
	public GameObject
{
public:
	Lifes();

	Sprite _hearth;

	void Initialise();

	void update(double dt);
	int GetLifes();
	void Damaged();
	void draw();

	int _lifes_n;

	virtual ~Lifes();
};

