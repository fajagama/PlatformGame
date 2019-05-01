#include "RenderImage.h"

#include "GameObject.h"
#include "Camera.h"
#include "Rect.h"
#include "ErrorLogging.h"

RenderImage::RenderImage(const RenderImage & com)
{
	filePath = com.filePath;
	setImage(filePath);
}

RenderImage::RenderImage(string filePath)
{
	this->setImage(filePath);
}

RenderImage::~RenderImage()
{
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(image);
}

void RenderImage::setImage(string filePath)
{
	this->filePath = filePath;
	if (image != nullptr) {
		SDL_DestroyTexture(texture);
		SDL_FreeSurface(image);
	}
	image = IMG_Load(filePath.c_str());
	texture = nullptr;
	if (!image) {
		ErrorLogging::addLog("IMG_Load, file not found! (RenderImage Component)", IMG_GetError());
		ErrorLogging::showErrorMsg("File not found!", "Game cannot load file! ", filePath);
		throw std::invalid_argument("File not found!");
	}
}

void RenderImage::resetRender()
{
	SDL_DestroyTexture(texture);
	texture = nullptr;
}

void RenderImage::render(SDL_Renderer * renderer)
{
	if (texture == nullptr) {
		texture = SDL_CreateTextureFromSurface(renderer, image);
	}
	SDL_RenderCopy(renderer, texture, &Rect::getRect(image->w, image->h), &Rect::getRect(*getGameObject()));
}

void RenderImage::update()
{
}

RenderImage * RenderImage::clone()
{
	return new RenderImage(*this);
}
