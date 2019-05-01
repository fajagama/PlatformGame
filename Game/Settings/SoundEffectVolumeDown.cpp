#include "SoundEffectVolumeDown.h"

#include "SoundManager.h"
#include "SoundController.h"

void SoundEffectVolumeDown::onMouseClick()
{
	getGameObject()->getComponent<SoundController>()->stop("ding");
	SoundManager::setSoundEffectVolume(SoundManager::getSoundEffectVolume() - 10);
	getGameObject()->getComponent<SoundController>()->play("ding");
}

SoundEffectVolumeDown * SoundEffectVolumeDown::clone()
{
	return new SoundEffectVolumeDown(*this);
}
