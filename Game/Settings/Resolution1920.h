#ifndef RESOLUTION_1920
#define RESOLUTION_1920

#include "Component.h"

class Resolution1920 : public Component {
public:
	void onMouseClick() override;
	Resolution1920 * clone() override;
};

#endif // !RESOLUTION_1920
