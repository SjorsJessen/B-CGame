#pragma once
#include <string>

class FBullCowGame
{
public:
	FBullCowGame();//Constructor

	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset();
	bool CheckGuessValidity(std::string);
	// Provide a method for counting Bulls and Cows en incrementing try number.

private:
	//See constructor for initialization.
	int MyCurrentTry;
	int MyMaxTries;
};

