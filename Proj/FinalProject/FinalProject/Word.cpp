/*
 * Word.cpp
 *
 *  Created on: Dec 3, 2015
 *      Author: David Hudkins II
 *     Purpose: Define member functions of class Word
 */

//User Libraries
#include "Word.h"

#ifndef WORD_CPP_
#define WORD_CPP_

/******************************************************************************
 * Word function is the constructor for the Word class
 ******************************************************************************/
Word::Word()
{
	flName1="0";
	flName1="0";
	flName3="0";
}

/******************************************************************************
 * genWord function accepts two parameters that are a string array and
 * the size of that array. The function then assigns words from a file
 * to that array to be randomly seeded into a string variable that is passed
 * back into the calling function.
 ******************************************************************************/
string Word::genWord(int difclty)
{
	string gameWrd[AR_SIZE];	//Array of words
	int index 			= 0;	//Index for array
	flName1 = 	"word1.txt";	//Input file name
	flName2 = 	"word2.txt";	//Input file name
	flName3 = 	"word3.txt";	//Input file name

	switch(difclty)
	{
	case 1:
		//Open the word list file and assign words to array
		inFile.open(flName1.c_str());		//open file

		//Execute until end of file or until max array size
		while(!inFile.eof() && (index < AR_SIZE))
		{
			getline(inFile, gameWrd[index]);//Assign word to array
			index++;						//Increment array index
		}
		inFile.close();						//close file

		//Seed the random number generator according to time
		srand(time(0));

		//Return a random word from the word list file
		return gameWrd[(rand() % 10)];

	case 2:
		//Open the word list file and assign words to array
		inFile.open(flName2.c_str());		//open file

		//Execute until end of file or until max array size
		while(!inFile.eof() && (index < AR_SIZE))
		{
			getline(inFile, gameWrd[index]);//Assign word to array
			index++;						//Increment array index
		}
		inFile.close();						//close file

		//Seed the random number generator according to time
		srand(time(0));

		//Return a random word from the word list file
		return gameWrd[(rand() % 10)];

	case 3:
		//Open the word list file and assign words to array
		inFile.open(flName3.c_str());		//open file

		//Execute until end of file or until max array size
		while(!inFile.eof() && (index < AR_SIZE))
		{
			getline(inFile, gameWrd[index]);//Assign word to array
			index++;						//Increment array index
		}
		inFile.close();						//close file

		//Seed the random number generator according to time
		srand(time(0));

		//Return a random word from the word list file
		return gameWrd[(rand() % 10)];
	}
	return 0;
}

/******************************************************************************
 * usrWord function accepts no parameters and allows the user to input their
 * own word for the hangman program that is no longer than 30 characters.
 ******************************************************************************/
string Word::usrWord()
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
 * ~Word function is the destructor for the Word class
 ******************************************************************************/
Word::~Word(){}

#endif /* WORD_CPP_ */
