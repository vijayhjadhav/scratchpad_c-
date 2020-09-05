#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long minimumAmount(int noBlackGifts, int noWhiteGifts, int X, int Y, int Z);

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int noTestCases;
	cin >> noTestCases;

	int *noBlackGifts = new int[noTestCases]; 
	int *noWhiteGifts = new int[noTestCases];
	int *X = new int[noTestCases]; 
	int *Y = new int[noTestCases];
	int *Z = new int[noTestCases];

	for(int i = 0; i < noTestCases; i++)
	{
		cin >> noBlackGifts[i] >> noWhiteGifts[i];
		cin >> X[i] >> Y[i] >> Z[i];
	}

	for(int j = 0; j < noTestCases; j++)
	{
		printf("%lld\n", minimumAmount(noBlackGifts[j], noWhiteGifts[j], X[j], Y[j], Z[j]));
	}

	delete[] noBlackGifts;
	delete[] noWhiteGifts;
	delete[] X;
	delete[] Y;
	delete[] Z;
    return 0;
}

long long minimumAmount(int noBlackGifts, int noWhiteGifts, int X, int Y, int Z)
{
//int noReducedAmount = noBlackGifts * X + noWhiteGifts * Y;

	if(X < Y)
	{
		if(X+Z < Y)
			Y = X+Z;
	}
	else
	{
		if(Y+Z < X)
			X = Y+Z;
	}

	return ((long long)noBlackGifts) * X + ((long long)noWhiteGifts) * Y;
}