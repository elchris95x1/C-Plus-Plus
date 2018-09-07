#include "Validation.h" // includes the header file



bool wholeNumberValidation(string str)
{//validate for whole numbers
	bool inval;
	//loops until the end of the input string
	for (int i = 0; i < (int)str.size(); i++)
	{
		//if the string[i] is between 1(ascii code = 48) and 9(ascii code = 57) this runs
		if (str[i] >= '1' && str[i] <= '9')
		{
			//invalid is set to false
			inval = false;
		}
		//else invalid is set to true
		else
		{
			inval = true;
			//breaks out of the loop if a string[i] is invalid
			break;
		}
	}
	return inval;
}

bool realNumberValidation(string str)
{//validates for real numbers
	//holds invalid
	bool inval;
	//negative sign counter
	int negCounter = 0;
	//dot sign counter
	int dotCounter = 0;
	//slash sign counter
	int slaCounter = 0;
	//loops unti end of of string
	for (int i = 0; i < (int)str.size(); i++)
	{
		//if string[i] is a number, ., /, or - this runs
		if (str[i] >= '1' && str[i] <= '9' || str[i] == '/' || str[i] == '-' || str[i] == '.')
		{
			//invalid is set to false
			inval = false;
			//if string[i] = a negative sign(acsii code = 45)
			if (str[i] == 45)
			{
				negCounter++;
			}
			//if string[i] = a dot sign(acsii code = 46)
			else if (str[i] == 46)
			{
				dotCounter++;
			}
			//if string[i] = a slash sign(acsii code = 47)
			else if (str[i] == 47)
			{
				slaCounter++;
			}
			//if ., /, or - signs are repeated this runs
			if (negCounter >= 2 || dotCounter >= 2 || slaCounter >= 2)
			{
				//invalid set to true
				inval = true;
				break;
			}
		}
		//else invalid is set to true
		else
		{
			inval = true;
			break;
		}
	}
	return inval;
}

bool charactersValidation(string str)
{//validates for characters
	bool inval;
	//loops util end os string
	for (int i = 0; i < (int)str.size(); i++)
	{
		//characters are entered this runs
		if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
		{
			inval = false;
		}
		//else invalid is set to true
		else
		{
			inval = true;
			break;
		}
	}
	return inval;
}

bool phoneNumberValidation(string str)
{
	bool inval;
	//if string size is 13 this runs
	if ((int)str.size() == 13)
	{
		//loops until end of string
		for (int i = 0; i < (int)str.size(); i++)
		{
			//if string[i] are numbers or string[0]= ( or string[4]= ) or string[8] = -
			if (str[i] >= 48 && str[i] <= 57 || str[0] == 40 || str[4] == 41 || str[8] == 45)
			{
				inval = false;
			}
			//else invalid is set to true
			else
			{
				inval = true;
				break;
			}
		}
		if (str[0] != 40 || str[4] != 41 || str[8] != 45)
		{
			//setes invalid to true 
			inval = true;
		}
	}
	//else invalid is true
	else
	{
		inval = true;
	}
	return inval;
}

bool socialSecurityNumberValidation(string str)
{//validate for SSN
	bool inval;
	//if string size is 11 this runs
	if ((int)str.size() == 11)
	{
		//loops until edn of string
		for (int i = 0; i < (int)str.size(); i++)
		{
			//if string[i] is a number or string[0]= "-" or string[4]= "-"
			if (str[i] >= 48 && str[i] <= 57 || str[3] != 45 || str[6] != 45)
			{
				inval = false;
			}
			//else invalid is true
			else
			{
				inval = true;
				break;
			}
		}
		if (str[3] != 45 || str[6] != 45)
		{
			//setes invalid to true 
			inval = true;
		}
	}
	//else invalid is set to true
	else
	{
		inval = true;
	}
	return inval;
}

bool emailAddressValidation(string str)
{//validates for email address
	//holds invalid bool
	bool inval = true;
	//hold atsingn @ bool
	bool atSign = false;
	//hold dotsingn . bool
	bool dotSign = false;
	int atCounter = 0;
	int dotCounter = 0;
	//loops until end of string
	for (int i = 0; i < (int)str.size(); i++)
	{
		if (i > 0)
		{
			//if string[i] = @ and string[i-1] is not equal to @
			if (str[i] == 64 && str[i - 1] != 64)
			{
				atSign = true;
				atCounter++;
			}
			//if string[i] = . and string[i-1] is not equal to . and atsign is true
			else if (str[i] == 46 && str[i - 1] != 64 && atSign == true)
			{
				dotSign = true;
				dotCounter++;
			}
			//if atsign is true and dot sign is true inval is set to false
			else if (atSign == true && dotSign == true)
			{
				inval = false;
			}
		}
		else if (str[i] == 46 || str[i] == 64)
		{
			inval = true;
			break;
		}
	}
	//there are more than one @ or . inval is set to true
	if (dotCounter >= 2 || atCounter >= 2)
	{
		inval = true;
	}
	return inval;
}

bool dateValidation(string date)
{
	bool invalDate;
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
	return invalDate;
}

bool timeValidation(string time)
{
	bool invalTime;
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

	return invalTime;
}

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
		cout << "\n\tTry Again!!. Use The Valid Format\n\n";
	}
}

void valStatement(bool inval)
{//displays a meessage to the user whether or not the input was valid
	//if invalid
	if (inval == true)
	{
		cout << "\n\n\tWrong! Use the valid format shown in the example\n\n";
	}
	//if valid
	else if (inval == false)
	{
		cout << "\n\n\tNice! That is a Valid input\n\n";
	}
}