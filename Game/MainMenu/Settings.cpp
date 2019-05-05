#include "Settings.h"

#include "Core.h"
#include <string>
#include <sstream>
#include "SharedMemory.h"
#include "WindowManager.h"
#include "SoundManager.h"

void Settings::onMouseClick()
{
	Core::loadLevel("settings");
}

Settings * Settings::clone()
{
	return new Settings(*this);
}

void Settings::onLoad()
{
	string music = SharedMemory::getValue("music");
	if (music != "") {
		int volume;
		std::istringstream iss(music);
		iss >> volume;
		if (100 >= volume && volume >= 0) {
			SoundManager::setMusicVolume(volume);
		}
	}
	string effect = SharedMemory::getValue("effect");
	if (effect != "") {
		int volume;
		std::istringstream iss(effect);
		iss >> volume;
		if (100 >= volume && volume >= 0) {
			SoundManager::setSoundEffectVolume(volume);
		}
	}
	if (SharedMemory::getValue("1024") == "true" && WindowManager::getWidth() != 1024) {
		WindowManager::setWidth(1024);
		WindowManager::setHeight(768);
		Core::reloadWindow();
	}
	if (SharedMemory::getValue("1360") == "true" && WindowManager::getWidth() != 1360) {
		WindowManager::setWidth(1360);
		WindowManager::setHeight(768);
		Core::reloadWindow();
	}
	if (SharedMemory::getValue("1920") == "true" && WindowManager::getWidth() != 1920) {
		WindowManager::setWidth(1920);
		WindowManager::setHeight(1080);
		Core::reloadWindow();
	}
	if (SharedMemory::getValue("fullscreen") == "true" && !WindowManager::isFullscreen()) {
		WindowManager::setFullscreen(true);
		Core::reloadWindow();
	}
}
