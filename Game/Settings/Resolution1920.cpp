#include "Resolution1920.h"

#include "WindowManager.h"
#include "Core.h"
#include "SharedMemory.h"

void Resolution1920::onMouseClick()
{
	WindowManager::setWidth(1920);
	WindowManager::setHeight(1080);

	SharedMemory::setValue("1024", "false");
	SharedMemory::setValue("1360", "false");
	SharedMemory::setValue("1920", "true");

	Core::reloadWindow();
}

Resolution1920 * Resolution1920::clone()
{
	return new Resolution1920(*this);
}
