#ifndef CORE
#define CORE

#include <SDL.h>

#include <map>
#include <list>
#include <string>
#include <stdexcept>

#include "Level.h"

#include "GameObject.h"

#include "SDL_image.h"
#include "SharedMemory.h"

#include "ColliderManager.h"

using namespace std;

class Level;

class Core {
private:
	SDL_Window * window;
	SDL_Renderer * renderer;
	static bool running;
	const int maxFPS = 90;
	const int backgroundFPS = 15;
	int currentFPS;
	string windowName;

	static map<string, Level*> levels;
	static string levelName;
	static Level * currentLevel;
		
	static list<GameObject *> gameObjectsToRemove;
	static bool reload;
		
	void handleEvents();
	void gameLoop();

	void init(string windowName);
	void initWindow();

	void loadFiles();
	void closeFiles();
public:
	/**
    @return windowName n�zev okna aplikace
	*/
	Core(string windowName);
	~Core();
	/**
	spust� hern� smy�ku
	*/
	void run();
	/**
	P�id� novou �rov�� hry do kolekce 

	@param level �rov�� hry
	*/
	void addLevel(Level & level);
	/**
	Na�te �rove� z kolekce

	@param levelName n�zev �rovn�
	*/
	static void loadLevel(string levelName);
	/**
	Najde hern� objekt podle n�zvu

	@param name n�zev hern�ho objektu
	@return vr�t� hledan� hern� objekt
	*/
	static GameObject * findGameObjectByName(string name);
	/**
	Odstran� hern� objekt z aktu�ln� �rovn�

	@param go hern� objekt
	*/
	static void removeGameObject(GameObject & go);
	/**
	Znovu na�te okno aplikace
	*/
	static void reloadWindow();
	/**
	Ukon�� hern� smy�ku a t�m celou aplikaci
	*/
	static void quit();
};

#endif // !CORE
