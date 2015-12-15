/*
 * Winner.cpp
 *
 *  Created on: Dec 7, 2015
 *      Author: David Hudkins II
 *     Purpose: Define member functions of the Winner class
 */

#include "Winner.h"
#ifndef WINNER_CPP_
#define WINNER_CPP_

/******************************************************************************
 * Winner function is the constructor for the Winner class
 ******************************************************************************/
Winner::Winner()
{
	choice =	 			  0;
	path =		 			  0;
	incGues =	 			  0;
	count1 =				  0;
	count2 =				  0;
	count3 =   				  0;
	flag =					  0;
	chars =					  0;
	end =					  0;
	numWin = 				  0;
    wrdPlay =			    "0";
    quit =				    '0';

    //Verify memory sufficiency
    try
    {
    	mark =    new char[AR_SIZE];
    }
    catch(bad_alloc &mark)
    {
    	cout<<"Insufficient memory to allocate";
    }

    //Verify memory sufficiency
    try
    {
	word   =  new char[AR_SIZE];
    }
    catch(bad_alloc &word)
    {
    	cout<<"Insufficient memory to allocate";
    }

    //Verify memory sufficiency
    try
    {
	prgrss =  new char[AR_SIZE];
    }
    catch(bad_alloc &prgrss)
    {
    	cout<<"Insufficient memory to allocate";
    }

    //Verify memory sufficiency
    try
    {
	guesses = new char[AR_SIZE];
    }
    catch(bad_alloc &guesses)
    {
    	cout<<"Insufficient memory to allocate";
    }
}

/******************************************************************************
 * hangMan function displays the hangman character based on the current
 * progression of the game at the time that it is called.
 ******************************************************************************/
void Winner::hangMan()
{
	//Execute according to game difficulty chosen
	switch(getMode())
	{
	//Execute if game is in easy mode
	case 1:
		//Display initial hangman figure
		if(incGues==0)
		{
			cout<<setw(11)<<"___"<<endl<<setw(12)<<"|  |"<<endl<<setw(12)<<"|"<<endl;
			cout<<setw(12)<<"|"<<endl<<setw(12)<<"|"<<endl<<setw(13)<<"---"<<endl<<endl;
		}

		//Display if number of guesses is 1
		if(incGues==1)
		{
			cout<<setw(11)<<"___"<<endl<<setw(12)<<"|  |"<<endl<<setw(12)<<" O  |";
			cout<<endl<<setw(12)<<"|"<<endl<<setw(12)<<"|"<<endl<<setw(12)<<"|";
			cout<<endl<<setw(13)<<"---"<<endl<<endl;
		}

		//Display if number of guesses is 2
		else if(incGues==2)
		{
			cout<<setw(11)<<"___"<<endl<<setw(12)<<"|  |"<<endl<<setw(12)<<" O  |";
			cout<<endl<<setw(12)<<"/-|-/|"<<endl<<setw(12)<<"|"<<endl<<setw(12)<<"|";
			cout<<endl<<setw(13)<<"---"<<endl<<endl;
		}

		//Display if number of guesses is 3
		else if(incGues==3)
		{
			cout<<setw(11)<<"___"<<endl<<setw(12)<<"|  |"<<endl<<setw(12)<<" O  |";
			cout<<endl<<setw(12)<<"/-|-/|"<<endl<<setw(12)<<".W W.|"<<endl<<setw(12)<<"|";
			cout<<endl<<setw(13)<<"---"<<endl<<endl;
		}
		break;

	//Execute if game is in normal mode
	case 2:
		//Display initial hangman figure
		if(incGues==0)
		{
			cout<<setw(11)<<"___"<<endl<<setw(12)<<"|  |"<<endl<<setw(12)<<"|"<<endl;
			cout<<setw(12)<<"|"<<endl<<setw(12)<<"|"<<endl<<setw(13)<<"---"<<endl<<endl;
		}

		//Display if number of guesses is 1
		if(incGues==1)
		{
			cout<<setw(11)<<"___"<<endl<<setw(12)<<"|  |"<<endl<<setw(12)<<" O  |";
			cout<<endl<<setw(12)<<"|"<<endl<<setw(12)<<"|"<<endl<<setw(12)<<"|";
			cout<<endl<<setw(13)<<"---"<<endl<<endl;
		}

		//Display if number of guesses is 2
		else if(incGues==2)
		{
			cout<<setw(11)<<"___"<<endl<<setw(12)<<"|  |"<<endl<<setw(12)<<" O  |";
			cout<<endl<<setw(12)<<"/-|  |"<<endl<<setw(12)<<"|"<<endl<<setw(12)<<"|";
			cout<<endl<<setw(13)<<"---"<<endl<<endl;
		}

		//Display if number of guesses is 3
		else if(incGues==3)
		{
			cout<<setw(11)<<"___"<<endl<<setw(12)<<"|  |"<<endl<<setw(12)<<" O  |";
			cout<<endl<<setw(12)<<"/-|-/|"<<endl<<setw(12)<<"|"<<endl<<setw(12)<<"|";
			cout<<endl<<setw(13)<<"---"<<endl<<endl;
		}

		//Display if number of guesses is 4
		else if(incGues==4)
		{
			cout<<setw(11)<<"___"<<endl<<setw(12)<<"|  |"<<endl<<setw(12)<<" O  |";
			cout<<endl<<setw(12)<<"/-|-/|"<<endl<<setw(12)<<".W   |"<<endl<<setw(12)<<"|";
			cout<<endl<<setw(13)<<"---"<<endl<<endl;
		}

		//Display if number of guesses is 5
		else if(incGues==5)
		{
			cout<<setw(11)<<"___"<<endl<<setw(12)<<"|  |"<<endl<<setw(12)<<" O  |";
			cout<<endl<<setw(12)<<"/-|-/|"<<endl<<setw(12)<<".W W.|"<<endl<<setw(12)<<"|";
			cout<<endl<<setw(13)<<"---"<<endl<<endl;
		}

		break;

	//Execute if game is in hard mode
	case 3:
		//Display initial hangman figure
		if(incGues==0)
		{
			cout<<setw(11)<<"___"<<endl<<setw(12)<<"|  |"<<endl<<setw(12)<<"|"<<endl;
			cout<<setw(12)<<"|"<<endl<<setw(12)<<"|"<<endl<<setw(13)<<"---"<<endl<<endl;
		}

		//Display if number of guesses is 1
		if(incGues==1)
		{
			cout<<setw(11)<<"___"<<endl<<setw(12)<<"|  |"<<endl<<setw(12)<<" O  |";
			cout<<endl<<setw(12)<<"|"<<endl<<setw(12)<<"|"<<endl<<setw(12)<<"|";
			cout<<endl<<setw(13)<<"---"<<endl<<endl;
		}

		//Display if number of guesses is 2
		else if(incGues==2)
		{
			cout<<setw(11)<<"___"<<endl<<setw(12)<<"|  |"<<endl<<setw(12)<<" O  |";
			cout<<endl<<setw(12)<<" -|  |"<<endl<<setw(12)<<"|"<<endl<<setw(12)<<"|";
			cout<<endl<<setw(13)<<"---"<<endl<<endl;
		}

		//Display if number of guesses is 3
		else if(incGues==3)
		{
			cout<<setw(11)<<"___"<<endl<<setw(12)<<"|  |"<<endl<<setw(12)<<" O  |";
			cout<<endl<<setw(12)<<" -|- |"<<endl<<setw(12)<<"|"<<endl<<setw(12)<<"|";
			cout<<endl<<setw(13)<<"---"<<endl<<endl;
		}

		//Display if number of guesses is 4
		else if(incGues==4)
		{
			cout<<setw(11)<<"___"<<endl<<setw(12)<<"|  |"<<endl<<setw(12)<<" O  |";
			cout<<endl<<setw(12)<<"/-|- |"<<endl<<setw(12)<<"|"<<endl<<setw(12)<<"|";
			cout<<endl<<setw(13)<<"---"<<endl<<endl;
		}

		//Display if number of guesses is 5
		else if(incGues==5)
		{
			cout<<setw(11)<<"___"<<endl<<setw(12)<<"|  |"<<endl<<setw(12)<<" O  |";
			cout<<endl<<setw(12)<<"/-|-/|"<<endl<<setw(12)<<"|"<<endl<<setw(12)<<"|";
			cout<<endl<<setw(13)<<"---"<<endl<<endl;
		}

		//Display if number of guesses is 6
		else if(incGues==6)
		{
			cout<<setw(11)<<"___"<<endl<<setw(12)<<"|  |"<<endl<<setw(12)<<" O  |";
			cout<<endl<<setw(12)<<"/-|-/|"<<endl<<setw(12)<<".W   |"<<endl<<setw(12)<<"|";
			cout<<endl<<setw(13)<<"---"<<endl<<endl;
		}

		//Display if number of guesses is 7
		else if(incGues==7)
		{
			cout<<setw(11)<<"___"<<endl<<setw(12)<<"|  |"<<endl<<setw(12)<<" O  |";
			cout<<endl<<setw(12)<<"/-|-/|"<<endl<<setw(12)<<".W W.|"<<endl<<setw(12)<<"|";
			cout<<endl<<setw(13)<<"---"<<endl<<endl;
		}

		break;

	//Default switch execution
	default: cout<<"ERROR";
	}
}

/******************************************************************************
 * initGme function intitializes the arrays that are used in the execution of
 * the main gameplay. Two character arrays are accepted as parameters and the
 * array representing gameplay progress is initialized to the number of
 * characters in the gameplay word and then is initialized to blank spaces
 * representing their respective characters in their respective location in
 * the word. The function then returns the number of characters that are
 * contained in the gameplay word to the calling function.
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

/******************************************************************************
 * plyGame function initializes the array that marks correct guess progression
 * at the beginning of a do-while loop. The menu choice is then displayed and
 * value chosen passed to the setChoic function. Paths are then executed based
 * said menu choice. The user can choose computer generated words, input their
 * own, or quit. If computer generated is chosen there are three difficulties
 * to choose from and the code will execute accordingly. The winning flag is
 * initialized to false and then the game begins. In the nested do-while loop
 * the play function is called to allow the player to input a guess. Then an if
 * loop is called to check for a correct guess. If so then an incorrect guess
 * is not counted and the player is allowed another guess. When the player gets
 * the word right, the win flag is set to true and the do-while loop terminates.
 * It also terminates if the user exceeds the maximum number of incorrect
 * guesses. When the loop terminates the user is asked if they would like to
 * continue. If yes the loop is repeated, if not the program is terminated.
 *
 ******************************************************************************/
void Winner::plyGame()
{
	do
	{
		//Initialize array that tracks user progression and correct guesses
		for(int i = 0;i<AR_SIZE;i++)
			mark[i]='0';

		//Display menu and allow user to choose gameplay settings
		setChoic(shwMenu());

		//Execute according to user's menu choice
		switch(choice)
		{
		case 1: path = 1;				//Computer generate word to play
			break;

		case 2: path = 2;				//User input word to play
			break;

		case 3: cout << "Goodbye!";
	    	exit(choice);				//Terminate Program
		}

		//Computer generates word to play game
		if(path == 1)
		{
			gmMode();							//Set difficulty
			wrdPlay = genWord(getMode());		//Set game word to computer generated word

			//Set number of incorrect guesses relevant to difficulty chosen
			switch(getMode())
			{
			case 1:
				end=3;		//Easy mode-3 incorrect guesses allowed
				break;

			case 2:
				end=5;		//Normal mode-5 incorrect guesses allowed
				break;

			case 3:
				end=7;		//Hard mode-7 incorrect guesses allowed
				break;
			}
		}
		else
		{
			wrdPlay = usrWord();				//Set game word to user input word
			end=5;								//User mode automatically set to normal
		}

		strcpy(word,wrdPlay.c_str());			//Convert string to character array

		chars = initGme(word,prgrss);			//Number of characters in the game word

		win = false;							//Initialize flag for win to false

		//Loop for turns in game
		do
		{
			//Call function to allow player to input character guess
			play();

			//Loop to check for winning condition
			for(int i=0, chkWin=0; i<=chars; i++)
			{
				if(word[i]==prgrss[i])		//Execute if guess matches a character in the word
				{
					chkWin+=1;				//Increment amount of letters guessed correctly

					//Execute if location of score keeping is empty, indicating a new correct guess
					if(mark[i]=='0')
					{
						mark[i]=word[i];	//Input and track correct guess
						count1++;			//Increment count to indicate correct guess this phase
						flag=1;				//Set flag to indicate at least one correct guess has been made
					}
				}

				//Execute if number of correct guesses equals number of characters in the game word
				if(chkWin==chars+1)
					win=true;				//Set winning flag to true
			}

			//Execute if current counter and holding counter evaluate as equal
			if(count1 == count2 || flag==0)
				incGues++;					//Increment number of guesses

			//Set counter for number of guesses to current counter for later comparison
			count2 = count1;
		}while(incGues < end && win==false);	//Loop until max guesses or winning condition

		//Inform user of what the game word was
		cout << "The word was ";

		//Loop to display game word
		for(int i=0; i<=chars; i++)
			cout << word[i];
		cout<<endl<<endl;

		//Execute if win flag is true
		if(win==true)
		{
			cout << "\n\nGood Job! You won!" << endl;	//Inform user of win
			numWin+=1;
		}

		//Execute if win flag is false
		if(win==false)
		{
			//Show completed hangman
			cout<<setw(11)<<"___"<<endl<<setw(12)<<"|  |"<<endl<<setw(12)<<" O  |";
			cout<<endl<<setw(12)<<"/-|-/|"<<endl<<setw(12)<<".W W.|"<<endl<<setw(12)<<"|";
			cout<<endl<<setw(13)<<"---"<<endl<<endl;
			cout<<"Letters guessed: ";

			//Show the letters already guessed
			for(int i=0; i<count3; i++)
				cout<<guesses[i];

			//Indicate loss
			cout<<"\nYou're DEAD!"<<endl<<endl;
		}
		//Prompt user to play again
		cout << "Would you like to play again?" << endl;
		cin >> quit;									//INPUT- Play again or not

		//Set guesses to 0 and counter for guesses to 0
		incGues=0;
		count3=0;

	}while(quit=='Y' || quit=='y');						//Loop until user chooses to quit
}

/******************************************************************************
 * play function deals with arrays that are the gameplay word array and the
 * gameplay progress array. The number of characters in the gameplay word is
 * handled as well. The function loops to display the progress and prompts the
 * user to input one character as a guess regarding the existence of the guess
 * as a character in the word. If the guess is correct, it is assigned to
 * its respective location in the progress array in as many places as it occurs.
 ******************************************************************************/
void Winner::play()
{
	//Declare variables
	char gChar;					//INPUT- Character guess

	//Show hangman progression
	hangMan();
	cout<<"Letters guessed: ";

	//Show the letters already guessed
	for(int i=0; i<count3; i++)
		cout<<guesses[i];
	cout<<endl<<endl;

	//Loop for number of characters in gameplay word
	for(int i=0; i<=chars; i++)
		cout << prgrss[i];		//Display gameplay progress

	//Prompt user to input guess
	cout << endl << "Guess one character in the word: ";
	cin >> gChar;				//INPUT- Character guess

	//Put guess in array of guesses
	guesses[count3]=gChar;

	//Loop for number of characters in gameplay word
	for(int i=0; i<=chars; i++)
	{
		//Execute if guess is correct at gameplay word subscript
		if(gChar == word[i])
			prgrss[i] = gChar;	//Assign guess to progress arrays respective location(s)
	}

	//Increment number of turns
	count3+=1;
}

/******************************************************************************
 * This function overloads the greater than operator to compare the number of
 * wins that each player had and returns which player has a greater number of
 * wins.
 ******************************************************************************/
bool Winner::operator >(const Winner &other)
{
	if(numWin > other.numWin)
		return true;
	else
		return false;
}

/******************************************************************************
 * ~Winner function is the destructor for the Winner class
 ******************************************************************************/
Winner::~Winner()
{
	//Delete all dynamically allocated memory in the class
	delete[]    mark;
	delete[]    word;
	delete[]  prgrss;
	delete[] guesses;
}

#endif /* WINNER_CPP_ */
