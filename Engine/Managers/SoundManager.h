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
	Nastav� hlasitost hudby

	@param volume hlasitost v procentech
	*/
	static void setMusicVolume(int volume);
	/**
	@return Hlastost hudby v procentech
	*/
	static int getMusicVolume();
	/**
	Nastav� hlasitost zvukov�ch efekt�

	@param volume hlasitost v procentech
	*/
	static void setSoundEffectVolume(int volume);
	/**
	@return Hlastost zvukov�ch efekt� v procentech
	*/
	static int getSoundEffectVolume();
	/**
	Pust� hudbu

	@param fileWithPath cesta k souboru
	*/
	static void playMusic(std::string fileWithPath);
	/**
	Pozastav� p�ehr�vanou hudbu
	*/
	static void pauseMusic();
	/**
	Pust� pozastavenou hudbu
	*/
	static void resumeMusic();
};
#endif // !COLLIDER_MANAGER
