#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<int> numList;
	numList.push_back(10);
	numList.push_back(20);
	numList.push_back(30);

	cout << "List of integers..." << endl;
	auto itr = numList.begin();
	while(itr != numList.end())
	{
		cout << *itr << endl;
		itr++;
	}

	cout << "Reverse list of integers...." << endl;
	auto ritr = numList.rbegin();
	while(ritr != numList.rend())
	{
		cout << *ritr << endl;
		ritr++;
	}

	vector<string> stringList;
	stringList.push_back("Hi");
	stringList.push_back("Hello");
	stringList.push_back("World");

	cout << "List of strings..." << endl;
	auto sitr = stringList.begin();
	while(sitr != stringList.end())
	{
		cout << *sitr << endl;
		sitr++;
	}

	cout << "Reverse List of strings..." << endl;
	string mstr = "Hi, Hello World";
	auto sritr = stringList.rbegin();
	size_t found;
	while(sritr != stringList.rend())
	{
		found = mstr.find(*sritr);
		if(found != string::npos)
			cout << *sritr << endl;
		sritr++;
	}
	return 0;
}