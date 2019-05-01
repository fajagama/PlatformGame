#include "Position.h"

Position::Position()
{
	this->posX = 0;
	this->posY = 0;
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
	return this->posX;
}

int Position::getPosY()
{
	return this->posY;
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
	return this->oldPosX;
}

int Position::getOldPosY()
{
	return this->oldPosY;
}


void Position::setNewOldPosition()
{
	this->oldPosX = this->posX;
	this->oldPosY = this->posY;
}

bool Position::isPositionChanged()
{
	return this->isPositionXChanged() || this->isPositionYChanged();
}

bool Position::isPositionXChanged()
{
	return oldPosX != posX;
}

bool Position::isPositionYChanged()
{
	return oldPosY != posY;
}
