#include <iostream>
using namespace std;
void Factorial(int* a, int* result)
{
	int temp{ *a };
	int fact{ 1 };

	while (temp != 0)
	{
		fact = fact * temp;
		temp--;
	}
	*result = fact;
}

int main()
{
	/*long long a = 1, b = 2;
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

	cout << sum << endl;*/

	int a{ 5 };
	int result{ 0 };
	Factorial(&a, &result);

	cout << "Factorial of " << a << " is " << result << endl;
	return 0;
}