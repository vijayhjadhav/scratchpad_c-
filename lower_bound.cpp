#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long int N;
    cin >> N;
    long long number;
    vector<long long> num_array(N);

    for(long int i = 0; i < N; i++)
    {
        cin >> num_array[i];
    }
    
    long int Q;
    cin >> Q;
    vector<long long>::iterator pos;
    for(long int i = 0; i < Q; i++)
    {
        cin >> number;
        pos = lower_bound(num_array.begin(), num_array.end(), number);
        if(*pos == number)
        {
            cout << "Yes " <<  (pos-num_array.begin())+1 << endl;    
        }
        else
        {			
            cout << "No " << (pos-num_array.begin())+1 << endl;
        }
    }   
    return 0;
}
