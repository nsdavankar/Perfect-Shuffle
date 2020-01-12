/**************************************************************************
* AUTHORS       : Nisha Davankar
* Student IDs   : 1045735
* Assignment    : 1
* CLASS         : CS1C
* SECTION       : MW 5pm
* DUE DATE      : 01/23/19
**************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//CONSTANTS
const int DECK_TOTAL = 52;
const int HALF_DECK = 26;

#ifndef HEADER_H_
#define HEADER_H_

enum ListOption							//Enumerated type for the list
{
	EXIT,
	InitializeDeck,
	PrintDeck,
	Shuffle,
	Compare,
	Count
};

struct card								//Struct for card
{
	string suit;						//INPUT- String type for suit
	string rank;						//INPUT- String type for rank
};

class Deck
{
public:
	/*****************************************************
	CONSTRUCTORS & DESTRUCTOR
	*****************************************************/
	Deck();
	~Deck();

	/*****************************************************
	FUNCTIONS
	*****************************************************/
	void InitailizeDeck();
	void PrintDeck();
	void Shuffle();
	bool Compare();

private:
	/*****************************************************
	PRIVATE MEMBERS
	*****************************************************/
	card deckOfCards[DECK_TOTAL];
	card compareDeck[DECK_TOTAL];
};

/**************************************************************************
* LISTOPTION
* This function outputs a menu, for the user to chose an option. It then 
* returns the user input integer to main.
**************************************************************************/
ListOption GetInput(); 

#endif /* HEADER_H_*/