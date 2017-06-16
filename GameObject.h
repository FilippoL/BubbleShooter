#pragma once
#include <string>
#include <vec2.hpp>
#include "FileManager.h"

#define WIDTH 1024
#define HEIGHT 768

class GameObject
{
public:
	GameObject();
	virtual ~GameObject() = 0;


	virtual void update(double dt) = 0;
	virtual void draw() = 0;

	void SetPosition(glm::vec2 pos);

	glm::vec2 GetPosition();
	

protected:
	glm::vec2 position;

	FileManager _variables_from_file;


	bool isColliding;

	float _width, _height;

};

