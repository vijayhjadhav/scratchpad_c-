#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
using namespace std;

using MIN_HEAP = priority_queue<int, vector<int>, greater<int>>;
using MAX_HEAP = priority_queue<int>;

void addNumber(int num, MAX_HEAP &lowers, MIN_HEAP &highers)
{
	if (lowers.size() == 0 || num < lowers.top())
		lowers.push(num);
	else
		highers.push(num);
}

void rebalance(MAX_HEAP &lowers, MIN_HEAP &highers)
{
	size_t szLowers = lowers.size();
	size_t szhighers = highers.size();

	if (abs((long long)szLowers - (long long)szhighers) >= 2)
	{
		if (szLowers > szhighers)
		{
			highers.push(lowers.top());
			lowers.pop();
		}
		else
		{
			lowers.push(highers.top());
			highers.pop();
		}
	}	
}

double getMedian(const MAX_HEAP &lowers, const MIN_HEAP &highers)
{
	size_t szLowers = lowers.size();
	size_t szhighers = highers.size();
	if (szLowers == szhighers)
		return ((double)lowers.top() + (double)highers.top()) / 2.0;

	if (szLowers > szhighers)
		return (double)lowers.top();
	else
		return (double)highers.top();
}

vector<double> getMedian(vector<int> arrNums)
{
	MAX_HEAP lowers;
	MIN_HEAP highers;
	int number;
	size_t szArrNums = arrNums.size();
	vector<double> medians(szArrNums, 0);
	for (int i = 0; i < szArrNums; i++)
	{
		number = arrNums[i];
		addNumber(number, lowers, highers);
		rebalance(lowers, highers);
		medians[i] = getMedian(lowers, highers);
	}

	return medians;
}



int main()
{
	
	vector<int> arrNums{ 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	
	cout << "input : ";
	for (auto i : arrNums)
		cout << i << "\t";
	cout << endl;

	vector<double> medians = getMedian(arrNums);
	cout << "output : ";
	for (auto i : medians)
		cout << i << "\t";

	cout << endl;


	return 0;
}

/*priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	for (auto i : { 2, 5, 45, 12, 1, 4, 7, 50, 10, 5 })
	{
		maxHeap.push(i);
		minHeap.push(i);
	}

	cout << "Max Heap....." << endl;
	while (!maxHeap.empty())
	{
		cout << maxHeap.top() << "\t";
		maxHeap.pop();
	}

	cout << endl;
	cout << endl;

	cout << "Min Heap......" << endl;
	while (!minHeap.empty())
	{
		cout << minHeap.top() << "\t";
		minHeap.pop();
	}

	cout << endl;*/