#include "List.h"

linklist::linklist() //constructor
{
	first = NULL;
	curr = NULL;
} //no gives a values to curr and first

//--------------------------------------------------------------
void linklist::addItem(Person addData) //add data item
{
	link* newlink = new link;//alloacates memory for new link
	newlink->next = NULL;//new link next is set to null
	newlink->data = addData;//the data of the new link is set to the data passed on the function
	if (first != NULL)//if first pointer is not null means first pointer is created already
	{
		curr = first;//current pointer is set to first pointer
		while (curr->next != NULL) //loops if the next pointer is not null
		{
			curr = curr->next;//sets current = last value of the list
		}
		curr->next = newlink;//sets pointer = to last value in the list
	}
	else
	{
		first = newlink;//else the first pointer is = to the newlink pointer
	}
}

void linklist::deleteItem(int n) 
{ //Delete node at position n
	link* temp1 = first;//creates a temp pointer of the struct
	if (n == 1) { //if number is 1
		first = temp1->next; //head now points to second node
		delete temp1;//delete temp pointer
		return;//return to main
	}
	for (int i = 0; i < n - 2; i++) 
		temp1 = temp1->next; //temp1 points to (n - 1)th Node
	link* temp2 = temp1->next; //nth Node
	temp1->next = temp2->next; // (n + 1)th Node
	delete temp2;//delte temp 2
}

void linklist::updateItem(Person updData, int n)
{//updates an item on the list
	deleteItem(n);//deletes the curent item
	link* temp1 = new link();//creates a temp pointer
	temp1->data = updData;//temp data = to data provided vy user
	temp1->next = NULL;//the pointer on the struct is set to null
	if (n == 1) {//if number is 1
		temp1->next = first;//the pointer on struct is set to the first pointer
		first = temp1;//the first pointer is set to temp1
		return;//return to main
	}
	link* temp2 = first;//temp2 = to firt pointer
	for (int i = 0; i < n-2; i++) {//loops until n-2 is more than i
		temp2 = temp2->next;//temp2 = to temp2 next pointer
	}
	temp1->next = temp2->next;//the next of temp1 = the next of temp 2
	temp2->next = temp1; //temp2 next = temp1
}

//--------------------------------------------------------------
void linklist::display() //display all links
{
	count = 0;
	link* current = first; //set ptr to first link
	//displays first row on the display function
	cout << left << fixed << setw(8) << "RowNum"
		<< left << fixed << setw(15) << "First Name"
		<< left << fixed << setw(15) << "Last Name"
		<< left << fixed << setw(10) << "Age"
		<< left << fixed << setw(15) << "Phone"
		<< left << fixed << setw(15) << "SSN" << endl;
	//dislpays alll content on the file 
	while (current != NULL) //quit on last link
	{
		count++;//keeps a counter of all records
		cout << left << fixed << setw(8) << count//outpus counter
			<< left << fixed << setw(15) << current->data.fName
			<< left << fixed << setw(15) << current->data.lName
			<< left << fixed << setw(10) << current->data.age
			<< left << fixed << setw(15) << current->data.phone
			<< left << fixed << setw(15) << current->data.ssn << endl;
		current = current->next; //move to next link
	}
}

void linklist::inputFile()
{
	try
	{
		ifstream file("data.csv"); // declare file stream
		Person p;
		while (file.good())
		{
			// read a string until next comma
			getline(file, p.fName, ',');
			getline(file, p.lName, ',');
			getline(file, p.age, ',');
			getline(file, p.phone, ',');
			getline(file, p.ssn);
			//add the current populated person
			if (p.fName != "") {//add item to list only if all data is in the file
				addItem(p);//adds item to list
			}
		}
		file.close();//closes file
	}
	catch (exception ex)
	{//if file not found 
		cout << "Error Reading the file";
	}

}

void linklist::FileOutput() //file outpurt
{
	ofstream myfile;
	myfile.open("data.csv");//opens file
	string strOut;
	link* current = first; //set ptr to first link
	while (current != NULL) //quit on last link
	{
		//concatinates all data into a string
		strOut = current->data.fName + ","
			+ current->data.lName + ","
			+ current->data.age + ","
			+ current->data.phone + ","
			+ current->data.ssn;
		//saves string in file
		myfile << strOut << endl;
		current = current->next; //move to next link
	}
	myfile.close();//closes file
}

