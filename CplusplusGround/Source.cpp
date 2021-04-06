#include "Integer.h"

Integer Add(const Integer& num1, const Integer& num2)
{
	Integer temp;
	temp.setValue(num1.getValue() + num2.getValue());
	return temp;
}
int main()
{
	Integer num1(5);
	Integer num2(10);
	Integer sum = Add(num1, num2);
	return 0;
}