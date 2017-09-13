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

	int GroupSelector() {
		cout << "Which group of characters would you like to remove?" << endl
			<< "1. Vowels" << endl
			<< "2. Consonants" << endl
			<< "3. Digits" << endl
			<< "4. Punctuation" << endl
			<< "5. Custom" << endl;

		bool isInvalid = true;
		int userSelection = 0;
		while (isInvalid) {
			cin >> userSelection;
			if (cin.fail() || (userSelection < 1 || userSelection > 5))
			{
				cin.clear();
				cout << "Selection must be a number between 1 and 5. Please try again : ";
				cin >> userSelection;
				isInvalid = (cin.fail() || (userSelection < 1 || userSelection > 5));
			}
		}
		return userSelection;
	}

	string Eraser(string userInput, int userSelection) {
		string editedString = "";
		//switch (userSelection) {
		//case 1: return editedString = VowelEraser(userInput);
		//case 2: return editedString = ConsonantEraser(userInput);
		//case 3: return editedString = DigitEraser(userInput);
		//case 4: return editedString = PunctuationEraser(userInput);
		//case 5: return editedString = CustomEraser(userInput);
		//default: cout << "Invalid Selection." << endl;
		//}

		if (userSelection = 1) {
			return editedString = VowelEraser(userInput);
		}
		else if (userSelection = 2) {
			return editedString = ConsonantEraser(userInput);
		}
		else if (userSelection = 3) {
			return editedString = DigitEraser(userInput);
		}
		else if (userSelection = 4) {
			return editedString = PunctuationEraser(userInput);
		}
		else if (userSelection = 5) {
			return editedString = CustomEraser(userInput);
		}
		else {
			cout << "Invalid Selection." << endl;
		}

		return editedString;
	}

	
	bool IsVowel(char letter) {
		if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u' ||
			letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U') {
			return true;
		}
		else {
			return false;
		}

	}

	bool IsConsonant(char letter) {
		if (!IsVowel && !IsDigit && !IsPunctuation) {
			return true;
		}
		else {
			return false;
		}
	}

	bool IsDigit(char letter) {
		if (letter > '0' && letter < '9') {
			return true;
		}
		else {
			return false;
		}
	}

	bool IsPunctuation(char letter) {
		if ((letter > ' ' && letter < '0') || (letter > '9' && letter < 'A')) {
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

	string ConsonantEraser(string userInput) {
		string removedConsonants = "";
		for (int i = 0; i < userInput.length(); i++) {
			if (!IsConsonant(userInput[i])) {
				removedConsonants.append(userInput, i, 1);
			}
		}

		return removedConsonants;
	}

	string DigitEraser(string userInput) {
		string removedDigits = "";
		for (int i = 0; i < userInput.length(); i++) {
			if (!IsDigit(userInput[i])) {
				removedDigits.append(userInput, i, 1);
			}
		}

		return removedDigits;
	}

	string PunctuationEraser(string userInput) {
		string removedPunctuation = "";
		for (int i = 0; i < userInput.length(); i++) {
			if (!IsPunctuation(userInput[i])) {
				removedPunctuation.append(userInput, i, 1);
			}
		}

		return removedPunctuation;
	}

	string CustomEraser(string userInput) {
		cout << "How many characters would you like to enter? : ";
		int numberOfCharacters = 0;
		cin >> numberOfCharacters;
		cout << "Enter the characters that you would like to erase." << endl;
		
		char customGroup[100];
		for (int i = 0; i < 100; i++) {
			customGroup[i] = ' ';
		}

		char customCharacter = ' ';
		for (int i = 0; i < numberOfCharacters; i++) {
			cout << "Character " << i + 1 << " : ";
			cin >> customCharacter;
		}

		string removedCustom = "";
		for (int i = 0; i < userInput.length(); i++) {
			bool isCustom = false;
			for (int j = 0; j < numberOfCharacters; j++) {
				if (customGroup[j] == userInput[i]) {
					isCustom = true;
			}
			}
				if (isCustom) {
					removedCustom.append(userInput, i, 1);
				}
		}

		return removedCustom;
	}

	void TestCode() {

		//Eraser
		cout << "Eraser" << endl;
		cout << "Banana : " << Eraser("Banana", 1) << endl;
		cout << "Banana : " << Eraser("Banana", 2) << endl;
		cout << "Banana : " << Eraser("Banana", 3) << endl;
		cout << "Banana : " << Eraser("Banana", 4) << endl;
		cout << "Banana : " << Eraser("Banana", 5) << endl;

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

		//GroupSelector
		cout << "Group Selector" << endl;
		int userSelection = GroupSelector();
		cout << userSelection << endl;

		

		int close = 0;
		cin >> close;
	}
}