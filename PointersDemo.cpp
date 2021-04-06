#include <iostream>
using namespace std;
void factorial(int* a, int* result);
void swap(int& num1, int& num2);
void PointerRefDemo();
int main()
{	
	int a{ 4 };
	int result{ 0 };

	cout << a << "\t" << result << endl;
	factorial(&a, &result);
	cout << a << "\t" << result << endl;

	int num1{ 5 };
	int num2{ 10 };

	cout << num1 << "\t" << num2 << endl;
	swap(num1, num2);
	cout << num1 << "\t" << num2 << endl;


	return 0;
}

void PointerRefDemo()
{
	int x = 5;
	const int MAX = 20;
	int& ref_x = x;
	const int& ref_Max = MAX;
	
	const int* ptr = &MAX;  // Valid
	const int* ptr2 = &MAX;  // Cannot convert from 'cont int *' to 'int *'

	const int& r1 = ref_x;  // Valid

	const int& ref_cx = x;
	const int& r2 = ref_cx;  // Cannot convert from 'const int' to 'int &'

	const int* ptr1 = &x;
	const int* p_ref1 = ptr1; // cannot convert from 'const int*' to 'int *&'

	int* const ptr3 = &x;
	const int* p_ref2 = ptr3; // cannot convert from 'int *const ' to 'const int *&'

	cout << "ref_x = " << ref_x << endl;
	cout << "ref_Max = " << ref_Max << endl;
	cout << "ref_cx = " << ref_cx << endl;

	ref_x = 10;
	//ref_Max = 15;
	//ref_cx = 25;

	cout << "ref_x = " << ref_x << endl;
	cout << "ref_Max = " << ref_Max << endl;
	cout << "ref_cx = " << ref_cx << endl;


}

void factorial(int* a, int* result)
{
	int temp{ *a };
	int fact{ 1 };

	while (temp > 0)
	{
		fact = fact * temp;
		temp--;
	}

	*result = fact;
}

void swap(int& num1, int& num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}