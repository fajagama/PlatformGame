#ifndef COLLIDERCOMPONENT
#define COLLIDERCOMPONENT

#include "Component.h"

class Collider : public Component
{
private:
	bool trigger = false;
	int width;
	int height;
	int offsetX = 0;
	int offsetY = 0;

	Collider();
public:
	Collider(const Collider &com);
	/**
	@param width šíøka kolizního objektu
	@param height výška kolizního objektu
	*/
	Collider(int width, int height);
	/**
	U triggerù se nekontrolují aktivnì kolize, tìchto objektù

	@return informace zda je kolizní objekt trigger
	*/
	bool isTrigger();
	/**
	Nastavení vlastnosti.

	@param value true pokud se jedná o trigger
	*/
	void setTrigger(bool value);
	/**
	Nastavení vlastnosti

	@param width výška kolizního objektu
	*/
	void setHeight(int height);
	/**
	@return výška kolizního objektu
	*/
	int getHeight();
	/**
	Nastavení vlastnosti

	@param width šíøka kolizního objektu
	*/
	void setWidth(int width);
	/**
	@return šíøka kolizního objektu
	*/
	int getWidth();

	void onCollision(GameObject & go) override;
	Collider * clone() override;
};

#endif // !COLLIDERCOMPONENT

