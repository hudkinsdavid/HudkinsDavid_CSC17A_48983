/*
 * Player.h
 *
 *  Created on: Dec 1, 2015
 *      Author: David Hudkins II
 *     Purpose: Create a class Player to keep track of game player's data
 *     	which includes their name and location. This class also handles the
 *     	difficulty level of the game that the user chooses.
 */

#include<iostream>		//Console input/output streaming library
#include <string>		//Allows use of string class
using namespace std;	//Utilize standard namespace

//Structures
enum State {CALIFORNIA, OTHER, NOTINUSA};	//Data type for location

struct PlyInfo		//Player information structure
{
	string fstName;	//Player first name
	string lstName;	//Player last name
	int 	 where;	//Player location
};

#ifndef PLAYER_H_
#define PLAYER_H_

class Player
{
protected:
	//Variables to be utilized by class Player and derived classes
	bool 	   win;
	string    name;
	int    	  diff;
public:
	//Default Constructor
    Player();

    //Accessor Functions
	void   rules();
	int  shwMenu();
	int  getMode(){return diff;}

	//Mutator Functions
	void setInfo();
	void  gmMode();

	//Destructor
	~Player();
};

#endif /* PLAYER_H_ */
