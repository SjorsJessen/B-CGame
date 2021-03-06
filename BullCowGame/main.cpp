/*
	This is the console executable, that makes use of the BullCow class
	This acts as the view in a MVC pattern, and is responsible for all
	user interaction. For Game Logic, see the FBullCowGame class.
*/
#include "pch.h"
#pragma once

#include <iostream>
#include <string>
#include "FBullCowGame.h"

//Defined this way to make syntax Unreal Engine friendly
using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
void PrintGameSummary();
FText GetValidGuess();
bool AskToPlayAgain();

FBullCowGame BullCowGame;

//Entry point for our application.
int main()
{
	bool bPlayAgain = false;
	do
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} 
	while (bPlayAgain);

	return 0;
}

void PrintIntro()
{
	std::cout << "Welcome to Bulls and Cows, a fun game." << std::endl;
	std::cout << "Can you guess the " << BullCowGame.GetHiddenWordLength() << " letter word I am looking for?" << "\n\n";
}

void PlayGame()
{
	BullCowGame.Reset();

	const int max_tries = BullCowGame.GetMaxTries();

	//Loop asking for Guesses while the game is not won and there are still tries remaining;.

	while(!BullCowGame.IsGameWon() && BullCowGame.GetCurrentTry() <= max_tries){
		const FText guess = GetValidGuess(); 

		//Submit valid guess to the game
		const FBullCowCount bull_cow_count = BullCowGame.SubmitValidGuess(guess);

		//Print number of Bulls and Cows
		std::cout << "Bulls: " << bull_cow_count.Bulls;
		std::cout << ". Cows: " << bull_cow_count.Cows << "\n\n";
	}		
	PrintGameSummary();
}

void PrintGameSummary()
{
	FString const WonGameScenario = "You Won Bulls And Cows! Congratulations.";
	FString const LostGameScenario = "You Lost! Want to try again with the same hidden word?";

	if (BullCowGame.IsGameWon())
	{
		std::cout << WonGameScenario;
		std::cout << std::endl;
	}

	else
	{
		std::cout << LostGameScenario;
		std::cout << std::endl;
	}
}

FText GetValidGuess()
{
	//Get a guess from the player
	EGuessStatus status;
	FText user_guess = "";
	
	do
	{
		const int current_try = BullCowGame.GetCurrentTry();
		std::cout << "Try " << current_try << " of " << BullCowGame.GetMaxTries();
		std::cout << ". Insert your guess here: ";
		getline(std::cin, user_guess);

		status = BullCowGame.CheckGuessValidity(user_guess);
		switch (status)
		{
			case EGuessStatus::Wrong_Length:
				std::cout << "Please enter a " << BullCowGame.GetHiddenWordLength() << " letter word. \n\n";
				break;

			case EGuessStatus::Not_Lowercase:
				std::cout << "Please only put input in lowercase! \n\n";
				break;

			case EGuessStatus::Not_An_Isogram:
				std::cout << "Please enter an isogram. \n\n";
				break;

			default:
				break;
		}
	} while (status != EGuessStatus::OK);
	return  user_guess;
	//Keep looping until we get no errors
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)?";
	FText response = "";
	getline(std::cin, response);

	return (response[0] == 'y') || (response[0] == 'Y');
}





