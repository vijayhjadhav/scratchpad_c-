#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool isMultiple(int n)
{
	return n % 3 == 0;
}


int main()
{

	
	vector<int> numbers{ 1,2,3,4,5,6,7,8,9,10 };
	//vector<int> numbers{ 3, 6, 9, 12 };
	if (all_of(numbers.begin(), numbers.end(), isMultiple))
		cout << "all the numbers are multiple of 3" << endl;

	if(any_of(numbers.begin(), numbers.end(), isMultiple))
		cout << "some of the numbers are multiple of 3" << endl;
	return 0;
}