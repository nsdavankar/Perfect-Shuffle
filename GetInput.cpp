/**************************************************************************
* AUTHORS       : Nisha Davankar
* Student IDs   : 1045735
* Assignment    : 1
* CLASS         : CS1C
* SECTION       : MW 5pm
* DUE DATE      : 01/23/19
*************************************************************************/

#include "Header.h"

/**************************************************************************
* ListOption GetInput()
* -------------------------------------------------------------------------
* This function outputs a menu, for the user to chose an option. It then 
* returns the user input integer to main.
* -------------------------------------------------------------------------
* INPUT
*		user input integer
* OUTPUT
*		returns enum type to main
**************************************************************************/
ListOption GetInput()
{
	//DECLARATION
	int userInput;							//INPUT- user entered choice	
	ListOption option;						//OUTPUT- user entered choice
							
	//INITIALIZATION
	userInput = 0;							

	//MENU OPTIONS 
	cout << "\nMENU OPTIONS\n" << endl
		<< "1 - Initialize Deck" << endl
		<< "2 - Print Deck" << endl
		<< "3 - Shuffle Deck" << endl
		<< "4 - Compare with the original" << endl
		<< "5 - Print Count" << endl
		<< "Enter an option(0 to exit) : ";

	//PROCRESSING- checks if the userinput is an integer
	if (!(cin >> userInput))
	{
		cout << "\n**** Please enter a NUMBER between 0 to 5 ****\n";
		cin.clear();
	}

	else if (userInput < 0 || userInput > 5)
	{
		cout << left;
		cout << "\n**** " << "The number " << userInput << setw(31) 
			 << " is an invalid entry "<< "****" << endl;
		cout << "**** " << setw(43) << "Please input a number between 0 to 5 "
			 << "****" << endl;
		cout << right;
	}

	else
	{
		option = ListOption(userInput);

		return option;
	}

	cin.ignore(1000, '\n');
}