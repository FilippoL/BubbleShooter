#include "Background.h"
#include "TextureManager.h"


Background::Background()
{
}

void Background::Initialise(std::string ID)
{
	_variables_from_file.InitialiseSection("BACKGROUNDS");
	
	(!TheTexture::Instance()->GetTexture("GUI_BACK")) ?
	TheTexture::Instance()->LoadTextureFromFile(_variables_from_file.GetAlphabeticVariable("GUI_BACK"), "GUI_BACK"):0;

	(!TheTexture::Instance()->GetTexture("GAMEOVER")) ?
	TheTexture::Instance()->LoadTextureFromFile(_variables_from_file.GetAlphabeticVariable("GAMEOVER"), "GAMEOVER"):0;

	(!TheTexture::Instance()->GetTexture("BACKGROUND")) ?
	TheTexture::Instance()->LoadTextureFromFile(_variables_from_file.GetAlphabeticVariable("BACKGROUND"), "BACKGROUND"):0;

	(!TheTexture::Instance()->GetTexture("ARCADE_BACKGROUND")) ?
	TheTexture::Instance()->LoadTextureFromFile(_variables_from_file.GetAlphabeticVariable("ARCADE_BACKGROUND"), "ARCADE_BACKGROUND"):0;

	(!TheTexture::Instance()->GetTexture("INSTRUCTIONS")) ?
	TheTexture::Instance()->LoadTextureFromFile(_variables_from_file.GetAlphabeticVariable("INSTRUCTIONS"), "INSTRUCTIONS"):0;

	_back_image.SetTexture(ID);
	_back_image.SetSpriteDimension(WIDTH, HEIGHT);
	_back_image.SetTextureDimension(1, 1, 1920, 1200);
			   
}

void Background::draw()
{
	_back_image.Draw();
}

Background::~Background()
{
}
