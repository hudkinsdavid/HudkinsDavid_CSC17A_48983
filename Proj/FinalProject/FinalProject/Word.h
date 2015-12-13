/*
 * Word.h
 *
 *  Created on: Dec 3, 2015
 *      Author: David Hudkins II
 *     Purpose: Create class word to handle data the hangman program
 *     	uses regarding the word used to play the game.
 */

#include<iostream>		//Console input & output
#include<string>		//Allows use of string class
#include<fstream>		//File operations library
#include<ctime>			//Time library
#include<cstdlib>		//C-standard library
using namespace std;

#ifndef WORD_H_
#define WORD_H_

class Word
{
protected:
	static const int AR_SIZE = 100;	//Size of array
	ifstream 				inFile;	//Input file designator
	string  			   flName1;	//Input file name for easy
	string 				   flName2;	//Input file name for normal
	string  			   flName3;	//Input file name for hard
public:
	Word();
	string genWord(int);
	string usrWord();
};

#endif /* WORD_H_ */
