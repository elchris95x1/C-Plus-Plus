//Programmed by Christian Lara on 7/1/2017
//Advanced C++ Programming (ITSE-2331-1031)
//Pointers new and delete


#include "List.h"//includes the list file
#include "Validation.h"//includes the validation file
linklist l;//makes list instance
Valid val;//vaidation class instance
Person per;//person struct instance
//Prototypes
void enterPerson();

//main function
int main()
{
	SetConsoleTitle("Info List");
	bool invalid; //used to validate
	string choice1;//choice 1 for the action choice
	string choice2;//choice two for record choice
	bool exit;//to exit infinite loop
	l.inputFile();//inputs file info
	do {
		exit = false;
		system("cls");//clears screen each time it runs
		cout << "\t\t\tInfo List\n\n";
		l.display();//displays contents on the file
		//main menu
		cout << "\n\n\tChoose an action\n"
			<< "1. Add\n"
			<< "2. Delete\n"
			<< "3. Update\n"
			<< "4. Exit\n"
			<< "Your choice: ";
		//gets input to choose action
		getline(cin, choice1);
		//if choice 1 the program adds to list
		if (choice1 == "1") {
			cout << "\n\tADD the Data of the Person you want to enter\n";
			enterPerson();//calls the function to enter data for person
			l.addItem(per);//add the person added to the struct
		}
		//if choice 2 the program deletes from list
		else if (choice1 == "2") {
			cout << "\n\tSelect the Item you want to DELETE from the list\n";
			l.display();//displays options to choose from to delete
			do {
				cout << "Your choice: ";
				getline(cin, choice2);//gets the choice
				invalid = val.ListSelection(choice2,l.count);
			} while (invalid == true);
			int tempInt =stoi(choice2);//cats the string to an int
			l.deleteItem(tempInt);//detes the record on that int
		}
		//if choice 3 the program updates from list
		else if (choice1 == "3") {
			cout << "\n\tSelect the Item you want to UPDATE from the list\n";
			l.display();//displays options to choose from to update
			do {
				cout << "Your choice: ";
				getline(cin, choice2);//gets the choice
				invalid = val.ListSelection(choice2, l.count);
			} while (invalid == true);
			int tempInt = stoi(choice2);//cats the string to an int
			enterPerson();//gets new data to write
			l.updateItem(per, tempInt);//cals the update function
		}
		//if choice 4 the program ends infinite loop
		else if (choice1 == "4") {
			exit = true;
			cout << "\n\n\tBYE\n";
		}
		//else an erro is displayed
		else{
			exit = false;
			cout << "\n\tTHIS IS THE ERROR Wrong input. Please Try Again\n\n";
			Sleep(500);
		}
	} while (exit == false);
	//writes file and all new data
	l.FileOutput();
	return 0;
}

void enterPerson()
{
	bool invalid;
	do {
		invalid = true;
		//gets first name
		cout << "Enter First Name(Ex. Juan): ";
		getline(cin, per.fName);
		invalid = val.charactersValidation(per.fName);
		//calls the statement function that shows to user if input was valid or not
		val.valStatement(invalid);
	} while (invalid == true);
	do {
		invalid = true;
		//gets last name
		cout << "Enter Last Name(Ex. Smith): ";
		getline(cin, per.lName);
		invalid = val.charactersValidation(per.lName);
		//calls the statement function that shows to user if input was valid or not
		val.valStatement(invalid);
	} while (invalid == true);
	do {
		invalid = true;
		//gets age
		cout << "Enter Age(Ex. 18): ";
		getline(cin, per.age);
		invalid = val.wholeNumberValidation(per.age);
		//calls the statement function that shows to user if input was valid or not
		val.valStatement(invalid);
	} while (invalid == true);
	do {
		invalid = true;
		//gets phone number
		cout << "Please Enter Phone Number(Ex. (254)564-2563): ";
		getline(cin, per.phone);
		invalid = val.phoneNumberValidation(per.phone);
		//calls the statement function that shows to user if input was valid or not
		val.valStatement(invalid);
	} while (invalid == true);
	do {
		invalid = true;
		//gets ssn
		cout << "Please Enter Social Security Number. (Ex. 123-45-6789): ";
		getline(cin, per.ssn);
		invalid = val.socialSecurityNumberValidation(per.ssn);
		//calls the statement function that shows to user if input was valid or not
		val.valStatement(invalid);
	} while (invalid == true);
}