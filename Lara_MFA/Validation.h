#ifndef VALIDATION_H
#define VALIDATION_H

#include <iostream>//main library
#include <string>//need for getlines
#include <Windows.h> //need for sleep
using namespace std;

//Prototypes declarations
bool wholeNumberValidation(string str);
bool realNumberValidation(string str);
bool charactersValidation(string str);
bool phoneNumberValidation(string str);
bool socialSecurityNumberValidation(string str);
bool emailAddressValidation(string str);
bool dateValidation(string date);
bool timeValidation(string time);
void numbBetween(string str, bool &inval, int sI1, int sI2, int smallestNum, int gratesNum);
void valStatement(bool inval);



#endif // !1
