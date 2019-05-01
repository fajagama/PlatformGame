#ifndef MUSIC_VOLUME
#define MUSIC_VOLUME

#include "Component.h"

class MusicVolume : public Component {
private:
	int musicVolume = 0;
public:
	void update() override;
	MusicVolume * clone() override;
};

#endif // !TEST_LEVEL
