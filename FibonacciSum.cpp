#include <iostream>
using namespace std;

int main()
{
	long long a = 1, b = 2;
	long long index = 0;
	long long sum = 2;
	long long temp = 2;
	//cout << a << "\t" << b;
	while (temp <= 4000000)
	{
		temp = a + b;
		if(temp % 2 == 0)
			sum = sum + temp;
		
		a = b;
		b = temp;		
	}

	cout << sum << endl;
	return 0;
}