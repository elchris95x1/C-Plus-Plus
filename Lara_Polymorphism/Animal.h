#ifndef H__ANIMAL
#define H__ANIMAL

#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

class Animal
{//Base class for all animals
protected://Variables for animals
	string name;
	string type;
	string description;

public:
	void set_name(string n);

	void set_type(string t);

	void set_desc(string d);

	string get_name();

	string get_type();

	string get_desc();

};

class Species : public Animal
{//SubClass for animals
public:

	void line();
	virtual void displayAnimal();
};

class Reptile : public Species
{//Subclass for animals into Reptiles

public:
	void displayAnimal();
};
class Mammal : public Species
{//Subcclass for animals into Mammals

public: 

	void displayAnimal();
};
class Bird : public Species
{//Subclass for animals into Birds

public:
	void displayAnimal();
};
#endif
