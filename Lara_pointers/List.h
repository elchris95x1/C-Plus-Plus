#ifndef LIST_H
#define LIST_H

#include <iostream>//main library
#include <fstream>//input and output files
#include <string>//use of getline
#include <Windows.h>//set title
#include <iomanip>//use of setw
using namespace std;

struct Person
{//person structure holds data for a person
	string fName;
	string lName;
	string age;
	string phone;
	string ssn;
};

struct link //one element of list
{
	Person data; //data item
	link* next; //pointer to next link
};


class linklist //a list of links
{
private:
	link* first; //pointer to first link
	link* curr;
public:
	int count = 0;
	linklist(); //no-argument constructor
	void inputFile();//gets file input
	void addItem(Person addData); //add data item (one link)
	void deleteItem(int n);//deletes an item
	void updateItem(Person updData, int n); //updates an item on th elist
	void display(); //display all links
	void FileOutput(); //file outpurt
	
};

#endif // !LIST_H

