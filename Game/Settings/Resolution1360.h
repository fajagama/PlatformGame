#ifndef RESOLUTION_1360
#define RESOLUTION_1360

#include "Component.h"

class Resolution1360 : public Component {
public:
	void onMouseClick() override;
	Resolution1360 * clone() override;
};

#endif // !RESOLUTION_1360
