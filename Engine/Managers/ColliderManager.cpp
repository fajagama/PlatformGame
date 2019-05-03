#include "ColliderManager.h"
#include "GameObject.h"
#include "Collider.h"

bool ColliderManager::checkCollision(GameObject & go1, GameObject & go2)
{
	int checkX1 = go1.getPosition().getPosX();
	int checkX2 = go1.getPosition().getPosX() + go1.getComponent<Collider>()->getWidth();

	int checkY1 = go1.getPosition().getPosY();
	int checkY2 = go1.getPosition().getPosY() + go1.getComponent<Collider>()->getHeight();
	
	int go2X1 = go2.getPosition().getPosX();
	int go2X2 = go2.getPosition().getPosX() + go2.getComponent<Collider>()->getWidth();

	int go2Y1 = go2.getPosition().getPosY();
	int go2Y2 = go2.getPosition().getPosY() + go2.getComponent<Collider>()->getHeight();

	return (
		checkPointCollision(checkX1, go2X1, go2X2, checkY1, go2Y1, go2Y2) ||
		checkPointCollision(checkX2, go2X1, go2X2, checkY1, go2Y1, go2Y2) ||
		checkPointCollision(checkX1, go2X1, go2X2, checkY2, go2Y1, go2Y2) ||
		checkPointCollision(checkX2, go2X1, go2X2, checkY2, go2Y1, go2Y2)
		);
}

bool ColliderManager::checkPointCollision(int pointX, int pointX1, int pointX2, int pointY, int pointY1, int pointY2)
{
	return (pointX >= pointX1 && pointX2 >= pointX && pointY >= pointY1 && pointY2 >= pointY);
}

void ColliderManager::checkCollision(GameObject & go, list<GameObject *> & gameObjects)
{
	if (go.getPosition().isPositionChanged() && go.isActive()) {
		Collider * goCol1 = go.getComponent<Collider>();

		if (goCol1 != nullptr) {
			for (GameObject * go2 : gameObjects) {
				Collider * goCol2 = go2->getComponent<Collider>();
				if (goCol2 != nullptr) {
					if (go.getName() != go2->getName() && go2->isActive()) {
						if (checkCollision(go, *go2) || checkCollision(*go2, go)) {
							if (goCol1->isTrigger()) {
								go.callOnTrigger(*go2);
							}
							else {
								go.callOnCollision(*go2);
							}
							if (goCol2->isTrigger()) {
								go2->callOnTrigger(go);
							}
							else {
								go2->callOnCollision(go);
							}
						}
					}
				}
			}
		}
	}
}

void ColliderManager::checkMouseClick(Position & position, list<GameObject*> & gameObjects)
{
	for (GameObject * go : gameObjects) {
		if (go->isActive()) {
			int pointX1 = go->getPosition().getPosX();
			int pointX2 = go->getPosition().getPosX() + go->getWidth();

			int pointY1 = go->getPosition().getPosY();
			int pointY2 = go->getPosition().getPosY() + go->getHeight();

			if (checkPointCollision(position.getPosX(), pointX1, pointX2, position.getPosY(), pointY1, pointY2)) {
				go->callOnMouseClick();
			}
		}
	}
}
