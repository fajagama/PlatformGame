#ifndef DEBUG_LOGGING
#define DEBUG_LOGGING

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class DebugLogging
{
private:
	static void makeDebugLine(string msg);
	static void printToConsole(string msg);
	static void printToFile(string msg);

	static bool debugMode;
	static bool fileEnable;
	static ofstream debugFile;
public:
	/**
	Zapnutí ladícího módu
	*/
	static void enableDebugMode();
	/**
	Vypnutí ladícího módu
	*/
	static void disableDebugMode();
	/**
	Zapnutí zápisu logù do souboru
	*/
	static void enablePrintToFile();
	/**
	Vypnutí zápisu logù do souboru
	*/
	static void disablePrintToFile();
	/**
	@param msg zpráva pro zápis do logù
	*/
	static void print(string msg);
	/**
	@param msg zpráva pro zápis do logù
	*/
	static void print(int msg);
};


#endif // !DEBUG_LOGGING
