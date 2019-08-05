#ifndef SOUND_EFFECT
#define SOUND_EFFECT

#include <SDL_mixer.h>
#include <string>

using namespace std;

class SoundEffect {
private:
	int channel = -20;
	Mix_Chunk * sound;
	string fileWithPath;
	SoundEffect();
public:
	SoundEffect(const SoundEffect & soundEffect);
	/**
	@param fileWithPath cesta k souboru se zvukovým efektem
	*/
	SoundEffect(string fileWithPath);
	~SoundEffect();
	/**
	Pøehraje zvukový efekt
	*/
	void play();
	/**
	Pustí pozastavený zvukový efekt
	*/
	void resume();
	/**
	Pozastavý pøehrávaný zvukový efekt
	*/
	void pause();
	/**
	Zastavý pøehrávaný zvukový efekt
	*/
	void stop();
};

#endif // !TESTCOM
