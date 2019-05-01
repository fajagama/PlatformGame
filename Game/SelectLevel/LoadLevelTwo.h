#ifndef LOAD_LEVEL_TWO
#define LOAD_LEVEL_TWO

#include "Component.h"

class LoadLevelTwo : public Component {
public:
	void onMouseClick() override;
	LoadLevelTwo * clone() override;
};

#endif // !LOAD_LEVEL_TWO
