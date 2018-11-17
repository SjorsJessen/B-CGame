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
	constexpr int MY_CURRENT_TRY = 1;
	const FString HIDDEN_WORD = "Planet";

	MyMaxTries = MAX_TRIES;	
	MyCurrentTry = MY_CURRENT_TRY;	
	MyHiddenWord = HIDDEN_WORD;
	return;
}
	
int32 FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

int32 FBullCowGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}


EWordStatus FBullCowGame::CheckGuessValidity(FString) const
{
	return EWordStatus::OK; //TODO Make actual error
}

//Receives a VALID guess, increments turn, and returns count.
FBullCowCount FBullCowGame::SubmitGuess(FString UserGuess)
{
	//Increment the turn number
	MyCurrentTry++;

	//Setup a return variable
	FBullCowCount BullCowCount;
	
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 HiddenWordCharacter = 0; HiddenWordCharacter < HiddenWordLength; HiddenWordCharacter++)
	{
		for (int32 GuessCharacter = 0; GuessCharacter < HiddenWordLength; GuessCharacter++)
		{
			if (UserGuess[GuessCharacter] == MyHiddenWord[HiddenWordCharacter])
			{
				if(HiddenWordCharacter == GuessCharacter)
				{
					BullCowCount.Bulls++;
				}
				else
				{
					BullCowCount.Cows++;
				}
			}
		}		
	}
	return BullCowCount;
}
