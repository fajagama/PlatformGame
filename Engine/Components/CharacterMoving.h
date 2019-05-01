#ifndef CHARACTER_MOVING
#define CHARACTER_MOVING

#include "Component.h"
#include "GameObject.h"

class CharacterMoving : public Component
{
private:
	unsigned int walkSpeed = 10;
	unsigned int jumpSpeed = 10;
	bool jump = false;
public:
	CharacterMoving(const CharacterMoving & com);
	/**
    @param walkSpeed rychlost chùze
    @param jumpSpeed rychlost výskoku
	*/
	CharacterMoving(unsigned int walkSpeed, unsigned int jumpSpeed);
	/**
	Nastavení vlastnosti

	@param walkSpeed rychlost chùze
	*/
	void setWalkSpeed(int walkSpeed);
	/**
	@return hodnota vlastnosti s informací o rychlosti chùze
	*/
	unsigned int getWalkSpeed();
	/**
	Nastavení vlastnosti

	@param jumpSpeed rychlost výskoku
	*/
	void setJumpSpeed(int jumpSpeed);
	/**
	@return hodnota vlastnosti s informací o rychlosti výskoku
	*/
	unsigned int getJumpSpeed();
	/**
	@return informace zdali je charakter stále ve vzduchu
	*/
	bool isJumping();
	/**
	Charakter udìlá krok vpravo
	*/
	void moveRight();
	/**
    Charakter udìlá kror vlevo
	*/
	void moveLeft();
	/**
	Charakter vyskoèí
	*/
	void doJump();
	
	virtual void update() override;
	CharacterMoving * clone() override;
};

#endif // !CHARACTERMOVING

