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
    @param walkSpeed rychlost ch�ze
    @param jumpSpeed rychlost v�skoku
	*/
	CharacterMoving(unsigned int walkSpeed, unsigned int jumpSpeed);
	/**
	Nastaven� vlastnosti

	@param walkSpeed rychlost ch�ze
	*/
	void setWalkSpeed(int walkSpeed);
	/**
	@return hodnota vlastnosti s informac� o rychlosti ch�ze
	*/
	unsigned int getWalkSpeed();
	/**
	Nastaven� vlastnosti

	@param jumpSpeed rychlost v�skoku
	*/
	void setJumpSpeed(int jumpSpeed);
	/**
	@return hodnota vlastnosti s informac� o rychlosti v�skoku
	*/
	unsigned int getJumpSpeed();
	/**
	@return informace zdali je charakter st�le ve vzduchu
	*/
	bool isJumping();
	/**
	Charakter ud�l� krok vpravo
	*/
	void moveRight();
	/**
    Charakter ud�l� kror vlevo
	*/
	void moveLeft();
	/**
	Charakter vysko��
	*/
	void doJump();
	
	virtual void update() override;
	CharacterMoving * clone() override;
};

#endif // !CHARACTERMOVING

