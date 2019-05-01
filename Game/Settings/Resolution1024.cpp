#include "Resolution1024.h"

#include "WindowManager.h"
#include "Core.h"

void Resolution1024::onMouseClick()
{
	WindowManager::setWidth(1024);
	WindowManager::setHeight(768);
	Core::reloadWindow();
}

Resolution1024 * Resolution1024::clone()
{
	return new Resolution1024(*this);
}
