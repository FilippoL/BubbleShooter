#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "FileManager.h"

class TansparentLayer :
	public GameObject
{
public:
	TansparentLayer();

	Sprite _back_image;
	FileManager _textures_path;

	void Initialise(std::string ID);

	void update(double dt) {};
	void draw();

	virtual ~TansparentLayer();
};

