#include "MusicVolumeUp.h"

#include "SoundManager.h"

void MusicVolumeUp::onMouseClick()
{
	SoundManager::setMusicVolume(SoundManager::getMusicVolume() + 10);
	SoundManager::playMusic("assets/ding.wav");
}

MusicVolumeUp * MusicVolumeUp::clone()
{
	return new MusicVolumeUp(*this);
}
