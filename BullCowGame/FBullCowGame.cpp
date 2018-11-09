#include "pch.h"
#include "FBullCowGame.h"

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
	
int FBullCowGame::GetMaxTries() const
{

	return MyMaxTries;
}

int FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}


bool FBullCowGame::CheckGuessValidity(std::string)
{
	return false;
}
