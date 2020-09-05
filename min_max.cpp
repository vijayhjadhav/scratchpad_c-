#include <vector>
#include <iostream>
using namespace std;

int main()
{
	vector<long int> numbers(5);
	for(int i = 0; i < 5; i++)
		cin >> numbers[i];

	long int max = 0, min = 0;
	long int sum = 0;
	int skip = 0;
	for(int i = 0; i < 5; i++)
	{
		sum = 0;
		for(int j = 0; j < 5; j++)
		{
			if(j != i)
				sum = sum + numbers[j];
		}
		if(i == 0)
		{
			max = sum;
			min = sum;
		}

		if(sum > max)
			max = sum;

		if(sum < min)
			min = sum;
	}

	cout << min << " " << max;
	return 0;
}