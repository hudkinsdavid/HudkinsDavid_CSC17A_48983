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
#include<iostream>		//Console input/output streaming library
#include<iomanip>		//Input/output manipulation library
#include<ctime>			//Time library
#include<cstdlib>		//C-standard library
#include<fstream>		//File operations library
#include<cstring>		//String operator library
using namespace std;	//Standard namespace

//User Libraries
#include "Player.h"

//Function Prototypes
void rules();
int shwMenu();
string usrWord();
int initGme(char [], char[]);
void plyGame(char [], char[], int);

//Main Function
int main()
{
	/**************************************************************************
	 * CONSTANTS
	 * ------------------------------------------------------------------------
	 * AR_SIZE:	Size of array
	 * END	  : Max number of guesses reached
	 *************************************************************************/
	const int AR_SIZE = 100;
	const int		END = 6;

	//Declare Variables
	int 			 choice;	//Menu choice
	int 			   path;	//Determines how program will execute
	int			  chars = 0;	//Number of characters in game word
	int			  	  guess;	//Number of guesses player has made
	char 			   quit;	//Option to quit or play again
	string compArr[AR_SIZE];	//Computer generated word array
	string 			wrdPlay;	//Word used to play hangman
	char word	  [AR_SIZE];	//Word used to play hangman
	char progrss  [AR_SIZE];	//Player progress to correct guess
	bool	        	win;	//Flag for winning condition

	//Display game rules
	rules();

	//Primary game loop
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
	    	return 0;					//Terminate Program
		}

		//Computer generates word to play game
		if(path == 1)
			wrdPlay = genWord(compArr, AR_SIZE);//Set game word to computer generated word
		else
			wrdPlay = usrWord();				//Set game word to user input word

		strcpy(word,wrdPlay.c_str());			//Convert string to character array

		chars = initGme(word,progrss);			//Number of characters in the game word

		win = false;							//Initialize flag for win to false
		guess   = 0;							//Initialize number of guesses to 0

		//Loop for turns in game
		do
		{
			//Call function to allow player to input character guess
			plyGame(word,progrss,chars);
			//Loop to check for correct guess
			for(int i=0, chkWin=0; i<=chars; i++)
			{
				if (word[i]==progrss[i])	//Execute if guess matches a character in the word
					chkWin+=1;				//Increment amount of letters guessed correctly
				if(chkWin==chars+1)			//Execute if number of correct guesses equals number of characters in the game word
					win=true;				//Set winning flag to true
			}
			guess++;						//Increment number of guesses
		}while(guess < END && win==false);	//Loop until max guesses or winning condition

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

	return 0;											//Terminate Program
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////FUNCTIONS/////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

/******************************************************************************
 * rules function accepts no parameters and displays the rules to the
 * game Hangman.
 ******************************************************************************/
void rules()
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
int shwMenu()
{
	int choice;
	//Display Menu
		do
		{
			//Prompt user to input integer from menu
			cout << "Please input the corresponding integer to the" << endl;
			cout << "path you would like to choose: " << endl << endl;
			cout << "(1)Allow computer to choose word" << endl;
			cout << "(2)Input a word of your own for somebody else to play" << endl;
			cout << "(3)Quit" << endl;
			cin >> choice;				//INPUT- Menu choice

			//Validate input
			while(!cin >> choice)		//Execute while input is broken
			{
				cin.clear();			//Clear keyboard buffer
				cin.ignore(1000,'\n');	//Ignore characters until whitespace
				cout << "Incorrect input. Please use an integer." << endl << endl;	//Inform user of invalid input
			}
		}while(choice != 1 && choice != 2 && choice != 3); //Execute until menu choice is valid

		//Return menu choice to calling function
		return choice;
}

/******************************************************************************
 * usrWord function accepts no parameters and allows the user to input their
 * own word for the hangman program that is no longer than 30 characters.
 ******************************************************************************/
string usrWord()
{
	//Declare variables
	string word;		//INPUT- User defined word for gameplay

	//Prompt user to input game word
	cout << "Please enter the word you would like to use to play hangman";
	cout << " of no longer than 10 characters: " << endl;
	cin >> word;		//INPUT- User defined word for gameplay

	return word;		//Return user defined word for gameplay to calling function
}

/******************************************************************************
 * initGme function intitializes the arrays that are used in the execution of
 * the main gameplay. Two character arrays are accepted as parameters and the
 * array representing gameplay progress is initialized to the number of
 * characters in the gameplay word and then is initialized to blank spaces
 * representing their respective characters in their respective location in
 * the word.
 ******************************************************************************/
int initGme(char word[], char progrss[])
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

/******************************************************************************
 * plyGame function accepts three parameters including two arrays. The arrays
 * are the gameplay word array and the gameplay progress array. The number
 * of characters in the gameplay word is accepted as a parameter as well. The
 * function loops to display the progress and promts the user to input one
 * character as a guess regarding the existence of the guess as a character in
 * the word. If the guess is correct, it is assigned to its respective location
 * in the progress array in as many places as it occurs.
 ******************************************************************************/
void plyGame(char word[], char progrss[], int num)
{
	//Declare variables
	char gChar;					//INPUT- Character guess
	//Loop for number of characters in gameplay word
	for(int i=0; i<=num; i++)
		cout << progrss[i];		//Display gameplay progress
	//Prompt user to input guess
	cout << endl << "Guess one character in the word: ";
	cin >> gChar;				//INPUT- Character guess
	//Loop for number of characters in gameplay word
	for(int i=0; i<=num; i++)
	{
		//Execute if guess is correct at gameplay word subscript
		if(gChar == word[i])
			progrss[i] = gChar;	//Assign guess to progress arrays respective location(s)
	}
}
