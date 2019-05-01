#include "ErrorLogging.h"

#include <ctime>
#include <sstream>
#include <iostream>
#include <fstream>
#include <SDL.h>

void ErrorLogging::addLog(string description, string error)
{
	time_t now = time(0);
	string date = ctime(&now);
	ofstream logfile;
	logfile.open("errorLog.txt", ios::app);
	if (logfile.is_open())
	{
		logfile << date.substr(0, date.length() - 1);
		logfile << " - ";
		logfile << description;
		logfile << ": ";
		logfile << error;
		logfile << "\n";
		logfile.close();
	}
}

void ErrorLogging::showErrorMsg(string title, string message, string description)
{
	stringstream ss;
	ss << message << " " << description;

	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
		title.c_str(),
		ss.str().c_str(),
		NULL);

}
