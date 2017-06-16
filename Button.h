#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "AABB.h"
#include "Sphere.h"
#include "Animation.h"
#include "Text.h"
#include "FileManager.h"

class Button :
	public GameObject
{
public:
	Button();
	virtual ~Button();


	void initialise(int W, int H, glm::vec2 pos, std::string label = "", bool animated = true);
	virtual void draw();
	virtual void update(double dt);

	void SwapLabel(std::string newlabel);

	bool Clicked();

private:
	std::string texture;
	bool _isClicked;

private:
	Animation* _buttons;
	Sphere* _bound;
	Text* _text;
	bool _isAnimated;
};

