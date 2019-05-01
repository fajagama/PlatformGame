#ifndef LEVEL_MENU
#define LEVEL_MENU

#include "Component.h"

class LevelMenu : public Component {
private:
	void showMenu();
	void hideMenu();
public:
	void update() override;
	void onMouseClick() override;
	LevelMenu * clone() override;
};

#endif // !LEVEL_MENU
