#include "LevelMenu.h"

#include "TimeManager.h"
#include "KeyCode.h"
#include "Core.h"
#include "Input.h"

void LevelMenu::showMenu()
{
	Core::findGameObjectByName("pause")->setActive(true);
	TimeManager::setTimeScale(0.0);
	Core::findGameObjectByName("back")->setActive(true);
	Core::findGameObjectByName("resume")->setActive(true);
}

void LevelMenu::hideMenu()
{
	Core::findGameObjectByName("pause")->setActive(false);
	TimeManager::setTimeScale(1.0);
	Core::findGameObjectByName("back")->setActive(false);
	Core::findGameObjectByName("resume")->setActive(false);
}

void LevelMenu::update()
{
	if (Input::getKeyUp(KeyCode::ESC)) {
		showMenu();
	}
}

void LevelMenu::onMouseClick()
{
	hideMenu();
}

LevelMenu * LevelMenu::clone()
{
	return new LevelMenu(*this);
}
