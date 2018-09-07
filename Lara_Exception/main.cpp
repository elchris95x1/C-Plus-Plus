//Programed by Christian Lara on 5/22/2017
//Advanced C++ Programming (ITSE-2331-1031)
//Exception handling

/*This application will validate for multiple user input, It will use a validation file that will be included
in the main file. The validation will be done by ascii codes. The application will also use an error class
to catch errors produced in the main class. A try catch will be placed on the main function*/


#include <iostream>//main library
#include <string>//needed to use getline
#include <Windows.h>//used for sleep
#include "Validation.h"//includes the validation file

using namespace std;

int main()
{
	SetConsoleTitle("Exception handling");
	Valid v;
	//holds user choice for main menu
	string choice;
	//holds the user input to validate
	string input;
	//used to validate for invalid input
	bool invalid;
	//used to create a infinite loop until 9 8is selected
	bool loop;
	//main loop loops until 9 is selected in the main menu
	do {
		try
		{
			//sets loop to true at the beggining of the loop
			loop = true;
			//displays main menu
			cout << "Chose a Field to Validate:\n" <<
				"\t1. Whole Number\n" <<
				"\t2. Real Number\n" <<
				"\t3. Characters\n" <<
				"\t4. Phone Number\n" <<
				"\t5. Social Security Number\n" <<
				"\t6. Email Address\n" <<
				"\t7. Date\n" <<
				"\t8. Time\n" <<
				"\t9. Exit Program\n";
			//gets user input
			getline(cin, choice);

			//if 1 is entered this runs
			if (choice == "1")
			{
				//loops if invalid is true
				do {
					invalid = false;
					cout << "Please Enter a Whole Number(Ex. 1,2,3...): ";
					getline(cin, input);
					//calls the wholenumberValidation from the validation file
					invalid = v.wholeNumberValidation(input);
					//calls the valid statement
					v.valStatement(invalid);
				} while (invalid == true);
			}
			//if 2 is entered this runs
			else if (choice == "2")
			{
				//loops if invalid is true
				do {
					invalid = false;
					cout << "Please Enter a Real Number(Ex. 1,1/2,3.1...): ";
					getline(cin, input);
					//calls the real number validation from the validation file
					invalid = v.realNumberValidation(input);
					//calls the valid statement
					v.valStatement(invalid);
				} while (invalid == true);
			}
			//if 3 is entered this runs
			else if (choice == "3")
			{
				//loops if invalid is true
				do {
					invalid = false;
					cout << "Please Enter Characters(Ex. something...): ";
					getline(cin, input);
					//calls the character validation from the validation file
					invalid = v.charactersValidation(input);
					//calls the valid statement
					v.valStatement(invalid);
				} while (invalid == true);
			}
			//if 4 is entered this runs
			else if (choice == "4")
			{
				//loops if invalid is true
				do {
					invalid = false;
					cout << "Please Enter Phone Number(Ex. (254)564-2563): ";
					getline(cin, input);
					//calls the phone NUmber validation from the validation file
					invalid = v.phoneNumberValidation(input);
					//calls the valid statement
					v.valStatement(invalid);
				} while (invalid == true);
			}
			//if 5 is entered this runs
			else if (choice == "5")
			{
				//loops if invalid is true
				do {
					invalid = false;
					cout << "Please Enter Social Security Number. (Ex. 123-45-6789): ";
					getline(cin, input);
					//calls the Social Security Number validation from the validation file
					invalid = v.socialSecurityNumberValidation(input);
					//calls the valid statement
					v.valStatement(invalid);
				} while (invalid == true);
			}
			//if 6 is entered this runs
			else if (choice == "6")
			{
				//loops if invalid is true
				do {
					invalid = false;
					cout << "Please Enter Email Address. (Ex. something@something.something): ";
					getline(cin, input);
					//calls the Email Address validation from the validation file
					invalid = v.emailAddressValidation(input);
					//calls the valid statement
					v.valStatement(invalid);
				} while (invalid == true);
			}
			//if 7 is entered this runs
			else if (choice == "7")
			{
				//loops if invalid is true
				do {
					invalid = false;
					cout << "Please Enter a Date (Ex. MM/DD/YYYY): ";
					getline(cin, input);
					//calls the Date validation from the validation file
					invalid = v.dateValidation(input);
					//calls the valid statement
					v.valStatement(invalid);
				} while (invalid == true);
			}
			//if 8 is entered this runs
			else if (choice == "8")
			{
				//loops if invalid is true
				do {
					invalid = false;
					cout << "Please Enter a Time (Ex. HH:MM:SS): ";
					getline(cin, input);
					//calls the time validation from the validation file
					invalid = v.timeValidation(input);
					//calls the valid statement
					v.valStatement(invalid);
				} while (invalid == true);
			}
			//if 9 is entered this runs
			else if (choice == "9")
			{
				cout << "\nThe program will exit";
				loop = false;
			}
			//else this runs
			else
			{
				cout << "\n\tTry AGAIN! Invalid Menu Choice.\n\n";
				loop = true;
			}
			}
		catch (Valid::AnError ex)
		{
			ex.errorMessage();
		}
	} while (loop == true);
		

	return 0;
	
	
}