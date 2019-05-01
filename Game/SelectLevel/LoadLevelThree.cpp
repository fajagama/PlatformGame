#include "LoadLevelThree.h"

#include "Core.h"

void LoadLevelThree::onMouseClick()
{
	Core::loadLevel("level_three");
}

LoadLevelThree * LoadLevelThree::clone()
{
	return new LoadLevelThree(*this);
}
