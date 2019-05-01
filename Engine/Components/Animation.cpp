#include "Animation.h"

#include "Rect.h"
#include "Rect.h"
#include "TimeManager.h"

Animation::Animation(const Animation & com)
{
	sprite = new Sprite(*com.sprite);
	texture = nullptr;
	animationSpeed = com.animationSpeed;
	frames = com.frames;
	frameIndex = com.frameIndex;
	lastTime = com.lastTime;
}

Animation::Animation(Sprite & sprite, float animationSpeed)
{
	this->sprite = new Sprite(sprite);
	this->animationSpeed = animationSpeed * 1000;
	this->frameIndex = 0;
	this->lastTime = TimeManager::getTime();
}

Animation::~Animation()
{
	delete sprite;
	SDL_DestroyTexture(texture);
}

void Animation::addFrame(unsigned int indexRow, unsigned int indexCol)
{
	tuple<int, int> position(indexRow, indexCol);
	frames.push_back(position);
}

void Animation::resetRender()
{
	SDL_DestroyTexture(this->texture);
	texture = nullptr;
}

void Animation::update()
{
	if (TimeManager::getTime() > (this->lastTime + this->animationSpeed)) {
		this->lastTime = TimeManager::getTime();
		this->frameIndex++;
		if (this->frameIndex >= this->frames.size()) {
			this->frameIndex = 0;
		}
	}
}

void Animation::render(SDL_Renderer * renderer)
{
	if (this->texture == nullptr) {
		this->texture = SDL_CreateTextureFromSurface(renderer, this->sprite->getImage());
	}

	int x = get<0>(this->frames[this->frameIndex]);
	int y = get<1>(this->frames[this->frameIndex]);

	SDL_RenderCopy(renderer, 
		this->texture,
		&Rect::getRect((x * this->sprite->getWidth()), (y * this->sprite->getHeight()), this->sprite->getWidth(), this->sprite->getHeight()),
		&Rect::getRect(*getGameObject())
	);
}

Animation * Animation::clone()
{
	return new Animation(*this);
}
