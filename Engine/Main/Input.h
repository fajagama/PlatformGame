#ifndef INPUT
#define INPUT

#include <SDL.h>
#include <string>
#include <map> 

#include "KeyCode.h" 
#include "Position.h" 

using namespace std;

class Input {
private:
	static string keyCodeDown;
	static string keyCodeUp;

	static int mouseCodeDown;
	static int mouseCodeUp;

	static Position mousePosition;

	static map<string, string> keysDown;
public:
	Input() = delete;
	Input(Input const&) = delete;
	void operator=(Input const&) = delete;
	/**
	Vrací true pokud je klávesa stisknutá

	@param key klávesa na klávesnici
	@return je klávesa stisknutá
	*/
	static bool getKeyDown(KeyCode key);
	/**
	Vrací true pokud je klávesa stisknutá

	@param key klávesa na klávesnici
	@return je klávesa stisknutá
	*/
	static bool getKeyDown(string key);
	/**
	Nastavý stisknutou klávesu na klávesnici

	@param keyCode klávesa na klávesnici
	*/
	static void setKeyDown(SDL_Keycode keyCode);
	/**
	Vrací true pokud je klávesa uvonìna

	@param key klávesa na klávesnici
	@return je klávesa uvolnìná
	*/
	static bool getKeyUp(KeyCode key);
	/**
	Vrací true pokud je klávesa uvonìna

	@param key klávesa na klávesnici
	@return je klávesa stiknutá
	*/
	static bool getKeyUp(string key);
	/**
	Nastavý uvolnìnou klávesu na klávesnici

	@param keyCode klávesa na klávesnici
	*/
	static void setKeyUp(SDL_Keycode keyCode);
	/**
	@param key The radius of the circle.
	@return je tlaèítko na myši zmaèknuté
	*/
	static bool getMouseKeyDown(KeyCode key);
	/**
	Nastavý zmaèknuté tlaèítko na myši

	@param mouseCode tlaèítko na myši
	*/
	static void setMouseKeyDown(int mouseCode);
	/**
	@param key klaèítko na myši
	@return je tlaèítko na myši uvolnìné
	*/
	static bool getMouseKeyUp(KeyCode key);
	/**
	Nastavý uvolnìné tlaèítko na myši

	@param mouseCode tlaèítko na myši
	*/
	static void setMouseKeyUp(int mouseCode);
	/**
	@return jesli uživatel klikl na tlaèítko na myši
	*/
	static bool isMouseClicked();
	/**
	@return pozice kurzoru myši v prostoru
	*/
	static Position & getMousePosition();
	/**
	Nastavuje pozici myši v prostoru

	@param x pozice na ose X
	@param y pozice na ose Y
	*/
	static void setMousePosition(int x, int y);
	/**
	Resetuje nastavené klávesy
	*/
	static void reset();
};

#endif // !INPUT
