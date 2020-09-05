/*Given an array of integers, find the length of the longest sub-sequence such
that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.

Examples:
[7,6,5,4,3,2,1] => 7
[1,2,3,4,6,7,8,9,10] => 5
[2,6,1,9,4,5,3] => 6
[2,6,1,9,4,5,3,6,7] => 7
[1,9,3,10,4,20,2] => 4
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int LongestLength(vector<int> arrIntegers);

int main()
{
	int arr[] = { 7,6,5,4,3,2,1 };
	vector<int> arrIntegers();
	cout << "Longest Length" << LongestLength(arrIntegers) << endl;
	return 0;
}

//[2,6,1,9,4,5,3,6,7] => 7
int LongestLength(vector<int> arrIntegers)
{
	sort(arrIntegers.begin(), arrIntegers.end()); logN
		// Set
		// unique in vector

		// After sorting [2,6,1,9,4,5,3] => [1,2,3,4,5,6,9]
		// After sorting [2,6,1,9,4,5,3,6,7] => [1,2,3,4,5,6,6,7,9]
		count = 6
		count = 3
		size_t size = arrIntegers.size();
	int longestLen = 0;
	int count = 1;
	for (size_t index = 0; index < size; index++)
	{
		if (arrIntegers[index + 1) == (arrIntegers[index] + 1))
		count++;
		else
		{
			if (count > longestLen)
				longestLen = count;
			count = 1;
		}
	}

	return LongestLen;
}