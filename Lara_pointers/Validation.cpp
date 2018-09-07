#include "Validation.h" // includes the header file


bool Valid::ListSelection(string str, int rowCount)
{//validate for whole numbers
	try
	{
		bool inval;
		int strToInt = stoi(str);//cats the string to an int
		//loops until the end of the input string
		for (int i = 0; i < (int)str.size(); i++)
		{
			//if the string[i] is between 1(ascii code = 48) and 9(ascii code = 57) this runs
			if (str[i] >= '1' && str[i] <= '9' &&  strToInt <= rowCount)
			{
				//invalid is set to false
				inval = false;
			}
			//else invalid is set to true
			else
			{
				cout << "\n\tWrong! Use a valid option from the list\n\n";
				inval = true;
				//breaks out of the loop if a string[i] is invalid
				break;
			}
		}
		return inval;
	}
	catch (const std::exception&)
	{
		cout << "\n\tWrong! Use a valid option from the list\n\n";
		return true;
	}
	
}

bool Valid::wholeNumberValidation(string str)
{//validate for whole numbers
	bool inval;
	//loops until the end of the input string
	for (int i = 0; i < (int)str.size(); i++)
	{
		//if the string[i] is between 1(ascii code = 48) and 9(ascii code = 57) this runs
		if (str[i] >= 48 && str[i] <= 57)
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

bool Valid::charactersValidation(string str)
{//validates for characters
	bool inval;
	//loops util end os string
	for (int i = 0; i < (int)str.size(); i++)
	{
		//characters are entered this runs
		if (str[i] >= 65 && str[i] <= 89 || str[i] >= 97 && str[i] <= 122)
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

bool Valid::phoneNumberValidation(string str)
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

bool Valid::socialSecurityNumberValidation(string str)
{//validate for SSN
	bool inval;
	//if string size is 11 this runs
	if ((int)str.size() == 11)
	{
		//loops until edn of string
		for (int i = 0; i < (int)str.size(); i++)
		{
			//if string[i] is a number or string[0]= "-" or string[4]= "-"
			if (str[i] >= 48 && str[i] <= 57 || str[3] == 45 || str[6] == 45)
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

void Valid::valStatement(bool inval)
{//displays a meessage to the user whether or not the input was valid
 //if invalid
	if (inval == true)
	{
		cout << "\n\tWrong! Use the valid format shown in the example\n\n";
	}
	//if valid
	else if (inval == false)
	{
		//nothingc
	}
}
