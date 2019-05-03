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
	@return seznam vlastn�n�ch komponent
	*/
	list<Component*> & getComponents();
	/**
	P�id�n� nov� komponenty hern�mu objektu

	@param com komponenta
	@return reference na hern� objekt
	*/
	GameObject & addComponent(Component & com);
	/**
	@param name jm�no hern�ho objektu
	*/
	void setName(string name);
	/**
	@return jm�no hern�ho objektu
	*/
	string getName();
	/**
	@param tag �t�tek hern�ho objektu
	*/
	void setTag(string tag);
	/**
	@return zna�ka hern�ho objektu
	*/
	string getTag();
	/**
	Vol�n� funkc� v komponent�ch v p��pad�, �e dojde ke kolizi a moje kolizn� komponenta je typu trigger

	@param go hern� objekt, se kter�m do�lo ke kolizi
	*/
	void callOnTrigger(GameObject & go);
	/**
	Vol�n� funkc� v komponent�ch v p��pad�, �e dojde ke kolizi

	@param go hern� objekt, se kter�m do�lo ke kolizi
	*/
	void callOnCollision(GameObject & go);
	/**
	Vol�n� funkc� v komponent�ch v p��pad�, �e dojde ke kliknut� na hern� objekt
	*/
	void callOnMouseClick();
	/**
	@param zIndex nastaven� pozice na ose Z
	*/
	void setZIndex(int zIndex);
	/**
	@return pozice prvku na ose Z
	*/
	int getZIndex();
	/**
	@param width v��ka v pixelech
	*/
	void setHeight(unsigned int height);
	/**
	@return v��ka hern�ho objektu
	*/
	unsigned int getHeight();
	/**
	@param width ���ka v pixelech
	*/
	void setWidth(unsigned int width);
	/**
	@return ���ka hern�ho objektu
	*/
	unsigned int getWidth();
	/**
	@return jestli je hern� objekt aktivn�
	*/
	bool isActive();
	/**
	Nastaven� vlastnosti

	@param active zdali je hern� objekt aktivn�
	*/
	void setActive(bool active);
	/**
	@return vr�t� hledanou komponentu podle typu
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