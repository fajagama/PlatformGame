#include "SoundEffectVolumeUp.h"

#include "SoundManager.h"
#include "SoundController.h"

void SoundEffectVolumeUp::onMouseClick()
{
	getGameObject()->getComponent<SoundController>()->stop("ding");
	SoundManager::setSoundEffectVolume(SoundManager::getSoundEffectVolume() + 10);
	getGameObject()->getComponent<SoundController>()->play("ding");
}

SoundEffectVolumeUp * SoundEffectVolumeUp::clone()
{
	return new SoundEffectVolumeUp(*this);
}
