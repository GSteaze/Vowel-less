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
	Tests if a char is a vowel

	returns true if the given char is a vowel
	*/
	bool IsVowel(char letter);

	/*
	Erases any char that are vowels from the string

	@param userInput the string input from the user
	@return removedVowels the string with all of the vowels removed
	*/
	string VowelEraser(string userInput);

	/*
	Contains code to test functions
	*/
	void TestCode();
}
#endif