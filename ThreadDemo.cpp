#include <iostream>
#include <thread>
#include <mutex>
#include <list>
using namespace std;

std::mutex mu;
std::list<int> myGList;
void shared_cout(string str, int num)
{
	mu.lock();
	cout << str << "\t" << num << endl;
	mu.unlock();
}

void Threadfunc1(string str)
{	
	for (int i = 0; i < 10; i++)
		shared_cout(str, i);
}

void AddToList(int interval, int maxval)
{
	for (int i = 0; i < maxval; i++)
	{
		if (i % interval == 0)
			myGList.push_back(i);
	}
}

void AddToList_DataProtected(int interval, int maxval)
{
	std::lock_guard<std::mutex> guard(mu);
	for (int i = 0; i < maxval; i++)
	{
		if (i % interval == 0)
			myGList.push_back(i);
	}
}
void PrintList()
{	
	auto itr = myGList.begin();
	while (itr != myGList.end())
	{
		cout << (*itr) << " ";
		itr++;
	}
}

void PrintList_DataProtected()
{
	std::lock_guard<std::mutex> guard(mu);
	auto itr = myGList.begin();
	while (itr != myGList.end())
	{
		cout << (*itr) << " ";
		itr++;
	}
}

int main()
{
	/*thread t1(&Threadfunc1, "worker thread");	
	
	for (int i = 0; i < 10; i++)
		shared_cout("main thread", i);

	t1.join();*/

	/*std::thread t1(&AddToList, 1, 100);
	t1.join();
	std::thread t2(&AddToList, 10, 100);
	t2.join();
	std::thread t3(&PrintList);	
	t3.join();*/

	std::thread t1(&AddToList_DataProtected, 1, 100);
	t1.join();
	std::thread t2(&AddToList_DataProtected, 10, 100);
	t2.join();
	std::thread t3(&PrintList_DataProtected);
	t3.join();

	return 0;
}