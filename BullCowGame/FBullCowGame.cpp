#include "pch.h"
#include "FBullCowGame.h"
#include <iostream>

using int32 = int;

FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	int32 MY_MAX_TRIES = 8;
	int32 MY_CURRENT_TRY = 1;

	MyMaxTries = MY_MAX_TRIES;	
	MyCurrentTry = MY_CURRENT_TRY;	
	MyHiddenWord = "planet";
	bWonGame = false;
}
	
int32 FBullCowGame::GetMaxTries() const{ return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const{ return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const{ return MyHiddenWord.length(); }
bool  FBullCowGame::IsGameWon() const{ return bWonGame; }

//Error checking code!
EGuessStatus FBullCowGame::CheckGuessValidity(FString UserGuess) const
{
	FBullCowCount BullCowCount;
	
	if(false)
	{
		return EGuessStatus::Not_An_Isogram;
	}
	else if (false)
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if(UserGuess.length() != GetHiddenWordLength())
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK; //TODO Make actual error	
	}
	
}

//Receives a VALID guess, increments turn, and returns count.
FBullCowCount FBullCowGame::SubmitValidGuess(FString UserGuess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	FBullCowGame BullCowGame;
	int32 WordLength = MyHiddenWord.length();

	for (int32 HiddenWordCharacter = 0; HiddenWordCharacter < WordLength; HiddenWordCharacter++)
	{
		for (int32 GuessCharacter = 0; GuessCharacter < WordLength; GuessCharacter++)
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
	if (BullCowCount.Bulls == WordLength)
	{
		bWonGame = true;
	}
	else
	{
		bWonGame = false;
	}
	return BullCowCount;
}
