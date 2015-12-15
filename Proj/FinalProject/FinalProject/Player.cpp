/*
 * Player.cpp
 *
 *  Created on: Dec 7, 2015
 *      Author: David Hudkins II
 *     Purpose: Define the member functions of the Player class.
 */

#include "Player.h"

#ifndef PLAYER_CPP_
#define PLAYER_CPP_

/******************************************************************************
 * Player function is the constructor for the Player class
 ******************************************************************************/
Player::Player()
{
	win	   = 0;
	diff =   0;
	name = "0";
}

/******************************************************************************
 * rules function accepts no parameters and displays the rules to the
 * game Hangman.
 ******************************************************************************/
void Player::rules()
{
	//Display Rules
	cout << "Welcome to Hangman!" << endl << endl;
	cout << "Game Rules:" << endl << endl;
	cout << "\t- Choose a word" << endl;
	cout << "\t- Enter letters ONLY (not case sensitive) for guesses" << endl;
	cout << "\t- Each guess will be either valid or invalid" << endl;
	cout << "\t- Valid choices will display a letter of the word" << endl;
	cout << "\t in its respective postition in the word." << endl;
	cout << "\t- Invalid choices will add a body part to the " <<endl;
	cout << "\t hangman figure. A complete hangman is 3 incorrect" << endl;
	cout << "\t guesses in easy mode, 5 incorrect guesses in normal" << endl;
	cout << "\t mode, and 7 incorrect guesses in hard mode, and will" << endl;
	cout << "\t end the game." << endl << endl;
}

/******************************************************************************
 * shwMenu function accepts no parameters and displays the menu for the game
 * hangman. The player makes an integer choice through input and the function
 * returns that integer to the calling function.
 ******************************************************************************/
int Player::shwMenu()
{
	int choose;
	//Display Menu
	do
	{
		//Prompt user to input integer from menu
		cout << "Please input the corresponding integer to the" << endl;
		cout << "path you would like to choose: " << endl << endl;
		cout << "(1)Allow computer to choose word" << endl;
		cout << "(2)Input a word of your own for somebody else to play" << endl;
		cout << "(3)Quit" << endl;
		cin >> choose;				//INPUT- Menu choice

		//Validate input
		while(!cin >> choose)		//Execute while input is broken
		{
			cin.clear();			//Clear keyboard buffer
			cin.ignore(1000,'\n');	//Ignore characters until whitespace
			cout << "Incorrect input. Please use an integer." << endl << endl;	//Inform user of invalid input
			cin >> choose;
		}
	}while(choose != 1 && choose != 2 && choose != 3); //Execute until menu choice is valid

	//Return menu choice to calling function
	return choose;
}

/******************************************************************************
 * getInfo function accepts no parameters and asks user to input information
 * including their first and last name, as well as their state of residence.
 * It uses a structure PlyInfo to receive the players information. Enumerated
 * data type State is used to compare players choice of residence.
 ******************************************************************************/
void Player::setInfo()
{
	PlyInfo Info;		//Contains information about the player
	string locatn;		//Players geographical location

	cout << "Please input your first and last name separated by a space: ";
	cin >> Info.fstName;												   //INPUT- User's first name
	cin >> Info.lstName;												   //INPUT- User's last name
	cout << "\nWhat state are you from?" << endl;
	cout << "\t(0)California" << endl << "\t(1)Other" << endl << "\t(2)Not from USA\n";
	cin >> Info.where;													   //INPUT- User location

	//Loop until input is not broken
	while(!cin >> Info.where  || Info.where > 2 || Info.where < 0)
	{
		cin.clear();														//Clear keyboard buffer
		cin.ignore(1000,'\n');												//Ignore characters until whitespace
		cout << "Incorrect input. Please use an integer." << endl << endl;	//Inform user of invalid input
		cin >> Info.where;													//INPUT- User location
	}

	//Execute if user entered California location
	if(Info.where == CALIFORNIA)
		locatn = "California";		//Set location to California
	//Execute if user entered other location
	else if(Info.where == OTHER)
	{
		//Prompt user to enter their state
		cout << "What state are you from then? " << endl;
		cin.ignore(1000,'\n');		//Ignore until whitespace
		getline(cin,locatn);		//INPUT- User location
	}
	//Execute if user entered out of country
	else if(Info.where == NOTINUSA)
	{
		//Prompt user to enter their country
		cout << "What country are you from then?" << endl;
		cin.ignore(1000,'\n');		//Ignore until whitespace
		getline(cin,locatn);		//INPUT- User location
	}
	//Execute if erroneous input was chosen
	else
	{
		//Prompt user to enter their planet
		cout << "If you aren't from the U.S. or any other location on this" << endl;
		cout << " planet, then you must be an alien. What planet are you" << endl;
		cout << " from, alien scum: " << endl;
		cin.ignore(1000,'\n');		//Ignore until whitespace
		getline(cin,locatn);		//INPUT- User location
	}
	//Inform user of game start
	cout << "Okay " << Info.fstName << " " << Info.lstName << " from ";
	cout << locatn << ", lets play Hangman!" << endl << endl;
}

void Player::gmMode()
{
	//Display options and prompt user for desired difficulty
	cout<<"Enter the level of difficulty you would like: "<<endl;
	cout<<"\t(1)Easy: Small words / 3 incorrect guesses"<<endl;
	cout<<"\t(2)Normal: Large words / 5 incorrect guesses"<<endl;
	cout<<"\t(3)Hard: Good luck / 7 incorrect guesses"<<endl;
	cin>>diff;		//INPUT- Difficulty level

	//Validate input
	while(!cin >> diff)
	{
		cin.clear();														//Clear keyboard buffer
		cin.ignore(1000,'\n');												//Ignore characters until whitespace
		cout << "Incorrect input. Please use an integer." << endl << endl;	//Inform user of invalid input
		cin >> diff;														//INPUT- Difficulty setting
	}
}

/******************************************************************************
 * ~Player function is the destructor for the Player class
 ******************************************************************************/
Player::~Player(){}

#endif /* PLAYER_CPP_ */
