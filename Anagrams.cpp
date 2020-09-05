#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {

	map<char,int> mpStra, mpStrb;
	string::iterator itr = a.begin();
	while(itr != a.end())
	{
		mpStra[*itr]++;
		itr++;
	}

	itr = b.begin();
	while(itr != b.end())
	{
		mpStrb[*itr]++;
		itr++;
	}

	int count = 0;
	map<char,int>::iterator itrMap = mpStra.begin();
	map<char,int>::iterator itrMap2; 
	while(itrMap != mpStra.end())
	{
		if(!mpStrb.empty() && (mpStrb.find(itrMap->first) != mpStrb.end()))
		{			
			count = count + abs(itrMap->second - mpStrb[itrMap->first]);
			mpStrb.erase(itrMap->first);
		}
		else
		{
			count = count + itrMap->second;			
		}
		itrMap++;
	}

	itrMap2 = mpStrb.begin();
	while(itrMap2 != mpStrb.end())
	{
		count = count + itrMap2->second;
		itrMap2++;
	}
	return count;
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    //fout << res << "\n";

    //fout.close();

    return 0;
}
