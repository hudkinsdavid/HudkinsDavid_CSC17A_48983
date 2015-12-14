/*
 * Winner.h
 *
 *  Created on: Dec 7, 2015
 *      Author: David
 */

#include <cstring>		//String operator library
#include <iomanip>		//Formatting library
#include "Player.h"
#include "Word.h"

#ifndef WINNER_H_
#define WINNER_H_

class Winner : public Player, public Word
{
protected:
	int 	 choice;	//Menu choice
	int 	   path;	//Determines how program will execute
	int			end;	//Maximum number of moves
	int		 count1;	//Counter for correct guesses
	int		 count2;	//Counter for correct guesses
	int		 count3;	//Counter for number of guesses
	int		   flag;	//Flag for first phase to allow incorrect guess to increment
	string 	wrdPlay;	//Word used to play hangman
	char	  *mark;	//Subscript of array already guessed correctly
	char 	  *word;	//Word used to play hangman
	char 	*prgrss;	//Keep track of game progression
	char   *guesses;	//Keep track of alphabetical guesses
	int		  chars;	//Number of characters in game word
	int	    incGues;	//Number of guesses player has made
	char	   quit;	//Choose to continue playing or quit
public:
	Winner();
	void     getchar(){cout<<mark[34];}
	void	setChoic(int c){choice=c;}
	int 	getChoic(){return choice;}
	int 	  initGme(char[], char[]);
	void 					plyGame();
	void 					   play();
	void					hangMan();
};

#endif /* WINNER_H_ */
