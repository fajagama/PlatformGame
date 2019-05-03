#include "SharedMemory.h"

#include <fstream>
#include <algorithm>
#include <utility>
#include <iostream>
#include <sstream>
#include <vector>

map<string, string> SharedMemory::values;

void SharedMemory::loadValues()
{
	string line;
	ifstream ifs("values", ifstream::in);
	if (ifs.is_open())
	{
		while (getline(ifs, line))
		{
			stringstream ss(line);
			std::string item;
			vector<std::string> myVector;
			while (getline(ss, item, ':'))
			{
				myVector.push_back(item);
			}
			if (myVector.capacity() == 2) {
				values[myVector[0]] = myVector[1];
			}
			else {
				values[myVector[0]] = "";
			}
		}
		ifs.close();
	}
}

void SharedMemory::setValue(string key, string value)
{
	values[key] = value;

	ofstream ofs("values", ofstream::out);
	if (ofs.is_open()) {
		for (std::map<string, string>::iterator it = values.begin(); it != values.end(); ++it)
		{
			ofs << it->first << ":" << it->second << endl;
		}
		ofs.close();
	}
}

string SharedMemory::getValue(string key)
{
	return values[key];
}
