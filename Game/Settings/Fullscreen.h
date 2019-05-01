#ifndef FULLSCREEN
#define FULLSCREEN

#include "Component.h"

class Fullscreen : public Component {
private:
	bool fullscreen = false;
public:
	void update() override;
	void onMouseClick() override;
	Fullscreen * clone() override;
};

#endif // !FULLSCREEN
