#include <iostream>
#include <cmath>
#include <math.h>
#include <string>
#include <vector>
using namespace std;
typedef __int64 uLL;

uLL karatsuba(uLL x, uLL y);
vector<int> karatsuba(vector<int> x, vector<int> y);
void powb10(vector<int> &arr, uLL& m, const uLL& multiplier);
void splitArray(vector<int>& arr, int m, vector<int>& higherBits, vector<int>& lowerBits);
void normalizeSize(vector<int>& x, vector<int>& y);
vector<int> operator+(vector<int> num1, vector<int> num2);
vector<int> operator-(vector<int> num1, vector<int> num2);
vector<int> operator*(vector<int>& num1, vector<int>& num2);
void print(vector<int> result);

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

vector<int> karatsuba(vector<int> x, vector<int> y)
{
	// Make number of digits same in both numbers
	normalizeSize(x, y);

	size_t szX = x.size();
	size_t szY = y.size();
	vector<int> result;

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
		return result;
	}

	size_t n = max(szX, szY);
	uLL m = ceil(n / 2);

	vector<int> x_H;
	vector<int> x_L;

	splitArray(x, m, x_H, x_L);

	vector<int> y_H;
	vector<int> y_L;

	splitArray(y, m, y_H, y_L);

	vector<int> a = karatsuba(x_H, y_H);
	vector<int> d = karatsuba(x_L, y_L);
	vector<int> xHplusxL = x_H + x_L;
	vector<int> yHplusyL = y_H + y_L;
	vector<int> aplusd = a + d;
	vector<int> xHpxLprodyHpyL = karatsuba(xHplusxL, yHplusyL);
	vector<int> e = xHpxLprodyHpyL - aplusd;
	powb10(a, m, 2);
	powb10(e, m, 1);
	vector<int> a10m2pluse10m = a + e;
	return a10m2pluse10m + d;

	//return a * (uLL)(pow(10, m * 2)) + e * (uLL)(pow(10, m)) + d;
}

void powb10(vector<int> &arr, uLL &m, const uLL &multiplier)
{
	int numZeros = m * multiplier;

	for (int i = 0; i < numZeros; i++)
	{
		arr.push_back(0);
	}
}

void splitArray(vector<int>& arr, int m, vector<int>& higherBits, vector<int>& lowerBits)
{
	higherBits.resize(m);
	lowerBits.resize(arr.size()-m);

	for (int i = 0; i < m; i++)
	{
		higherBits[i] = arr[i];
    }

	for (int j = m; j < arr.size(); j++)
	{
		lowerBits[j - m] = arr[j];
	}
}

void normalizeSize(vector<int>& x, vector<int>& y)
{
	size_t szX = x.size();
	size_t szY = y.size();
	int diff = abs((int)(szX - szY));
	
	if (0 == diff)
		return;

	vector<int>::iterator iter;
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

vector<int> operator+(vector<int> num1, vector<int> num2)
{
	normalizeSize(num1, num2);
	size_t szNum1 = num1.size();
	size_t szNum2 = num2.size();
	size_t szMax = max(szNum1, szNum2);
	vector<int> result(szMax, 0);
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

	return result;
}

vector<int> operator-(vector<int> num1, vector<int> num2)
{
	normalizeSize(num1, num2);
	size_t szMax = max(num1.size(), num2.size());
	vector<int> result(szMax, 0);
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
			result[index] = num1[index] - num2[index] - carry;
			carry = 0;
		}
	}

	// remove leading zero's
	vector<int>::iterator iterBegin = result.begin();
	vector<int>::iterator iterEnd = result.begin();
	while (iterEnd != result.end() && *iterEnd == 0)
	{
		iterEnd++;
	}
	result.erase(iterBegin, iterEnd);

	return result;
}

vector<int> operator*(vector<int>& num1, vector<int>& num2)
{
	return karatsuba(num1, num2);
}

void print(vector<int> result)
{
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i];
	}
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


	vector<int> num1{ 2,0,0,6 };
	vector<int> num2{ 1,8,9,7 };
	print(num1);
	print(num2);
	//vector<int> sum = num1 + num2;
	//vector<int> sub = num1 - num2;
	vector<int> prod = num1 * num2;
	
	//print(sum);
	print(prod);
	//print(sub);
	
	return 0;
}