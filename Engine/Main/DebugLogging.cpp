#include "DebugLogging.h"

#include "TimeManager.h"

bool DebugLogging::debugMode = true;
bool DebugLogging::fileEnable = true;
std::ofstream DebugLogging::debugFile;

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

void DebugLogging::print(std::string msg)
{
	makeDebugLine(msg);
}
void DebugLogging::print(int msg)
{
	makeDebugLine(std::to_string(msg));
}

void DebugLogging::makeDebugLine(std::string msg)
{
	if (debugMode == true) {
		std::string printLine = TimeManager::getFullCurrentDateTime() + " | " + msg + "\n";

		printToConsole(printLine);
		printToFile(printLine);
	}
}

void DebugLogging::printToConsole(std::string msg)
{
		std::cout << msg;
}

void DebugLogging::printToFile(std::string msg)
{
	if (DebugLogging::fileEnable == true) {
		if (debugFile.is_open()) {
			debugFile << msg;
		}
		else {
			printToConsole("Cannot load debug log file!");
		}
	}
}
