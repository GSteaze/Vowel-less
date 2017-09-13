#include <iostream>
#include <iomanip>
#include <string>

#include "VowelLess.h"

using namespace std;

namespace vowelless
{
	string UserInput() {
		
		string userInput = "";

		cout << "Please enter a string." << endl;
		cout << "Input : ";
		userInput = InputValidater();
		return userInput;
	}

	string InputValidater() {
		string userInput = "";
		cin >> userInput;
		bool isInvalid = cin.fail() || userInput.empty();
			while (isInvalid) {
				cin.clear();
				cout << "Please enter a valid string." << endl
					<< "New input : ";
				cin >> userInput;
				isInvalid = cin.fail() || userInput.empty();
		}
			return userInput;
	}

	bool IsVowel(char letter) {
		if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u') {
			return true;
		}
		else {
			return false;
		}

	}

	string VowelEraser(string userInput) {
		string removedVowels = "";
		for (int i = 0; i < userInput.length(); i++) {
			if (!IsVowel(userInput[i])) {
				removedVowels.append(userInput, i, 1);
			}
		}

		return removedVowels;
	}


	void TestCode() {

		//UserInput
		string userInput = "";
		cout << "UserInput" << endl;
		userInput = UserInput();
		cout << "Input : " << userInput << endl;

		//InputValidater
		string validatedInput = "";
		cout << "InputValidater" << endl;
		validatedInput = InputValidater();
		cout << "Validated : " << validatedInput << endl;

		//IsVowel
		cout << "IsVowel" << endl;
		cout << "a " << IsVowel('a') << endl;
		cout << "b " << IsVowel('b') << endl;
		cout << "i " << IsVowel('i') << endl;

		//VowelEraser
		cout << "VowelEraser" << endl;
		cout << "There : " << VowelEraser("There") << endl;
		cout << "Has Been a While : " << VowelEraser("Has Been a While") << endl;

		int close = 0;
		cin >> close;
	}
}