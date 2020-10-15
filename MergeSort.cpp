#include <iostream>
#include <vector>
using namespace std;
int merge(vector<int>& vArray, int left, int middle, int right);
int mgSort(vector<int>& vArray, int left, int right);

int mgSort(vector<int> &vArray, int left, int right)
{
	int iInvCounter = 0;
	if (left < right)
	{
		int middle = (left+right) / 2;
		iInvCounter += mgSort(vArray, left, middle);
		iInvCounter += mgSort(vArray, middle + 1, right);
		iInvCounter += merge(vArray, left, middle, right);
	}
	return iInvCounter;
}

int merge(vector<int>& vArray, int left, int middle, int right)
{
	vector<int> vTempArray;
	int iInvCounter = 0;
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
			// count the inversions
			iInvCounter += middle-i+1;
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
	return iInvCounter;
}

void printArray(vector<int> vArray)
{
	size_t sz = vArray.size();
	for (size_t i = 0; i < sz; i++)
	{
		cout << vArray[i] << "\t";
	}

	cout << endl;
}

int main()
{
	//vector<int> vArray{ 23,45,24,5,7,9,10,15,20 };
	//vector<int> vArray{ 1, 3, 5, 2, 4, 6 };
	//vector<int> vArray{ 50, 25, 30, 2, 56, 5, 4, 1 };
	vector<int> vArray{ 23, 4, 6, 9, 2, 1, 10 };
	printArray(vArray);
	int iInvCount = mgSort(vArray, 0, vArray.size() - 1);
	printArray(vArray);
	return 0;
}