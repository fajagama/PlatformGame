#ifndef SETTINGS
#define SETTINGS

#include "Component.h"

class Settings : public Component {
public:
	void onMouseClick() override;
	Settings * clone() override;
};

#endif // !TEST_LEVEL
