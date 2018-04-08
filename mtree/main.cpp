#include "node.h"
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

string fileToString(const char *fin);

int main(int argc, char**argv)
{
	if(argc > 1)
		cout << fileToString(argv[1]) << endl;
}



// I'm assuming the file is short to make it simple
string fileToString(const char *fin)
{
	cout << "converting \"" << fin << "\" to a string..." << endl;
	
	return "asdf";
}
