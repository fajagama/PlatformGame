#include "Resolution1360.h"

#include "WindowManager.h"
#include "Core.h"
#include "SharedMemory.h"

void Resolution1360::onMouseClick()
{
	WindowManager::setWidth(1360);
	WindowManager::setHeight(768);

	SharedMemory::setValue("1024", "false");
	SharedMemory::setValue("1360", "true");
	SharedMemory::setValue("1920", "false");

	Core::reloadWindow();
}

Resolution1360 * Resolution1360::clone()
{
	return new Resolution1360(*this);
}
