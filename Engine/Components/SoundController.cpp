#include "SoundController.h"

#include <algorithm>

SoundController::SoundController(const SoundController & com)
{
	for (auto i = com.sounds.begin(); i != com.sounds.end(); ++i) {
		sounds[i->first] = unique_ptr<SoundEffect>(new SoundEffect(*i->second));
	}
}

SoundController::SoundController()
{
}

void SoundController::add(string name, string fileWithPath)
{
	sounds[name] = unique_ptr<SoundEffect>(new SoundEffect(fileWithPath));
}

void SoundController::remove(string name)
{
	sounds.erase(name);
}

void SoundController::play(string name)
{
	sounds[name]->play();
}

void SoundController::pause(string name)
{
	sounds[name]->pause();
}

void SoundController::resume(string name)
{
	sounds[name]->resume();
}

void SoundController::stop(string name)
{
	sounds[name]->stop();
}

SoundController * SoundController::clone()
{
	return new SoundController(*this);
}
