#ifndef OVERLOAD_H
#define OVERLOAD_H

class Overload //declares class
{
private:
	//holds the number from the user
	int num;
public:
	//constructor set the num variable
	Overload(int myNum) :num(myNum) {};
	//prototypes
	int get_num(); //return the num
	void operator !(void);//overloads the ! operator
	bool operator == (Overload o) const;//overloads the == operator
};

#endif // !1

