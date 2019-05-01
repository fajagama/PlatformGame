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
	@param ���ka okna v pixelech
	*/
	static int getWidth();
	/**
	@param v��ka okna v pixelech
	*/
	static int getHeight();
	/**
	@param width ���ka okna v pixelech
	*/
	static void setWidth(int width);
	/**
	@param height v��ka okna v pixelech
	*/
	static void setHeight(int height);
	/**
	@return informace zdali je okno p�es celou obrazovku
	*/
	static bool isFullscreen();
	/**
	Nastav� okno na celou obrazovku

	@param fullscreen true = okno bude p�es celou obrazovku
	*/
	static void setFullscreen(bool fullscreen);
};
#endif // !WINDOW_MANAGER
