#include <iostream>
#include <vector>
#include <string>
using namespace std;
int populateTower(vector<vector<int> > &gridOfTowers);
void printGridStatus(vector<vector<int> >& gridOfTowers, int numRows, int numColumns);
int main()
{
	/*vector<vector<int> > grids{ {1, 0, 0, 0, 0},
								{0, 0, 0, 0, 0},
								{0, 0, 0, 0, 0}, 
								{0, 0, 0, 0, 0}, 
								{0, 0, 0, 0, 0} };*/
	vector<vector<int> > grids{ {1, 1, 1, 1, 1},
								{1, 1, 1, 1, 1},
								{1, 1, 1, 1, 1},
								{1, 1, 1, 1, 1},
								{1, 1, 1, 1, 1} };

	cout << "Number of days required to update all towers is " << populateTower(grids) << endl;

	return 0;
}

void printGridStatus(vector<vector<int> >& gridOfTowers, int numRows, int numColumns)
{
	for (int row = 0; row < numRows; row++)
	{
		for (int col = 0; col < numColumns; col++)
		{
			cout << gridOfTowers[row][col] << " ";
		}
		cout << endl;
	}
}

int populateTower(vector<vector<int> > &gridOfTowers)
{
	size_t numRows = gridOfTowers.size();
	size_t numCols = gridOfTowers[0].size();
	int numDays = 0;
	bool isUpdated = true;
	vector<vector<int> > temp(gridOfTowers);
	cout << "Status of grid on day 0 :" << numDays << endl;
	printGridStatus(gridOfTowers, numRows, numCols);
	int adjRow = 0, adjCol = 0;
	while (isUpdated)
	{
		isUpdated = false;
		for (size_t row = 0; row < numRows; row++)
		{
			for (size_t col = 0; col < numCols; col++)
			{
				if (gridOfTowers[row][col] == 1)
				{
					adjRow = row - 1;
					if (((adjRow) >= 0) && gridOfTowers[adjRow][col] == 0)
					{
						temp[adjRow][col] = 1;
						isUpdated = true;
					}

					adjRow = row + 1;
					if (adjRow < numRows && gridOfTowers[adjRow][col] == 0)
					{
						temp[adjRow][col] = 1;
						isUpdated = true;
					}

					adjCol = col - 1;
					if (adjCol >= 0 && gridOfTowers[row][adjCol] == 0)
					{
						temp[row][col - 1] = 1;
						isUpdated = true;
					}

					adjCol = col + 1;
					if (adjCol < numCols && gridOfTowers[row][adjCol] == 0)
					{
						temp[row][adjCol] = 1;
						isUpdated = true;
					}
				}
			}
		}

		if (isUpdated)
		{
			numDays++;
			gridOfTowers.assign(temp.begin(), temp.end());
			cout << "Status of grid after day " << numDays << " :" << endl;
			printGridStatus(gridOfTowers, numRows, numCols);
		}
	}
	return numDays;
}
