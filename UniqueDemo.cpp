#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
	vector<int> vCount = { 10, 20, 20, 15, 16, 20, 15, 11 };
	
	cout << "Input Array..." << endl;
	for (auto i : vCount)
	{
		cout << i << ",\t";
	}
	cout << endl;
	cout << endl;

	auto itr = unique(vCount.begin(), vCount.end());
	vCount.resize(distance(vCount.begin(), itr));
	
	cout << "Unsorted Unique Array..." << endl;
	for (auto i : vCount)
	{
		cout << i << ",\t";
	}
	cout << endl;
	cout << endl;

	vector<int> vCount2 = { 10, 20, 20, 15, 16, 20, 15, 11 };
	cout << "Input Array..." << endl;
	for (auto i : vCount2)
	{
		cout << i << ",\t";
	}
	cout << endl;
	cout << endl;

	sort(vCount2.begin(), vCount2.end());
	cout << "Sorted Array..." << endl;

	for (auto j : vCount2)
	{
		cout << j << ",\t";
	}
	cout << endl;
	cout << endl;

	auto itr2 = unique(vCount2.begin(), vCount2.end());
	vCount2.resize(distance(vCount2.begin(), itr2));
	
	cout << "Sorted Unique Array..." << endl;
	for (auto i : vCount2)
	{
		cout << i << ",\t";
	}
	cout << endl;
	cout << endl;
	return 0;
}