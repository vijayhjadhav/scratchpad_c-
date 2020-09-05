#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> cellCompete(int* states, int days);
int main()
{
	int states[] = {1, 1, 1, 0, 1, 1, 1, 1};
	vector<int> output = cellCompete(states, 2);

	return 0;
}

vector<int> cellCompete(int* states, int days)
{
	vector<int> cells(states, states + 8);
	vector<int> output(8, 0);
	int start = 0;
	int end = 7;
	for (int day = 1; day <= days; day++)
	{
		for (int cell = start; cell <= end; cell++)
		{
			if (cell == start)
			{
				if (cells[cell + 1] == 0)
				{
					output[cell] = 0;
				}
				else
				{
					output[cell] = 1;
				}
			}
			else if (cell == end)
			{
				if (cells[cell - 1] == 0)
				{
					output[cell] = 0;
				}
				else
				{
					output[cell] = 1;
				}
			}
			else
			{
				if (cells[cell - 1] == cells[cell + 1])
				{
					output[cell] = 0;
				}
				else
				{
					output[cell] = 1;
				}
			}
		}
		copy(output.begin(), output.end(), cells.begin());
	}

	return output;

	// WRITE YOUR CODE HERE  
}