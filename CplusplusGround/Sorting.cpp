#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

class mySort
{
public:
	void populateDS(int start, int end);
	void printDS();
	void bubbleSort();
	void selectionSort();
	void insertionSort();
	void mergeSort() { return mergeSort(arrNumbers, 0, arrNumbers.size()-1); };
	void quickSort();
	void heapSort() { return heapSort(arrNumbers, arrNumbers.size()); }
	int DAC_Max() { return DAC_Max(arrNumbers, 0, arrNumbers.size()); }
	int DAC_Min() { return DAC_Min(arrNumbers, 0, arrNumbers.size()); }

private:
	int DAC_Max(vector<int> arrNums, int index, int sz);
	int DAC_Min(vector<int> arrNums, int index, int sz);
	void mergeSort(vector<int> &arrNums, int left, int right);
	void merge(vector<int> &arrNums, int left, int mid, int right);
	void quickSort(vector<int> &arrNums, int low, int high);
	int partition(vector<int> &arrNums, int low, int high);
	void heapSort(vector<int>& arrNums, int n);
	void heapify(vector<int>& arrNums, int n, int i);
	
private:
	vector<int> arrNumbers;
};

void mySort::heapify(vector<int>& arrNums, int n, int i)
{
	int largest = i;  // Initialize largest as root
	int leftIndex = 2 * i + 1;
	int rightIndex = 2 * i + 2;

	// left child greater then root
	if (leftIndex < n && arrNums[leftIndex] > arrNums[largest])
		largest = leftIndex;

	// right child greater than root
	if (rightIndex < n && arrNums[rightIndex] > arrNums[largest])
		largest = rightIndex;

	// largest != root
	if (largest != i)
	{
		swap(arrNums[largest], arrNums[i]);

		heapify(arrNums, n, largest);
	}
}

void mySort::heapSort(vector<int>& arrNums, int n)
{
	// Build heap
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(arrNums, n, i);
	}

	// 
	for (int i = n - 1; i > 0; i--)
	{
		// move current root to end of array.
		swap(arrNums[0], arrNums[i]);

		// call max heapify on reduced head
		heapify(arrNums, i, 0);
	}
}
int mySort::partition(vector<int>& arrNums, int low, int high)
{
	int pivot = arrNumbers[high];
	int i = low - 1; // index of smaller element and indicates the right position of pivot found so far
	for (int j = low; j < high; j++)
	{
		if (arrNums[j] < pivot)
		{
			i++;
			swap(arrNums[i], arrNums[j]);
		}
	}

	// finally place the pivot at the correct position.
	swap(arrNums[i + 1], arrNums[high]);

	return (i + 1);
}

void mySort::quickSort(vector<int> &arrNums, int low, int high)
{
	if (low < high)
	{
		int pivotIndex = partition(arrNums, low, high);
		quickSort(arrNums, low, pivotIndex-1);
		quickSort(arrNums, pivotIndex + 1, high);
	}
}

// Time complexity : O(nlogn)
// Space complexity : O(1)
void mySort::quickSort()
{
	quickSort(arrNumbers, 0, arrNumbers.size() - 1);
}

// Time complexity : T(n) = 2T(n/2) + n = O(nlogn)
// Space complexity : O(n) 
void mySort::mergeSort(vector<int> &arrNums, int left, int right)
{
	if (left >= right)
		return;

	int mid = left + (right - left) / 2;
	mergeSort(arrNums, left, mid);
	mergeSort(arrNums, mid + 1, right);
	merge(arrNums, left, mid, right);
}

void mySort::merge(vector<int> &arrNums, int left, int mid, int right)
{
	vector<int> tmpSortSubArray(right - left + 1, 0);
	int startLeftIndex = left;
	int startRightIndex = mid + 1;
	int indexSubArray = 0;
	while (startLeftIndex <= mid && startRightIndex <= right)
	{
		if (arrNums[startLeftIndex] <= arrNums[startRightIndex])
		{
			tmpSortSubArray[indexSubArray] = arrNums[startLeftIndex];
			startLeftIndex++;
		}
		else
		{
			tmpSortSubArray[indexSubArray] = arrNumbers[startRightIndex];
			startRightIndex++;
		}
		
		indexSubArray++;		
	}

	while (startLeftIndex <= mid)
	{
		tmpSortSubArray[indexSubArray] = arrNums[startLeftIndex];
		startLeftIndex++;
		indexSubArray++;
	}

	while (startRightIndex <= right)
	{
		tmpSortSubArray[indexSubArray] = arrNums[startRightIndex];
		startRightIndex++;
		indexSubArray++;
	}

	indexSubArray = 0;
	for (int i = left; i <= right; i++)
	{
		arrNums[i] = tmpSortSubArray[indexSubArray];
		indexSubArray++;
	}
}

void mySort::bubbleSort()
{
	size_t sz = arrNumbers.size();
	bool bswap = false;

	// Time complexity : O(n^2)
	// Space complexity : O(1)
	for (int i = 0; i < sz; i++)
	{
		bswap = false;
		for (int j = 0; j < sz - i - 1; j++)
		{
			if (arrNumbers[j] > arrNumbers[j + 1])
			{
				swap(arrNumbers[j], arrNumbers[j + 1]);
				bswap = true;
			}				
		}

		if (bswap == false)
			break;
	}
}

void mySort::insertionSort()
{
	size_t sz = arrNumbers.size();
	int curNum;
	int j;

	// Time complexity : O(n^2)
	// Space complexity : O(1)
	/*for (int i = 0; i < sz - 1; i++) // n
	{
		curNum = arrNumbers[i+1];
		for (j = i; j >= 0; j--) 0, 1,.....,n-1
		{
			if (curNum < arrNumbers[j])
				arrNumbers[j+1] = arrNumbers[j];
			else
			{
				break;
			}
		}

		arrNumbers[j+1] = curNum;		 
	}*/


	for (int i = 1; i < sz; i++)
	{
		curNum = arrNumbers[i];
		j = i - 1;
		while (j >= 0 && arrNumbers[j] > curNum)
		{
			arrNumbers[j + 1] = arrNumbers[j];
			j = j - 1;
		}

		arrNumbers[j + 1] = curNum;		
	}
}

void mySort::selectionSort()
{
	size_t sz = arrNumbers.size();
	int indexMin;
	// Time complexity : O(n^2)
    // Space complexity : O(1)
	for (int i = 0; i < sz-1; i++) // N
	{
		indexMin = i;
		for (int j = i + 1; j < sz; j++) //N-1, N-2, N-3,.....,2,1 = N(N-1)/2 ~ N^2
		{
			if (arrNumbers[j] < arrNumbers[indexMin])
				indexMin = j;
		}

		swap(arrNumbers[i], arrNumbers[indexMin]);
	}
}

void swap(int& num1, int& num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

int mySort::DAC_Max(vector<int> arrNums, int index, int sz)
{
	if (index >= sz - 2)
	{
		if (arrNumbers[index] > arrNumbers[index + 1])
			return arrNumbers[index];
		else
			return arrNumbers[index + 1];
	}

	int max = DAC_Max(arrNums, index + 1, sz);
	if (arrNumbers[index] > max)
		return arrNumbers[index];
	else return max;
}

int mySort::DAC_Min(vector<int> arrNums, int index, int sz)
{
	if (index >= sz - 2)
	{
		if (arrNumbers[index] < arrNumbers[index + 1])
			return arrNumbers[index];
		else
			return arrNumbers[index + 1];
	}

	int min = DAC_Min(arrNums, index + 1, sz);
	if (arrNumbers[index] < min)
		return arrNumbers[index];
	else
		return min;
}

void mySort::populateDS(int start, int end)
{
	arrNumbers.clear();

	srand(time(NULL));
	//srand(1450);
	int range = end - start;
	arrNumbers.resize(range, 0);
	for (int i = 0; i < range; i++)
	{
		arrNumbers[i] = rand() % range;
	}
}

void mySort::printDS()
{	
	for (auto i : arrNumbers)
		cout << i << "\t";

	cout << endl;
}

int main()
{
	mySort objSort;
	objSort.populateDS(0, 50);
	objSort.printDS();
	cout << "Maximum Number : " << objSort.DAC_Max() << endl;
	cout << "Minimum Number : " << objSort.DAC_Min() << endl;
	//objSort.bubbleSort();
	//objSort.selectionSort();
	//objSort.insertionSort();
	//objSort.mergeSort();
	//objSort.quickSort();
	objSort.heapSort();
	
	objSort.printDS();
	return 0;
}