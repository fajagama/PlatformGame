#ifndef SOUND_MANAGER
#define SOUND_MANAGER

#include <SDL_mixer.h>
#include <string>
#include <memory>

class SoundManager {
private:
	static Mix_Music * music;

	static int musicVolume;
	static int soundEffectVolume;
public:
	SoundManager() = delete;
	SoundManager(SoundManager const&) = delete;
	void operator=(SoundManager const&) = delete;
	/**
	Nastaví hlasitost hudby

	@param volume hlasitost v procentech
	*/
	static void setMusicVolume(int volume);
	/**
	@return Hlastost hudby v procentech
	*/
	static int getMusicVolume();
	/**
	Nastaví hlasitost zvukových efektù

	@param volume hlasitost v procentech
	*/
	static void setSoundEffectVolume(int volume);
	/**
	@return Hlastost zvukových efektù v procentech
	*/
	static int getSoundEffectVolume();
	/**
	Pustí hudbu

	@param fileWithPath cesta k souboru
	*/
	static void playMusic(std::string fileWithPath);
	/**
	Pozastaví pøehrávanou hudbu
	*/
	static void pauseMusic();
	/**
	Pustí pozastavenou hudbu
	*/
	static void resumeMusic();
};
#endif // !COLLIDER_MANAGER
