#include "Label.h"
#include "TextureManager.h"


Label::Label()
{
}

void Label::Initialise(std::string ID, int W, int H,glm::vec2 position, glm::vec3 color)
{
	_variables_from_file.InitialiseSection("LABEL");

	(!TheTexture::Instance()->GetTexture("TEXT")) ?
		TheTexture::Instance()->LoadFontFromFile(_variables_from_file.GetAlphabeticVariable("FONT"), 50, "TEXT") : 0;

	_position = position;

	_text.SetFont(ID);
	_text.SetSize(W, H);
	_text.SetColor(color.r,color.g,color.b);
}


void Label::SetLabel(std::string l)
{
	_text.SetText(l);
}

void Label::draw()
{
	_text.Draw(_position.x,_position.y);
}

Label::~Label()
{
}
