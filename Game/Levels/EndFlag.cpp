#include "EndFlag.h"

#include <sstream>

#include "PlayerController.h"
#include "Core.h"
#include "TimeManager.h"
#include "RenderImage.h"

void EndFlag::showTime(char number, string nameOfGO)
{
	stringstream ss;
	ss << "assets/number-" << number << ".png";
	Core::findGameObjectByName(nameOfGO)->getComponent<RenderImage>()->setImage(ss.str());
}

void EndFlag::onTrigger(GameObject & go)
{
	if (go.getName() == "player") {
		if (go.getComponent<PlayerController>()->getCounter() == 3) {
			TimeManager::setTimeScale(0.0f);
			Core::findGameObjectByName("dialog")->setActive(true);
			Core::findGameObjectByName("back")->setActive(true);
			Core::findGameObjectByName("time_one")->setActive(true);
			Core::findGameObjectByName("time_two")->setActive(true);
			Core::findGameObjectByName("time_colon")->setActive(true);
			Core::findGameObjectByName("time_three")->setActive(true);
			Core::findGameObjectByName("time_four")->setActive(true);
			if (Core::findGameObjectByName("next_level") != nullptr) {
				Core::findGameObjectByName("next_level")->setActive(true);
			}

			if (endTime == 0) {
				endTime = TimeManager::getTime();
				unsigned int totalTime = (endTime - startTime) / 1000;
				string s = to_string(totalTime);

				if (s.length() > 0) {
					showTime(s.at(s.length() - 1), "time_four");
				}
				if (s.length() > 1) {
					showTime(s.at(s.length() - 2), "time_three");
				}
				if (s.length() > 2) {
					showTime(s.at(s.length() - 3), "time_two");
				}
				if (s.length() > 3) {
					showTime(s.at(s.length() - 4), "time_one");
				}
			}
		}
	}
}

EndFlag * EndFlag::clone()
{
	return new EndFlag(*this);
}

void EndFlag::onLoad()
{
	startTime = TimeManager::getTime();
}
