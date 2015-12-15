/*
 * Winner.h
 *
 *  Created on: Dec 7, 2015
 *      Author: David Hudkins II
 *     Purpose: Create Winner class to handle all data regarding the hangman
 *     	game. This class inherits two classes, Player and Word. The class
 *     	uses several character arrays for comparison and contains the actual
 *     	gameplay loop that executes to play and display the game hangman. After
 *     	the game is completed the class destructor is called.
 */

//System Libraries
#include <cstring>		//String operator library
#include <iomanip>		//Formatting library
#include <stdlib.h>		//For exit function
#include <new>			//Need for bad_alloc

//User Libraries
#include "Player.h"
#include "Word.h"

#ifndef WINNER_H_
#define WINNER_H_

class Winner : public Player, public Word
{
protected:
	//Variables to be utitlized by Winner class and derived classes
	int 	 choice;		//Menu choice
	int 	   path;		//Determines how program will execute
	int			end;	//Maximum number of moves
	int		 count1;	//Counter for correct guesses
	int		 count2;	//Counter for correct guesses
	int		 count3;	//Counter for number of guesses
	int		   flag;	//Flag for first phase to allow incorrect guess to increment
	int		 numWin;	//Holds the number of wins each player gets
	string 	wrdPlay;	//Word used to play hangman
	char	  *mark;	//Subscript of array already guessed correctly
	char 	  *word;	//Word used to play hangman
	char 	*prgrss;	//Keep track of game progression
	char   *guesses;	//Keep track of alphabetical guesses
	int		  chars;	//Number of characters in game word
	int	    incGues;	//Number of guesses player has made
	char	   quit;	//Choose to continue playing or quit
public:
	//Default Constructor
	Winner();

	//Accessor Functions
	int 	getChoic(){return choice;}
	void					hangMan();

	//Mutator Functions
	int 	 	  initGme(char[], char[]);
	void	  setChoic(int c){choice=c;}
	void 					plyGame();
	void 					   play();

	//Operator Overloading
	bool operator >(const Winner &other);

	//Destructor
	~Winner();
};

#endif /* WINNER_H_ */
