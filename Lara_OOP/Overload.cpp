#include "Overload.h"

int Overload::get_num() //return count
{//returns the numb declared in the overload class
	return num;
}

void Overload::operator!(void)
{//sets the num to zero
	num = !num;
}

bool Overload::operator == (Overload o) const
{//overload the == operator
	//if the first object is equal to the second object
	if (o.num == o.num)
	{
		//return true
		return true;
	}
	else
	{	//return false
		return false;
	}
}
