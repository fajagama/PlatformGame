#include "Rect.h"

SDL_Rect Rect::getRect(int width, int height)
{
	SDL_Rect rect;

	rect.x = 0;
	rect.y = 0;
	rect.w = width;
	rect.h = height;

	return rect;
}

SDL_Rect Rect::getRect(GameObject & go)
{
	SDL_Rect rect;

	rect.x = go.getPosition().getPosX() - Camera::getCenterPosition().getPosX();
	rect.y = go.getPosition().getPosY() - Camera::getCenterPosition().getPosY();
	rect.w = go.getWidth();
	rect.h = go.getHeight();

	return rect;
}

SDL_Rect Rect::getRect(int offsetX, int offsetY, int width, int height)
{
	SDL_Rect rect;

	rect.x = 0 + offsetX;
	rect.y = 0 + offsetY;
	rect.w = width;
	rect.h = height;

	return rect;
}
