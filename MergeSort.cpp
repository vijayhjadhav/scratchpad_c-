#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int>& vArray, int left, int middle, int right);

void mgSort(vector<int> &vArray, int left, int right)
{
	if (left < right)
	{
		int middle = (left+right) / 2;
		mgSort(vArray, left, middle);
		mgSort(vArray, middle + 1, right);
		merge(vArray, left, middle, right);
	}
}

void merge(vector<int>& vArray, int left, int middle, int right)
{
	vector<int> vTempArray;
	int i = left;
	int j = middle + 1;
	while (i <= middle && j <= right)
	{
		if (vArray[i] <= vArray[j])
		{
			vTempArray.push_back(vArray[i]);
			i++;
		}
		else
		{
			vTempArray.push_back(vArray[j]);
			j++;
		}
	}

	while (i <= middle)
	{
		vTempArray.push_back(vArray[i]);
		i++;
	}

	while (j <= right)
	{
		vTempArray.push_back(vArray[j]);
		j++;
	}

	int k = 0;
	for (int i = left; i <= right; i++)
	{
		vArray[i] = vTempArray[i-left];
	}
}

void printArray(vector<int> vArray)
{
	size_t sz = vArray.size();
	for (int i = 0; i < sz; i++)
	{
		cout << vArray[i] << "\t";
	}

	cout << endl;
}

int main()
{
	vector<int> vArray{ 23,45,24,5,7,9,10, 15 };
	printArray(vArray);
	mgSort(vArray, 0, vArray.size() - 1);
	printArray(vArray);
	return 0;
}