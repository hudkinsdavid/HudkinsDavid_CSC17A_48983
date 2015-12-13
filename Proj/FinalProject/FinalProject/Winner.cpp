/*
 * Winner.cpp
 *
 *  Created on: Dec 7, 2015
 *      Author: David
 */

#include "Winner.h"
#ifndef WINNER_CPP_
#define WINNER_CPP_

Winner::Winner()
{
	choice =				 0;
	path =					 0;
	incGues =				 0;
	chars =					 0;
	end =					 0;
    wrdPlay =			   "0";
    quit =				   '0';
	word   = new char[AR_SIZE];
	prgrss = new char[AR_SIZE];
}

/******************************************************************************
 * initGme function intitializes the arrays that are used in the execution of
 * the main gameplay. Two character arrays are accepted as parameters and the
 * array representing gameplay progress is initialized to the number of
 * characters in the gameplay word and then is initialized to blank spaces
 * representing their respective characters in their respective location in
 * the word.
 ******************************************************************************/
int Winner::initGme(char word[], char progrss[])
{
	//Declare variables
	int numChar = 0;			//Number of characters in gameplay word
	//Loop until null terminator is encountered
	for(int i=0; word[i]!='\0'; i++)
		numChar = i;			//Assign number of characters in gameplay word to variable
	//Loop for number of characters in gameplay word
	for(int i=0; i<=numChar; i++)
		progrss[i] = word[i];	//Assign subscript of gameplay word array to subscript of progress array
	//Loop for number of characters in gameplay word
	for(int i=0; i<=numChar; i++)
		progrss[i] = '-';		//Assign blank space to all subscripts of progress array

	return numChar;				//Return number of characters in gameplay word
}

void Winner::plyGame()
{
	do
	{

		choice = shwMenu();				//Show game menu and assign choice

		//Execute according to user's menu choice
		switch(choice)
		{
		case 1: path = 1;				//Computer generate word to play
			break;
		case 2: path = 2;				//User input word to play
			break;
		case 3: cout << "Goodbye!";
	    	throw;						//Terminate Program
		}

		//Computer generates word to play game
		if(path == 1)
			wrdPlay = genWord(choice);		//Set game word to computer generated word
		else
			wrdPlay = usrWord();			//Set game word to user input word

		strcpy(word,wrdPlay.c_str());			//Convert string to character array

		chars = initGme(word,prgrss);			//Number of characters in the game word

		win = false;							//Initialize flag for win to false

		//Loop for turns in game
		do
		{
			//Call function to allow player to input character guess
			plyGame();
			//Loop to check for correct guess
			for(int i=0, chkWin=0; i<=chars; i++)
			{
				if (word[i]==prgrss[i])		//Execute if guess matches a character in the word
					chkWin+=1;				//Increment amount of letters guessed correctly
				if(chkWin==chars+1)			//Execute if number of correct guesses equals number of characters in the game word
					win=true;				//Set winning flag to true
			}
			incGues++;						//Increment number of guesses
		}while(*incGues < end && win==false);	//Loop until max guesses or winning condition

		//Inform user of what the game word was
		cout << "The word was ";
		//Loop to display game word
		for(int i=0; i<=chars; i++)
			cout << word[i];
		if(win==true)									//Execute if win flag is true
			cout << "\n\nGood Job! You won!" << endl;	//Inform user of win
		//Prompt user to play again
		cout << "Would you like to play again?" << endl;
		cin >> quit;									//INPUT- Play again or not

	}while(quit=='Y' || quit=='y');						//Loop until user chooses to quit
}

/******************************************************************************
 * play function accepts three parameters including two arrays. The arrays
 * are the gameplay word array and the gameplay progress array. The number
 * of characters in the gameplay word is accepted as a parameter as well. The
 * function loops to display the progress and promts the user to input one
 * character as a guess regarding the existence of the guess as a character in
 * the word. If the guess is correct, it is assigned to its respective location
 * in the progress array in as many places as it occurs.
 ******************************************************************************/
void Winner::play()
{
	//Declare variables
	char gChar;					//INPUT- Character guess
	//Loop for number of characters in gameplay word
	for(int i=0; i<=chars; i++)
		cout << prgrss[i];		//Display gameplay progress
	//Prompt user to input guess
	cout << endl << "Guess one character in the word: ";
	cin >> gChar;				//INPUT- Character guess
	//Loop for number of characters in gameplay word
	for(int i=0; i<=chars; i++)
	{
		//Execute if guess is correct at gameplay word subscript
		if(gChar == word[i])
			prgrss[i] = gChar;	//Assign guess to progress arrays respective location(s)
	}
}

#endif /* WINNER_CPP_ */
