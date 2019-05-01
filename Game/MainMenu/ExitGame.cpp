#include "ExitGame.h"

#include "Core.h"

void ExitGame::onMouseClick()
{
	Core::quit();
}

ExitGame * ExitGame::clone()
{
	return new ExitGame(*this);
}
