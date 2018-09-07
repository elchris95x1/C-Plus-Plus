//Team 26
//ITSE 2331-1031
//Programmed starting July 17th, 2017; last updated July 17th, 2017

/*This application allows a user to create, load, and service (test functionality of) vending machines.
  The user is also able to adjust prices of products and generate a sales report showing the sales totals of each
  item. */

 //Fill with appropriate class headers -Austin
//#include "Fountain" 
//#include "Snack"
//#include "Bottled"
#include "VendingMachine.h"

//remove when classes are included into main.cpp -Austin
#include <iostream> 
#include <iomanip>
#include <string>
#include <conio.h>
using namespace std; 

bool validMenuSelect(int lowerBound, int upperBound, string numberInput);
bool validMachineName(string nameInput);

int main() {
	//menu flags
	bool exitProgram = false;
	bool exitSubmenu;
	bool fileLoaded = false;
	//menu navigating variables
	int maxMenu = 7;
	int convertedMenuInput = 0;
	string menuInput = "";
	//local class variables to be stored into object values
	string machineType = "";
	string machineName = "";
	//object pointers
	int numberOfMachines = 0;
	//Fountain* tempFount;
	//Snack* tempSnack;
	//Bottle* tempBottle;
	VendingMachine* tempMachine;
	VendingMachine* topMachine = NULL;
	VendingMachine* ptrIndexCatalog[1000];


	do {
		do {
			system("cls");
			if (fileLoaded == false) {
				cout << "\n              Vend-O-Rama Vending Machine Builder"
					<< "\n\n    Enter a number to select a menu option:"
					<< "\n\n    1. Load in existing machines from file"
					<< "\n    2. Create a new machine"
					<< "\n    3. Load products into machine"
					<< "\n    4. Set product pricing for a machine"
					<< "\n    5. Test machine service"
					<< "\n    6. Generate inventory report for a machine"
					<< "\n    7. Exit Program\n\n    ";
			}
			else {
				cout << "\n              Vend-O-Rama Vending Machine Builder"
					<< "\n\n    Enter a number to select a menu option:"
					<< "\n    1. Create a new machine"
					<< "\n    2. Load products into machine"
					<< "\n    3. Set product pricing for a machine"
					<< "\n    4. Test machine service"
					<< "\n    5. Generate inventory report for a machine"
					<< "\n    6. Exit Program\n\n    ";
			}
			getline(cin, menuInput);
		} while (validMenuSelect(1, maxMenu, menuInput) == false);

		if (fileLoaded == true) { convertedMenuInput = stoi(menuInput) + 1; }
		else { convertedMenuInput = stoi(menuInput); }

		switch (convertedMenuInput) {
		case 1:
			fileLoaded = true;
			fileLoaded = topMachine->fileIn();//file read operation
			maxMenu = 6;
			cout << "\n\nMachines have been loaded in from file.\n\n";
			system("pause");
			break;
		case 2:
			do{
				system("cls");
				cout << "\n   Select the new machine's type: "
					<< "\n   1. Fountain Fluid"
					<< "\n   2. Packaged Snack"
					<< "\n   3. Bottled Beverage"
					<< "\n   4. Exit\n\n   ";
				getline(cin, menuInput);
			} while (validMenuSelect(1, 4, menuInput) == false);
			switch (stoi(menuInput)) {
			case 1:
				machineType = "fountain";
				break;
			case 2:
				machineType = "snack";
				break;
			case 3:
				machineType = "bottle";
				break;
			case 4:
				break;
			}
			if (stoi(menuInput) == 4) {
			   continue;
			}
			do{
				cout << "\n   Enter a name for the new machine: ";
				getline(cin, menuInput);
				if (validMachineName(menuInput) == false) {
					for (int b = 0; b < (34 + menuInput.length()); b++){
						cout << "\b";
					}
				}
			} while (validMachineName(menuInput) == false);
			machineName = menuInput;
			//if (machineType == "fountain") {
			//   tempFount = new Fountain();
			//   tempMachine = tempFount;
			//}
			//else if (machineType == "snack") {
			//   tempSnack = new Snack();
			//   tempMachine = tempSnack;
			//}
			//else if (machineType == "bottle") {
			//   tempBottle = new Bottle();
			//   tempMachine = tempBottle;
			//}
			//tempMachine->setName(machineName);
			cout << endl << "   " << machineType << " machine \"" << machineName << "\" has been created.\n   ";
			system("pause");
			break;
		case 3:
			/*do{*/
			system("cls");
			cout << "\n   Please select a machine to load:\n";
			/*for (int m = 0; m < numberOfMachines; m++) {
			   cout << "\n   " << (m + 1) << ". " << ptrIndexCatalog[m]->getMachineName();
			}
			cout << "\n\n";
			getline(cin, menuInput);
			} while (validMenuSelect(1, numberOfMachines - 1, menuInput) == false);*/
			//
			//convertedMenuInput = stoi(menuInput);
			//
			//do{
			//exitSubmenu = false;
			//do{
			//system("cls");
			//cout << "\n   Loading products for " + ptrIndexCatalog[convertedMenuInput]->getMachineName()
			//<< "\n   Select an action:"
			//<< "\n   1. View Products"
			//<< "\n   2. Edit Products"
			//<< "\n   3. Add a Product"
			//<< "\n   4. Return to Main Menu\n\n   ";
			//getline(cin, menuInput);													//Derrick says that there is a add items function that returns
			//} while (validMenuInput(1, 4, menuInput) == false);						//a bool that checks to see if there are too many items,
			//																			//no need to construct one yourself
			switch (stoi(menuInput)) {
			case 1:
				system("cls");
				//cout << "\n   Displaying products for " + ptrIndexCatalog[convertedMenuInput]->getMachineName();
				//for (int p = 0; p < numberOfMachines; p++) {
				//   cout << "\n" + (p+1) + ".   " + ptrIndexCatalog[convertedMenuInput]->getProductAt(p).ShowInfo();
				//}
				//cout << endl << "Press any key to return to " + ptrIndexCatalog[convertedMenuInput]->getMachineName() + " submenu";
				//_getch();
				break;
			case 2:
				system("cls");
				break;
			case 3:
				system("cls");
				//if (ptrIndexCatalog[convertedMenuInput]->AddProduct(ptrIndexCatalog[convertedMenuInput]->GetProductAt(1)))
				
				break;
			case 4:
				exitSubmenu = true;
				break;
			}
			//} while (exitSubmenu == false);
			break; 																	    
		case 4:
			//do{
			system("cls");
			cout << "\n   Please select a machine to set pricing for:\n";
			//for (int m = 0; m < numberOfMachines; m++) {
			//   cout << "\n   " + (m + 1) + ". " + ptrIndexCatalog[m]->getMachineName();
			//}
			//cout << "\n\n";
			//getline(cin, menuInput);
			//} while (validMenuSelect(1, ptrIndexCatalog.size() - 1, menuInput) == false);
			//
			//convertedMenuInput = stoi(menuInput);
			//
			//do{
			//exitSubmenu = false;
			//do{
			//system("cls");
			//cout << "\n   Pricing products for " + ptrIndexCatalog[convertedMenuInput]->getMachineName()
			//<< "\n   Select an action:"
			//<< "\n   1. View Products"
			//<< "\n   2. Edit Products"
			//<< "\n   3. Add a Product"
			//<< "\n   4. Return to Main Menu\n\n   ";
			//getline(cin, menuInput);													//Derrick says that there is a add items function that returns
			//} while (validMenuInput(1, 4, menuInput) == false);						//a bool that checks to see if there are too many items,
			//																			//no need to construct one yourself
			switch (stoi(menuInput)) {
			case 1:
				system("cls");
				//cout << "\n   Displaying products for " + ptrIndexCatalog[convertedMenuInput]->getMachineName();
				//for (int p = 0; p < numberOfMachines; p++) {
				//   cout << "\n" + (p+1) + ".   " + ptrIndexCatalog[convertedMenuInput]->getProductAt(p).ShowInfo();
				//}
				//cout << endl << "Press any key to return to " + ptrIndexCatalog[convertedMenuInput]->getMachineName() + " submenu";
				//_getch();
				break;
			case 2:
				system("cls");
				break;
			case 3:
				system("cls");
				//if (ptrIndexCatalog[convertedMenuInput]->AddProduct(ptrIndexCatalog[convertedMenuInput]->GetProductAt(1)))

				break;
			case 4:
				exitSubmenu = true;
				break;
			}
			//} while (exitSubmenu == false);
			break;
		case 5:
			system("cls");
			break;
		case 6:
			system("cls");
			break;
		case 7:
			system("cls");
			//file write operation
			cout << "Vending machine data has been written to machine.dat\n";
			exitProgram = true;
			break;
		default:
			break;
		}
	} while (exitProgram == false);
	return 0;
}

bool validMenuSelect(int lowerBound, int upperBound, string numberInput) {
	if (int(numberInput.length()) <= 0) { //first checks for no empty string
		return false;
	}
	else if (!atoi(numberInput.c_str())) { //then checks for a valid integer
		return false;
	}
	else if (atoi(numberInput.c_str()) < lowerBound || atoi(numberInput.c_str()) > upperBound) { //finally checks for integer being within range.
		return false;
	}
	return true;
}

bool validMachineName(string nameInput) {
	if (nameInput.length() <= 0) { return false; }
	for each (char letter in nameInput) {
		if (!isalpha(letter)) { return false; }
	}
	return true;
}