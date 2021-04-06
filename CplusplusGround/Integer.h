#pragma once
#include <iostream>
using namespace std;
class Integer
{
public:
	Integer();
	Integer(int val);
	~Integer();
	int getValue() const;
	void setValue(int val);
	int* getptrValue();
	void setptrValue(int* val);
	
	// Copy value semantics
	Integer(const Integer& other);

	// Copy move semantics
	Integer(Integer&& other);

	// insertion operator
	friend ostream& operator<<(ostream& os, const Integer& iobj);

private:
	int* mValue;
};


