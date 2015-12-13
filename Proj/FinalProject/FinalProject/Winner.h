/*
 * Winner.h
 *
 *  Created on: Dec 7, 2015
 *      Author: David
 */

#include <cstring>		//String operator library
#include "Player.h"
#include "Word.h"

#ifndef WINNER_H_
#define WINNER_H_

class Winner : protected Player,Word
{
protected:
	int 	 choice;	//Menu choice
	int 	   path;	//Determines how program will execute
	int			end;	//Maximum number of moves
	string 	wrdPlay;	//Word used to play hangman
	char 	  *word;	//Word used to play hangman
	char 	*prgrss;	//Keep track of game progression
	int		  chars;	//Number of characters in game word
	int	   *incGues;	//Number of guesses player has made
	char	   quit;	//Choose to continue playing or quit
public:
	Winner();
	int initGme(char[], char[]);
	void plyGame();
	void play();
};

#endif /* WINNER_H_ */
