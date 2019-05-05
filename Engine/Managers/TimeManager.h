#ifndef TIME_MANAGER
#define TIME_MANAGER

#include <string>

using namespace std;

class TimeManager
{
private:
	static float delta;
	static float timeScale;
public:

	TimeManager() = delete;
	TimeManager(TimeManager const&) = delete;
	void operator=(TimeManager const&) = delete;
	/**
	Vrací hodnotu delta

	@return hodnota určující koluk
	*/
	static float getDeltaTime();
	/**
	Vrací čas

	@return vrací počet milisekund od startu programu
	*/
	static unsigned int getTime();
	/**
	Vrací aktuální čas

	@return aktuální čas
	*/
	static string getFullCurrentDateTime();
	/**
    Nastavuje hodnotu vlastnosti

	@param scale rychlost toku času, výchozí = 1
	*/
	static void setTimeScale(float scale);
	/**
    Vrací hodnotu vlastnosti

    @return hodnota aktuální rychlosti toku času
	*/
	static float getTimeScale();
};

#endif // !TIME_MANAGER
