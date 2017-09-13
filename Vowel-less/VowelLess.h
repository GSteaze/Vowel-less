#ifndef VOWELLESS_H
#define VOWELLESS_H

using namespace std;

namespace vowelless
{
	/*
	Takes input from the user
	
	@return userInput the string input by the user
	*/
	string UserInput();

	/*
	Tests if the user input is valid

	@returns a valid string
	*/
	string InputValidater();

	/*
	Erases the group of character indicated by the user

	@param userInput the string input by the user
	@param the group selected by the user to be erased

	@return editedString the string with the selected group removed
	*/
	string Eraser(string userInput, int userSelection);

	/*
	Prompts the user if they would like to remove vowels, consonants, digits, or punctuation
	from the string
	*/
	int GroupSelector();

	/*
	Tests if a char is a vowel

	returns true if the given char is a vowel
	*/
	bool IsVowel(char letter);

	/*
	Tests if a char is a consonant

	returns true if the given char is a consonant
	*/
	bool IsConsonant(char letter);

	/*
	Tests if a char is a digit
	*/
	bool IsDigit(char letter);

	/*
	Tests if a char is punctuation
	*/
	bool IsPunctuation(char letter);

	/*
	Erases characters that are vowels from the string

	@param userInput the string input from the user
	@return removedVowels the string with all of the vowels removed
	*/
	string VowelEraser(string userInput);

	/*
	Erases characters that are consonants from the string

	@param userInput the string input from the user
	@return removedConsonants the string with all of the consonants removed
	*/
	string ConsonantEraser(string userInput);

	/*
	Erases characters that are digits from the string

	@param userInput the string input from the user
	@return removedDigits the string with all of the digits removed
	*/
	string DigitEraser(string userInput);

	/*
	Erases characters that are punctuation from the string

	@param userInput the string input from the user
	@return removedPunctuation the string with all of the punctuation removed
	*/
	string PunctuationEraser(string userInput);

	/*
	Erases characters that are punctuation from the string

	@param userInput the string input from the user
	@return removedPunctuation the string with all of the punctuation removed
	*/
	string CustomEraser(string userInput);

	/*
	Contains code to test functions
	*/
	void TestCode();
}
#endif