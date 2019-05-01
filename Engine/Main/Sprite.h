#ifndef SPRITE
#define SPRITE
 
#include <SDL.h>
#include <string>
#include <SDL_image.h>
#include "ErrorLogging.h"

using namespace std;

class Sprite {
private:
	unsigned int widthOfCell;
	unsigned int heightOfCell;
	SDL_Surface * image = nullptr;
	string file;
public:
	Sprite(const Sprite & sprite);
	/**
    Konstruktor

    @param file obr�zkov� soubor s anima�n�mi sn�mky
    @param widthOfCell ���ka jedn� jednoho anima�n�ho sn�mku
    @param heightOfCell v��ka jedn� jednoho anima�n�ho sn�mku
	*/
	Sprite(string file, unsigned int widthOfCell, unsigned int heightOfCell);
	/**
	Destruktor ni�� instanci obr�zku
	*/
	~Sprite();
	/**
	Vraci hodnotu vlastnosti

	@return obr�zek s animovan�mi sn�mky
	*/
	SDL_Surface * getImage();
	/**
    Vraci hodnotu vlastnosti

	@return vy�ka jednoho anima�n�ho sn�mku
	*/
	unsigned int getHeight();
	/**
    Vraci hodnotu vlastnosti

	@return ���ka jednoho anima�n�ho sn�mku
	*/
	unsigned int getWidth();
};

#endif // !SPRITE
