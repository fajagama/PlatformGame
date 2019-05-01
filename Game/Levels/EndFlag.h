#ifndef END_FLAG
#define END_FLAG

#include "Component.h"

class EndFlag : public Component {
private:
	unsigned int startTime;
	unsigned int endTime = 0;
public:
	void showTime(char number, string nameOfGO);
	void onTrigger(GameObject & go) override;
	EndFlag * clone() override;
	void onLoad() override;
};

#endif // !END_FLAG

