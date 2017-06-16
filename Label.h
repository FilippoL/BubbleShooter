#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "Text.h"
#include "FileManager.h"

class Label :
	public GameObject
{
public:
	Label();

	void Initialise(std::string ID, int W, int H, glm::vec2 position, glm::vec3 color);


	Text _text;

	void update(double dt) {};
	void SetLabel(std::string l);
	void draw();
	glm::vec2 _position;

	virtual ~Label();
};

