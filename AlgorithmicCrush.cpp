#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long int M, N;
	cin >> N >> M;
	vector<long long int> arr(N);
	
	int a, b;
	long long int k;
	for(auto i = 0; i < M; i++)
	{
		cin >> a >> b >> k;
		for(auto j = a-1; j < b; j++)
		{
			arr[j] = arr[j] + k;
		}
	}

	cout << *max_element(arr.begin(), arr.end()) << endl;

    return 0;
}
