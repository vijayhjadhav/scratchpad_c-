#include <iostream>
#include <map>
//#include <iomanip>
//#include <utility>
using namespace std;

//const int NUM_LETTERS = 26;

using CharCount = map<char, int>;

CharCount getCharCounts(string str)
{
	CharCount cc;
	for (auto ch : str)
	{
		cc[ch]++;
	}
	return move(cc);
}

int getDelta(CharCount& cc1, CharCount& cc2)
{
	int delta = 0;
	auto itrCC1 = cc1.begin();
	while (itrCC1 != cc1.end())
	{
		auto itrCC2 = cc2.find((*itrCC1).first);
		if (itrCC2 != cc2.end())
		{
			delta = delta + abs((*itrCC1).second - (*itrCC2).second);
			cc2.erase((*itrCC1).first);
		}
		else
			delta = delta + (*itrCC1).second;

		itrCC1++;
	}

	auto itrCC2 = cc2.begin();
	while (itrCC2 != cc2.end())
	{
		delta = delta + (*itrCC2).second;
		itrCC2++;
	}

	return delta;
}

int numberNeeded(string str1, string str2)
{
	CharCount cc1 = getCharCounts(str1);
	CharCount cc2 = getCharCounts(str2);

	return getDelta(cc1, cc2);
}

int main()
{
	string str1 = "restful1&";//"newyorktimes";//"hello";
	string str2 = "fluster";//"monkeyswrite";//"billion";

	cout << "Number needed : " << numberNeeded(str1, str2) << endl;

	return 0;
}