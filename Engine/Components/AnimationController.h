#ifndef	ANIMATION_CONTROLLER
#define ANIMATION_CONTROLLER

#include <string>
#include <map>
#include "Animation.h"
#include "Component.h"

using namespace std;

class AnimationController : public Component {
private:
	map<string, Animation *> animations;
	string currentAnimation = "";

public:
	AnimationController(const AnimationController & com);
	AnimationController();
	~AnimationController();
	/**
	P�id� animaci do kolekce

	@param name jm�no animace
	@param animation komponenta s nastavenou animac�
	*/
	void add(string name, Animation & animation);
	/**
	Odstran�n� animace z kolekce

	@param name n�zev animace v kolekci
	*/
	void remove(string name);
	/**
	P�ehr�n� animace z kolekce

	@param name n�zev animace v kolekci
	*/
	void play(string name);

	void resetRender() override;
	void update() override;
	void render(SDL_Renderer * renderer) override;
	AnimationController * clone() override;
};

#endif // !TESTCOM
