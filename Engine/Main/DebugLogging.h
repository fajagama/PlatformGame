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
	Zapnut� lad�c�ho m�du
	*/
	static void enableDebugMode();
	/**
	Vypnut� lad�c�ho m�du
	*/
	static void disableDebugMode();
	/**
	Zapnut� z�pisu log� do souboru
	*/
	static void enablePrintToFile();
	/**
	Vypnut� z�pisu log� do souboru
	*/
	static void disablePrintToFile();
	/**
	@param msg zpr�va pro z�pis do log�
	*/
	static void print(string msg);
	/**
	@param msg zpr�va pro z�pis do log�
	*/
	static void print(int msg);
};


#endif // !DEBUG_LOGGING
