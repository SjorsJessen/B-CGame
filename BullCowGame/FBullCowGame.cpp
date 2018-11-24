#include "pch.h"
#pragma once

#include "FBullCowGame.h"
#include <map>

#define TMap std::map

using int32 = int;

FBullCowGame::FBullCowGame() //Default constructor 
{
	Reset();
}

void FBullCowGame::Reset()
{
	const int32 my_current_try = 1;
	MyCurrentTry = my_current_try;

	MyHiddenWord = "planet"; //This must be an isogram!
	bWonGame = false;
}
	
int32 FBullCowGame::GetCurrentTry() const{ return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const{ return MyHiddenWord.length(); }
int32 FBullCowGame::GetMaxTries() const
{
	TMap<int32, int32> HiddenWordLengthToMaxTries{{3,5}, {4,6}, {5,8}, {6,10}, {7,15}, {8,20}};
	return HiddenWordLengthToMaxTries[GetHiddenWordLength()];
}

bool FBullCowGame::IsGameWon() const{ return bWonGame; }
bool FBullCowGame::IsIsogram(FString Word) const
{
	//treat 0 and 1 letters words as isograms
	if (Word.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen;
	
	for (auto Letter : Word)
	{
		Letter = tolower(Letter);
		//loop through all letters of the word
		if(LetterSeen[Letter])
		{
			return false;
		}
		LetterSeen[Letter] = true;
	}
	return true; // for example in cases where \0 is entered as a guess
}

bool FBullCowGame::IsLowercase(FString word) const
{
	for (auto Letter : word)
	{
		if (!islower(Letter))
		{
			return false;
		}
	}
	return true; 
}

//Error checking code!
EGuessStatus FBullCowGame::CheckGuessValidity(FString user_guess) const
{
	if(!IsIsogram(user_guess))
	{
		return EGuessStatus::Not_An_Isogram;
	}
	if (!IsLowercase(user_guess))
	{
		return EGuessStatus::Not_Lowercase;
	}
	if(user_guess.length() != GetHiddenWordLength())
	{
		return EGuessStatus::Wrong_Length;
	}
	return EGuessStatus::OK; 
}

//Receives a VALID guess, increments turn, and returns count.
FBullCowCount FBullCowGame::SubmitValidGuess(FString user_guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	const int32 word_length = MyHiddenWord.length();

	for (int32 HiddenWordCharacter = 0; HiddenWordCharacter < word_length; HiddenWordCharacter++)
	{
		for (int32 GuessCharacter = 0; GuessCharacter < word_length; GuessCharacter++)
		{
			if (user_guess[GuessCharacter] == MyHiddenWord[HiddenWordCharacter])
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
	if (BullCowCount.Bulls == word_length)
	{
		bWonGame = true;
	}
	else
	{
		bWonGame = false;
	}
	return BullCowCount;
}


