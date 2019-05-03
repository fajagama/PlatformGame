#include "Resolution1024.h"

#include "WindowManager.h"
#include "Core.h"
#include "SharedMemory.h"

void Resolution1024::onMouseClick()
{
	WindowManager::setWidth(1024);
	WindowManager::setHeight(768);

	SharedMemory::setValue("1024", "true");
	SharedMemory::setValue("1360", "false");
	SharedMemory::setValue("1920", "false");

	Core::reloadWindow();
}

Resolution1024 * Resolution1024::clone()
{
	return new Resolution1024(*this);
}
