#include <iostream>
#include <iomanip>
#include <string>

#include "VowelLess.h"

using namespace std;
using namespace vowelless;

int main()
{
	cout << "Welcome to Vowel-less!" << endl << endl;

	string userInput = UserInput();
	int userSelection = GroupSelector();
	string newString = Eraser(userInput, userSelection);
	cout << newString << endl;
	
	TestCode();

	return 0;
}