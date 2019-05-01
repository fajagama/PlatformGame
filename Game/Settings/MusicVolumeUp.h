#ifndef MUSIC_VOLUME_UP
#define MUSIC_VOLUME_UP

#include "Component.h"

class MusicVolumeUp : public Component {
public:
	void onMouseClick() override;
	MusicVolumeUp * clone() override;
};

#endif // !TEST_LEVEL
