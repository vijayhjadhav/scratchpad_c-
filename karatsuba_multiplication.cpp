#include <iostream>
#include <cmath>
#include <math.h>
#include <string>
using namespace std;
typedef __int64 uLL;

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

int main()
{
	cout << sizeof(uLL) << endl;
	cout << sizeof(unsigned long long int) << endl;
	cout << karatsuba(12, 12) << endl;
	cout << karatsuba(1234, 4321) << endl;
	cout << karatsuba(999999999, 999999999) << endl;
	__int64 i = (__int64)999999999 * 999999999;
	cout << i << endl;
	return 0;
}