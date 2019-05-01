#ifndef RESOLUTION_1024
#define RESOLUTION_1024

#include "Component.h"

class Resolution1024 : public Component {
public:
	void onMouseClick() override;
	Resolution1024 * clone() override;
};

#endif // !RESOLUTION_1024
