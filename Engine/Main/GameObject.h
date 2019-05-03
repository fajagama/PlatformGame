#ifndef GAMEOBJECT
#define GAMEOBJECT

class Component;

#include <list>
#include <typeinfo>
#include <string>

#include "Component.h"
#include "Position.h"
#include "Rect.h"

using namespace std;

class GameObject 
{
private:
	Position position;
 	list<Component*> components;
	string name = "";
	string tag = "";
	int zIndex = 0;	
	unsigned int height;
	unsigned int width;
	bool active = true;
public:
	GameObject(const GameObject & go);
	GameObject(unsigned int width, unsigned int height);
	GameObject(string name, unsigned int width, unsigned int height);
	~GameObject();
	/**
	@return pozice v prostoru
	*/
	Position & getPosition();
	/**
	@param x pozice na ose X
	@param y pozice na ose Y
	*/
	void setPosition(int x, int y);
	/**
	@return seznam vlastnìných komponent
	*/
	list<Component*> & getComponents();
	/**
	Pøidání nové komponenty hernímu objektu

	@param com komponenta
	@return reference na herní objekt
	*/
	GameObject & addComponent(Component & com);
	/**
	@param name jméno herního objektu
	*/
	void setName(string name);
	/**
	@return jméno herního objektu
	*/
	string getName();
	/**
	@param tag štítek herního objektu
	*/
	void setTag(string tag);
	/**
	@return znaèka herního objektu
	*/
	string getTag();
	/**
	Volání funkcí v komponentách v pøípadì, že dojde ke kolizi a moje kolizní komponenta je typu trigger

	@param go herní objekt, se kterým došlo ke kolizi
	*/
	void callOnTrigger(GameObject & go);
	/**
	Volání funkcí v komponentách v pøípadì, že dojde ke kolizi

	@param go herní objekt, se kterým došlo ke kolizi
	*/
	void callOnCollision(GameObject & go);
	/**
	Volání funkcí v komponentách v pøípadì, že dojde ke kliknutí na herní objekt
	*/
	void callOnMouseClick();
	/**
	@param zIndex nastavení pozice na ose Z
	*/
	void setZIndex(int zIndex);
	/**
	@return pozice prvku na ose Z
	*/
	int getZIndex();
	/**
	@param width výška v pixelech
	*/
	void setHeight(unsigned int height);
	/**
	@return výška herního objektu
	*/
	unsigned int getHeight();
	/**
	@param width šíøka v pixelech
	*/
	void setWidth(unsigned int width);
	/**
	@return šíøka herního objektu
	*/
	unsigned int getWidth();
	/**
	@return jestli je herní objekt aktivní
	*/
	bool isActive();
	/**
	Nastavení vlastnosti

	@param active zdali je herní objekt aktivní
	*/
	void setActive(bool active);
	/**
	@return vrátí hledanou komponentu podle typu
	*/
	template<class Type>
	Type * getComponent() {	
		for (Component * com : this->components)
		{
			if (typeid(Type) == typeid(*com)) {
				return dynamic_cast<Type*>(com);
			}
		}			
		return nullptr;
	}
};

#endif // !GAMEOBJECT