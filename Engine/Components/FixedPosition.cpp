#include "FixedPosition.h"
#include "WindowManager.h"
#include "Camera.h"

FixedPosition::FixedPosition(const FixedPosition & com)
{
	position = com.position;
	offsetX = com.offsetX;
	offsetY = com.offsetY;
}

FixedPosition::FixedPosition(Spot position)
{
	this->position = position;
}

void FixedPosition::setOffsetX(int offset)
{
	this->offsetX = offset;
}

void FixedPosition::setOffsetY(int offset)
{
	this->offsetY = offset;
}

void FixedPosition::update()
{
	int posX = 0;
	int posY = 0;
	switch (position)
	{
	case Spot::TOP_RIGHT:
		posX = Camera::getCenterPosition().getPosX() + WindowManager::getWidth() - getGameObject()->getWidth();
		posY = Camera::getCenterPosition().getPosY();
		break;
	case Spot::TOP_LEFT:
		posX = Camera::getCenterPosition().getPosX();
		posY = Camera::getCenterPosition().getPosY();
		break;
	case Spot::BOTTOM_RIGHT:
		posX = Camera::getCenterPosition().getPosX() + WindowManager::getWidth() - getGameObject()->getWidth();
		posY = Camera::getCenterPosition().getPosY() + WindowManager::getHeight() - getGameObject()->getHeight();
		break;
	case Spot::BOTTOM_LEFT:
		posX = Camera::getCenterPosition().getPosX();
		posY = Camera::getCenterPosition().getPosY() + WindowManager::getHeight() - getGameObject()->getHeight();
		break;
	case Spot::CENTER:
		posX = Camera::getCenterPosition().getPosX() + (WindowManager::getWidth() / 2) - (getGameObject()->getWidth() / 2);
		posY = Camera::getCenterPosition().getPosY() + (WindowManager::getHeight() / 2) - (getGameObject()->getHeight() / 2);
		break;
	}
	getGameObject()->getPosition().setPosX(posX + offsetX);
	getGameObject()->getPosition().setPosY(posY + offsetY);
}

FixedPosition * FixedPosition::clone()
{
	return new FixedPosition(*this);
}
