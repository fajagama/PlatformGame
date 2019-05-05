#include "AnimationController.h"

#include <algorithm>

AnimationController::AnimationController(const AnimationController & com)
{
	currentAnimation = com.currentAnimation;

	for (auto animation : com.animations) {
		add(animation.first, *animation.second);
	}
}

AnimationController::AnimationController()
{
}

AnimationController::~AnimationController()
{
	for (auto animation : animations) {
		delete animation.second;
	}
	animations.clear();
}

void AnimationController::add(string name, Animation & animation)
{
	this->animations[name] = new Animation(animation);
	this->currentAnimation = name;
}

void AnimationController::remove(string name)
{
	this->animations.erase(name);
}

void AnimationController::play(string name)
{
	this->currentAnimation = name;
}

void AnimationController::resetRender()
{
	animations[currentAnimation]->resetRender();
	for_each(animations.begin(), animations.end(), [](pair<string, Animation *> element) { element.second->resetRender(); });
}

void AnimationController::update()
{
	animations[currentAnimation]->setGameObject(getGameObject());
	animations[currentAnimation]->update();
}

void AnimationController::render(SDL_Renderer * renderer)
{
	animations[currentAnimation]->setGameObject(getGameObject());
	animations[currentAnimation]->render(renderer);
}

AnimationController * AnimationController::clone()
{
	return new AnimationController(*this);
}
