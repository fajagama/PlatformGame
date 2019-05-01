#include "TimeManager.h"

#include <SDL.h>
#include <cstdint>
#include <time.h>  

float TimeManager::delta = 0.25f;
float TimeManager::timeScale = 1.0;

float TimeManager::getDeltaTime() {
	return delta * timeScale;
}

int unsigned TimeManager::getTime() {
	return SDL_GetTicks();
}

string TimeManager::getFullCurrentDateTime()
{
	time_t rawtime;
	time(&rawtime);

	return strtok(ctime(&rawtime), "\n");
}

void TimeManager::setTimeScale(float scale)
{
	timeScale = scale;
}

float TimeManager::getTimeScale()
{
	return timeScale;
}
