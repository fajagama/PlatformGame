#include "Core.h"
#include "Component.h"
#include "TimeManager.h"
#include "ErrorLogging.h"
#include "DebugLogging.h"
#include "Input.h"
#include "WindowManager.h"
#include "Rect.h"

#include <algorithm>
#include <SDL_mixer.h>

#include <iostream>
#include <memory>

list<GameObject *> Core::gameObjectsToRemove;
bool Core::reload = false;
map<string, Level*> Core::levels;
Level * Core::currentLevel = nullptr;
string Core::levelName;
bool Core::running = false;

void Core::handleEvents()
{
	Input::reset();
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			running = false;
			break;
		default:
			break;
		}

		if (event.type == SDL_KEYDOWN) {
			Input::setKeyDown(event.key.keysym.sym);
		}
		if (event.type == SDL_KEYUP) {
			Input::setKeyUp(event.key.keysym.sym);
		}
		if (event.type == SDL_MOUSEBUTTONDOWN) {
			Input::setMouseKeyDown(event.button.button);
		}
		if (event.type == SDL_MOUSEBUTTONUP) {
			Input::setMouseKeyUp(event.button.button);
		}

		int mouseX, mouseY;
		SDL_GetMouseState(&mouseX, &mouseY);
		Input::setMousePosition(mouseX, mouseY);
		
		if (event.type == SDL_WINDOWEVENT) {
			switch (event.window.event) {
			case SDL_WINDOWEVENT_FOCUS_LOST:
				currentFPS = backgroundFPS;
				break;
			case SDL_WINDOWEVENT_FOCUS_GAINED:
				currentFPS = maxFPS;
				break;
			}
		}
	}
}

void Core::gameLoop()
{
	while (running) {
		if (currentLevel == nullptr || levelName != currentLevel->getName()) {
			if (currentLevel != nullptr) {
				delete currentLevel;
			}
			currentLevel = new Level(*levels[levelName]);
			currentLevel->onLoad();
			TimeManager::setTimeScale(1.0);
			for (GameObject * go : currentLevel->getGameObjects())
			{
				for (auto& com : go->getComponents()) 
				{
					com->onLoad();
					com->resetRender();
				}
				go->getPosition().setNewOldPosition();
			}
		}
		
		handleEvents();

		if (TimeManager::getDeltaTime() < (1000.0f / this->currentFPS))
		{
			SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
			SDL_RenderFillRect(this->renderer, &Rect::getRect(640, 480));
			
			for (GameObject * go :gameObjectsToRemove)
			{
				if (currentLevel->removeGameObject(go->getName())) {
					delete go;
				}
			}
			gameObjectsToRemove.clear();

			if (reload) {
				SDL_DestroyWindow(window);
				SDL_DestroyRenderer(renderer);
				initWindow();
				reload = false;
				for (GameObject * go : currentLevel->getGameObjects())
				{
					for (auto& com : go->getComponents())
					{
						com->resetRender();
					}
				}
			}
									
			for (GameObject * go : currentLevel->getGameObjects())
			{
				if (go->isActive()) {
					for (auto& com : go->getComponents())
					{
						com->update();
						if (go->getPosition().isPositionChanged()) {
							ColliderManager::checkCollision(*go, currentLevel->getGameObjects());
						}
						com->render(this->renderer);
					}
					go->getPosition().setNewOldPosition();
				}
			}

			for (GameObject * go : currentLevel->getGameObjects())
			{
				if (go->isActive()) {
					for (auto& com : go->getComponents())
					{
						com->render(this->renderer);
					}
				}
			}

			if (Input::isMouseClicked()) {
				ColliderManager::checkMouseClick(Input::getMousePosition(), currentLevel->getGameObjects());
			}

			SDL_RenderPresent(this->renderer);
			
			SDL_Delay((int)((900.0f / this->currentFPS) - TimeManager::getDeltaTime()));
		}
	}
}

void Core::init(string windowName)
{
	this->windowName = windowName;
	
	//Initialize SDL_mixer 
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
		ErrorLogging::addLog("SDL_mixer could not initialize! SDL_mixer Error:", Mix_GetError());
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		initWindow();
	}
	else {
		ErrorLogging::addLog("SDL initialization failed. SDL Error:", SDL_GetError());
		throw invalid_argument(SDL_GetError());
	}
	SharedMemory::loadValues();
}

void Core::initWindow()
{
	Uint32 flag;
	if (WindowManager::isFullscreen()) {
		flag = SDL_WINDOW_FULLSCREEN;
	}
	else {
		flag = SDL_WINDOW_SHOWN;
	}
	window = SDL_CreateWindow(windowName.c_str(), 50, 50, WindowManager::getWidth(), WindowManager::getHeight(), flag);
	DebugLogging::print("SDL initialization succeeded!");
	
	if (window != 0)
	{
		renderer = SDL_CreateRenderer(window, -1, 0);
		running = true;
	}
}

Core::Core(string windowName)
{
	init(windowName);
	currentFPS = maxFPS;
}

Core::~Core()
{
	if (currentLevel != nullptr) {
		delete currentLevel;
	}
	for (auto level : levels) {
		delete level.second;
	}
	levels.clear();
	gameObjectsToRemove.clear();

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}

void Core::run()
{
	gameLoop();
}

void Core::addLevel(Level & level)
{
	levels[level.getName()] = new Level(level);
}

void Core::loadLevel(string levelName)
{
	Core::levelName = levelName;
}

GameObject * Core::findGameObjectByName(string name)
{
	list<GameObject * >::iterator it = find_if(currentLevel->getGameObjects().begin(), currentLevel->getGameObjects().end(), [name](GameObject * go) {
		return go->getName() == name;
	});
	if (currentLevel->getGameObjects().end() != it) {
		return (*it);
	}
	else {
		return nullptr;
	}
}

void Core::removeGameObject(GameObject & go)
{
	go.setActive(false);
	gameObjectsToRemove.push_back(&go);
}

void Core::reloadWindow()
{
	reload = true;
}

void Core::quit()
{
	running = false;
}
