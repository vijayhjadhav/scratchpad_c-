#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void numOperations(int size, int *arrayL);
int leastLength(int size, int *arrayL);

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int noSticks;
	cin >> noSticks;
	int *arrayLength = new int[noSticks]; 
	for(int i = 0; i < noSticks; i++)
	{
		cin >> arrayLength[i];
	}

	numOperations(noSticks, arrayLength);
	delete[] arrayLength;	
    return 0;
}

int leastLength(int size, int *arrayL)
{
	return *std::min_element(arrayL, arrayL+size);
}

void numOperations(int size, int *arrayL)
{
	int *temp = new int[size];
	int newLength = 0;
	for (int i = 0; i < size; i++)
	{
		if(arrayL[i] > 0)
			temp[newLength++] = arrayL[i];
	}

	if (newLength != 0)
	{
		int lLength = leastLength(newLength, temp);
		int count = 0;
		for (int i = 0; i < newLength; i++)
		{
			temp[i] = temp[i] - lLength;
			count++;
		}
		cout << count << endl;
		numOperations(newLength, temp);
		delete[] temp;
		return;
	}
	else
	{
		delete[] temp;
		return;
	}
}