#include <vector>
#include <iostream>
#include <string>
using namespace std;

int longest_chain(vector < string > w);
int main() {
    //ofstream fout(getenv("OUTPUT_PATH"));
    int res;
    
    int _w_size;
    cin >> _w_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<string> _w;
    string _w_item;
    for(int _w_i=0; _w_i<_w_size; _w_i++) {
        getline(cin, _w_item);
        _w.push_back(_w_item);
    }
    
    res = longest_chain(_w);
    cout << res << endl;
    
    //cout.close();
    return 0;
}

/*
 * Complete the function below.
 */
int longest_chain(vector < string > w) 
{
	vector<int> arrStrLength;
	int len = w.size();
	for(int i = 0; i < len; i++)
	{
		arrStrLength.push_back(w[i].length());
	}

	for(int i = 0; i < len; i++)
	{
		cout << w[i] << "\t" << arrStrLength[i] << endl;
	}

	for(int i = 0; i < len; i++)
	{
		if(w[i].length() > 1)
		{
			int numChars = 1;
			int strlength = w[i].length();
			for(int j = 0; j < strlength; j++)
			{

			}
		}
	}
	return 0;
	
}