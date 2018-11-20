/*
	This is the console executable, that makes use of the BullCow class
	This acts as the view in a MVC pattern, and is responsible for all
	user interaction. For Game Logic, see the FBullCowGame class.
*/

#include "pch.h"
#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;

void PrintIntro();
void PlayGame();
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

	int MaxTries = BullCowGame.GetMaxTries();

	//Loop asking for Guesses while the game is not won and there are still tries remaining;.

	while(!BullCowGame.IsGameWon() && BullCowGame.GetCurrentTry() <= MaxTries){
		FText Guess = GetValidGuess(); //TODO Check guess on validity

		//Submit valid guess to the game
		FBullCowCount BullCowCount = BullCowGame.SubmitValidGuess(Guess);

		//Print number of Bulls and Cows
		std::cout << "Bulls: " << BullCowCount.Bulls;
		std::cout << ". Cows: " << BullCowCount.Cows << "\n\n";
	}		
	//TODO: summarize game. 
}

FText GetValidGuess()
{
	//Get a guess from the player
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	FText UserGuess = "";
	
	do
	{
		int CurrentTry = BullCowGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry; std::cout << ". Insert your guess here: ";
		getline(std::cin, UserGuess);

		Status = BullCowGame.CheckGuessValidity(UserGuess);
		switch (Status)
		{
			case EGuessStatus::Wrong_Length:
				std::cout << "Please enter a " << BullCowGame.GetHiddenWordLength() << " letter word. \n";
				break;

			case EGuessStatus::Not_Lowercase:
				std::cout << "Please only put input in lowercase! \n";
				break;

			case EGuessStatus::Not_An_Isogram:
				std::cout << "Please enter an isogram. \n";
				break;

			default:
				break;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK);
	return  UserGuess;
	//Keep looping until we get no errors
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)?";
	FText Response = "";
	getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}





