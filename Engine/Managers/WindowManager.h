#ifndef WINDOW_MANAGER
#define WINDOW_MANAGER

using namespace std;

class WindowManager {
private:
	static int width;
	static int height;
	static bool fullscreen;

	WindowManager() {}
public:
	WindowManager(WindowManager const&) = delete;
	void operator=(WindowManager const&) = delete;
	/**
	@param šíøka okna v pixelech
	*/
	static int getWidth();
	/**
	@param výška okna v pixelech
	*/
	static int getHeight();
	/**
	@param width šíøka okna v pixelech
	*/
	static void setWidth(int width);
	/**
	@param height výška okna v pixelech
	*/
	static void setHeight(int height);
	/**
	@return informace zdali je okno pøes celou obrazovku
	*/
	static bool isFullscreen();
	/**
	Nastaví okno na celou obrazovku

	@param fullscreen true = okno bude pøes celou obrazovku
	*/
	static void setFullscreen(bool fullscreen);
};
#endif // !WINDOW_MANAGER
