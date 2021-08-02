#include <iostream>
#include <algorithm>
#include <vector>
#include <thread>
using namespace std;

bool isMultiple(int n)
{
	return n % 3 == 0;
}

class addnums
{
public:
	void operator()(int num1, int num2)
	{
		cout << "additions: " << num1 + num2 << endl;
	}
};

int main()
{
	
	std::thread threadObj((addnums()), 4, 5);
	threadObj.join();

	addnums addnumsobj;
	std::thread threadObj2(addnumsobj, 14, 5);

	threadObj2.join();

	//vector<int> numbers{ 1,2,3,4,5,6,7,8,9,10 };
	////vector<int> numbers{ 3, 6, 9, 12 };
	//if (all_of(numbers.begin(), numbers.end(), isMultiple))
	//	cout << "all the numbers are multiple of 3" << endl;

	//if(any_of(numbers.begin(), numbers.end(), isMultiple))
	//	cout << "some of the numbers are multiple of 3" << endl;
	return 0;
}