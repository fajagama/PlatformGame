#include "Collider.h"

Collider::Collider(const Collider & com)
{
	trigger = com.trigger;
	width = com.width;
	height = com.height;
}

Collider::Collider(int width, int height)
{
	this->width = width;
	this->height = height;
} 

bool Collider::isTrigger()
{
	return this->trigger;
}

void Collider::setTrigger(bool value)
{
	this->trigger = value;
}

void Collider::setHeight(int height)
{
	this->height = height;
}

int Collider::getHeight()
{
	return this->height;
}

void Collider::setWidth(int width)
{
	this->width = width;
}

int Collider::getWidth()
{
	return this->width;
}

void Collider::onCollision(GameObject & go)
{
	if (!go.getComponent<Collider>()->isTrigger()) {
		int otherX = go.getPosition().getPosX();
		int otherY = go.getPosition().getPosY();
		int otherWidth = go.getComponent<Collider>()->getWidth();
		int otherHeight = go.getComponent<Collider>()->getHeight();

		int myX = getGameObject()->getPosition().getPosX();
		int myY = getGameObject()->getPosition().getPosY();
		int myOldX = getGameObject()->getPosition().getOldPosX();
		int myOldY = getGameObject()->getPosition().getOldPosY();

		bool changeX = false;

		if (myX != myOldX) {
			if (((myY >= otherY && (otherY + otherHeight) > myY)) || ((myY + height) > otherY && (otherY + otherHeight) >= (myY + height)) ||
				((otherY >= myY && (myY + height) > otherY)) || ((otherY + otherHeight) > myY && (myY + height) >= (otherY + otherHeight))) {
				myX = myOldX;
				changeX = true;
			}
		}

		if (myY != myOldY) {
			if (((myX >= otherX && (otherX + otherWidth) > myX) || ((myX + width) > otherX && (otherX + otherWidth) >= (myX + width))) ||
				((otherX >= myX && (myX + width) > otherX) || ((otherX + otherWidth) > myX && (myX + width) >= (otherX + otherWidth)))) {
				if (otherY > myY) {
					//jsem nad
					if ((myY + height) > otherY) {
						myY = otherY - height;
					}
				}
				else {
					//jsem pod
					if ((otherY + otherHeight) > myY) {
						myY = otherY + otherHeight;
					}
				}
			}
		}

		if (changeX) {
			myX = getGameObject()->getPosition().getPosX();
			if (otherX > myX) {
				//jsem vlevo
				if ((myX + width) > otherX) {
					myX = otherX - width;
				}
			}
			else {
				//jsem vpravo
				if ((otherX + otherWidth) > myX) {
					myX = otherX + otherWidth;
				}
			}
		}

		getGameObject()->getPosition().setPosX(myX);
		getGameObject()->getPosition().setPosY(myY);
	}
}

Collider * Collider::clone()
{
	return new Collider(*this);
}

