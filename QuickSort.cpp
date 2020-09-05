#include <stdlib.h>
#include <iostream>
using namespace std;

void printArray(int *A, int length);
void quicksort(int A[], int left, int right); 

int compare(const void *num1, const void *num2)
{
	return (*(int*)num2 - *(int*)num1);
}

int main()
{
	//int A[] = {31, 41, 59, 26, 41, 58};
	int A[] = {3,7,8,5,2,1,9,5,4};
	
	cout << "Before sorting" << endl;
	printArray(A, 9);
	
	quicksort(A, 0, 8);
	//qsort(A, 6, sizeof(int), compare);

	cout << "After sorting" << endl;		
	printArray(A,9);

	bool i = true;
	bool j =  false;
	int sizeA = sizeof(A)/sizeof(int);
	//bool k = i&&i || i&&j;

	return 0;
}

void printArray(int *A, int length)
{
	for(int index = 0; index < length; index++)
	{
		cout << A[index] << "\t";
	}
	cout << endl;
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