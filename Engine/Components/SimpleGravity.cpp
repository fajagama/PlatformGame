#include "SimpleGravity.h"

#include "TimeManager.h"

SimpleGravity::SimpleGravity(const SimpleGravity & com)
{
	weight = com.weight;
	gravity = com.gravity;
	terminalVelocity = com.terminalVelocity;
	fallSpeed = com.fallSpeed;
	grounded = com.grounded;
}

SimpleGravity::SimpleGravity()
{
}

void SimpleGravity::setWeight(unsigned int weight)
{
	this->weight = weight;
}

int SimpleGravity::getWeight()
{
	return weight;
}

void SimpleGravity::setGravity(unsigned int gravity)
{
	this->gravity = gravity;
}

int SimpleGravity::getGravity()
{
	return gravity;
}

bool SimpleGravity::isGrounded()
{
	return grounded == true;
}

void SimpleGravity::update()
{	
	if (TimeManager::getDeltaTime() > 0.0) {
		fallSpeed += (float)((weight * gravity) / 100.0f * TimeManager::getDeltaTime());
		if (fallSpeed > terminalVelocity) {
			fallSpeed = terminalVelocity;
		}

		float poxY = getGameObject()->getPosition().getPosY();
		getGameObject()->getPosition().setPosY(poxY + fallSpeed);

		if (fallSpeed > 1) {
			grounded = false;
		}
	}
}

void SimpleGravity::onCollision(GameObject & go)
{
	if (!go.getComponent<Collider>()->isTrigger()) {
		int otherX = go.getPosition().getPosX();
		int otherY = go.getPosition().getPosY();
		int otherWidth = go.getComponent<Collider>()->getWidth();

		int myX = getGameObject()->getPosition().getPosX();
		int myY = getGameObject()->getPosition().getPosY();
		int myOldX = getGameObject()->getPosition().getOldPosX();
		int myOldY = getGameObject()->getPosition().getOldPosY();
		int myWidth = getGameObject()->getComponent<Collider>()->getWidth();
		int myHeight = getGameObject()->getComponent<Collider>()->getHeight();

		if ((myX >= otherX && (otherX + otherWidth) > myX) || ((myX + myWidth) > otherX && (otherX + otherWidth) >= (myX + myWidth))) {
			if (otherY > myY) {
				//jsem nad
				if ((myY + myHeight) >= otherY) {
					fallSpeed = 0;
					grounded = true;
				}
			}
		}
	}
}

SimpleGravity * SimpleGravity::clone()
{
	return new SimpleGravity(*this);
}
