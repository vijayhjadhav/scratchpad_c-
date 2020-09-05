#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int numChars = 0;
	for(int i = 0; i < n; i++)
	{
		cout.width(n-numChars++);
		for(int j = 0; j < numChars; j++)
		{
			cout << std::right << "#";
		}
		cout << endl;		
	}
	return 0;
}