#ifndef ANIMATION
#define ANIMATION

#include "Component.h"
#include "Sprite.h"
#include <tuple>  
#include <vector>  

class Animation : public Component {
private:
	Sprite * sprite = nullptr;
	SDL_Texture * texture = nullptr;

	float animationSpeed;
	vector<tuple<int, int>> frames;
	unsigned int frameIndex;
	unsigned int lastTime;
public:
	Animation(const Animation & com);
	/**
	@param sprite tøída s animaènímy snímky
	@param animationSpeed rychlost animace
	*/
	Animation(Sprite & sprite, float animationSpeed);

	~Animation();
	/**
	Pøidání animaèního snímku do animace

	@param indexRow index animaèního snímku na øádku
	@param indexCol index animaèního snímku ve sloupci
	*/
	void addFrame(unsigned int indexRow, unsigned int indexCol);
	
	void resetRender() override;
	void update() override;
	void render(SDL_Renderer * renderer) override;
	Animation * clone() override;
};

#endif // !ANIMATION
