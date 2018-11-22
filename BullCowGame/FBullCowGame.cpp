#include "pch.h"
#include "FBullCowGame.h"
#include <map>
#define TMap std::map

using int32 = int;

FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	const int32 my_max_tries = 8;
	const int32 my_current_try = 1;

	MyMaxTries = my_max_tries;	
	MyCurrentTry = my_current_try;	
	MyHiddenWord = "planet";
	bWonGame = false;
}
	
int32 FBullCowGame::GetMaxTries() const{ return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const{ return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const{ return MyHiddenWord.length(); }

bool  FBullCowGame::IsGameWon() const{ return bWonGame; }
bool  FBullCowGame::IsIsogram(FString) const
{
	//treat 0 and 1 letters words as isograms

	//Get input char and boolean to set up Tmap
		//Loop through all the letters the word consists of (word length) and add them as a char to the Tmap
			//Check all letters linear in alphabetic order and add +1 for each letter which is part of the word
				//Check if there are duplicate letters. If so, add another +1 and return false when 2 (1+1)
					//Word is not an Isogram, leave loop
				//If no duplicates, return that the word is an isogram and thus is a valid guess.
		
	return true; // for example in cases where /0 is entered as a guess
}

//Error checking code!
EGuessStatus FBullCowGame::CheckGuessValidity(FString UserGuess) const
{
	if(!IsIsogram(UserGuess))
	{
		return EGuessStatus::Not_An_Isogram;
	}
	
	else if (false)
	{
		return EGuessStatus::Not_Lowercase; //TODO: Write function for analyzing is letters are lowercase
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


