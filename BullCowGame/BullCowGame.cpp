#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	//Introduce the game
	constexpr int WORLD_LENGTH = 9;

    cout << "Welcome to Bulls and Cows, a fun game." << endl;
    cout << "Can you guess the " << WORLD_LENGTH << " letter word I am looking for?" << endl;

	//Get a guess from the player
	string Guess = "";
	
	cout << "Insert your guess here: "; 
	getline(cin, Guess);
	
	//Repeat the guess back to them.
	cout << "Your guess was: " << Guess << endl;


	//Get a guess from the player
	cout << "Insert your guess here: ";
	getline(cin, Guess);

	//Repeat the guess back to them.
	cout << "Your guess was: " << Guess << endl;

	return 0;
}


