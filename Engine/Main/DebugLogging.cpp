#include "DebugLogging.h"

#include "TimeManager.h"

bool DebugLogging::debugMode = true;
bool DebugLogging::fileEnable = false;
ofstream DebugLogging::debugFile;

void DebugLogging::enableDebugMode()
{
	debugMode = true;
}

void DebugLogging::disableDebugMode()
{
	debugMode = false;
}

void DebugLogging::enablePrintToFile()
{
	fileEnable = true;
}

void DebugLogging::disablePrintToFile()
{
	fileEnable = false;
}

void DebugLogging::print(string msg)
{
	makeDebugLine(msg);
}
void DebugLogging::print(int msg)
{
	makeDebugLine(to_string(msg));
}

void DebugLogging::makeDebugLine(string msg)
{
	if (debugMode == true) {
		string printLine = TimeManager::getFullCurrentDateTime() + " | " + msg + "\n";

		printToConsole(printLine);
		printToFile(printLine);
	}
}

void DebugLogging::printToConsole(string msg)
{
	cout << msg << endl;
}

void DebugLogging::printToFile(string msg)
{
	if (fileEnable == true) {
		debugFile.open("debug.txt", ios::app);
		if (debugFile.is_open()) {
			debugFile << msg;
			debugFile.close();
		}
		else {
			printToConsole("Cannot load debug log file!");
		}
	}
}
