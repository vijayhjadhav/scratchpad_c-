#include <iostream>
using namespace std;
constexpr int Add(int a, int b)
{
	return a + b;
}

constexpr int maxNum(int a, int b)
{
	return a > b ? a : b;
}

constexpr int minNum(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

int main()
{
	int arr[Add(2, 3)]{};

	int arr2[maxNum(5, 6)]{};

	return 0;
}