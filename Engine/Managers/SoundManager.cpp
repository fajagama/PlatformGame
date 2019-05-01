#include "SoundManager.h"
#include "ErrorLogging.h"

Mix_Music * SoundManager::music = nullptr;
int SoundManager::musicVolume = 100;
int SoundManager::soundEffectVolume = 100;

void SoundManager::setMusicVolume(int volume)
{
	if (volume > 100) {
		musicVolume = 100;
	}
	else {
		if (0 > volume) {
			musicVolume = 0;
		}
		else {
			musicVolume = volume;
		}
	}
	int newVolume = ((float)musicVolume / 100.0) * 128.0;
	Mix_VolumeMusic(newVolume);
}

int SoundManager::getMusicVolume()
{
	return musicVolume;
}

void SoundManager::setSoundEffectVolume(int volume)
{
	if (volume > 100) {
		soundEffectVolume = 100;
	}
	else {
		if (0 > volume) {
			soundEffectVolume = 0;
		}
		else {
			soundEffectVolume = volume;
		}
	}
	int newVolume = ((float)soundEffectVolume / 100.0) * 128.0;
	Mix_Volume(-1, newVolume);
}

int SoundManager::getSoundEffectVolume()
{
	return soundEffectVolume;
}

void SoundManager::playMusic(std::string fileWithPath)
{
	if (music != nullptr) {
		Mix_FreeMusic(music);
	}
	music = Mix_LoadMUS(fileWithPath.c_str());
	if (music == nullptr) {
		ErrorLogging::addLog("Failed to load music! SDL_mixer Error:", Mix_GetError());
	}
	Mix_PlayMusic(music, 0);
}

void SoundManager::pauseMusic()
{
	Mix_PauseMusic();
}

void SoundManager::resumeMusic()
{
	Mix_ResumeMusic();
}
