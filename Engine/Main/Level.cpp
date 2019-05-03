#include "Level.h"

#include "Camera.h"

#include <sstream>
#include <string>
#include <algorithm>

Level::Level(const Level & level)
{
	name = level.name;
	string cameraName = level.goCameraFollow->getName();
	gameObjects.clear();
	for (auto go : level.gameObjects) {
		gameObjects.push_back(new GameObject(*go));
	}
	list<GameObject *>::iterator it = find_if(gameObjects.begin(), gameObjects.end(), [cameraName](GameObject * item) { return item->getName() == cameraName; });
	goCameraFollow = *it;
}

Level::Level(string name)
{
	this->name = name;
	this->gameObjects = list<GameObject *>();
}

Level::~Level()
{
	if (gameObjects.size() > 0) {
		for (GameObject * go : gameObjects)
		{
			delete go;
		}
	}
	gameObjects.clear();
}

Level & Level::addGameObject(GameObject & go)
{
	GameObject * newGo = new GameObject(go);
	if (newGo->getName() == "") {
		stringstream stringStream;
		stringStream << "GameObject (" << gameObjects.size() << ")";
		newGo->setName(stringStream.str());
	}
	bool nameExist = (find_if(gameObjects.begin(), gameObjects.end(), [newGo](GameObject * item) { return item->getName() == newGo->getName(); }) != gameObjects.end());
	if (nameExist) {
		stringstream stringStream;
		stringStream << newGo->getName() << " (" << gameObjects.size() << ")";
		newGo->setName(stringStream.str());		
	}
	list<GameObject *>::iterator it = find_if(gameObjects.begin(), gameObjects.end(), [newGo](GameObject * item) { return item->getZIndex() > newGo->getZIndex(); });
	gameObjects.insert(it, newGo);
	return *this;
}

bool Level::removeGameObject(string name)
{
	list<GameObject *>::iterator it = find_if(gameObjects.begin(), gameObjects.end(), [name](GameObject * item) { return item->getName() == name; });
	if (it != gameObjects.end()) {
		gameObjects.remove(*it);
		return true;
	}
	return false;
}

void Level::cameraFollow(string name)
{
	list<GameObject *>::iterator it = find_if(gameObjects.begin(), gameObjects.end(), [name](GameObject * item) { return item->getName() == name; });
	goCameraFollow = *it;
}

void Level::onLoad()
{
	Camera::followGameObject(goCameraFollow);
}

list<GameObject*> & Level::getGameObjects()
{
	return gameObjects;
}

string Level::getName()
{
	return name;
}
