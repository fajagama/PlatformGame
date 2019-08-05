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
	@param fileWithPath cesta k souboru se zvukov�m efektem
	*/
	SoundEffect(string fileWithPath);
	~SoundEffect();
	/**
	P�ehraje zvukov� efekt
	*/
	void play();
	/**
	Pust� pozastaven� zvukov� efekt
	*/
	void resume();
	/**
	Pozastav� p�ehr�van� zvukov� efekt
	*/
	void pause();
	/**
	Zastav� p�ehr�van� zvukov� efekt
	*/
	void stop();
};

#endif // !TESTCOM
