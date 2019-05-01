#ifndef LEVEL
#define LEVEL

#include <string>
#include <list>
#include "GameObject.h"

using namespace std;

class Level {
private:
	string name;
	list<GameObject *> gameObjects;
	GameObject * goCameraFollow = nullptr;

	Level();
public:
	Level(const Level & level);
	/**
	@param name jm�no �rovn�
	*/
	Level(string name);
	~Level();
	/**
	P�id�v� hern� objekt do kolekce

	@param go hern� objekt
	@return aktu�ln� �rove�
	*/
	Level & addGameObject(GameObject & go);
	/**
	Odstracn� hern� objekt do kolekce

	@param name nazev hern�ho objektu
	*/
	bool removeGameObject(string name);
	/**
	Hern� objekt, kter� bude kamera sledovat

	@param name nazev hern�ho objektu
	*/
	void cameraFollow(string name);
	/**
	Nastaven� �rovn� po na�ten�
	*/
	void onLoad();
	/**
	@return seznam hern�ch objekt� �rovn�
	*/
	list<GameObject *> & getGameObjects();
	/**
	@return jm�no �rovn�
	*/
	string getName();
};

#endif // !LEVEL
