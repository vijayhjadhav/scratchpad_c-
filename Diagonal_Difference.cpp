#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector< vector<int> > a(n,vector<int>(n));
    for(int a_i = 0;a_i < n;a_i++){
       for(int a_j = 0;a_j < n;a_j++){
          cin >> a[a_i][a_j];
       }
    }
    int start = 0, end = n - 1;
    int sumdiag1 = 0, sumdiag2 = 0;
    for(int a_i = 0; a_i < n; a_i++)
    {
        sumdiag1 = sumdiag1 + a[a_i][start++];
        sumdiag2 = sumdiag2 + a[a_i][end--];
    }
    int result = abs(sumdiag1-sumdiag2);
	cout << result << endl;
    return 0;
}
