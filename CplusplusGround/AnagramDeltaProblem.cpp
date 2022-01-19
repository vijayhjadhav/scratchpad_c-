#include <iostream>
#include <map>
//#include <iomanip>
//#include <utility>
using namespace std;

//const int NUM_LETTERS = 26;

using CharCountMap = map<char, int>;

CharCountMap getCharCountMapping(string str)
{
	CharCountMap ccMapping;
	for (auto ch : str)
	{
		ccMapping[ch]++;
	}
	return move(ccMapping);
}

int getDelta(CharCountMap& ccMapping1, CharCountMap& ccMapping2)
{
	int delta = 0;
	auto itrccMapping1 = ccMapping1.begin();
	while (itrccMapping1 != ccMapping1.end())
	{
		auto itrccMapping2 = ccMapping2.find((*itrccMapping1).first);
		if (itrccMapping2 != ccMapping2.end())
		{
			delta = delta + abs((*itrccMapping1).second - (*itrccMapping2).second);
			ccMapping2.erase((*itrccMapping1).first);
		}
		else
			delta = delta + (*itrccMapping1).second;

		itrccMapping1++;
	}

	auto itrccMapping2 = ccMapping2.begin();
	while (itrccMapping2 != ccMapping2.end())
	{
		delta = delta + (*itrccMapping2).second;
		itrccMapping2++;
	}

	return delta;
}

int numberNeeded(string str1, string str2)
{
	CharCountMap ccMapping1 = getCharCountMapping(str1);
	CharCountMap ccMapping2 = getCharCountMapping(str2);

	return getDelta(ccMapping1, ccMapping2);
}

int main()
{
	string str1 = "restful1&";//"newyorktimes";//"hello";
	string str2 = "fluster";//"monkeyswrite";//"billion";

	cout << "Number needed : " << numberNeeded(str1, str2) << endl;

	return 0;
}