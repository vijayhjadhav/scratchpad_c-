#include <iostream>
using namespace std;

template<typename T, int size>
void Print(T (&arr)[size])
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
}

int main()
{
	int arr[]{ 2, 3, 4 ,5 };
	float farr[]{ 2.4f, 5.6f, 7.2f, 10.3f, 50.4f };
	Print(arr);
	Print(farr);
	return 0;
}