#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

bool GetPrimeNumbers(long long nLowerBound, long long nUpperBound, vector<long long> &nPrimeNumbers);
void printPrimeNumbers(vector<long long> nPrimeNumbers);
long long largestPrimeFactor(long long nNumber, vector<long long> nPrimeNumbers);
bool isPrime(long long lNumber);

int main()
{
	vector<long long> nPrimeNumbers;
	long long nNumber =  600851475143;
	long long nLargestPrimeFactor = 0;
	long long nUpperBound = (long long)sqrt((double)nNumber);//nNumber / 2;
	long long nLowerBound = nUpperBound - (nUpperBound / 10000);
	
	while(nLowerBound > 2)
	{
		cout << "Lowerbound = " << nLowerBound << "\t Upperbound = " << nUpperBound << endl;
		if(GetPrimeNumbers(nLowerBound, nUpperBound, nPrimeNumbers))
		{
			//printPrimeNumbers(nPrimeNumbers);
			nLargestPrimeFactor = largestPrimeFactor(nNumber, nPrimeNumbers);
			if (nLargestPrimeFactor > 0)
				break;
			nPrimeNumbers.clear();
		}

		if (nLowerBound == 3)
			break;

		nUpperBound = nLowerBound;
		if((nUpperBound / 100) > 0)
		{
			nLowerBound = nUpperBound - (nUpperBound / 10);
		}
		else
		{
			nLowerBound = 3;
		}
				
	}
	cout << nLargestPrimeFactor;
	return 0;
}

bool GetPrimeNumbers(long long nLowerBound, long long nUpperBound, vector<long long> &nPrimeNumbers)
{
	for (auto index2 = nLowerBound; index2 <= nUpperBound; index2++)
	{
		if(isPrime(index2))
			nPrimeNumbers.push_back(index2);		
				
	}
	return (!nPrimeNumbers.empty())? true: false;
}

void printPrimeNumbers(vector<long long> nPrimeNumbers)
{
	for(auto itr = nPrimeNumbers.begin(); itr != nPrimeNumbers.end(); itr++)
		cout << *itr << "\t";
}

long long largestPrimeFactor(long long nNumber, vector<long long> nPrimeNumbers)
{
	for(auto itr = nPrimeNumbers.rbegin(); itr < nPrimeNumbers.rend(); itr++)
	{
		if(nNumber % *itr == 0)
			return *itr;
	}

	return 0;
}

bool isPrime(long long lNumber)
{
	long long lMiddle = lNumber / 2;
	for (auto index = 2; index <= lMiddle; index++)
	{
		if (lNumber%index == 0)
			return false;
	}
	return true;
}