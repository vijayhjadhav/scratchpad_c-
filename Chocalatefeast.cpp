#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int calculateExtra(int numWrappers, int limitWrappers);
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
	int *n,*c,*m;
	cin>>t;
	n = new int[t];
	c = new int[t];
	m = new int[t];
    
    for(int i = 0; i < t; i++)
	{
        cin>>n[i]>>c[i]>>m[i];    
    }

	for(int j = 0; j < t; j++)
	{
	    int answer=0;
        // Computer answer
        int numChocolates = n[j] / c[j];
		int extraChocolates = calculateExtra(numChocolates, m[j]);
		
        cout<<(numChocolates + extraChocolates)<<endl;
	}
    return 0;
}

int calculateExtra(int numWrappers, int limitWrappers)
{
	if(numWrappers < limitWrappers)
		return 0;
	return (numWrappers/limitWrappers) + calculateExtra(((numWrappers / limitWrappers) + (numWrappers % limitWrappers)), limitWrappers);
}