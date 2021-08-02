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
	Integer num3 = 40;

	Integer sum2 = Add(50, 20);
	// when explicit is not used with operator int()
	int y = num1;

	// When explicit is used with operator int()
	int x = static_cast<int>(num1);
	cout << x << endl;
	return 0;
}