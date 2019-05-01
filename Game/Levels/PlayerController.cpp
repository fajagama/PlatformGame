#include "PlayerController.h"
#include "GameObject.h"
#include "RenderImage.h"
#include "KeyCode.h"
#include "string";
#include "WindowManager.h";
#include "Core.h";
#include "SoundManager.h";
#include "SimpleGravity.h";
#include "AnimationController.h";
#include "CharacterMoving.h"
#include "Input.h"

using namespace std;

int PlayerController::getCounter()
{
	return counter;
}

void PlayerController::update()
{
	if (!this->getGameObject()->getComponent<SimpleGravity>()->isGrounded()) {
		this->getGameObject()->getComponent<AnimationController>()->play("jump");
	}
	else {
		this->getGameObject()->getComponent<AnimationController>()->play("stand");
	}
	if(Input::getKeyUp("a") || Input::getKeyUp("d")) {
		this->getGameObject()->getComponent<AnimationController>()->play("stand");
	}

	if (Input::getKeyDown("a")) {
		this->getGameObject()->getComponent<CharacterMoving>()->moveLeft();
		if (this->getGameObject()->getComponent<SimpleGravity>()->isGrounded())
			this->getGameObject()->getComponent<AnimationController>()->play("walk");
	}
	if (Input::getKeyDown("d")) {
		this->getGameObject()->getComponent<CharacterMoving>()->moveRight();
		if (this->getGameObject()->getComponent<SimpleGravity>()->isGrounded())
			this->getGameObject()->getComponent<AnimationController>()->play("walk");
	}
	if (Input::getKeyDown("w")) {
		if (!this->getGameObject()->getComponent<CharacterMoving>()->isJumping())
			this->getGameObject()->getComponent<SoundController>()->play("jump");
		
		this->getGameObject()->getComponent<CharacterMoving>()->doJump();
	}
}

void PlayerController::onCollision(GameObject & go)
{
	if (go.getTag() == "coin") {
		Core::removeGameObject(go);
		this->getGameObject()->getComponent<SoundController>()->play("coin");
		counter++;
		switch (counter)
		{
		case 1:
			Core::findGameObjectByName("score")->getComponent<RenderImage>()->setImage("assets/score-1.png");
			break;
		case 2:
			Core::findGameObjectByName("score")->getComponent<RenderImage>()->setImage("assets/score-2.png");
			break;
		case 3:
			Core::findGameObjectByName("score")->getComponent<RenderImage>()->setImage("assets/score-3.png");
			break;
		}
	}
}

void PlayerController::onLoad()
{
	counter = 0;
}

PlayerController * PlayerController::clone()
{
	return new PlayerController(*this);
}
