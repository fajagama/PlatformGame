#ifndef SIMPLEGRAVITY
#define SIMPLEGRAVITY

#include "Component.h"
#include "GameObject.h"
#include "Collider.h"

class SimpleGravity : public Component
{
private:
	unsigned int weight = 1;
	unsigned int gravity = 5;

	float terminalVelocity = 50.0f;
	float fallSpeed = 0.0f;

	bool grounded = false;
public:
	SimpleGravity(const SimpleGravity & com);
	SimpleGravity();
	/**
	Nastavuje vlastnost

	@param weight váha objektu
	*/
	void setWeight(unsigned int weight);
	/**
	@return váha objektu
	*/
	int getWeight();
	/**
	Nastavuje vlastnost

	@param gravity gravitaèní síla
	*/
	void setGravity(unsigned int gravity);
	/**
	@return gravitaèní sila pùsobící na objekt
	*/
	int getGravity();
	/**
	@return pravda pokud se objekt dotýká zeme
	*/
	bool isGrounded();
	
	void update() override;
	void onCollision(GameObject & go) override;
	SimpleGravity * clone() override;
};

#endif // !SIMPLEGRAVITY

