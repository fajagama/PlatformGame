#include "SoundEffect.h"
#include "ErrorLogging.h"

SoundEffect::SoundEffect(const SoundEffect & soundEffect)
{
	sound = Mix_LoadWAV(soundEffect.fileWithPath.c_str());
	fileWithPath = soundEffect.fileWithPath;
	channel = soundEffect.channel;
}

SoundEffect::SoundEffect(string fileWithPath)
{
	this->fileWithPath = fileWithPath;
	sound = Mix_LoadWAV(fileWithPath.c_str()); 
	if (sound == nullptr) { 
		ErrorLogging::addLog("Failed to load sound effect! SDL_mixer Error:", Mix_GetError());
		ErrorLogging::showErrorMsg("File not found!", "Game cannot load file! ", fileWithPath);
	}
}

SoundEffect::~SoundEffect()
{
	Mix_FreeChunk(sound);
}

void SoundEffect::play()
{
	if (!Mix_Playing(channel) || channel == -20) {
		channel = Mix_PlayChannel(-1, sound, 0);
		if (channel == -1) {
			ErrorLogging::addLog("Mix_PlayChannel error:", Mix_GetError());
		}
	}
}

void SoundEffect::resume()
{
	if (channel != -20) {
		Mix_Resume(channel);
	}
}

void SoundEffect::pause()
{
	if (channel != -20) {
		Mix_Pause(channel);
	}
}

void SoundEffect::stop()
{
	if (channel != -20) {
		Mix_HaltChannel(channel);
	}
}
