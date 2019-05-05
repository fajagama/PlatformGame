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
	Vrac� true pokud je kl�vesa stisknut�

	@param key kl�vesa na kl�vesnici
	@return je kl�vesa stisknut�
	*/
	static bool getKeyDown(KeyCode key);
	/**
	Vrac� true pokud je kl�vesa stisknut�

	@param key kl�vesa na kl�vesnici
	@return je kl�vesa stisknut�
	*/
	static bool getKeyDown(string key);
	/**
	Nastav� stisknutou kl�vesu na kl�vesnici

	@param keyCode kl�vesa na kl�vesnici
	*/
	static void setKeyDown(SDL_Keycode keyCode);
	/**
	Vrac� true pokud je kl�vesa uvon�na

	@param key kl�vesa na kl�vesnici
	@return je kl�vesa uvoln�n�
	*/
	static bool getKeyUp(KeyCode key);
	/**
	Vrac� true pokud je kl�vesa uvon�na

	@param key kl�vesa na kl�vesnici
	@return je kl�vesa stiknut�
	*/
	static bool getKeyUp(string key);
	/**
	Nastav� uvoln�nou kl�vesu na kl�vesnici

	@param keyCode kl�vesa na kl�vesnici
	*/
	static void setKeyUp(SDL_Keycode keyCode);
	/**
	@param key The radius of the circle.
	@return je tla��tko na my�i zma�knut�
	*/
	static bool getMouseKeyDown(KeyCode key);
	/**
	Nastav� zma�knut� tla��tko na my�i

	@param mouseCode tla��tko na my�i
	*/
	static void setMouseKeyDown(int mouseCode);
	/**
	@param key kla��tko na my�i
	@return je tla��tko na my�i uvoln�n�
	*/
	static bool getMouseKeyUp(KeyCode key);
	/**
	Nastav� uvoln�n� tla��tko na my�i

	@param mouseCode tla��tko na my�i
	*/
	static void setMouseKeyUp(int mouseCode);
	/**
	@return jesli u�ivatel klikl na tla��tko na my�i
	*/
	static bool isMouseClicked();
	/**
	@return pozice kurzoru my�i v prostoru
	*/
	static Position & getMousePosition();
	/**
	Nastavuje pozici my�i v prostoru

	@param x pozice na ose X
	@param y pozice na ose Y
	*/
	static void setMousePosition(int x, int y);
	/**
	Resetuje nastaven� kl�vesy
	*/
	static void reset();
};

#endif // !INPUT
