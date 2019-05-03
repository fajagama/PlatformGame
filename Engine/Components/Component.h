#ifndef COMPONENT
#define COMPONENT

class GameObject;

#include <SDL_image.h>

#include "GameObject.h"

class Component
{
private:
	GameObject * go = nullptr;
protected:
	/**
    Vrac� hern� objekt, kter� komponentu vyu��v�

    @return GameObject
	*/
	GameObject * getGameObject();
public:
	virtual ~Component();
	/**
	Funkce nastavuje ukazatel na hern� objekt, kter� vlastn� danou komponentu

	@param go ukazatel na hern� objekt
	*/
	void setGameObject(GameObject * go);
	/**
	Funkce je vol�na v r�mci hern� smy�ky  
	*/
	virtual void update();
	/**
	Funkce je vol�na v r�mci hern� smy�ky
	Prov�d� vykreslov�n� na pl�tno

	@param renderer pl�tno, na kter� se kresl�
	*/
	virtual void render(SDL_Renderer * renderer);
	/**
	Prov�d� vymaz�n� alokace grafick�ch prvk�, kter� se n�sledn� p�i dal��m vol�n� funkce render alokuj�
	*/
	virtual void resetRender();
	/**
	Funkce je vol�na p�i kolizi s jin�m hern�m objektem a kolizn� komponenta m� stav trigger

	@param go je hern� objekt, se kter�m do�lo ke kolizi
	*/
	virtual void onTrigger(GameObject & go);
	/**
	Funkce je vol�na p�i kolizi s jin�m hern�m objektem

	@param go je hern� objekt, se kter�m do�lo ke kolizi
	*/
	virtual void onCollision(GameObject & go);
	/**
	Funkce je vol�na p�i kolizi m�sta, kde do�lo ke kliknut� my��
	*/
	virtual void onMouseClick();
	/**
	Funkce je vol�na p�i na�ten� levelu a nastav� po��te�n� stav komponenty
	*/
	virtual void onLoad();
	/**
	@return vr�t� kopii objektu
	*/
	virtual Component * clone() = 0;
};
#endif // !COMPONENT


