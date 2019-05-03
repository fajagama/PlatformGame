#include <crtdbg.h>
#include "LevelSetup.h"


int main(int argc, char * argv[])
{
	LevelSetup * ls = new LevelSetup();
	ls->run();
	delete ls;

	return 0;
}