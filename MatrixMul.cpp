#include <iostream>
using namespace std;

int main()
{
	int matrixA[3][2] = {{2, 4}, {5, 6}, {7,3}};
	int matrixB[2][3] = {{7,3, 5}, {2,6, 4}};
	int matrixC[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
	
	cout << "Matrix A...." << endl;
	for(auto i = 0; i < 3; i++)
	{
		for(auto j = 0; j < 2; j++)
		{
			cout << matrixA[i][j] << "\t";
		}
		cout << endl;
	}

	cout << "Matrix B...." << endl;
	for(auto i = 0; i < 2; i++)
	{
		for(auto j = 0; j < 3; j++)
		{
			cout << matrixB[i][j] << "\t";
		}
		cout << endl;
	}

	for(auto i = 0; i < 3; i++)
	{
		for(auto j = 0; j < 3; j++)
		{
			for(auto k = 0; k < 2; k ++)
			{
				matrixC[i][j] = matrixC[i][j] + matrixA[i][k]*matrixB[k][j];
			}
		}
	}

	cout << "Matrix C...." << endl;
	for(auto i = 0; i < 3; i++)
	{
		for(auto j = 0; j < 3; j++)
			cout << matrixC[i][j] << "\t";
		cout << endl;
	}
	return 0;
}