#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void displayList(int noPersons, int *listPersons);
int maxTopics(int binaryNum);
int binaryToDecimal(int binaryNum);
int decimalToBinary(int decimalNum);
int binaryStringAddition(int binaryNum1, int binaryNum2);
int factorial(int num);

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int noPersons, noTopics;
	cin >> noPersons >> noTopics;
	int *listPersons = new int[noPersons];
	for (int i = 0; i < noPersons; i++)
	{
		cin >> listPersons[i];
	}

	//displayList(noPersons, listPersons);
	int numAdditions = factorial(noPersons -1);
	int *listAdditions = new int[numAdditions];
	int *numTopics = new int[numAdditions];

	int k = 0;
	//cout << "Binary Additions..." << endl;
	for(int i = 0; i < noPersons; i++)
	{
		for(int j = i+1; j < noPersons; j++)
		{
			listAdditions[k] =  binaryStringAddition(listPersons[i], listPersons[j]);
			numTopics[k] = maxTopics(listAdditions[k]);
			//cout << listPersons[i] << "+" << listPersons[j] << " = " << listAdditions[k++] << endl;
			//cout << listAdditions[k] << "\t" << numTopics[k] << endl;
			k++;
		}
	}
	int mxTopics = *std::max_element(numTopics, numTopics+numAdditions);
	int numTeams = std::count(numTopics, numTopics+numAdditions, mxTopics);

	cout << mxTopics << endl;
	cout << numTeams << endl;

	return 0;
}

int factorial(int num)
{
	int fact = 1;
	while(num != 0)
	{
		fact = fact * num;
		num--;
	}
	return fact;
}

void displayList(int noPersons, int *listPersons)
{
	for(int i = 0; i < noPersons; i++)
	{
		cout << listPersons[i] << endl;
	}
}

int binaryToDecimal(int binaryNum)
{
	int decimal = 0;
	int rem = 0;
	int i = 0;
	while(binaryNum != 0)
	{
		rem = binaryNum % 10;
		binaryNum = binaryNum / 10;
		decimal += rem * pow(2, i);
		++i;
	}
	return decimal;
}

int decimalToBinary(int decimalNum)
{
	int rem;
	int binary = 0;
	int i = 1;

	while(decimalNum != 0)
	{
		rem = decimalNum % 2;
		decimalNum = decimalNum / 2;
		binary += rem * i;
		i *= 10;
	}	
	return binary;
}

int binaryStringAddition(int binaryNum1, int binaryNum2)
{
	return decimalToBinary(binaryToDecimal(binaryNum1) | binaryToDecimal(binaryNum2));
}

int maxTopics(int binaryNum)
{	
	//int binaryResult = 0;
	int bit = 0;
	int count = 0;
	/*for(int i = 0; i < noPersons; i++)
	{
		result = result | binaryToDecimal(listPersons[i]);
	}*/
	//binaryResult = decimalToBinary(result);
	//cout << binaryResult << endl;

	while(binaryNum != 0)
	{
		bit = binaryNum % 10;
		binaryNum /= 10;
		if(bit == 1)
			count++;
	}
	//cout << count << endl;
	return count;
}