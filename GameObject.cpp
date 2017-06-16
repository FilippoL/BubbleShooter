#include "GameObject.h"



GameObject::GameObject()
{
	position = glm::vec2(0.0, 0.0);
}

GameObject::~GameObject()
{

}


void GameObject::draw()
{

}

void GameObject::SetPosition(glm::vec2 pos)
{
	position = pos;
}

glm::vec2 GameObject::GetPosition()
{
	return position;
}



