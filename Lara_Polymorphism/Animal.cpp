#include "Animal.h"


void Animal::set_name(string n)
{name = n;}//Sets the animals name


void Animal::set_type(string t)
{type = t;}//Sets the typpe of animal


void Animal::set_desc(string d)
{description = d;}//Sets the description for the animal

string Animal::get_name()
{
	return name;
}

string Animal::get_type()
{
	return type;
}

string Animal::get_desc()
{
	return description;
}//Sets the description for the animal


void Species::displayAnimal()
{//Formats screen to look more professional 
	//placeholder
}

void Species::line()
{//Formats screen to look more professional 
	string line;
	line.assign(25, '=');
	cout << line << endl;
}

void Reptile::displayAnimal()
{//Displays the Information for a Reptile
	cout << "Animal Name: " << name << endl;
	cout << "Animal Type: " << type << endl;
	cout << "Description: " << description << endl;
}

void Mammal::displayAnimal()
{//Displays the Information for a Mammal
	cout << "Animal Name: " << name << endl;
	cout << "Animal Type: " << type << endl;
	cout << "Description: " << description << endl;
}

void Bird::displayAnimal()
{//Displays the Information for a Bird
	cout << "Animal Name: " << name << endl;
	cout << "Animal Type: " << type << endl;
	cout << "Description: " << description << endl;
}