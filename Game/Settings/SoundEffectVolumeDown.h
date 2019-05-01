#ifndef SOUND_EFFECT_DOWN
#define SOUND_EFFECT_DOWN

#include "Component.h"

class SoundEffectVolumeDown : public Component {
public:
	void onMouseClick() override;
	SoundEffectVolumeDown * clone() override;
};

#endif // !TEST_LEVEL
