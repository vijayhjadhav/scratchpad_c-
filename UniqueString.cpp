#include <iostream>
#include <string>
using namespace std;
bool isUnique(string str);

int main()
{
	string str("array");
	if (isUnique(str))
		cout << "String has all unique characters" << endl;
	else
		cout << "String is not unique" << endl;
	return 0;
}

bool isUnique(string str)
{
	bool bResult = true;
	size_t strSize = str.size();
	for (auto index = 0; index < strSize; index++)
	{
		for (auto index2 = index + 1; index2 < strSize; index2++)
		{
			if (str.at(index) == str.at(index2))
			{
				bResult = false;
				break;
			}
		}

		if (bResult == false)
			break;
	}
	return bResult;
}