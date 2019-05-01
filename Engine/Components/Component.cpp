#include "Component.h"

void Component::setGameObject(GameObject * go)
{
	this->go = go;
}
void Component::update()
{
}
void Component::render(SDL_Renderer * renderer)
{
}
void Component::resetRender()
{
}
void Component::onTrigger(GameObject & go)
{
}
void Component::onCollision(GameObject & go)
{
}
void Component::onMouseClick()
{
}
void Component::onLoad()
{
}
Component * Component::clone()
{
	return nullptr;
}
GameObject * Component::getGameObject()
{
	return go;
}

Component::~Component()
{
}
