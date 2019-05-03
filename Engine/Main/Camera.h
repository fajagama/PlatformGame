#ifndef CAMERA
#define CAMERA

#include "GameObject.h"

class Camera {
private:
	static GameObject * go;
	static int offsetX;
	static int offsetY;

	Camera() {}
public:
	Camera(Camera const&) = delete;
	void operator=(Camera const&) = delete;
	/**
	Nastavuje hern� objekt, kter� bude kamera nasledovat

	@param go hern� objekt
	*/
	static void followGameObject(GameObject * go);
	/**
	@return hern� objekt, kter� je n�sledov�n kamerou
	*/
	static GameObject * getGameObject();
	/**
	@return p�esn� bod aktu�ln� obrazovky
	*/
	static Position getCenterPosition();
	/**
	Nastavuje odsazen� na ose X

	@param offsetY odsazen�
	*/
	static void setOffsetX(int offsetX);
	/**
	@return odsazen� na ose X
	*/
	static int getOffsetX();
	/**
	Nastavuje odsazen� na ose Y

	@param offsetY odsazen�
	*/
	static void setOffsetY(int offsetY);
	/**
	@return odsazen� na ose Y
	*/
	static int getOffsetY();
};

#endif // !CAMERA
