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
	@param width ���ka v pixelech
	@param height v��ka v pixelech
	@return vr�ti obd�ln�kou oblast pro vykreslen�
	*/
	static SDL_Rect getRect(int width, int height);
	/**
	V�sledn� oblast je oblast v �rovni v z�visloti na pozici kamery

	@param go hern� objekt
	@return vr�ti obd�ln�kou oblast pro vykreslen�
	*/
	static SDL_Rect getRect(GameObject & go);
	/**
	@param offsetX odsazen� na ose X
	@param offsetY odsazen� na ose Y
	@param width ���ka v pixelech
	@param height v��ka v pixelech
	@return vr�ti obd�ln�kou oblast pro vykreslen�
	*/
	static SDL_Rect getRect(int offsetX, int offsetY, int width, int height);
};

#endif // !RECT
