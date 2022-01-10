#include <iostream>
#include <stack>
#include <exception>
using namespace std;

class stackEmptyException : public exception
{
	const char* what() const noexcept { return "Empty Stack\n"; }
};

template<class T>
class myQueue
{
public:
	myQueue(){}
	void enqueue(T newElement);
	T top();
	T dequeue();
	void shiftStacks();
private:
	stack<T> newestOnTop;
	stack<T> oldestOnTop;
};

template<class T>
void myQueue<T>::enqueue(T newElement)
{
	newestOnTop.push(newElement);
}

template<class T>
T myQueue<T>::top()
{
	shiftStacks();
	if (oldestOnTop.empty())
		throw stackEmptyException();
	return oldestOnTop.top();
}

template<class T>
T myQueue<T>::dequeue()
{
	shiftStacks();
	try
	{
		if (oldestOnTop.empty())
			throw stackEmptyException();
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}
	
	T top = oldestOnTop.top();
	oldestOnTop.pop();
	return top;
}

template<class T>
void myQueue<T>::shiftStacks()
{
	if (oldestOnTop.empty())
	{
		while (!newestOnTop.empty())
		{
			oldestOnTop.push(newestOnTop.top());
			newestOnTop.pop();
		}
	}
}

int main()
{
	myQueue<int> mQ;

	for (auto i : { 2, 4 ,6, 12 })
		mQ.enqueue(i);

	cout << "top : " << mQ.top() << endl;

	cout << "value poped : " << mQ.dequeue() << endl;
	cout << "value poped : " << mQ.dequeue() << endl;
	cout << "value poped : " << mQ.dequeue() << endl;
	
	
	for (auto i : {34, 50,67,0 })
		mQ.enqueue(i);
	
	cout << "value poped : " << mQ.dequeue() << endl;
	cout << "value poped : " << mQ.dequeue() << endl;
	cout << "value poped : " << mQ.dequeue() << endl;
	cout << "value poped : " << mQ.dequeue() << endl;
	cout << "value poped : " << mQ.dequeue() << endl;
	cout << "value poped : " << mQ.dequeue() << endl;

	return 0;
}