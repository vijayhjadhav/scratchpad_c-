#include <iostream>
using namespace std;

void Print(int& x)
{
	cout << "Print(int&)" << endl;
}

void Print(const int& x)
{
	cout << "Print(const int&)" << endl;
}

void Print(int&& x)
{
	cout << "Print(int&&)" << endl;
}
int& Add(int num1, int num2, int& sum)
{
	sum = num1 + num2;
	return sum;
}

int Sub(int num1, int num2)
{
	return num1 - num2;
}

int main()
{
	int x = 5;
	Print(x);
	Print(10);

	int& y = x;
	//int& w = 0;
	int&& z = 5;

	int num1 = 3;
	int num2 = 4;
	int sum{};
	int& p = Add(num1, num2, sum);
	int&& q = Sub(num1, num2);
	return 0;
}