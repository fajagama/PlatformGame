#include "Camera.h"
#include "WindowManager.h"

GameObject * Camera::go = nullptr;
int Camera::offsetX = 0;
int Camera::offsetY = 0;

void Camera::followGameObject(GameObject * go)
{
	Camera::go = go;
}

GameObject * Camera::getGameObject()
{
	return go;
}

Position Camera::getCenterPosition()
{
	Position cameraPosition = Position();
		
	if (go != nullptr) {
		int width = (WindowManager::getWidth() / 2) + offsetY;
		int height = (WindowManager::getHeight()) / 2 + offsetX;

		int goHeightCenter = (go->getHeight() / 2);
		int goWidthCenter = (go->getWidth() / 2);

		cameraPosition.setPosX(go->getPosition().getPosX() - width + goWidthCenter);
		cameraPosition.setPosY(go->getPosition().getPosY() - height + goHeightCenter);
	}
	else {
		cameraPosition.setPosX(0);
		cameraPosition.setPosY(0);
	}

	return cameraPosition;
}

void Camera::setOffsetX(int offsetX)
{
	Camera::offsetX = offsetX;
}

int Camera::getOffsetX()
{
	return 0;
}

void Camera::setOffsetY(int offsetY)
{
	Camera::offsetY = offsetY;
}

int Camera::getOffsetY()
{
	return offsetY;
}
