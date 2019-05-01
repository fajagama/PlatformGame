#ifndef KEY_CODE
#define KEY_CODE

#include <SDL.h>

enum class KeyCode {
	NONE,

	MOUSE_BUTTON_LEFT = SDL_BUTTON_LEFT, 
	MOUSE_BUTTON_MIDDLE = SDL_BUTTON_MIDDLE,
	MOUSE_BUTTON_RIGHT = SDL_BUTTON_RIGHT,

	ESC = SDLK_ESCAPE,
	F1 = SDLK_F1,
	F2 = SDLK_F2,
	F3 = SDLK_F3,
	F4 = SDLK_F4,
	F5 = SDLK_F5,
	F6 = SDLK_F6,
	F7 = SDLK_F7,
	F8 = SDLK_F8,
	F9 = SDLK_F9,
	F10 = SDLK_F10,
	F11 = SDLK_F11,
	F12 = SDLK_F12,
	RCTRL = SDLK_RCTRL,
	LCTRL = SDLK_LCTRL,
	LSHIFT = SDLK_LSHIFT,
	RSHIFT = SDLK_RSHIFT,
	LALT = SDLK_LALT,
	RALT = SDLK_RALT,
	ENTER = SDLK_KP_ENTER,
};

#endif // !KEY_CODE
