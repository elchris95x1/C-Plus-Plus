//Programmed by Christian Lara on 5/12/2017
//Advanced C++ Programming (ITSE-2331-1031)
//Date & Time Validation

/*This program validates for a set format in date and time input from the user
we'll use acci codes to validate for numbers*/

#include <iostream> //main library
#include <string> //needed to use getlines
#include <Windows.h>//needed to set the console title

using namespace std;
//////Prototypes
void numbBetween(string date, bool &inval, int sI1, int sI2, int smallestNum, int gratesNum);

int main()
{
	//sets console title
	SetConsoleTitle("Date & Time Validation");
	//holds the date input
	string date;
	//holds the time input
	string time;
	//used to check for date validation
	bool invalDate;
	//used to check for time validation
	bool invalTime;


	//******do while for the date input
	do {
		//resets invalid date to false each time it loops
		invalDate = false;
		//asks user for a date
		cout << "Please provide a Date in the following format MM/DD/YYYY\n";
		//gets the user input and store it
		getline(cin, date);
		//if the user input is 10 characters long this runs
		if (date.size() == 10)
		{
			//loops the number of characters in the string
			for (int i = 0; i < (int)date.size(); i++)
			{
				//if input are numbers this runs, use of ACCI codes
				if (date[i] > 47 && date[i] < 58)
				{
					//if a number was inputed, invalDate is set to false
					invalDate = false;
					//this if statement is cheking for the two / / in the date format
					if (date[2] != 47 || date[5] != 47)
					{
						//setes invalid to true 
						invalDate = true;
						//tells user the format is wrong
						cout << "\n\tTry Again!!. Use this format MM/DD/YYYY  :)\n\n";
						//breaks out of the for loop
						break;
					}
				}
				//else if the input contain the two / / this runs
				else if (date[2] == 47 || date[5] == 47)
				{
					//invalid is set to false beacause twose caracter are permited at that location
					invalDate = false;
				}
				//else any other input this runs
				else
				{
					//invalid is set to true 
					invalDate = true;
					//the user is told to try again
					cout << "\n\tTry Again!!. Use this format MM/DD/YYYY\n\n";
					break;
				}
			}
		}
		//else if the first if statement is false
		else
		{
			//the user is told to enter valid amount of characters
			cout << "\n\tTry Again!!. Enter the right amnount of characters\n\n";
			//invalid is true
			invalDate = true;
		}
		//these if statement further validates for a posible date input not just the format
		if (invalDate == false)
		{
			//calls the numbetween function for first two values on the date
			numbBetween(date, invalDate, 0, 1, 01, 12);
			//calls the numbetween function for 3 and 4 values on the date
			numbBetween(date, invalDate, 3, 4, 01, 31);
			//calls the numbetween function for 8 and 9 values on the date
			numbBetween(date, invalDate, 8, 9, 01, 120);
		}
		//loops while invalid is true
	} while (invalDate == true);


	//******do while for the time input
	do{
		//resets invalid time to false each time it loops
		invalTime = false;
		//asks user for a date
		cout << "Please provide a Time in the following format HH:MM:SS\n";
		//gets the user input and store it
		getline(cin, time);
		//if the user input is 8 characters long this runs
		if (time.size() == 8)
		{
			//loops the number of characters in the string
			for (int i = 0; i < (int)time.size() - 1; i++)
			{
				//if input are numbers this runs, use of ACCI codes
				if (time[i] > 47 && time[i] < 58)
				{
					//setes invalid to false 
					invalTime = false;
					//this if statement is cheking for the two : : in the date format
					if (time[2] != 58 || time[5] != 58)
					{
						//setes invalid to true 
						invalTime = true;
						//tells user the format is wrong
						cout << "\n\tTry Again!!. Use this format HH:MM:SS :(\n\n";
						//breaks out of the for loop
						break;
					}
				}
				//else if the input contain the two : : this runs
				else if (time[2] == 58 || time[5] == 58)
				{
					//setes invalid to false
					invalTime = false;
				}
				//else any other input this runs
				else
				{
					//invalid is set to true 
					invalTime = true;
					//the user is told to try again
					cout << "\n\tTry Again!!. Use this format HH:MM:SS\n\n";
					break;
				}
			}
		}
		//else if the first if statement is false
		else
		{
			//the user is told to enter valid amount of characters
			cout << "\n\tTry Again!!. Enter the right amnount of characters\n\n";
			//invalid is true
			invalTime = true;
		}
		//these if statement further validates for a posible time input not just the format
		if (invalTime == false)
		{
			//calls the numbetween function for 0 and 1 values on the time
			numbBetween(time, invalTime, 0, 1, 01, 24);
			//calls the numbetween function for 3 and 4 values on the time
			numbBetween(time, invalTime, 3, 4, 00, 60);
			//calls the numbetween function for 6 and 7 values on the time
			numbBetween(time, invalTime, 6, 7, 00, 60);
		}
		//loops while invalid is true
	} while (invalTime == true);
	

	//clears the console
	system("cls");
	//teslls the final valid date and time
	cout << "The correct date and time of the event is: " << date << " " << time << endl << endl;

	return 0;
}

//This functions lets the programmer determine two string indexes then it cast them into a int to validate 
//for a particular range of numbers, it also lets the programmer chose the range of values
void numbBetween(string str, bool &inval, int sI1, int sI2, int smallestNum, int gratesNum)
{
	
	//********Keyboard definitions************//

	//gratesNum-----used to determine greates number allowed
	//smallestNum---used to determine smallest number allowed
	//sI1-----------index of the left part of the string
	//sI2-----------index of the right part of the string


	//used to hold the string indexes
	string strToInt;
	//puts toghether two string indexes
	strToInt = strToInt + str[sI1] + str[sI2];
	//cast strring into integer
	int testint = atoi(strToInt.c_str());
	//testes for out of range numbers with
	if (testint < smallestNum || testint > gratesNum)
	{
		//setes invalid to true 
		inval = true;
		//tells user the format is wrong
		cout << "\n\tTry Again!!. Use a Valid Date or time\n\n";
	}

	//**********LEGACY CODE
	//if (date[sI1] > 49 || date[sI2] == 48)
	//{
	//	//setes invalid to true 
	//	invalDate = true;
	//	//tells user the format is wrong
	//	cout << "\n\tTry Again!!. There are 12 months in a year\n\n";
	//}
	//else if (date[sI1] == 49 && date[sI2] > 50)
	//{
	//	//setes invalid to true 
	//	invalDate = true;
	//	//tells user the format is wrong
	//	cout << "\n\tTry Again!!. Years only have 12 months\n\n";
	//}
	 
}

