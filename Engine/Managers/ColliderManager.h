#ifndef COLLIDER_MANAGER
#define COLLIDER_MANAGER

class GameObject;

#include <list>
#include <stdexcept>
#include "Position.h"

using namespace std;

class ColliderManager {
private:
	static bool checkPointCollision(GameObject & go, int pointX, int pointY);
	static bool checkPointCollision(int pointX, int pointX1, int pointX2, int pointY, int pointY1, int pointY2);
	static bool checkCollision(GameObject & go1, GameObject & go2);
	
	ColliderManager() {}
public:
	ColliderManager(ColliderManager const&) = delete;
	void operator=(ColliderManager const&) = delete;
	/**
	Kontroluje kolize mezi hern�mi objekty, v p��pad� kolize zavol� p��slu�nou metodu konkr�tn�ho hern�ho objektu

	@param go hern� objekt, u kter�ho se kontroluje kolize
	@param gameObjects hern� objekty v levelu
	*/
	static void checkCollision(GameObject & go, list<GameObject *> & gameObjects);
	/**
	Kontroluje kolize mezi hern�mi objekty a ur�it�m bodem, v p��pad� kolize zavol� p��slu�nou metodu konkr�tn�ho hern�ho objektu

	@param position pozice v prostoru
	@param gameObjects hern� objekty v levelu
	*/
	static void checkMouseClick(Position & position, list<GameObject *> & gameObjects);
};
#endif // !COLLIDER_MANAGER
