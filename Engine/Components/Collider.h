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
	@param width ���ka kolizn�ho objektu
	@param height v��ka kolizn�ho objektu
	*/
	Collider(int width, int height);
	/**
	U trigger� se nekontroluj� aktivn� kolize, t�chto objekt�

	@return informace zda je kolizn� objekt trigger
	*/
	bool isTrigger();
	/**
	Nastaven� vlastnosti.

	@param value true pokud se jedn� o trigger
	*/
	void setTrigger(bool value);
	/**
	Nastaven� vlastnosti

	@param width v��ka kolizn�ho objektu
	*/
	void setHeight(int height);
	/**
	@return v��ka kolizn�ho objektu
	*/
	int getHeight();
	/**
	Nastaven� vlastnosti

	@param width ���ka kolizn�ho objektu
	*/
	void setWidth(int width);
	/**
	@return ���ka kolizn�ho objektu
	*/
	int getWidth();

	void onCollision(GameObject & go) override;
	Collider * clone() override;
};

#endif // !COLLIDERCOMPONENT

