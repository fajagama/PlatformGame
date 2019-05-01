#ifndef ERROR_LOGGING
#define ERROR_LOGGING

#include <string>

using namespace std;

class ErrorLogging {
public:
	/**
    Zapisuje chybov� logy do souboru

    @param description popis chyby
    @param error typ chyby
	*/
	static void addLog(string description, string error = "");
	/**
	Zobraz� chybov� dialog

	@param title titulek okna
	@param message chybov� zpr�va
	@param description dopl�uj�c� popisek
	*/
	static void showErrorMsg(string title, string message, string description);
};

#endif // !ERROR_LOGGING

