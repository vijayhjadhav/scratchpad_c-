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
	long int *K = new long int[noTestCases];
	for (int i = 0; i < noTestCases; i ++)
	{
		cin >> K[i];
	}

	for (int j = 0; j < noTestCases; j ++)
	{
		long int vertical = K[j] / 2;
		long int horizontal = vertical + K[j] % 2;
		cout << vertical * horizontal << endl;
	}

	delete[] K;
    return 0;
}