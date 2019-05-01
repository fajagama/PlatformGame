#ifndef EXIT_GAME
#define EXIT_GAME

#include "Component.h"

class ExitGame : public Component {
public:
	void onMouseClick() override;
	ExitGame * clone() override;
};

#endif // !TEST_LEVEL
