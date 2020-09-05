#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<iso646.h>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N, NQ;
    cin >> N >> NQ;

	vector<vector<long long>>seqList(N);
	vector<vector<long long>>inputsList;
	//int type, x, y;
	long long lastAns = 0;
	int seq = 0;
 
	vector<long long> inputs(3);
	for(int i = 0; i < NQ; i++)
	{
		cin >> inputs[0] >> inputs[1] >> inputs[2];
		inputsList.push_back(inputs);
	}

	cout << "Inputs..." << endl;
	for(int i = 0; i < NQ; i++)
	{
		cout << inputsList[i][0] <<" "<<inputsList[i][1] << " " <<inputsList[i][2] << endl;		
	}

	cout << "Output..." << endl;
	long long y, rem;
	for(int i = 0; i < NQ; i++)
	{
		//cin >> type >> x >> y;
		seq = (inputsList[i][1]^lastAns)%2;
		if(inputsList[i][0] == 1)  //1 x y
		{
			seqList[seq].push_back(inputsList[i][2]); 
		}
		else  //2 x y
		{
			size_t sz = seqList[seq].size();
			y = inputsList[i][2];
			rem = y%sz;
			lastAns = seqList[seq][rem];
			cout << lastAns << endl;
		}
	}
 

 //   int **seqList = new int*[N];
 //   for(int i = 0; i < N; i++)
 //   {
 //       seqList[i] = new int[N];        
 //   }

	//// Initialize the sequences
	//for(auto i = 0; i < N; i++)
	//	for(auto j = 0; j < N; j++)
	//		seqList[i][j] = 0;
 //   
 //   int type, x, y;
 //   int lastAns = 0;
	//int seq = 0;
 //       
 //   for(int i = 0; i < NQ; i++)
 //   {
 //       cin >> type >> x >> y;
 //       seq = (x^lastAns)%2;
 //       if(type == 1)
 //       {
 //          seqList[seq][0] = y; 
 //       }
 //       else
 //       {
 //           
 //       }
 //   }
    return 0;
}
