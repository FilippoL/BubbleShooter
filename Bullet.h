#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "Animation.h"
#include "Sphere.h"
#include <vector>

class Bullet :
	public GameObject
{
public:
	Bullet();
	virtual ~Bullet();

	virtual void update(double dt);
	virtual void draw();

public:
	bool & Shoot();

public:
	Sphere GetBound();

private:
	float an_speed;
	
private:
	bool needsReset;
	bool isShoot;

private:
	float coll_y;
	float radius;
	
private:
	Animation m_rock;
	Sphere m_bound;
};

