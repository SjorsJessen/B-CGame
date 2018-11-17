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
FText GetGuess();
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
	std::cout << "Can you guess the " << BullCowGame.GetHiddenWordLength() << " letter word I am looking for?" << std::endl;
	std::cout << std::endl;
}

void PlayGame()
{
	BullCowGame.Reset();

	int MaxTries = BullCowGame.GetMaxTries();

	for (int count = 0; count <= MaxTries; count++)
	{
		FText Guess = GetGuess(); //TODO Check guess on validity

		//Submit valid guess to the game
		FBullCowCount BullCowCount = BullCowGame.SubmitGuess(Guess);


		//Print number of Bulls and Cows
		std::cout << "Bulls: " << BullCowCount.Bulls; 
		std::cout << ". Cows: " << BullCowCount.Cows << std::endl; 
		std::cout << std::endl;
	}

	//TODO: summarize game. 
}

FText GetGuess()
{
	//Get a guess from the player
	int CurrentTry = BullCowGame.GetCurrentTry();
	std::cout << "Try " << CurrentTry; std::cout << ". Insert your guess here: ";
	FText user_guess = "";
	getline(std::cin, user_guess);

	return user_guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)?";
	FText Response = "";
	getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}





