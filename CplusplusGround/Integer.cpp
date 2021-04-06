#include "Integer.h"
#include <iostream>
using namespace std;

Integer::Integer()
{
	cout << "Integer::Integer() called" << endl;
	mValue = new int(0);
	
}

Integer::Integer(int val)
{
	cout << "Integer::Integer(int val) called" << endl;
	mValue = new int(val);
}

Integer::~Integer()
{
	cout << "Integer::~Integer() called" << endl;
	if (mValue != nullptr)
	{
		delete mValue;
		mValue = nullptr;
	}
	
}

int Integer::getValue() const
{
	return *mValue;
}

void Integer::setValue(int val)
{
	*mValue = val;
}

int* Integer::getptrValue()
{
	return mValue;
}

void Integer::setptrValue(int* val)
{
	mValue = val;
}

Integer::Integer(const Integer& other)
{
	cout << "Integer::Integer(const Integer& ) called" << endl;
	mValue = new int(other.getValue());
}

Integer::Integer(Integer&& other)
{
	cout << "Integer::Integer(Integer&& ) called" << endl;
	mValue = other.getptrValue();
	other.setptrValue(nullptr);
}

ostream& operator<<(ostream& os, const Integer& iobj)
{
	os << iobj.getValue();
	return os;
}