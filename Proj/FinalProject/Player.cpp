/*
 * Player.cpp
 *
 *  Created on: Dec 7, 2015
 *      Author: David
 */

#include "Player.h"

#ifndef PLAYER_CPP_
#define PLAYER_CPP_

/******************************************************************************
 * getInfo function accepts no parameters and asks user to input information
 * including their first and last name, as well as their state of residence.
 * It uses a structure PlyInfo to receive the players information. Enumerated
 * data type State is used to compare players choice of residence.
 ******************************************************************************/
void setInfo()
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



#endif /* PLAYER_CPP_ */
