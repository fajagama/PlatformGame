#include "Resolution1360.h"

#include "WindowManager.h"
#include "Core.h"

void Resolution1360::onMouseClick()
{
	WindowManager::setWidth(1360);
	WindowManager::setHeight(768);
	Core::reloadWindow();
}

Resolution1360 * Resolution1360::clone()
{
	return new Resolution1360(*this);
}
