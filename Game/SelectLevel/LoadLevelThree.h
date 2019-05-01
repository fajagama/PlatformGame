#ifndef LOAD_LEVEL_THREE
#define LOAD_LEVEL_THREE

#include "Component.h"

class LoadLevelThree : public Component {
public:
	void onMouseClick() override;
	LoadLevelThree * clone() override;
};

#endif // !LOAD_LEVEL_THREE
