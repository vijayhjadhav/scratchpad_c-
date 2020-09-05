#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;


int main() {    
    int N;
    cin >> N;
    map<string, int> stringFrequency;
    string strIn;
    for(auto i = 0; i < N; i++)
    {
        cin >> strIn;
        stringFrequency[strIn]++;
    }
    
    int Q;
    cin >> Q;
    string strQuery;
    vector<string> Queries;
    for(auto i = 0; i < Q; i++)
    {
        cin >> strQuery;
        Queries.push_back(strQuery);
    }
    
    for(auto i = 0; i < Q; i++)
    {
      auto itr = stringFrequency.find(Queries[i]);
      if(itr != stringFrequency.end())
      {
		  cout << (*itr).second << endl;  
      }
      else
        cout << "0" << endl;  
    }
    
    return 0;
}
