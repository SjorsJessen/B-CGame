#include "pch.h"
#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	constexpr int MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	constexpr int MY_CURRENT_TRY = 1;
	MyCurrentTry = MY_CURRENT_TRY;

	const FString HIDDEN_WORD = "Planet";
	MyHiddenWord = HIDDEN_WORD;
}
	
int32 FBullCowGame::GetMaxTries() const
{

	return MyMaxTries;
}

int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}


bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}

//Receives a VALID guess, increments turn, and returns count.
FBullCowCount FBullCowGame::SubmitGuess(FString)
{
	//Increment the turn number
	MyCurrentTry++;

	//Setup a return variable

	FBullCowCount BullCowCount;

	//Loop through all letters in the guess
	//Compare letters against the hidden word
	

	return BullCowCount;
}
