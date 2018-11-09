#include "pch.h"
#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
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
	constexpr int word_length = 9;

	std::cout << "Welcome to Bulls and Cows, a fun game." << std::endl;
	std::cout << "Can you guess the " << word_length << " letter word I am looking for?" << std::endl;
	std::cout << std::endl;
}

void PlayGame()
{
	BullCowGame.Reset();

	int MaxTries = BullCowGame.GetMaxTries();

	for (int count = 0; count <= MaxTries; count++)
	{
		std::string Guess = GetGuess(); //TODO Check guess on validity

		//Submit valid guess to the game
		//Print number of Bulls and Cows

		std::cout << "Your guess was: " << Guess; 
		std::cout << std::endl;
	}

	//TODO: summarize game. 
}

std::string GetGuess()
{
	//Get a guess from the player
	int CurrentTry = BullCowGame.GetCurrentTry();
	std::cout << "Try " << CurrentTry; std::cout << ". Insert your guess here: ";
	std::string user_guess = "";
	getline(std::cin, user_guess);

	return user_guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)?";
	std::string Response = "";
	getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}





