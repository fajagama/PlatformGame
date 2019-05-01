#ifndef SHARED_MEMORY
#define SHARED_MEMORY

#include <string>
#include <map>
	
using namespace std;

class SharedMemory {
private:
	SharedMemory();
	static map<string, string> values;
public:
	/**
	Naète uložené hodnoty ze souboru
	*/
	static void loadValues();
	/**
	Vloží hodnotu do pamìti a zároveò ji uloží do souboru

	@param key klíè hodnoty
	@param value obsah hodnoty
	*/
	static void setValue(string key, string value);
	/**
	@param klíè hodnoty
	@return obsah hodnoty
	*/
	static string getValue(string key);
};

#endif // !SHARED_MEMORY
