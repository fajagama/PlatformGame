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
	@param name jméno úrovnì
	*/
	Level(string name);
	~Level();
	/**
	Pøidává herní objekt do kolekce

	@param go herní objekt
	@return aktuální úroveò
	*/
	Level & addGameObject(GameObject & go);
	/**
	Odstracní herní objekt do kolekce

	@param name nazev herního objektu
	*/
	bool removeGameObject(string name);
	/**
	Herní objekt, který bude kamera sledovat

	@param name nazev herního objektu
	*/
	void cameraFollow(string name);
	/**
	Nastavení úrovnì po naètení
	*/
	void onLoad();
	/**
	@return seznam herních objektù úrovnì
	*/
	list<GameObject *> & getGameObjects();
	/**
	@return jméno úrovnì
	*/
	string getName();
};

#endif // !LEVEL
