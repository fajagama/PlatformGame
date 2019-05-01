#ifndef MUSIC_VOLUME_DOWN
#define MUSIC_VOLUME_DOWN

#include "Component.h"

class MusicVolumeDown : public Component {
public:
	void onMouseClick() override;
	MusicVolumeDown * clone() override;
};

#endif // !TEST_LEVEL
