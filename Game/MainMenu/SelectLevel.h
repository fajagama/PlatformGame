#ifndef SELECT_LEVEL
#define SELECT_LEVEL

#include "Component.h"

class SelectLevel : public Component {
public:
	void onMouseClick() override;
	SelectLevel * clone() override;
};

#endif // !SELECT_LEVEL
