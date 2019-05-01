#include "LoadLevelOne.h"

#include "Core.h"

void LoadLevelOne::onMouseClick()
{
	Core::loadLevel("level_one");
}

LoadLevelOne * LoadLevelOne::clone()
{
	return new LoadLevelOne(*this);
}
