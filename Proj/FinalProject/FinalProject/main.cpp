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

	//Show game rules
	p1.rules();

	//Get information from user for game initialization
	p1.setInfo();

	//Play the game
	p1.plyGame();

	return 0;	//Terminate Program
}
