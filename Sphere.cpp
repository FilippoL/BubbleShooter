#include "Sphere.h"

//------------------------------------------------------------------------------------------------------
//constructor that assigns all default values
//------------------------------------------------------------------------------------------------------
Sphere::Sphere()
{

	m_radius = 0.0f;
	_canCollide = true;
	
}
//------------------------------------------------------------------------------------------------------
//setter function that assigns dimension of sphere
//------------------------------------------------------------------------------------------------------
void Sphere::SetRadius(float radius)
{

	m_radius = radius;

}
//------------------------------------------------------------------------------------------------------
//setter function that assigns position of sphere
//------------------------------------------------------------------------------------------------------
void Sphere::SetPosition(float x, float y)
{

	m_position.x = x;
	m_position.y = y;

}

int Sphere::GetRadius()
{
	return m_radius;
}

//------------------------------------------------------------------------------------------------------
//function that checks if sphere collides with another sphere object
//------------------------------------------------------------------------------------------------------
bool Sphere::IsColliding(const Sphere& secondSphere)
{
	if (_canCollide)
	{
		//first calculate distance between both spheres and store that temporarily
		float distance = glm::length((m_position + m_radius) - 
									 (secondSphere.m_position + secondSphere.m_radius));

		//return collision flag based on distance and radii formula  
		return (distance <= (m_radius + secondSphere.m_radius)); 
	}

	return false;
}

bool & Sphere::canCollide()
{
	// TODO: insert return statement here
	return _canCollide;
}
