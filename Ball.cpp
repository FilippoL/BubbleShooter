#include "Ball.h"
#include "TextureManager.h"
#include "AABB.h"
#include "Sprite.h"
#include "InputManager.h"
#include "AudioManager.h"
#include "Bullet.h"
#include <iostream>


Ball::Ball()
 {
	_totalBalls = 0;
}

void Ball::Initialise(float OriginalWidth, float OriginalHeight, glm::vec2 originalpos, int max_balls)
{
	_max_number = max_balls;

	_variables_from_file.InitialiseSection("BALLS");

	(!TheTexture::Instance()->GetTexture("BALL1"))
		?TheTexture::Instance()->LoadTextureFromFile(_variables_from_file.GetAlphabeticVariable("b1"), "BALL1"):0;

	(!TheTexture::Instance()->GetTexture("BALL2"))
		?TheTexture::Instance()->LoadTextureFromFile(_variables_from_file.GetAlphabeticVariable("b2"), "BALL2"):0;

	(!TheTexture::Instance()->GetTexture("BALL3"))?
		TheTexture::Instance()->LoadTextureFromFile(_variables_from_file.GetAlphabeticVariable("b3"), "BALL3"):0;

	(!TheTexture::Instance()->GetTexture("BALL4"))?
		TheTexture::Instance()->LoadTextureFromFile(_variables_from_file.GetAlphabeticVariable("b4"), "BALL4"):0;

	TheAudio::Instance()->LoadFromFile("Assets//Audio//BubblePop.wav", TheAudio::Instance()->SFX_AUDIO, "POP");
	pop = new SFX;

	pop->SetSFX("POP");
	pop->SetVolume(100);


	_ball.push_back(new Ball());
	//SET INITIAL VALUES
	_ball.front()->_level = 1;
	_ball.front()->_W = OriginalWidth;
	_ball.front()->_H = OriginalHeight;
	_ball.front()->_position = glm::vec2(originalpos.x + OriginalWidth, originalpos.y + OriginalHeight);
	_ball.front()->_speed.x = 250;
	_ball.front()->_speed.y = 2.00;
	_ball.front()->_angle = originalpos.y;
	_ball.front()->_sprite = new Sprite;
	_ball.front()->_coll = new Sphere;

	_ball.front()->_coll->SetPosition(_ball.front()->_position.x,_ball.front()->_position.y);
	_ball.front()->_coll->SetRadius(_ball.front()->_W/2);

	_ball.front()->_sprite->SetTexture("BALL4");
	_ball.front()->_sprite->SetTextureDimension(1,1,225,225);
	_ball.front()->_sprite->SetSpriteDimension(_ball.front()->_W,_ball.front()->_H);
}


void Ball::update(double dt)
{
	keys = TheInput::Instance()->GetKeyStates();


	if (!_ball.empty())
	{
		for (auto it = _ball.begin(); it != _ball.end(); ++it) //FOR ALL THE ELEMENTS IN THE LIST
		{
 			if (!(*it)->_dead) //IF NOT DEAD
			{
				//UPDATE...
				(*it)->_angle += (*it)->_speed.y * dt;
				(*it)->_position.x += (*it)->_speed.x * dt;
			
				(*it)->_position.y = (((HEIGHT - 25) - (*it)->_W)+ (abs(sin((*it)->_angle))) * -(HEIGHT - 25)/1.15); //FORMULA FOR BOUNCING
	
				if ((*it)->_position.x + (*it)->_W >= WIDTH || (*it)->_position.x < 1) //CHECKING COLLISION WITH MAX SCREEN 
				{
					(*it)->_speed.x *= -1.0f;
				}

				(*it)->_coll->SetPosition((*it)->_position.x , (*it)->_position.y );
			}
			
			if ((*it)->_dead)//IF DIED
			{
				Die();
				pop->Play();
				_totalBalls++; //VARIABLE FOR SCORE
			}

		}
		

	}
}

void Ball::draw()
{
	for (auto it = _ball.begin(); it != _ball.end(); it++)
	{
		(*it)->_sprite->Draw((*it)->_position.x, (*it)->_position.y);
	}
}

Ball* Ball::Generate(Ball* NewBall) //MAYBE COULD PASS A REFERENCE AND ALWAYS USE THE SAME SPOT IN THE LIST,
									//PLUS CREATING A NEW ONE EVERY TWO(?)
{
	c++;//JUST A COUNTER -> TO BE OPTIMISED

	float scalefactor = 0.55f; //APPLY A SCALE EVERYTIME ON: SIZE, SPEED

	Ball *temp_ball; //CREATE A TEMPORARY INSTANCE FOR COPYING

	temp_ball = new Ball;

	temp_ball->_W = NewBall->_W * scalefactor;
	temp_ball->_H = NewBall->_H * scalefactor;
	
	temp_ball->_level = NewBall->_level + 1;

	temp_ball->_dead = false;

	temp_ball->_sprite = new Sprite;
	temp_ball->_coll = new Sphere;
			  
	temp_ball->_sprite->SetTextureDimension(1,1,87,86);
	temp_ball->_sprite->SetSpriteDimension(temp_ball->_W,temp_ball->_H);

	temp_ball->_angle = NewBall->_angle; //SAME ANGLE OF ROTATION ON THE Y 
	

	if (c%2 == 0) //ON EVERY ONE IS GOING TO
	{
		if (c == 2)
		{
			temp_ball->_sprite->SetTexture("BALL1"); //HAVE DIFFERENT TEXTURE --> TO BE OPTIMISED
		}

		else
		{
			temp_ball->_sprite->SetTexture("BALL2");
		}
		
		temp_ball->_speed.y = abs(NewBall->_speed.y) * 0.98f; //OPPOSITE DIRECTION
		temp_ball->_speed.x = -abs(NewBall->_speed.x) * (scalefactor * 1.15f);
		temp_ball->_position = NewBall->_position - glm::vec2(temp_ball->_W/1.25, 0.0);
		if (temp_ball->_position.x < temp_ball->_width)
		{
			temp_ball->_position.x = temp_ball->_position.x = temp_ball->_width;
		}		
		
		(temp_ball->_position.x < WIDTH) ? temp_ball->_position.x = temp_ball->_position.x - temp_ball->_width: 0;


	}
	else
	{
		temp_ball->_speed.y = abs(NewBall->_speed.y) * 0.90f;
		temp_ball->_sprite->SetTexture("BALL3");
		temp_ball->_speed.x = abs(NewBall->_speed.x)*(scalefactor * 1.35f);
		temp_ball->_position = NewBall->_position + glm::vec2(temp_ball->_W/1.25, 0.0);
		if (temp_ball->_position.x < temp_ball->_width)
		{
			temp_ball->_position.x = temp_ball->_position.x = temp_ball->_width;
		}

		(temp_ball->_position.x < WIDTH) ? temp_ball->_position.x = temp_ball->_position.x - temp_ball->_width : 0;

	}
		
	temp_ball->_coll->SetPosition(temp_ball->_position.x, temp_ball->_position.y);
	temp_ball->_coll->SetRadius(temp_ball->_W/2);

	if (c > 7)	{c = 0;}

	return temp_ball;
}


int Ball::GetFinalBallsNumber()
{
	return _totalBalls*20;
}

int Ball::GetBallsNumber()
{
	return _ball.size();
}

void::Ball::reset(glm::vec2 pos, glm::vec2 size)
{
	for (auto it = _ball.begin(); it != _ball.end(); it++)//CLEAN UP
	{
		delete (*it)->_sprite;
		delete (*it)->_coll;
		delete *it;
	}
	_ball.clear();

	_ball.push_back(new Ball());
	//SET INITIAL VALUES
	_ball.front()->_level = 1;
	_ball.front()->_W = size.x;
	_ball.front()->_H = size.y;
	_ball.front()->_position = glm::vec2(pos.x + size.x, pos.y + size.y);
	_ball.front()->_speed.x = 250;
	_ball.front()->_speed.y = 2.00;
	_ball.front()->_angle = pos.y;
	_ball.front()->_sprite = new Sprite;
	_ball.front()->_coll = new Sphere;

	_ball.front()->_coll->SetPosition(_ball.front()->_position.x,_ball.front()->_position.y);
	_ball.front()->_coll->SetRadius(_ball.front()->_W/2);

	_ball.front()->_sprite->SetTexture("BALL4");
	_ball.front()->_sprite->SetTextureDimension(1,1,225,225);
	_ball.front()->_sprite->SetSpriteDimension(_ball.front()->_W,_ball.front()->_H);

}

void Ball::Die()
{
												/*PREDICATE LAMBA EXPRESSION FINDING ALL DEAD BALLS*/
	auto it = std::find_if(_ball.begin(), _ball.end(), [](const Ball* ball) {return ball->_dead;}); 
		
  	if ((*it)->_level < _max_number)//SET A MAX NUMBER TO CAP THE BALLS
	{
		_ball.push_front(Generate(*it)); //PUSH FRONT TWO CHILD OF THE SHOOT BALL
		_ball.push_front(Generate(*it));
	}

	//LOOP AND REMOVE THE CORPSE
	_ball.remove_if([](const Ball* ball) {return ball->_dead; });
}


bool Ball::CheckCollision(Sphere _coll, bool isfordying)
{
	if (!_ball.empty())
	{
		if (!isfordying)
		{
			for (auto it = _ball.begin(); it != _ball.end(); it++)
			{
				if (_coll.IsColliding(*(*it)->_coll)) //CHECK COLLISION FOR EACH BALL WITH THE PARSED SPHERE
				{									
	 			 		(*it)->_dead = true;
						return true;
				}
			}

		}

		else
		{
			for (auto it = _ball.begin(); it != _ball.end(); it++)
			{
				if (_coll.IsColliding(*(*it)->_coll)) //CHECK COLLISION FOR EACH BALL WITH THE PARSED SPHERE
				{									
						return true;
				}
			}
		}

	}
	return false;
}


Ball::~Ball()
{
	for (auto it = _ball.begin(); it != _ball.end(); it++)//CLEAN UP
	{
		delete (*it)->_sprite;
		delete (*it)->_coll;
		delete *it;
	}
	
	_ball.clear();

	TheAudio::Instance()->UnloadFromMemory(TheAudio::Instance()->SFX_AUDIO, TheAudio::Instance()->CUSTOM_AUDIO,"POP" ); //WONT NEED IN FUTURE
}
