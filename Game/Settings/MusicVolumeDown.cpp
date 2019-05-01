#include "MusicVolumeDown.h"

#include "SoundManager.h"

void MusicVolumeDown::onMouseClick()
{
	SoundManager::setMusicVolume(SoundManager::getMusicVolume() - 10);
	SoundManager::playMusic("assets/ding.wav");
}

MusicVolumeDown * MusicVolumeDown::clone()
{
	return new MusicVolumeDown(*this);
}
