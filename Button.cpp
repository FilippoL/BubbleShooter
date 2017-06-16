#include "Button.h"
#include "InputManager.h"
#include "TextureManager.h"
#include "Text.h"

Button::Button()
{
	_buttons = new Animation;
	_bound = new Sphere;
	_text = new Text;
}


void Button::initialise(int W, int H, glm::vec2 pos, std::string label, bool animated) //create a button
{
	

	_variables_from_file.InitialiseSection("LABEL");

	(!TheTexture::Instance()->GetTexture("TEXT")) ?
		TheTexture::Instance()->LoadFontFromFile(_variables_from_file.GetAlphabeticVariable("FONT"), 50, "TEXT") : 0;

	position = pos;

	_width = W;
	_height = H;

	_variables_from_file.InitialiseSection("TEXTURES_BUTTONS");


	(!TheTexture::Instance()->GetTexture("CLICKED"))?	
		TheTexture::Instance()->LoadTextureFromFile(_variables_from_file.GetAlphabeticVariable("CLICKED"), "CLICKED"):0;
	
	(!TheTexture::Instance()->GetTexture("NORMAL"))?	
		TheTexture::Instance()->LoadTextureFromFile(_variables_from_file.GetAlphabeticVariable("NORMAL"), "NORMAL"):0;

	(!TheTexture::Instance()->GetTexture("MOUSE_ON")) ?
		TheTexture::Instance()->LoadTextureFromFile(_variables_from_file.GetAlphabeticVariable("MOUSE_ON"), "MOUSE_ON"):0;


	_text->SetFont("TEXT");

	if (label.size() < 5)//adjust the size if bigger than 5 letters
	{
		_text->SetSize(_width - _width/label.length(),_height -  _height /label.length()); //ruffly
	}
	else
	{
		_text->SetSize(_width - (_width/label.length()*2.5),_height -  (_height /label.length())*2.5);
	}
	_text->SetText(label);
	
	_buttons->SetTextureDimension(1,1,256,256);
	_buttons->SetSpriteDimension(W, H);

	texture = "NORMAL";

	_isAnimated = animated;

	_bound->SetPosition(position.x,position.y );
	_bound->SetRadius(H/2);
}

void Button::draw()
{
	_buttons->SetTexture(texture);
	_buttons->Draw(position.x,position.y);
	_text->Draw(position.x + _width/6, position.y + _height/6);
}

void Button::update(double dt)
{
	if (TheInput::Instance()->IsMouseColliding(*_bound))//collision 
	{
		if (_isAnimated)
		{
			texture = "MOUSE_ON";
			_buttons->SetAnimationVelocity(20.0f);
			_buttons->SetTextureCell(0,0);
			_buttons->SetTextureDimension(6, 5, 3240/6, 2700/5);
			_buttons->IsAnimationLooping() = true;
		}

		else
		{
			texture = "CLICKED";
		}
		_text->SetColor(250, 250, 0);

		_isClicked = false;

		if (TheInput::Instance()->GetLeftButtonState())
		{
			texture = "CLICKED";
			_text->SetColor(250, 250, 250);
			_isClicked = true;
			_buttons->SetAnimationVelocity(0);
			SDL_Delay(100);

		}

	}

	else
	{
		texture = "NORMAL";
		_buttons->SetAnimationVelocity(0);
		_text->SetColor(250, 50, 0);
		_isClicked = false;

	}
	
}

void Button::SwapLabel(std::string newlabel)
{

	_text->SetText(newlabel);

}

bool Button::Clicked()
{
	return _isClicked;
}

Button::~Button()
{
	delete _buttons;
	delete _bound;
	delete _text;
}
