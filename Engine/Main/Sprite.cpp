#include "Sprite.h"

Sprite::Sprite(const Sprite & sprite)
{
	file = sprite.file;
	image = IMG_Load(file.c_str());
	widthOfCell = sprite.widthOfCell;
	heightOfCell = sprite.heightOfCell;
}

Sprite::Sprite(string file, unsigned int widthOfCell, unsigned int heightOfCell)
{
	this->file = file;
	this->image = IMG_Load(file.c_str());
	if (this->image == nullptr) {
		ErrorLogging::addLog("IMG_Load, file not found! (RenderImage Component)", IMG_GetError());
		ErrorLogging::showErrorMsg("File not found!", "Game cannot load file! ", file);
		throw std::invalid_argument("File not found!");
	}
	this->widthOfCell = widthOfCell;
	this->heightOfCell = heightOfCell;
}

Sprite::~Sprite()
{
	SDL_FreeSurface(image);
}

SDL_Surface * Sprite::getImage()
{
	return image;
}

unsigned int Sprite::getHeight()
{
	return this->heightOfCell;
}

unsigned int Sprite::getWidth()
{
	return this->widthOfCell;
}
