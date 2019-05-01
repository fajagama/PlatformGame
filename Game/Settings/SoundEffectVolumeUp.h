#ifndef SOUND_EFFECT_UP
#define SOUND_EFFECT_UP

#include "Component.h"

class SoundEffectVolumeUp : public Component {
public:
	void onMouseClick() override;
	SoundEffectVolumeUp * clone() override;
};

#endif // !TEST_LEVEL
