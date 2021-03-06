#ifndef SHARED_MEMORY
#define SHARED_MEMORY

#include <string>
#include <map>
	
using namespace std;

class SharedMemory {
private:
	static map<string, string> values;
public:
	SharedMemory() = delete;
	SharedMemory(SharedMemory const&) = delete;
	void operator=(SharedMemory const&) = delete;
	/**
	Na�te ulo�en� hodnoty ze souboru
	*/
	static void loadValues();
	/**
	Vlo�� hodnotu do pam�ti a z�rove� ji ulo�� do souboru

	@param key kl�� hodnoty
	@param value obsah hodnoty
	*/
	static void setValue(string key, string value);
	/**
	@param kl�� hodnoty
	@return obsah hodnoty
	*/
	static string getValue(string key);
};

#endif // !SHARED_MEMORY
