/**************************************************************************
* AUTHORS       : Nisha Davankar
* Student IDs   : 1045735
* Assignment    : 1
* CLASS         : CS1C
* SECTION       : MW 5pm
* DUE DATE      : 01/23/19
**************************************************************************/

#include "Header.h"

/**************************************************************************
* Deck::Deck()
* -------------------------------------------------------------------------
* This is the class constructor
* -------------------------------------------------------------------------
*
**************************************************************************/
Deck::Deck()
{}

/**************************************************************************
* Deck::~Deck()
* -------------------------------------------------------------------------
* This is the class destructor
* -------------------------------------------------------------------------
*
**************************************************************************/
Deck::~Deck()
{}

/**************************************************************************
* void Deck::InitailizeDeck()
* -------------------------------------------------------------------------
* This is function initializes the deck of cards
* -------------------------------------------------------------------------
*
**************************************************************************/
void Deck::InitailizeDeck()
{
	//DECLARATION
	int i;								//INPUT- int i for the for loop

	//INITIALIZATION
	i = 0;
	string suits[] = {"Hearts", "Diamonds", "Spades", "Clubs" };
	string ranks[] = {"A", "2", "3","4","5","6","7","8","9","10","J","Q","K"};

	//PROCESSING- for loop will initialize two deck of cards
	for (i; i < DECK_TOTAL; i++)
	{
		deckOfCards[i].suit = suits[i / 13];
		deckOfCards[i].rank = ranks[i % 13];
		compareDeck[i].suit = suits[i / 13];
		compareDeck[i].rank = ranks[i % 13];
	}
}

/**************************************************************************
* void Deck::InitailizeDeck()
* -------------------------------------------------------------------------
* This is function print the deck of cards
* -------------------------------------------------------------------------
*
**************************************************************************/
void Deck::PrintDeck()
{
	//DECLARATION
	int i;								//INPUT- int i for the for loop

	//INITIALIZATION
	i = 0;

	//PROCESSING- for loop will print the deck of cards
	for (i; i < DECK_TOTAL; i++)
	{
		cout << deckOfCards[i].rank << " of " << deckOfCards[i].suit << endl;
	}
}

/**************************************************************************
* void Deck::Shuffle()
* -------------------------------------------------------------------------
* This is function will shuffle the deck of card in a perfect shuffle. The 
* 1st card will be followed by the 27th, then the 2nd, then the 28th etc.
* -------------------------------------------------------------------------
*
**************************************************************************/
void Deck::Shuffle()
{
	//DECLARATION
	int i;									//INPUT- int i for the for loop
	int j;									//INPUT- int j for the for loop
	card firstHalfDeck[HALF_DECK];			//CALC & OUT- First half of the 
											//			  deck
	card secondHalfDeck[HALF_DECK];			//CALC & OUT- Second half of the 
											//			  deck

	//INITIALIZATION
	i = 0;
	j = 26;

	//PROCESSING - for loop will seperate the deck into first half and second 
	//			   half
	for (i, j; i < HALF_DECK; i++, j++)
	{
			firstHalfDeck[i] = deckOfCards[i];
			secondHalfDeck[i] = deckOfCards[j];
	}

	//PROCESSING - for loop will perform a perfect shuffle
	for (i= 0, j = 0; i < DECK_TOTAL; i+=2, j++)
	{
		deckOfCards[i] = firstHalfDeck[j];
		deckOfCards[i + 1] = secondHalfDeck[j];
	}
}

/**************************************************************************
* bool Deck::Compare()
* -------------------------------------------------------------------------
* This is function will compare the current deck of cards to original deck 
* after the first shuffle.
* -------------------------------------------------------------------------
* OUTPUT
*		returns bool
**************************************************************************/
bool Deck::Compare()
{
	//DECLARATION
	bool originalDeck;						//CALC & OUT- bool to check the deck
	int i;									//INPUT- int i for the for loop 

	//INITIALIZATION
	originalDeck = false;
	i = 0;

	//PROCESSING- do while loop will compare the current deck to the original deck after 
	//			  the first shuffle
	do
	{
		if (deckOfCards[i].rank == compareDeck[i].rank 
			&& deckOfCards[i].suit == compareDeck[i].suit)
		{
			originalDeck = true;
		}
		else
		{
			originalDeck = false;
		}

		i++;
	} while (originalDeck != false && i < DECK_TOTAL);
	
	return originalDeck;
}