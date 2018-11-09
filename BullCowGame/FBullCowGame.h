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

private:
	//See constructor for initialization.
	int MyCurrentTry;
	int MyMaxTries;
};

