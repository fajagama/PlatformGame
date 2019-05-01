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
    @return windowName název okna aplikace
	*/
	Core(string windowName);
	~Core();
	/**
	spustí herní smyèku
	*/
	void run();
	/**
	Pøidá novou úrovìò hry do kolekce 

	@param level úrovìò hry
	*/
	void addLevel(Level & level);
	/**
	Naète úroveò z kolekce

	@param levelName název úrovnì
	*/
	static void loadLevel(string levelName);
	/**
	Najde herní objekt podle názvu

	@param name název herního objektu
	@return vrátí hledaný herní objekt
	*/
	static GameObject * findGameObjectByName(string name);
	/**
	Odstraní herní objekt z aktuální úrovnì

	@param go herní objekt
	*/
	static void removeGameObject(GameObject & go);
	/**
	Znovu naète okno aplikace
	*/
	static void reloadWindow();
	/**
	Ukonèí herní smyèku a tím celou aplikaci
	*/
	static void quit();
};

#endif // !CORE
