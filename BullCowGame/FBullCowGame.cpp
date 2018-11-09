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
