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
	P�id� zvukov� efekt do kolekce

	@param name n�zek zvuku
	@param fileWithPath cesta k souboru
	*/
	void add(string name, string fileWithPath);
	/**
	Odstran� zvuk z kolekce

	@param name n�zek zvuku
	*/
	void remove(string name);
	/**
	P�ehraje zvuk z kolekce

	@param name n�zek zvuku
	*/
	void play(string name);
	/**
	Pozastav� p�ehr�van� zvuk 

	@param name n�zek zvuku
	*/
	void pause(string name);
	/**
	Pust� pozastaven� zvuk

	@param name n�zek zvuku
	*/
	void resume(string name);
	/**
	P�eru�� p�ehr�van� zvuk

	@param name n�zek zvuku
	*/
	void stop(string name);
	SoundController * clone() override;
};

#endif // !SOUND_CONTROLLER
