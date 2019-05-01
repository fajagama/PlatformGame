#include "ColliderManager.h"
#include "GameObject.h"
#include "Collider.h"

bool ColliderManager::checkCollision(GameObject & go1, GameObject & go2)
{
	int x1 = go2.getPosition().getPosX();
	int x2 = x1 + go2.getComponent<Collider>()->getWidth();

	int y1 = go2.getPosition().getPosY();
	int y2 = y1 + go2.getComponent<Collider>()->getHeight();

	return (ColliderManager::checkPointCollision(go1, x1, y1) ||
		ColliderManager::checkPointCollision(go1, x2, y1) ||
		ColliderManager::checkPointCollision(go1, x1, y2) ||
		ColliderManager::checkPointCollision(go1, x2, y2));
}

bool ColliderManager::checkPointCollision(GameObject & go, int pointX, int pointY)
{
	int pointX1 = go.getPosition().getPosX();
	int pointX2 = pointX1 + go.getComponent<Collider>()->getWidth();

	int pointY1 = go.getPosition().getPosY();
	int pointY2 = pointY1 + go.getComponent<Collider>()->getHeight();
	
	return checkPointCollision(pointX, pointX1, pointX2, pointY, pointY1, pointY2);
}

bool ColliderManager::checkPointCollision(int pointX, int pointX1, int pointX2, int pointY, int pointY1, int pointY2)
{
	return (pointX >= pointX1 && pointX2 >= pointX && pointY >= pointY1 && pointY2 >= pointY);
}

void ColliderManager::checkCollision(GameObject & go, list<GameObject *> & gameObjects)
{
	if (go.getPosition().isPositionChanged()) {
		Collider * goCol1 = go.getComponent<Collider>();

		if (goCol1 != nullptr) {
			for (GameObject * go2 : gameObjects) {
				Collider * goCol2 = go2->getComponent<Collider>();
				if (goCol2 != nullptr && &go != go2 && go2->isActive()) {
					if (ColliderManager::checkCollision(go, *go2) || ColliderManager::checkCollision(*go2, go)) {
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
