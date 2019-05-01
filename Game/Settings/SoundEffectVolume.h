#ifndef SOUND_EFFECT_VOLUME
#define SOUND_EFFECT_VOLUME

#include "Component.h"

class SoundEffectVolume : public Component {
private:
	int volume = 0;
public:
	void update() override;
	SoundEffectVolume * clone() override;
};

#endif // !TEST_LEVEL
