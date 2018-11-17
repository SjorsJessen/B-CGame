#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame
{
public:
	FBullCowGame();//Constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;

	bool IsGameWon() const;
	bool CheckGuessValidity(FString) const;

	void Reset();
	
	
	// Provide a method for counting Bulls and Cows en incrementing try number.
	FBullCowCount SubmitGuess(FString);

private:
	//See constructor for initialization.
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};

