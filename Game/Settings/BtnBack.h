#ifndef BTN_BACK
#define BTN_BACK

#include "Component.h"

class BtnBack : public Component {
public:
	void onMouseClick() override;
	BtnBack * clone() override;
};

#endif // !BTN_BACK
