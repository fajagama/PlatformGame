#include "SelectLevel.h"

#include "Core.h"

void SelectLevel::onMouseClick()
{
	Core::loadLevel("select_level");
}

SelectLevel * SelectLevel::clone()
{
	return new SelectLevel(*this);
}
