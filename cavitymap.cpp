#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
using namespace std;
#define MAX_DIGITS	100

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int noTestCases;
	cin >> noTestCases;
	vector<string> v;
	string input;

	for(int i = 0; i < noTestCases; i++)
	{		
		cin >> input;
		v.push_back(input);
	}

	for(int j = 0; j < noTestCases; j++)
	{
		size_t strlength = v[j].length();
		char *temp = new char[strlength+1];
		memset(temp, 0, strlength+1);
		v[j].copy(temp, strlength, 0);
		temp[strlength] = '\0';
		
		int digits[3];
		for(size_t k = 0; k+2 < strlength; k++)
		{
			digits[0] = temp[k];
			digits[1] = temp[k+1];
			digits[2] = temp[k+2];

			if((digits[1] > digits[0]) && (digits[1] > digits[2]))
			{
				temp[k+1] = 'X';
				k = k+1;
			}
		}
		
		cout << temp << endl; 
		delete[] temp;
	}
	v.clear();
    return 0;
}
