#include "CharacterMoving.h"

#include "SimpleGravity.h"
#include "TimeManager.h"

CharacterMoving::CharacterMoving(const CharacterMoving & com)
{
	walkSpeed = com.walkSpeed;
	jumpSpeed = com.jumpSpeed;
	jump = com.jump;
}

CharacterMoving::CharacterMoving(unsigned int walkSpeed, unsigned int jumpSpeed)
{
	this->walkSpeed = walkSpeed;
	this->jumpSpeed = jumpSpeed;
}

void CharacterMoving::setWalkSpeed(int walkSpeed)
{
	this->walkSpeed = walkSpeed;
}

unsigned int CharacterMoving::getWalkSpeed()
{
	return walkSpeed;
}

void CharacterMoving::setJumpSpeed(int jumpSpeed)
{
	this->jumpSpeed = jumpSpeed;
}

unsigned int CharacterMoving::getJumpSpeed()
{
	return jumpSpeed;
}

bool CharacterMoving::isJumping()
{
	return jump;
}

void CharacterMoving::moveRight()
{
	int poxX = getGameObject()->getPosition().getPosX();
	int move = (walkSpeed * TimeManager::getDeltaTime());
	getGameObject()->getPosition().setPosX(poxX + move);
}

void CharacterMoving::moveLeft()
{
	int poxX = getGameObject()->getPosition().getPosX();
	int move = (walkSpeed * TimeManager::getDeltaTime());
	getGameObject()->getPosition().setPosX(poxX - move);
}

void CharacterMoving::doJump()
{
	if (!jump) {
		jump = true;
	}
}

void CharacterMoving::update()
{
	if (jump) {
		int posY = getGameObject()->getPosition().getPosY();
		int move = (jumpSpeed * TimeManager::getDeltaTime());
		getGameObject()->getPosition().setPosY(posY - move);
	}
	if (getGameObject()->getComponent<SimpleGravity>()->isGrounded()) {
		jump = false;
	}
}

CharacterMoving * CharacterMoving::clone()
{
	return new CharacterMoving(*this);
}
