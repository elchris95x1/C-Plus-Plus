//Christian Lara
//ITSE-2331 Advanced C++
//Virtual Functions and Polymorphism

/*This program will use an array of pinters to dynamicly direct the user to the information it needs.
The program will also use a virtual function to be oberriten in the child functions
and it will show a list of types of animals, then a list of all the animals in that group
the user can see more detail about the animal*/

#include "Animal.h"
#include <fstream>
int main()
{
	SetConsoleTitle("Current Animals in SmallVille ZOO");
	char choice;//main menu choice
	char choice2;//submenu choice
	bool repeatMenu;//repeats the main menu
	bool innerFlag;//repeats the submenu
	bool innerFlag2;//loops the animal selection
	char repeat;//stores the repeat yews or not
	ifstream input("data/Animal.txt"); //input stream
	int Repcount = 0;//keeps count of reptiles
	int mamCount = 0;//keeps count of mammals
	int birdCount = 0;//keeps count of birds
	Mammal mammal[5];//5 mammals
	Reptile reptile[5];//5 reptiles
	Bird bird[5];//5 birds
	Species *animalPtr[3][5];//double array of pointers
	string name, type, desc;//stores values from file
	int ChoiceIntVal = 0;//used to convert the choice char to int
	int Choice2IntVal = 0;//used to convert the choice2 char to int


	while (!input.eof())
	{//Loop to bring information in from file
		
		getline(input, name, ',');
		getline(input, type, ',');
		getline(input, desc);
		if (type == "Mammal")
		{//stores the values on the current mammal class
			mammal[mamCount].set_name(name);
			mammal[mamCount].set_desc(desc);
			mammal[mamCount].set_type(type);
			animalPtr[0][mamCount] = &mammal[mamCount];
			mamCount++;
		}
		if (type == "Reptile") 
		{//stores the values on the current reptile class
			reptile[Repcount].set_name(name);
			reptile[Repcount].set_desc(desc);
			reptile[Repcount].set_type(type);
			animalPtr[1][Repcount] = &reptile[Repcount];
			Repcount++;
		}
		if (type == "Bird") 
		{//stores the values on the current bird class
			bird[birdCount].set_name(name);
			bird[birdCount].set_desc(desc);
			bird[birdCount].set_type(type);
			animalPtr[2][birdCount] = &bird[birdCount];
			birdCount++;
		}
	}

	do {//Do loop for main menu
		system("cls");
		bird[ChoiceIntVal].line();//displays line
		repeatMenu = true;
		cout << "Main Menu\n\n";
		bird[ChoiceIntVal].line();//displays line
		//displays the main menu
		cout << "1. Mammals\n"; 
		cout << "2. Reptiles\n";
		cout << "3. Birds\n";
		cout << "4. Exit\n";
		cout << "Choose the species you wish to view: ";
		cin >> choice;
		ChoiceIntVal = choice - '0';//converts the choice char to int
		switch (choice)
		{
		case '1': case '2': case '3'://animal type selection 1-3 is a valid choice in the menu
			system("cls");
			do {
				system("cls");
				reptile[ChoiceIntVal].line();//displays line
				innerFlag = false;
				innerFlag2 = false;
				cout << animalPtr[ChoiceIntVal - 1][0]->get_type() << "('s)" << endl;//gets the current animal type from class address
				reptile[ChoiceIntVal].line();//displays line
				//get all the names of the animals of the selected type
				cout << "1. " << animalPtr[ChoiceIntVal - 1][0]->get_name() << endl;
				cout << "2. " << animalPtr[ChoiceIntVal - 1][1]->get_name() << endl;
				cout << "3. " << animalPtr[ChoiceIntVal - 1][2]->get_name() << endl;
				cout << "4. " << animalPtr[ChoiceIntVal - 1][3]->get_name() << endl;
				cout << "5. Return to Main Menu" << endl;
				//get user choice on animal species
				cout << "Choose the animal you wish to view: ";
				cin >> choice2;
				Choice2IntVal = choice2 - '0';//converts the choice char to int
				switch (choice2)
				{
				case '1': case '2': case '3': case '4'://animal species slection is valid 1-4 in the menu
					system("cls");
					reptile[ChoiceIntVal].line();//displays line
					animalPtr[ChoiceIntVal - 1][Choice2IntVal - 1]->displayAnimal();//uses the display function of current class
					do {//ask user if he wants to choose another animal from the current type
						cout << "Do you wish to view another Reptile? (Y/N)";
						cin >> repeat;
						if (repeat == 'Y' || repeat == 'y') {
							innerFlag = false;
							innerFlag2 = true;
						}
						else if (repeat == 'N' || repeat == 'n') {
							innerFlag = true;
							innerFlag2 = true;
						}
						else {
							cout << "PLease enter either Y for Yes or N for No" << endl;
						}
					} while (innerFlag2 == false);
					break;
				case '5'://Returns to main menu
					innerFlag = true;
					break;
				default:
					cout << "Please enter a choice from the given options." << endl;
					break;
				}
			} while (innerFlag == false);
			break;
		case '4'://Closes Program
			exit(0);
			break;
		default:
			cout << "Please enter one of the given choices to view the animals of that species." << endl;
			break;
		}

	}while(repeatMenu == true);
	return 0;
}