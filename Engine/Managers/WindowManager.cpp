#include "WindowManager.h"
#include "Core.h"

bool WindowManager::fullscreen = false;
int WindowManager::width = 1360;
int WindowManager::height = 768;

int WindowManager::getWidth()
{
	return width;
}

int WindowManager::getHeight()
{
	return height;
}

void WindowManager::setWidth(int width)
{
	WindowManager::width = width;
}

void WindowManager::setHeight(int height)
{
	WindowManager::height = height;
}

bool WindowManager::isFullscreen()
{
	return fullscreen;
}

void WindowManager::setFullscreen(bool fullscreen)
{
	WindowManager::fullscreen = fullscreen;
}
