#ifndef VALIDATION_H
#define VALIDATION_H

#include <iostream>//main library
#include <string>//need for getlines
#include <Windows.h> //need for sleep

using namespace std;

class Valid //a class
{
public:
	//Prototypes declarations
	bool Valid::ListSelection(string str, int rowCount);
	bool Valid::wholeNumberValidation(std::string str);//validates for whole numbers
	bool Valid::charactersValidation(std::string str);//vallidates for character a-Z
	bool Valid::phoneNumberValidation(std::string str); // validates for phone numbers
	bool Valid::socialSecurityNumberValidation(std::string str);//valodates for ssn
	void Valid::valStatement(bool inval);//displays a statement if wrong input is given
};

#endif // !1
