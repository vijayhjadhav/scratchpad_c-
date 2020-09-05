#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int isAnagram(string str);
int main()
{
	cout << isAnagram("aaabbb") << endl;
	cout << isAnagram("ab") << endl;
	cout << isAnagram("abc") << endl;
	cout << isAnagram("mnop") << endl;
	cout << isAnagram("xyyx") << endl;
	cout << isAnagram("xaxbbbxx") << endl;
	return 0;
}

int isAnagram(string s)
{
	auto size = s.size();
	if (size % 2 > 0)
		return -1;

	string s1 = s.substr(0, (size / 2));
	string s2 = s.substr((size / 2), (size / 2));
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	vector<char> vCommon(size / 2);
	auto itr = set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), vCommon.begin());
	vCommon.resize(itr - vCommon.begin());
	return ((size/2) - vCommon.size());
}