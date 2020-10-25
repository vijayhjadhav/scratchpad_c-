#include "MergeSort.hpp"

int compareX(void* a, void* b)
{
	Point* p1 = (Point*)a;
	Point* p2 = (Point*)b;
	return (p1->x - p2->x);
}

int compareY(void* a, void* b)
{
	Point* p1 = (Point*)a;
	Point* p2 = (Point*)b;
	return (p1->y - p2->y);
}

int MergeSort::mgSort(IntArray &vArray, int left, int right)
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

int MergeSort::merge(IntArray& vArray, int left, int middle, int right)
{
	IntArray vTempArray;
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

int MergeSort::merge(PointsArray& vArray, int left, int middle, int right, int (*compare)(void*, void*))
{
	PointsArray vTempArray;
	int iInvCounter = 0;
	int i = left;
	int j = middle + 1;
	while (i <= middle && j <= right)
	{
		if (compare(&vArray[i], &vArray[j]) <= 0)
		{
			vTempArray.push_back(vArray[i]);
			i++;
		}
		else
		{
			vTempArray.push_back(vArray[j]);
			j++;
			// count the inversions
			iInvCounter += middle - i + 1;
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
		vArray[i] = vTempArray[i - left];
	}
	return iInvCounter;

}
int MergeSort::mgSort(PointsArray& vArray, int left, int right, int (*compare)(void*, void*))
{
	int iInvCounter = 0;
	if (left < right)
	{
		int middle = (left + right) / 2;
		iInvCounter += mgSort(vArray, left, middle, compare);
		iInvCounter += mgSort(vArray, middle + 1, right, compare);
		iInvCounter += merge(vArray, left, middle, right, compare);
	}
	return iInvCounter;
}

void printArray(IntArray vArray)
{
	size_t sz = vArray.size();
	for (size_t i = 0; i < sz; i++)
	{
		cout << vArray[i] << "\t";
	}

	cout << endl;
}

/*int main()
{
	//IntArray vArray{ 23,45,24,5,7,9,10,15,20 };
	//IntArray vArray{ 1, 3, 5, 2, 4, 6 };
	//IntArray vArray{ 50, 25, 30, 2, 56, 5, 4, 1 };
	IntArray vArray{ 23, 4, 6, 9, 2, 1, 10 };
	printArray(vArray);
	MergeSort obMgSort;
	int iInvCount = obMgSort.mgSort(vArray, 0, vArray.size() - 1);
	printArray(vArray);
	return 0;
}*/