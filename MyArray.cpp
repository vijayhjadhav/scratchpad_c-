#include <iostream>
using namespace std;
#define ARRAY_SIZE 10

class myArray
{
public:
	void initArray();
	void bubbleSortArray();
	void insertionSortArray();
	void reverseArray();
	void printArray();
private:
	int m_array[ARRAY_SIZE];
};

void myArray::initArray()
{
	cout << "Enter" << ARRAY_SIZE << " elements of the array" << endl;
	for(int index = 0; index < ARRAY_SIZE; index++)
	{
		cin >> m_array[index];
	}	
}

void myArray::bubbleSortArray()
{
	bool bAscending = true;	
	int numElements = ARRAY_SIZE;
	int nlastSwapped;
	int temp;
	do
	{
		temp = 0;
		nlastSwapped = 0;
		for (int index = 1; index < numElements; index++)
		{
			if(m_array[index-1] > m_array[index])
			{
				temp = m_array[index-1];
				m_array[index-1] = m_array[index];
				m_array[index] = temp;				
				nlastSwapped = index;
			}
		}
		numElements = nlastSwapped;
	}while(nlastSwapped != 0);
}

void myArray::insertionSortArray()
{
	int numElements = ARRAY_SIZE;
	int j = 0;
	int temp = 0;
	for(int index = 1; index < numElements; index++)
	{
		j = index;
		while(j > 0 && (m_array[j-1] > m_array[j]))
		{
			temp = m_array[j];
			m_array[j] = m_array[j-1];
			m_array[j-1] = temp;
			j = j - 1;
		}
	}
}

void myArray::reverseArray()
{
	int temp = 0;
	int startIndex = 0;  // First element
	int endIndex = ARRAY_SIZE-1; // Last element
	int indexBackward = endIndex;
	for(int indexForward = startIndex; indexForward < ARRAY_SIZE; indexForward++)
	{
		if(indexForward < indexBackward)
		{
			temp = m_array[indexBackward];
			m_array[indexBackward] = m_array[indexForward];
			m_array[indexForward] = temp;
		}
		else
		{
			// Both the index are on the same element. So no more reversing is required.
			break;
		}
		indexBackward--;
	}
}

void myArray::printArray()
{
	for(int index = 0; index < ARRAY_SIZE; index++)
	{
		cout << m_array[index] << "\t";
	}	
}

int main()
{
	myArray objArray;

	// Fill the Array and print it
	objArray.initArray();
	objArray.printArray();
	cout << endl;

	// Reverse the array and print it
	objArray.reverseArray();
	cout << "After reversing the array" << endl;
	objArray.printArray();
	cout << endl;

	// Sort the array and print it
	//objArray.bubbleSortArray();
	objArray.insertionSortArray();
	cout << "After bubble sort" << endl;
	objArray.printArray();
	cout << endl;

	return 0;
}

