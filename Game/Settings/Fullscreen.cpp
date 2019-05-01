#include "Fullscreen.h"

#include "WindowManager.h"
#include "RenderImage.h"
#include "Core.h"

void Fullscreen::update()
{
	if (WindowManager::isFullscreen() != fullscreen) {
		fullscreen = WindowManager::isFullscreen();
		if (fullscreen) {
			getGameObject()->getComponent<RenderImage>()->setImage("assets/checked.png");
		}
		else {
			getGameObject()->getComponent<RenderImage>()->setImage("assets/empty.png");
		}
	}
}

void Fullscreen::onMouseClick()
{
	WindowManager::setFullscreen(!fullscreen);
	Core::reloadWindow();
}

Fullscreen * Fullscreen::clone()
{
	return new Fullscreen(*this);
}
