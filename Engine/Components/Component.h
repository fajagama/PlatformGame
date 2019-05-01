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
    Vrací herní objekt, který komponentu využívá

    @return GameObject
	*/
	GameObject * getGameObject();
public:
	virtual ~Component();
	/**
	Funkce nastavuje ukazatel na herní objekt, který vlastní danou komponentu

	@param ge ukazatel na herní objekt
	*/
	void setGameObject(GameObject * go);
	/**
	Funkce je voláda v rámci herní smyèky  
	*/
	virtual void update();
	/**
	Funkce je voláda v rámci herní smyèky
	Provádí vykreslování na plátno

	@param renderer platno, na které se kreslý
	*/
	virtual void render(SDL_Renderer * renderer);
	/**
	Provádí vymazání alokace grafických prvkù, které se následnì pøi dalším prùchodu alokují
	*/
	virtual void resetRender();
	/**
	Funkce je volána pøi kolizi s jiným herním objektem a kolizní komponenta má stav trigger

	@param go je herní objekt, se kterým došlo ke kolizi
	*/
	virtual void onTrigger(GameObject & go);
	/**
	Funkce je volána pøi kolizi s jiným herním objektem

	@param go je herní objekt, se kterým došlo ke kolizi
	*/
	virtual void onCollision(GameObject & go);
	/**
	Funkce je volána pøi kolizi místa, kde došlo ke kliknutí myší
	*/
	virtual void onMouseClick();
	/**
	Funkce je volána pøi naètení levelu a nastuve poèáteèní stav komponenty
	*/
	virtual void onLoad();
	/**
	@return vrátí kopii objektu
	*/
	virtual Component * clone() = 0;
};
#endif // !COMPONENT


