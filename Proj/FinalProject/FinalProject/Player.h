/*
 * Player.h
 *
 *  Created on: Dec 1, 2015
 *      Author: David Hudkins II
 *     Purpose: Create a class Player to keep track of game player's data
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
	//Variables
	bool 	   win;
	string    name;
	int    	  diff;
public:
    Player();
	void   rules();
	void setInfo();
	int  shwMenu();
	void  gmMode();
	int  getMode(){return diff;}
};

#endif /* PLAYER_H_ */
