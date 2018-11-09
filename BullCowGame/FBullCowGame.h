#pragma once
#include <string>

using FString = std::string;
using int32 = int;

class FBullCowGame
{
public:
	FBullCowGame();//Constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset();
	bool CheckGuessValidity(FString);
	// Provide a method for counting Bulls and Cows en incrementing try number.

private:
	//See constructor for initialization.
	int32 MyCurrentTry;
	int32 MyMaxTries;
};

