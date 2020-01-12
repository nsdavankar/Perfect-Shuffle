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
* Deck of Cards
* -------------------------------------------------------------------------
* This program will create a standard deck of cards that will represent both 
* the suit and the rank. It will perform a perfect shuffle. It will print the 
* current deck and output how many shuffles are required to return to the 
* original configuration.
* --------------------------------------------------------------------------
* INPUT
*		choice- enum type used input
* 
* OUTPUT
*
***************************************************************************/

int main()

{
	//DECLARATION
	ListOption choice;					//INPUT- enum type user input
	Deck NewDeck;						//INPUT- object of class Deck
	int count;							//CALC & OUT- count of number of 
										//			  shuffles
	bool sameDeck;						//CALC & OUT- bool of comparison 
										//            of the deck

	//INITIALIZATION
	sameDeck = false;
	count = 0;

	//PROCESSING- do while loop for the menu
	do
	{
		choice = GetInput();

		//PROCESSING- switch statement for menu
		switch (choice)
		{
		case InitializeDeck: NewDeck.InitailizeDeck();
			break;

		case PrintDeck: NewDeck.PrintDeck();
			break;

		case Shuffle: NewDeck.Shuffle();
			count++;
			break; 
		
		case Compare: NewDeck.Compare();
			sameDeck = NewDeck.Compare();
			//PROCESSING - bool is returned by compare() to compare to the 
			//			   original deck
			if (sameDeck == true)
			{
				cout << "The deck is same as the original deck" << endl;
			}
			else
			{
				cout << "The deck is not the same as ther original deck" << endl;
			}
			break;

		case Count: cout << "The deck has been shuffled " << count << " times." << endl;
			break;
		}

	} while (choice != EXIT);

	return 0;
}

