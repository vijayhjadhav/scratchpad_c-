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

	// Copy assignment operat
	Integer& operator=(const Integer& other);

	// Move assignment operator
	Integer& operator==(Integer&& other);

	// + operator 
	Integer operator+(const Integer& other) const;

	//Pre Increment operator
	Integer& operator++();

	//  Post Increment operator
	Integer operator++(int);

	// Comparison operator
	bool operator==(const Integer& other) const;

	// insertion operator
	friend ostream& operator<<(ostream& os, const Integer& iobj);

	//conversion operator
	//explicit operator int();
	operator int();

private:
	int* mValue;
};


