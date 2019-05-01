#include "Settings.h"

#include "Core.h"
#include <string>

void Settings::onMouseClick()
{
	Core::loadLevel("settings");
}

Settings * Settings::clone()
{
	return new Settings(*this);
}
