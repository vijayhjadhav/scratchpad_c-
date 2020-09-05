#include <iostream>
using namespace std;

void printArray(int *A, int length);
void myInsertionSort(int *A, int length);
int linearSearch(int *A, int length, int value);
void quicksort(int A[], int left, int right); 
int main()
{
	int A[] = {31, 41, 59, 26, 41, 58};
	//cout << "Before sorting" << endl;
	cout << "Before searching" << endl;
	printArray(A, 6);
	//myInsertionSort(A, 6);
	int j = linearSearch(A, 6, 50);

	//cout << "After sorting" << endl;
	if(j >= 0)
		cout << "index = " << j << endl;
	else
		cout << "index = NIL" << endl;
		
	//printArray(A,6);

	return 0;
}

void printArray(int *A, int length)
{
	for(int index = 0; index < 6; index++)
	{
		cout << A[index] << "\t";
	}
	cout << endl;
}

void myInsertionSort(int *A, int length)
{
	int key;
	for(int index = 1; index < 6; index++)
	{
		key = A[index];
		int leftIndex = index - 1;
		while((leftIndex >= 0) && (A[leftIndex] < key))
		{
			A[leftIndex+1] = A[leftIndex];
			leftIndex = leftIndex - 1;
		}

		A[leftIndex+1] = key;
	}
}

int linearSearch(int *A, int length, int value)
{
	for(int index = 0; index < length; index++)
	{
		if( value == A[index])
		{
			return index+1;
		}
	}

	return -1;
}

void quicksort(int A[], int left, int right)
{
	int i = left;
	int j = right;
	int pivot = A[(left+right)/2];
	int temp;
	// Partition
	while( i <= j)
	{
		while(A[i] < pivot)
			i++;

		while(A[j] > pivot)
			j--;

		if(i <= j)
		{
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
			i++;
			j--;
		}
	}

	if(left < j)
		quicksort(A, left, j);

	if(right > i)
		quicksort(A, i, right);
}