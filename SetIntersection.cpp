#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
string twostrings(string s1, string s2);
int main()
{
	twostrings("aardvark", "apple");
	twostrings("beetroot", "sandals");
	twostrings("hello", "world");	
	return 0;
}

string twostrings(string s1, string s2)
{
	auto size = s1.size() > s2.size() ? s1.size() : s2.size();
	vector<char> vIntersection(size);
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	auto itr = set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), vIntersection.begin());
	vIntersection.resize(itr - vIntersection.begin());

	if (vIntersection.empty())
		return "NO";

	return "YES";
}

