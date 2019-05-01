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

    @param file obrázkový soubor s animaèními snímky
    @param widthOfCell šíøka jedné jednoho animaèního snímku
    @param heightOfCell výška jedné jednoho animaèního snímku
	*/
	Sprite(string file, unsigned int widthOfCell, unsigned int heightOfCell);
	/**
	Destruktor nièí instanci obrázku
	*/
	~Sprite();
	/**
	Vraci hodnotu vlastnosti

	@return obrázek s animovanými snímky
	*/
	SDL_Surface * getImage();
	/**
    Vraci hodnotu vlastnosti

	@return vyška jednoho animaèního snímku
	*/
	unsigned int getHeight();
	/**
    Vraci hodnotu vlastnosti

	@return šíøka jednoho animaèního snímku
	*/
	unsigned int getWidth();
};

#endif // !SPRITE
