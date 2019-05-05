#include "GameObject.h"

#include "Rect.h"

GameObject::GameObject(const GameObject & go)
{
	position = go.position;
	zIndex = go.zIndex;
	name = go.name;
	tag = go.tag;
	height = go.height;
	width = go.width;
	active = go.active;

	for (auto& com : go.components) {
		Component * newCom = com.second->clone();
		newCom->setGameObject(this);
		components[typeid(*newCom).name()] = newCom;
	}

}

GameObject::GameObject(unsigned int width, unsigned int height)
{
	this->position = Position();
	this->components = map<string, Component *>();
	this->zIndex = 0;
	this->name = "";
	this->height = height;
	this->width = width;
}

GameObject::GameObject(string name, unsigned int width, unsigned int height)
{
	this->position = Position();
	this->components = map<string, Component *>();
	this->zIndex = 0;
	this->name = name;
	this->height = height;
	this->width = width;
}

GameObject::~GameObject()
{
	if (components.size() > 0) {
		for (auto& com : components) {
			delete com.second;
		}
	}
	components.clear();
}

Position & GameObject::getPosition()
{
	return this->position;
}

void GameObject::setPosition(int x, int y)
{
	this->position = Position(x, y);
}

map<string, Component *> & GameObject::getComponents()
{
	return this->components;
}

void GameObject::setName(string name)
{
	this->name = name;
}

string GameObject::getName()
{
	return name;
}

void GameObject::setTag(string tag)
{
	this->tag = tag;
}

string GameObject::getTag()
{
	return tag;
}

GameObject & GameObject::addComponent(Component & com)
{
	components[typeid(com).name()] = com.clone();
	return *this;
}

void GameObject::callOnTrigger(GameObject & go)
{
	for (auto& com : components) {
		com.second->onTrigger(go);
	}
}

void GameObject::callOnCollision(GameObject & go)
{
	for (auto& com : components) {
		com.second->onCollision(go);
	}
}

void GameObject::callOnMouseClick()
{
	for (auto& com : components) {
		com.second->onMouseClick();
	}
}

void GameObject::setZIndex(int zIndex)
{
	this->zIndex = zIndex;
}

int GameObject::getZIndex()
{
	return this->zIndex;
}

void GameObject::setHeight(unsigned int height)
{
	this->height = height;
}

unsigned int GameObject::getHeight()
{
	return this->height;
}

void GameObject::setWidth(unsigned int width)
{
	this->width = width;
}

unsigned int GameObject::getWidth()
{
	return this->width;
}

bool GameObject::isActive()
{
	return active;
}

void GameObject::setActive(bool active)
{
	this->active = active;
}

