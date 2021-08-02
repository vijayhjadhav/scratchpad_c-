#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename ...Args>
void FoldPrint(Args&& ...args)
{
	(cout << ... << forward<Args>(args)) << endl;
}

template <typename T, typename ...Args>
void FoldPushBack(vector<T>& v, Args&& ...args)
{
	(v.push_back(args), ...);
}

int main()
{
	FoldPrint("hello", ", ", 10, ", ", 90.0);

	vector<int> num;
	FoldPushBack(num, 2, 3, 6, 8, 9);

	for (auto& i : num)
	{
		cout << i << endl;
	}
}
