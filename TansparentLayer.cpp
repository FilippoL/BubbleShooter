#include "TansparentLayer.h"
#include "TextureManager.h"



TansparentLayer::TansparentLayer()
{
}

void TansparentLayer::Initialise(std::string ID)
{
	_textures_path.InitialiseSection("TRANSPARENT_TILES");
	

	(!TheTexture::Instance()->GetTexture("TRANSPAR")) ?
	TheTexture::Instance()->LoadTextureFromFile(_textures_path.GetAlphabeticVariable("TRANSPAR"), "TRANSPAR"):0;

	(!TheTexture::Instance()->GetTexture("TRANSPAR_2")) ?
	TheTexture::Instance()->LoadTextureFromFile(_textures_path.GetAlphabeticVariable("TRANSPAR_2"), "TRANSPAR_2"):0;

	

	_back_image.SetTexture(ID);
	_back_image.SetSpriteDimension(142, 142);
	_back_image.SetTextureDimension(1, 1, 142, 142);
}


void TansparentLayer::draw()
{
	for (size_t i = 0; i < WIDTH; i += 142)
	{
		for (size_t j = 0; j < HEIGHT; j += 142)
		{
			_back_image.Draw(0 + i, 0 + j);
		}
	}
}

TansparentLayer::~TansparentLayer()
{
}
