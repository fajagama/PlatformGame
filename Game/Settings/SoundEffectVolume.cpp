#include "SoundEffectVolume.h"

#include "RenderImage.h"
#include "SoundManager.h"

void SoundEffectVolume::update()
{
	if (volume != SoundManager::getSoundEffectVolume()) {
		volume = SoundManager::getSoundEffectVolume();

		switch (volume)
		{
		case 0:
			getGameObject()->getComponent<RenderImage>()->setImage("assets/0.png");
			break;
		case 10:
			getGameObject()->getComponent<RenderImage>()->setImage("assets/10.png");
			break;
		case 20:
			getGameObject()->getComponent<RenderImage>()->setImage("assets/20.png");
			break;
		case 30:
			getGameObject()->getComponent<RenderImage>()->setImage("assets/30.png");
			break;
		case 40:
			getGameObject()->getComponent<RenderImage>()->setImage("assets/40.png");
			break;
		case 50:
			getGameObject()->getComponent<RenderImage>()->setImage("assets/50.png");
			break;
		case 60:
			getGameObject()->getComponent<RenderImage>()->setImage("assets/60.png");
			break;
		case 70:
			getGameObject()->getComponent<RenderImage>()->setImage("assets/70.png");
			break;
		case 80:
			getGameObject()->getComponent<RenderImage>()->setImage("assets/80.png");
			break;
		case 90:
			getGameObject()->getComponent<RenderImage>()->setImage("assets/90.png");
			break;
		case 100:
			getGameObject()->getComponent<RenderImage>()->setImage("assets/100.png");
			break;
		default:
			getGameObject()->getComponent<RenderImage>()->setImage("assets/0.png");
			break;
		}
	}
}

SoundEffectVolume * SoundEffectVolume::clone()
{
	return new SoundEffectVolume(*this);
}
