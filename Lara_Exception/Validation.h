#ifndef VALIDATION_H
#define VALIDATION_H

#include <iostream>//main library
#include <string>//need for getlines
#include <Windows.h> //need for sleep

using namespace std;

class Valid //a class
{
public:
	class AnError //exception class
	{
	public:
		AnError(std::string); // constructor
		void errorMessage();
	private:
		std::string _errorType;
	};
	

	//Prototypes declarations
	bool Valid::wholeNumberValidation(std::string str);
	bool Valid::realNumberValidation(std::string str);
	bool Valid::charactersValidation(std::string str);
	bool Valid::phoneNumberValidation(std::string str);
	bool Valid::socialSecurityNumberValidation(std::string str);
	bool Valid::emailAddressValidation(std::string str);
	void Valid::numbBetween(std::string str, bool &inval, int sI1, int sI2, int smallestNum, int gratesNum);
	bool Valid::dateValidation(std::string date);
	bool Valid::timeValidation(std::string time);
	void Valid::valStatement(bool inval);

};

#endif // !1
