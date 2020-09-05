#include <iostream>
#include <sstream>
#include <string>
#include <ctype.h>
#include <vector>
#include <stack>
using namespace std;


// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &S) {
	vector<string> operations;
	istringstream ss(S);
	string operation;
	do
	{
		ss >> operation;
		operations.push_back(operation);
	} while (ss);

	operations.erase()
	stack<int> iStack;
	auto itr = operations.begin();
	while (itr != operations.end())
	{
		if (isdigit((*itr)[0]))
		{
			iStack.push(stoi(*itr));
		}

		if ((*itr).compare("POP") == 0)
		{
			if (!iStack.empty())
				iStack.pop();
		}

		if ((*itr).compare("DUP") == 0)
		{
			if (iStack.empty())
				return -1;
			iStack.push(iStack.top());
		}

		if ((*itr).compare("+") == 0)
		{
			if (iStack.size() < 2)
				return -1;
			auto num1 = iStack.top();
			iStack.pop();
			auto num2 = iStack.top();
			iStack.pop();
			iStack.push(num1 + num2);
		}

		if ((*itr).compare("-") == 0)
		{
			if (iStack.size() < 2)
				return -1;
			auto num1 = iStack.top();
			iStack.pop();
			auto num2 = iStack.top();
			iStack.pop();
			if (num1 - num2 < 0)
				return -1;
			iStack.push(num1 - num2);
		}
		itr++;
	}
	if (iStack.empty())
		return -1;
	return iStack.top();

}
int main()
{
	string S("13 DUP 4 POP 5 DUP + DUP + -");
	int i = solution(S);
	cout << "test"<< endl;
	return 0;
}