#include <iostream>
#include <deque> 
using namespace std;
////void printKMax(int arr[], int n, int k){   
////   int max;
////   for(auto i = 0; i <= n-k; i++)
////   {
////	   max = arr[i];
////	   for(auto j = i+1; j < i+k; j++)
////	   {
////		   if(arr[j] > max)
////			   max = arr[j];
////	   }
////
////	   cout << max << " ";
////   }
////
////   cout << endl;
////}

void printKMax(int arr[], int n, int k)
{
	deque< pair< int, int > > dq;
    dq.push_back( make_pair( arr[ 0 ], 0 ) );

	for( int i = 1; i < k; ++i )
	{
		while( !dq.empty() && dq.back().first < arr[ i ] )
		{
			dq.pop_back();
		}
		dq.push_back( make_pair( arr[ i ], i ) );
	}
	cout << dq.front().first << ' ';

	for( int i = k; i < n; ++i )
	{
		while( !dq.empty() && dq.back().first < arr[ i ] )
		{
			dq.pop_back();
		}
		dq.push_back( make_pair( arr[ i ], i ) );		
		
		if( dq.front().second == i - k )
		{
			dq.pop_front();
		}
		cout << dq.front().first << ' ';
    }
	cout << endl;
}

int main(){
   int t;
   cin >> t;
   while(t>0) {
      int n,k;
       cin >> n >> k;
       int i;
       int *arr = new int[n];
       for(i=0;i<n;i++)
            cin >> arr[i];
       printKMax(arr, n, k);
	   delete[] arr;
       t--;
     }
     return 0;
}
