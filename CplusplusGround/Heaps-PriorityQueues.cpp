#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>
using namespace std;

class InvalidStateException : public exception
{
	virtual const char* what() const throw()
	{
		return "Array is in invalid state";
	}
}invalidStateException;

class myHeap
{
public:
	myHeap()
	{
		items.resize(capacity, -1);
	}

	int peek();
	int poll();
	void heapifyDownMin();
	void heapifyUpMin();
	void heapifyDownMax();
	void heapifyUpMax();
	void add(int item);
	void printHeap();
private:
	int getLeftChildIndex(int parentIndex) { return 2 * parentIndex + 1; }
	int getRightChildIndex(int parentIndex) { return 2 * parentIndex + 2; }
	int getParentIndex(int childIndex) { return (childIndex -1) / 2; }

	bool hasLeftChild(int index) { return getLeftChildIndex(index) < size; }
	bool hasRightChild(int index) { return getRightChildIndex(index) < size; }
	bool hasParent(int index) { return getParentIndex(index) >= 0; }

	int leftChild(int index) { return items[getLeftChildIndex(index)]; }
	int righChild(int index) { return items[getRightChildIndex(index)]; }
	int parent(int index) { return items[getParentIndex(index)]; }

	void swap(int indexOne, int indexTwo);
	void ensureExtraCapacity();

	
private:
	int capacity = 10;
	int size = 0;

	vector<int> items;
};

//// 15, 23, 1, 32, 4 ,5, 0, 22, 17, 6
void myHeap::add(int item)
{
	ensureExtraCapacity();
	items[size] = item;
	size++;
	heapifyUpMin();
}

void myHeap::swap(int indexOne, int indexTwo)
{
	int temp = items[indexOne];
	items[indexOne] = items[indexTwo];
	items[indexTwo] = temp;
}

void myHeap::ensureExtraCapacity()
{
	if (size == capacity)
	{
		items.resize(capacity * 2, -1);
		capacity *= 2;
	}
}

int myHeap::peek()
{
	//try
	//{
		if (size == 0)
			throw invalidStateException;
		return items[0];
	//}
	//catch (exception& e)
	//{
	//	cout << e.what() << endl;
	//}	
}

int myHeap::poll()
{
	//try
	//{
		if (size == 0)
			throw invalidStateException;
		int item = items[0];
		items[0] = items[size - 1];
		size--;
		heapifyDownMin();
		return item;
	//}
	//catch (exception& e)
	//{
	//	cout << e.what() << endl;
	//}
}

void myHeap::heapifyUpMin()
{
	int index = size - 1;

	// min heap
	while (hasParent(index) && parent(index) > items[index])
	{
		// swap the last element with its parent element
		swap(getParentIndex(index), index);

		// heapify parent it above elements now
		index = getParentIndex(index);
	}
}

void myHeap::heapifyDownMin()
{
	int index = 0;
	while (hasLeftChild(index))
	{
		int smallerChildIndex = getLeftChildIndex(index);
		//mean heap
		if (hasRightChild(index) && righChild(index) < leftChild(index))
			smallerChildIndex = getRightChildIndex(index);

		if (items[index] < items[smallerChildIndex])
			break;
		else
			swap(index, smallerChildIndex);

		index = smallerChildIndex;
	}
}

void myHeap::heapifyUpMax()
{
	int index = size - 1;

	// max heap
	while (hasParent(index) && parent(index) < items[index])
	{
		// swap the last element with its parent element
		swap(getParentIndex(index), index);

		// heapify parent it above elements now
		index = getParentIndex(index);
	}
}

void myHeap::heapifyDownMax()
{
	int index = 0;
	while (hasLeftChild(index))
	{
		int largerChildIndex = getLeftChildIndex(index);
		//max heap
		if (hasRightChild(index) && righChild(index) > leftChild(index))
			largerChildIndex = getRightChildIndex(index);

		if (items[index] > items[largerChildIndex])
			break;
		else
			swap(index, largerChildIndex);

		index = largerChildIndex;
	}
}

void myHeap::printHeap()
{
	for(int i = 0; i < size; i++)
		cout << items[i] << "\t";
	cout << endl;

	heapifyDownMin();

	cout << endl;
}

int main()
{
	myHeap mH;

	// 15, 23, 1, 32, 4 ,5, 0, 22, 17, 6
	mH.add(15);
	mH.add(23);
	mH.add(1);
	mH.add(32);
	mH.add(4);
	mH.add(5);
	mH.add(0);
	mH.add(22);
	mH.add(17);
	mH.add(6);
	mH.printHeap();
	mH.add(3);
	mH.printHeap();

	return 0;
}