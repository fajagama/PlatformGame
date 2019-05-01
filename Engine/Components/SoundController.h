#ifndef SOUND_CONTROLLER
#define SOUND_CONTROLLER

#include <string>
#include <map>
#include <memory>

#include "Component.h"
#include "SoundEffect.h"

using namespace std;

class SoundController : public Component {
private:
	map<string, unique_ptr<SoundEffect>> sounds;
public:
	SoundController(const SoundController & com);
	SoundController();
	/**
	Pøidá zvukový efekt do kolekce

	@param name názek zvuku
	@param fileWithPath cesta k souboru
	*/
	void add(string name, string fileWithPath);
	/**
	Odstraní zvuk z kolekce

	@param name názek zvuku
	*/
	void remove(string name);
	/**
	Pøehraje zvuk z kolekce

	@param name názek zvuku
	*/
	void play(string name);
	/**
	Pozastavý pøehrávaný zvuk 

	@param name názek zvuku
	*/
	void pause(string name);
	/**
	Pustí pozastavený zvuk

	@param name názek zvuku
	*/
	void resume(string name);
	/**
	Pøeruší pøehrávaný zvuk

	@param name názek zvuku
	*/
	void stop(string name);
	SoundController * clone() override;
};

#endif // !SOUND_CONTROLLER
