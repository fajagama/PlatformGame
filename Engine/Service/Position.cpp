#include "Position.h"

Position::Position()
{
	posX = 0;
	posY = 0;
}

Position::Position(float posX, float posY)
{
	this->posX = posX;
	this->posY = posY;
}

Position::~Position()
{
}

int Position::getPosX()
{
	return posX;
}

int Position::getPosY()
{
	return posY;
}

void Position::setPosX(float posX)
{
	this->posX = posX;
}

void Position::setPosY(float posY)
{
	this->posY = posY;
}

int Position::getOldPosX()
{
	return oldPosX;
}

int Position::getOldPosY()
{
	return oldPosY;
}


void Position::setNewOldPosition()
{
	oldPosX = posX;
	oldPosY = posY;
}

bool Position::isPositionChanged()
{
	return isPositionXChanged() || isPositionYChanged();
}

bool Position::isPositionXChanged()
{
	return oldPosX != posX;
}

bool Position::isPositionYChanged()
{
	return oldPosY != posY;
}
