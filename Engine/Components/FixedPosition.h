#ifndef FIXED_POSITION
#define FIXED_POSITION

#include "Component.h"


/**
V��et hodnot s mo�nosty um�st�n� v prostoru
*/
enum class Spot { TOP_RIGHT, TOP_LEFT, BOTTOM_RIGHT, BOTTOM_LEFT, CENTER };

class FixedPosition : public Component
{
public:
	FixedPosition(const FixedPosition & com);
	/**
	@param Spot pozice v prostoru, kde se bude objekt nach�zet
	*/
	FixedPosition(Spot position);
	/**
	Nastaven� odaszen� od nasteven� pozice v ose X

	@param offset v pixelech
	*/
	void setOffsetX(int offset);
	/**
	Nastaven� odaszen� od nasteven� pozice v ose Y

	@param offset v pixelech
	*/
	void setOffsetY(int offset);

	virtual void update() override;
	FixedPosition * clone() override;
private:
	Spot position;
	int offsetX = 0;
	int offsetY = 0;
};

#endif // !CHARACTERMOVING

