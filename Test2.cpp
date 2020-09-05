#include <iostream>
#include <vector>

using namespace std;
int minimumCostOfOperation(vector<int> elements);
int main()
{
	int arr[] = { 5, 2, 6, 8, 7, 1, 10 };
	vector<int> A(arr, arr + sizeof(arr)/sizeof(int));
	minimumCostOfOperation(A);
	return 0;
}
/*
2+8 = 10
2+7 = 9
2+1 = 3
6+7 = 13
6+1 = 7
8+1 = 9
*/
int minimumCostOfOperation(vector<int> A)
{
	size_t size = A.size();
	int min_cost = A[0] + A[2];
	int cost = 0;
	for (size_t P = 0; P < size - 3; P++)
	{
		for (size_t Q = P + 3; Q < size - 1; Q++)
		{
			cost = A[P] + A[Q];
			if (cost < min_cost)
				min_cost = cost;
		}
	}

	return min_cost;
}