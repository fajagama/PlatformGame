#include "BtnBack.h"

#include "Core.h"

void BtnBack::onMouseClick()
{
	Core::loadLevel("main_menu");
}

BtnBack * BtnBack::clone()
{
	return new BtnBack(*this);
}
