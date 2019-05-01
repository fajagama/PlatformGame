#ifndef DEBUG_LOGGING
#define DEBUG_LOGGING

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class DebugLogging
{
private:
	static void makeDebugLine(std::string msg);
	static void printToConsole(std::string msg);
	static void printToFile(std::string msg);

	static bool debugMode;
	static bool fileEnable;
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
	static void print(std::string msg);
	/**
	@param msg zpráva pro zápis do logù
	*/
	static void print(int msg);
	/**
	Soubor pro zápis logù
	*/
	static std::ofstream debugFile;
};


#endif // !DEBUG_LOGGING
