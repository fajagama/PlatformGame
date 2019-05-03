#ifndef SOUND_EFFECT_VOLUME
#define SOUND_EFFECT_VOLUME

#include "Component.h"

class SoundEffectVolume : public Component {
private:
	int volume = -20;
public:
	void update() override;
	SoundEffectVolume * clone() override;
};

#endif // !TEST_LEVEL
