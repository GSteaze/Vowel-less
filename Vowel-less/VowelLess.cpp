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
		getline(cin, userInput, '\n');
		bool isInvalid = cin.fail() || userInput.empty();
		while (isInvalid) {
			cin.clear();
			cout << "Please enter a valid string." << endl
				<< "New input : ";
			getline(cin, userInput, '\n');
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

		bool isValid = false;
		int userSelection = 0;
		while (!isValid) {
			cin >> userSelection;
			if (userSelection >= 1 || userSelection >= 5) {
				return userSelection;
			} else {
				cin.clear();
				cout << "Selection must be a number between 1 and 5. Please try again : ";
				cin >> userSelection;
				isValid = (userSelection >=1 || userSelection <= 5);
			}
		}
		return userSelection;
	}

	string Eraser(string userInput, int userSelection) {
		string editedString = "";

		switch (userSelection) {
		case 1: return editedString = VowelEraser(userInput);
			break;
		case 2: return editedString = ConsonantEraser(userInput);
			break;
		case 3: return editedString = DigitEraser(userInput);
			break;
		case 4: return editedString = PunctuationEraser(userInput);
			break;
		case 5: return editedString = CustomEraser(userInput);
			break;
		default: cout << "Invalid Selection." << endl;
		}

		/*if (userSelection == 1) {
			return editedString = VowelEraser(userInput);
		}
		else if (userSelection == 2) {
			return editedString = ConsonantEraser(userInput);
		}
		else if (userSelection == 3) {
			return editedString = DigitEraser(userInput);
		}
		else if (userSelection == 4) {
			return editedString = PunctuationEraser(userInput);
		}
		else if (userSelection == 5) {
			return editedString = CustomEraser(userInput);
		}
		else {
			cout << "Invalid Selection." << endl;
		}*/

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
		if (!IsVowel(letter) && !IsDigit(letter) && !IsPunctuation(letter)) {
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
		if ((letter > ' ') && (letter < '0')) {
			return true;
		}
		else if ((letter > '9') && (letter < 'A')) {
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

	bool IsCustom(char letter, char customGroup[], int numberOfCharacters) {
		for (int i = 0; i < numberOfCharacters; i++) {
			if (customGroup[i] == letter) {
				return true;
			}
		}
		return false;
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
			customGroup[i] = customCharacter;
		}

		string removedCustom = "";
		for (int i = 0; i < userInput.length(); i++) {
			if (!IsCustom(userInput[i], customGroup, numberOfCharacters)) {
				removedCustom.append(userInput, i, 1);
			}
		}
		return removedCustom;
	}

	void TestCode() {
		//GroupSelector
		cout << "Group Selector" << endl;
		int userSelection = GroupSelector();
		cout << userSelection << endl;


		//Eraser
		cout << "Eraser" << endl;
		cout << "Banana : " << Eraser("Banana", 1) << endl;
		cout << "Banana : " << Eraser("Banana", 2) << endl;
		cout << "Banana : " << Eraser("Banana", 3) << endl;
		cout << "Banana : " << Eraser("Banana", 4) << endl;
		cout << "Banana : " << Eraser("Banana", 5) << endl;

		//IsVowel
		cout << "IsVowel" << endl;
		cout << "a " << IsVowel('a') << endl;
		cout << "b " << IsVowel('b') << endl;
		cout << "i " << IsVowel('i') << endl;
		cout << "1 " << IsVowel('1') << endl;


		//IsConsonant
		cout << "IsConsonant" << endl;
		cout << "a " << IsConsonant('a') << endl;
		cout << "b " << IsConsonant('b') << endl;
		cout << "! " << IsConsonant('!') << endl;
		cout << "1 " << IsConsonant('1') << endl;



		//IsDigit
		cout << "IsDigit" << endl;
		cout << "a " << IsDigit('a') << endl;
		cout << "b " << IsDigit('b') << endl;
		cout << "! " << IsDigit('!') << endl;
		cout << "1 " << IsDigit('1') << endl;

		//IsPunctuation
		cout << "IsPunctuation" << endl;
		cout << "a " << IsPunctuation('a') << endl;
		cout << "b " << IsPunctuation('b') << endl;
		cout << "! " << IsPunctuation('!') << endl;
		cout << "1 " << IsPunctuation('1') << endl;

		//VowelEraser
		cout << "VowelEraser" << endl;
		cout << "There : " << VowelEraser("There") << endl;
		cout << "Has Been a While : " << VowelEraser("Has Been a While") << endl;

		//ConsonantEraser
		cout << "Consonant Eraser" << endl;
		cout << "There : " << ConsonantEraser("There") << endl;
		cout << "Has Been a While : " << ConsonantEraser("Has Been a While") << endl;


		//DigitEraser
		cout << "Digit Eraser" << endl;
		cout << "Th1e45re : " << DigitEraser("Th1e45re") << endl;
		cout << "Ha4s Be657en a5 Wh6ile : " << DigitEraser("Ha4s Be657en a5 Wh6ile") << endl;

		//PunctuationEraser
		cout << "Punctuation Eraser" << endl;
		cout << "T!her@e. : " << PunctuationEraser("T!her@e.") << endl;
		cout << "Ha.s Be,en a Wh?ile! : " << PunctuationEraser("Ha.s Be,en a Wh?ile!") << endl;

		//CustomerEraser
		cout << "Customer Eraser" << endl;
		cout << "T!her@e. : " << CustomEraser("T!her@e.") << endl;
		cout << "Ha.s Be,en a Wh?ile! : " << CustomEraser("Ha.s Be,en a Wh?ile!") << endl;

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

		

		

		int close = 0;
		cin >> close;
	}
}