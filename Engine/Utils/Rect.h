#ifndef RECT
#define RECT

#include <SDL.h>
#include "GameObject.h"
#include "Camera.h"

class Rect {
public:
	Rect() = delete;
	Rect(Rect const&) = delete;
	void operator=(Rect const&) = delete;
	/**
	@param width šíøka v pixelech
	@param height výška v pixelech
	@return vráti obdélníkou oblast pro vykreslení
	*/
	static SDL_Rect getRect(int width, int height);
	/**
	Výsledná oblast je oblast v úrovni v závisloti na pozici kamery

	@param go herní objekt
	@return vráti obdélníkou oblast pro vykreslení
	*/
	static SDL_Rect getRect(GameObject & go);
	/**
	@param offsetX odsazení na ose X
	@param offsetY odsazení na ose Y
	@param width šíøka v pixelech
	@param height výška v pixelech
	@return vráti obdélníkou oblast pro vykreslení
	*/
	static SDL_Rect getRect(int offsetX, int offsetY, int width, int height);
};

#endif // !RECT
