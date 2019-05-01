#ifndef ERROR_LOGGING
#define ERROR_LOGGING

#include <string>

using namespace std;

class ErrorLogging {
public:
	/**
    Zapisuje chybové logy do souboru

    @param description popis chyby
    @param error typ chyby
	*/
	static void addLog(string description, string error = "");
	/**
	Zobrazí chybový dialog

	@param title titulek okna
	@param message chybová zpráva
	@param description doplòující popisek
	*/
	static void showErrorMsg(string title, string message, string description);
};

#endif // !ERROR_LOGGING

