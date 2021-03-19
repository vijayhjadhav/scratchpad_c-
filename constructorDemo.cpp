#include <iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		val1 = 1;
	}

	Base(int value) : Base()  // Delegate base constructor
	{
		val2 = value;
	}

	int val1;
	int val2;
};

class subclass : public Base
{
public:
	using Base::Base;  // inheritance constructor
};

int main()
{
	Base bobj(3);
	subclass sobj(3);
	return 0;
}