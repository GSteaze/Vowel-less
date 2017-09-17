#include <iostream>
#include <iomanip>
#include <string>

#include "VowelLess.h"

using namespace std;
using namespace vowelless;

int main()
{
	cout << "Welcome to Vowel-less!" << endl << endl;
	bool isAgain = false;
	do {
		string userInput = UserInput();
		int userSelection = GroupSelector();
		string newString = Eraser(userInput, userSelection);
		cout << "The formatted string : " << newString << endl << endl;

		isAgain = IsAgain();
	} while (isAgain);


	//TestCode();

	return 0;
}