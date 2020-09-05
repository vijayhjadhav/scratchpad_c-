#include <iostream>
using namespace std;

int main()
{
	long long number = 13195;
	long long Factor = number / 2;
	while (Factor > 1)
	{
		if (number % Factor == 0)
			cout << Factor << "\t";
		Factor--;
	}
	return 0;
}