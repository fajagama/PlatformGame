#ifndef PLAYER_CONTROLLER
#define PLAYER_CONTROLLER

#include "Component.h"
#include "SoundController.h"

class PlayerController : public Component {
private:
	int counter;
public:
	int getCounter();

	void update() override;
	void onCollision(GameObject & go) override;
	void onLoad() override;
	PlayerController * clone() override;
};

#endif // !PLAYER_CONTROLLER

