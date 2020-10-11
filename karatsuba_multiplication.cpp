#include <iostream>
#include <cmath>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

typedef __int64 uLL;
typedef vector<int> LARGE_INTEGERS;
int glevel = 0;
uLL karatsuba(uLL x, uLL y);
LARGE_INTEGERS karatsuba(LARGE_INTEGERS x, LARGE_INTEGERS y, int level);
LARGE_INTEGERS powb10(LARGE_INTEGERS &arr, uLL& m, const uLL& multiplier, int level);
void splitArray(LARGE_INTEGERS& arr, int m, LARGE_INTEGERS& higherBits, LARGE_INTEGERS& lowerBits);
void normalizeSize(LARGE_INTEGERS& x, LARGE_INTEGERS& y);
LARGE_INTEGERS operator+(LARGE_INTEGERS num1, LARGE_INTEGERS num2);
LARGE_INTEGERS operator-(LARGE_INTEGERS num1, LARGE_INTEGERS num2);
LARGE_INTEGERS operator*(LARGE_INTEGERS& num1, LARGE_INTEGERS& num2);
void print(LARGE_INTEGERS result);
void printExp(LARGE_INTEGERS& num1, LARGE_INTEGERS& num2, LARGE_INTEGERS& result, const string& operation, int level = 0);
void printFunStartMessage(const char* sFuncName, int level);
void printFunEndMessage(const char* sFuncName, int level);
void adjustSpace(int level);

uLL karatsuba(uLL x, uLL y)
{
	if ((x < 10) && (y < 10))
		return x * y;
	
	size_t n = max(to_string(x).size(), to_string(y).size());
	uLL m = ceil(n / 2);
	
	uLL x_H = floor(x / pow(10, m));
	uLL x_L = fmod (x, pow(10, m));

	uLL y_H = floor(y / pow(10, m));
	uLL y_L = fmod(y, pow(10, m));

	uLL a = karatsuba(x_H, y_H);
	uLL d = karatsuba(x_L, y_L);
	uLL e = karatsuba(x_H + x_L, y_H + y_L) - a - d;
	
	return a * (uLL)(pow(10, m*2)) + e * (uLL)(pow(10, m)) + d;
}

LARGE_INTEGERS karatsuba(LARGE_INTEGERS x, LARGE_INTEGERS y, int level)
{
	printFunStartMessage(__func__, level);
	glevel = level;

	adjustSpace(level);
	cout << "k ( " ;
	print(x);
	cout << " , ";
	print(y);
	cout << " ) " << endl;

	// Make number of digits same in both numbers
	normalizeSize(x, y);

	size_t szX = x.size();
	size_t szY = y.size();
	LARGE_INTEGERS result;

	if ((szX < 2) && (szY < 2))
	{
		int prod = x[0] * y[0];
		int digit = 0;
		digit = prod % 10;
		prod = prod / 10;
		result.push_back(digit);
		digit = prod % 10;
		prod = prod / 10;
		if (digit > 0)
			result.insert(result.begin(), digit);

		printExp(x, y, result, "*", level);

		printFunEndMessage(__func__, level);

		return result;
	}

	size_t n = max(szX, szY);
	uLL m = ceil(n / 2);

	LARGE_INTEGERS x_H;
	LARGE_INTEGERS x_L;

	splitArray(x, m, x_H, x_L);

	LARGE_INTEGERS y_H;
	LARGE_INTEGERS y_L;

	splitArray(y, m, y_H, y_L);

	LARGE_INTEGERS a = karatsuba(x_H, y_H, level + 1);
	LARGE_INTEGERS d = karatsuba(x_L, y_L, level + 1);
	//LARGE_INTEGERS aplusd = a + d;

	LARGE_INTEGERS xHplusxL = x_H + x_L;
	LARGE_INTEGERS yHplusyL = y_H + y_L;
	//LARGE_INTEGERS xHpxLprodyHpyL = karatsuba(xHplusxL, yHplusyL, level + 1);
	//LARGE_INTEGERS e = xHpxLprodyHpyL - a - d;// aplusd;
	LARGE_INTEGERS e = karatsuba(x_H + x_L, y_H + y_L, level + 1) - a - d;
	LARGE_INTEGERS a10m2 = powb10(a, m, 2, level+1);
	LARGE_INTEGERS e10m1 = powb10(e, m, 1, level+1);
	//LARGE_INTEGERS a10m2pluse10m = a + e;

	//printExp(x, y, a10m2pluse10m, "*", level+1);

	//result = a10m2pluse10m + d;
	result = a10m2 + e10m1 + d;
	printExp(x, y, result, "*", level + 1);
	printFunEndMessage(__func__, level);
	
	return result;
	//return a * (uLL)(pow(10, m * 2)) + e * (uLL)(pow(10, m)) + d;
}

LARGE_INTEGERS powb10(LARGE_INTEGERS &arr, uLL &m, const uLL &multiplier, int level)
{
	printFunStartMessage(__func__, level);
	int numZeros = m * multiplier;

	adjustSpace(level+1);
	cout << "input number is ";
	print(arr);
	cout << endl;
	
	adjustSpace(level + 1);
	cout << "m = " << m << " multiplier = " << multiplier << endl;

	LARGE_INTEGERS result(arr);
	for (int i = 0; i < numZeros; i++)
	{
		result.push_back(0);
	}

	adjustSpace(level+1);
	cout << "output number is ";
	print(result);
	cout << endl;

	printFunEndMessage(__func__, level);
	return result;
}

void splitArray(LARGE_INTEGERS& arr, int m, LARGE_INTEGERS& higherBits, LARGE_INTEGERS& lowerBits)
{

	higherBits.resize(arr.size() -m);
	lowerBits.resize(m);
	int k = 0;
	for (int i = 0; i < higherBits.size(); i++)
	{
		higherBits[i] = arr[k];
		k++;
    }

	for (int j = 0; j < lowerBits.size(); j++)
	{
		lowerBits[j] = arr[k];
		k++;
	}
}

void normalizeSize(LARGE_INTEGERS& x, LARGE_INTEGERS& y)
{
	size_t szX = x.size();
	size_t szY = y.size();
	
	int diff = abs((int)(szX - szY));
	if (0 == diff)
		return;

	LARGE_INTEGERS::iterator iter;
	if (szX > szY)
	{
		iter = y.begin();
		y.insert(iter, diff, 0);
	}
	else
	{
		iter = x.begin();
		x.insert(iter, diff, 0);
	}
}


LARGE_INTEGERS operator+(LARGE_INTEGERS num1, LARGE_INTEGERS num2)
{
	normalizeSize(num1, num2);
	size_t szNum1 = num1.size();
	size_t szNum2 = num2.size();
	size_t szMax = max(szNum1, szNum2);
	LARGE_INTEGERS result(szMax, 0);
	int sum = 0;
	int carry = 0;
	while (szMax > 0)
	{
		sum = num1[szMax - 1] + num2[szMax - 1] + carry;
		carry = 0;
		if (sum >= 10)
		{
			carry = 1;
			sum = sum - 10;
		}
		result[szMax - 1] = sum;
		szMax--;
	}

	if (carry == 1)
	{
		result.insert(result.begin(), carry);
	}

	printExp(num1, num2, result, "+", glevel);

	return result;	
}

LARGE_INTEGERS operator-(LARGE_INTEGERS num1, LARGE_INTEGERS num2)
{
	normalizeSize(num1, num2);
	size_t szMax = max(num1.size(), num2.size());
	LARGE_INTEGERS result(szMax, 0);
	int carry = 0;
	int carryIndex = 0;
	for (int index = szMax - 1; index >= 0; index--)
	{
		if (num1[index] < num2[index])
		{
			result[index] = num1[index] - num2[index] + 10 - carry;
			carry = 1;
		}
		else
		{
			if (carry == 1 && (num1[index] > num2[index]))
			{
				result[index] = num1[index] - num2[index] - carry;
				carry = 0;
			}
			else if(carry == 1 && (num1[index] == num2[index]))
			{
				result[index] = num1[index] - num2[index] + 10 - carry;
			}
			else
			{
				result[index] = num1[index] - num2[index];
			}
		}
	}

	// remove leading zero's
	LARGE_INTEGERS::iterator iterBegin = result.begin();
	LARGE_INTEGERS::iterator iterEnd = result.begin();
	while (iterEnd != result.end() && *iterEnd == 0)
	{
		iterEnd++;
	}
	result.erase(iterBegin, iterEnd);

	printExp(num1, num2, result, "-", glevel);

	return result;	
}

LARGE_INTEGERS operator*(LARGE_INTEGERS& num1, LARGE_INTEGERS& num2)
{
	return karatsuba(num1, num2, 0);	
}

void print(LARGE_INTEGERS result)
{
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i];
	}
}

void adjustSpace(int level)
{
	for (int ntab = 0; ntab < level; ntab++)
		cout << "\t";
}

void printFunStartMessage(const char* sFuncName, int level)
{
	adjustSpace(level);
	cout << sFuncName << " : Start..." << endl;
}

void printFunEndMessage(const char* sFuncName, int level)
{
	adjustSpace(level);
	cout << sFuncName << " : End..." << endl;
}

void printExp(LARGE_INTEGERS &num1, LARGE_INTEGERS &num2, LARGE_INTEGERS &result, const string &operation, int level)
{
	size_t szNum1 = num1.size();
	size_t szNum2 = num2.size();
	size_t szResult = result.size();

	adjustSpace(level);

	for (auto& i : num1)
		cout << i;
	cout << " " << operation << " ";

	for (auto& i : num2)
		cout << i;
	cout << " = ";

	for (auto& i : result)
		cout << i;

	cout << endl;
}

int main()
{
	/*cout << sizeof(uLL) << endl;
	cout << sizeof(unsigned long long int) << endl;
	cout << karatsuba(12, 12) << endl;
	cout << karatsuba(1234, 4321) << endl;
	cout << karatsuba(999999999, 999999999) << endl;
	cout << karatsuba(999999999, 999999999) << endl;
	__int64 i = (__int64)999999999 * 999999999;
	cout << i << endl;*/
	// inputs
	// { 2, 3, 4, 5, 6, 1, 3, 4, 9, 1, 3, 5, 1 }
	// { 5, 6, 1, 2, 4, 9, 0, 8, 3, 1, 5, 3, 1 }
	// { 2, 0, 0, 6 }
	// { 1, 8, 9, 7 } 
	// { 9, 9, 9, 9, 9, 9, 9, 9, 9, 9 }
	// { 9, 9, 9, 9, 9, 9, 9, 9, 9, 9 }


	LARGE_INTEGERS num1{ 9, 9, 9, 9, 9, 9, 9, 9, 9, 9 };
	LARGE_INTEGERS num2{ 9, 9, 9, 9, 9, 9, 9, 9, 9, 9 };
	print(num1);
	print(num2);
	LARGE_INTEGERS prod = num1 * num2;

	return 0;
}