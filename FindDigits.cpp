#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
	int noTestCases;
	cin >> noTestCases;
	long unsigned int *N = new long unsigned int[noTestCases];
	for (int i = 0; i < noTestCases; i++)
	{
		cin >> N[i];
	}

	for (int i = 0; i < noTestCases; i++)
	{
		long unsigned int temp = N[i];
		int count = 0;
		do
		{
			int digit = temp % 10;
			if (digit > 0)
			{
				if(N[i] % digit == 0)
					count++;
			}
			temp = temp / 10;
		}while(temp > 0);

		cout << count << endl;
	}
    return 0;
}
