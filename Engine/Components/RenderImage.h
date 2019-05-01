#ifndef RENDERIMAGE
#define RENDERIMAGE

#include "Component.h"

#include <string>

using namespace std;

class RenderImage : public Component
{
private:
	string filePath;
	SDL_Surface * image = nullptr;
	SDL_Texture * texture = nullptr;
public:
	RenderImage(const RenderImage & com);
	/**
    @param file cesta k obrázku
	*/
	RenderImage(string filePath);
	~RenderImage();
	/**
	Nastavení obrázku

	@param file cesta k obrázku
	*/
	void setImage(string filePath);
	
	void resetRender() override;
	void render(SDL_Renderer * renderer) override;
	void update() override;
	RenderImage * clone() override;
};
#endif // !RENDERIMAGE
