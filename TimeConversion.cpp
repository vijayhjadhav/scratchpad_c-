#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int main(){
    string time;

	// time in 12 hour format
    cin >> time;
	
	string strhh = time.substr(0,2);
	string strmmss = time.substr(3,5);	
	int hh;
	hh = stoi(strhh);
	if((time.find("PM") != string::npos) || (time.find("pm") != string::npos))
	{
		if(hh != 12)
			hh = hh + 12;
		strhh = to_string(hh);
	}
	else
		{
			if((hh == 12) || (hh == 0))
			{
				strhh = "00";
			}
	}	

	string time24 = strhh + ":" + strmmss;

	// Time in 24 hour format
	cout << time24 << endl;	

    return 0;
}