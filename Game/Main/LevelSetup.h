#ifndef LEVEL_SETUP
#define LEVEL_SETUP

#include <iostream>
#include <string>

#include "Component.h"
#include "Core.h"
#include "RenderImage.h"
#include "SimpleGravity.h"
#include "Sprite.h"
#include "Animation.h"
#include "Camera.h"
#include "GameObject.h"
#include "SharedMemory.h"

class LevelSetup {
private:

public:
	void run();
	void makeLevel(Level & level, int map[25][76]);
};

#endif // !TEST_LEVEL
