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
	static void print(std::string msg);
	/**
	@param msg zpr�va pro z�pis do log�
	*/
	static void print(int msg);
	/**
	Soubor pro z�pis log�
	*/
	static std::ofstream debugFile;
};


#endif // !DEBUG_LOGGING
