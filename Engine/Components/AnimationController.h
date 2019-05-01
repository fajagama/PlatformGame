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
	Pøidá animaci do kolekce

	@param name jméno animace
	@param animation komponenta s nastavenou animací
	*/
	void add(string name, Animation & animation);
	/**
	Odstranìní animace z kolekce

	@param name název animace v kolekci
	*/
	void remove(string name);
	/**
	Pøehrání animace z kolekce

	@param name název animace v kolekci
	*/
	void play(string name);

	void resetRender() override;
	void update() override;
	void render(SDL_Renderer * renderer) override;
	AnimationController * clone() override;
};

#endif // !TESTCOM
