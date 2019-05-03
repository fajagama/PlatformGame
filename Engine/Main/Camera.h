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
	Nastavuje herní objekt, který bude kamera nasledovat

	@param go herní objekt
	*/
	static void followGameObject(GameObject * go);
	/**
	@return herní objekt, který je následován kamerou
	*/
	static GameObject * getGameObject();
	/**
	@return pøesný bod aktuální obrazovky
	*/
	static Position getCenterPosition();
	/**
	Nastavuje odsazení na ose X

	@param offsetY odsazení
	*/
	static void setOffsetX(int offsetX);
	/**
	@return odsazení na ose X
	*/
	static int getOffsetX();
	/**
	Nastavuje odsazení na ose Y

	@param offsetY odsazení
	*/
	static void setOffsetY(int offsetY);
	/**
	@return odsazení na ose Y
	*/
	static int getOffsetY();
};

#endif // !CAMERA
