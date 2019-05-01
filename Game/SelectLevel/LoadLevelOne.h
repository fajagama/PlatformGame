#ifndef LOAD_LEVEL_ONE
#define LOAD_LEVEL_ONE

#include "Component.h"

class LoadLevelOne : public Component {
public:
	void onMouseClick() override;
	LoadLevelOne * clone() override;
};

#endif // !LOAD_LEVEL_ONE
