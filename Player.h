#pragma once
#include "GameObject.h"
#include "Animation.h"
#include "Bullet.h"
#include "Sphere.h"

class Player :
	public GameObject
{
public:
	Player();
	Sphere  GetBulletBound();
	Sphere  GetPlayerBound();
	void ResetBullett();
	virtual ~Player();
	
public:
	virtual void update(double dt);
	virtual void draw();

private:
	float _health;
	float _speed = 2;
	bool _going_right;

private:
	float animation_speed;

private:
	const Uint8* keys = nullptr;

protected:
	Animation hero;
	Sphere m_bound;
	Bullet* _bullett;
};

