//Programed by Christian Lara on 5/26/2017
//Advanced C++ Programming (ITSE-2331-1031)
//Operator Overload

/*This program is just a demostration of overloaded operators, I used the == operator to work with objects.
The ! operator was overloaded to reset an object to 0*/

#include "Overload.h"
#include <iostream>
using namespace std;

int main()
{
	int num1;//holds first user inpu
	int num2;//holds second user input
	
	//asks for input
	cout << "Please Enter two numbers to be compared as objects\n";
	cout << "\nFirst Number: ";
	//gest the first user input
	cin >> num1;
	cout << "\nSecond Number: ";
	//gets the second user input
	cin >> num2;
	//declares the two objects
	Overload obj1(num1), obj2(num2);
	//compares the two objects with the == overloaded operator and if they are equal this runs
	if (num1 == num2)
	{
		//tells user the object are equal
		cout << "Equal(==) is overloaded " << obj1.get_num() << " is equal to " << obj2.get_num() << endl;
	}
	//else this runs
	else
	{
		//tells user the object are NOT equal
		cout << "Equal(==) is overloaded " << obj1.get_num() << " is NOT equal to " << obj2.get_num() << endl;
	}
	
	//the fist object is reseted to 0 with the ! overloaded operator
	!obj1;
	cout << "Non Equal(!=) is overloaded " << obj1.get_num() << endl;
	

	return 0;
}