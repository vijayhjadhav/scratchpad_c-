#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	map<int, pair<int, int>> mp;
	int num1, num2;
	int result;
	string strResult;
	int index1 = 0;
	int index2 = 5;
	for (num1 = 999; num1 >= 100; num1--)
	{
		for (num2 = num1; num2 >= 100; num2--)
		{
			result = num1 * num2;
			strResult = to_string(result);
			index1 = 0;
			index2 = strResult.size()-1;
			while (index1 < index2)
			{
				if (strResult[index1] != strResult[index2])
					break;

				index1++;
				index2--;
			}
			if (index1 == index2 || index1 > index2)
			{
				mp[result] = make_pair(num1, num2);
			}			
		}
	}
	auto ritr = mp.rbegin();
	cout << ritr->first << endl;
	return 0;
}