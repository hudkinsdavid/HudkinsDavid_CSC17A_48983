/*
 * main.cpp
 *
 *  Created on: Oct 13, 2015
 *      Author: David Hudkins II
 *  Purpose: Execute the game hangman. User chooses either computer generated
 *  	word or the user chooses to input their own word. User then guesses
 *  	letters until word is completely deciphered or fails 6 times and
 *  	the hangman character is completed and the game is over.
 */

//System Libraries

//User Libraries
#include "Winner.h"

//Function Prototypes

//Global Constants

//Program Execution
int main()
{
	//Declare Variables
	Winner p1;
	Winner p2;
	int numPs;

	//Ask user one or two players
	cout<<"One or two players?";
	cin>>numPs;			//INPUT- number of players

	//Validate input
	while(!cin >> numPs || numPs<1 || numPs>2)								//Execute while input is broken
	{
		cin.clear();			//Clear keyboard buffer
		cin.ignore(1000,'\n');	//Ignore characters until whitespace
		cout << "Incorrect input. Please use an integer." << endl << endl;	//Inform user of invalid input
		cin>>numPs;
	}

	//Show game rules
	p1.rules();

	//Get information from user for game initialization
	p1.setInfo();

	//Play the game
	p1.plyGame();

	if(numPs==2)
	{
		//Show game rules
		p2.rules();

		//Get information from user for game initialization
		p2.setInfo();

		//Play the game
		p2.plyGame();

		//Tell users which player had more number of wins in the hangman games
		if(p2>p1)
			cout<<"Player 2 has more wins!";
		else
			cout<<"Player 1 has more wins!";
	}

	return 0;	//Terminate Program
}
