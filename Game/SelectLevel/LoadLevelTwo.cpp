#include "LoadLevelTwo.h"

#include "Core.h"

void LoadLevelTwo::onMouseClick()
{
	Core::loadLevel("level_two");
}

LoadLevelTwo * LoadLevelTwo::clone()
{
	return new LoadLevelTwo(*this);
}
