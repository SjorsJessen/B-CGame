#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();


//Entry point for our application.
int main()
{
	PrintIntro();
	PlayGame();
	
	return 0;
}

void PrintIntro()
{
	constexpr int word_length = 9;

	cout << "Welcome to Bulls and Cows, a fun game." << endl;
	cout << "Can you guess the " << word_length << " letter word I am looking for?" << endl;
	cout << endl;
	return;
}

void PlayGame()
{
	constexpr int possible_guesses = 4;

	for (int count = 0; count <= possible_guesses; count++)
	{
		string Guess = GetGuess();
		cout << "Your guess was: " << Guess;
		cout << endl;
	}
}

string GetGuess()
{
	//Get a guess from the player
	cout << "Insert your guess here: ";
	string user_guess = "";
	getline(cin, user_guess);
	return user_guess;
}





