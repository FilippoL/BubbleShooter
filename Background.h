#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "FileManager.h"

class Background :
	public GameObject
{
public:
	Background();

	Sprite _back_image;

	void Initialise(std::string ID);

	void update(double dt) {};
	void draw();


	virtual ~Background();
};

