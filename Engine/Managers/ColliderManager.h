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
	Kontroluje kolize mezi herními objekty, v pøípadì kolize zavolá pøíslušnou metodu konkrétního herního objektu

	@param go herní objekt, u kterého se kontroluje kolize
	@param gameObjects herní objekty v levelu
	*/
	static void checkCollision(GameObject & go, list<GameObject *> & gameObjects);
	/**
	Kontroluje kolize mezi herními objekty a urèitým bodem, v pøípadì kolize zavolá pøíslušnou metodu konkrétního herního objektu

	@param position pozice v prostoru
	@param gameObjects herní objekty v levelu
	*/
	static void checkMouseClick(Position & position, list<GameObject *> & gameObjects);
};
#endif // !COLLIDER_MANAGER
