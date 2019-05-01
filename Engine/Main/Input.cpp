#include "Input.h"

#include "Camera.h"
#include <algorithm>
#include <cstdlib>   

string Input::keyCodeDown = "";
string Input::keyCodeUp = "";

int Input::mouseCodeDown = -1;
int Input::mouseCodeUp = -1;

Position Input::mousePosition = Position();

map<string, string> Input::keysDown;

bool Input::getKeyDown(KeyCode key)
{
	string lowerKey = SDL_GetKeyName(static_cast<SDL_Keycode>(key));
	transform(lowerKey.begin(), lowerKey.end(), lowerKey.begin(), ::tolower);
	return getKeyDown(lowerKey);
}

bool Input::getKeyDown(string key)
{
	return (keysDown.find(key) != keysDown.end());
}

void Input::setKeyDown(SDL_Keycode keyCode)
{
	string lowerKey = SDL_GetKeyName(keyCode);
	transform(lowerKey.begin(), lowerKey.end(), lowerKey.begin(), ::tolower);
	keyCodeDown = lowerKey;
	keysDown[lowerKey] = lowerKey;
}

bool Input::getKeyUp(KeyCode key)
{
	string lowerKey = SDL_GetKeyName(static_cast<SDL_Keycode>(key));
	transform(lowerKey.begin(), lowerKey.end(), lowerKey.begin(), ::tolower);
	return getKeyUp(lowerKey);
}

bool Input::getKeyUp(string key)
{
	return !keyCodeUp.empty() && key.compare(keyCodeUp) == 0;
}

void Input::setKeyUp(SDL_Keycode keyCode)
{
	string lowerKey = SDL_GetKeyName(keyCode);
	transform(lowerKey.begin(), lowerKey.end(), lowerKey.begin(), ::tolower);
	keyCodeUp = lowerKey;
	keysDown.erase(lowerKey);
}

bool Input::getMouseKeyDown(KeyCode key)
{
	return mouseCodeDown == static_cast<SDL_Keycode>(key);
}

void Input::setMouseKeyDown(int mouseCode)
{
	mouseCodeDown = mouseCode;
}

bool Input::getMouseKeyUp(KeyCode key)
{
	return mouseCodeUp == static_cast<SDL_Keycode>(key);
}

void Input::setMouseKeyUp(int mouseCode)
{
	mouseCodeUp = mouseCode;
}

bool Input::isMouseClicked()
{
	return mouseCodeUp != -1;
}

Position & Input::getMousePosition()
{
	return mousePosition;
}

void Input::setMousePosition(int x, int y)
{
	mousePosition.setPosX(x + Camera::getCenterPosition().getPosX());
	mousePosition.setPosY(y + Camera::getCenterPosition().getPosY());
}

void Input::reset()
{
	keyCodeDown = "";
	keyCodeUp = "";
	mouseCodeDown = -1;
	mouseCodeUp = -1;
}
