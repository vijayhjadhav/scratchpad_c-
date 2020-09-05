#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
	int die1, die2, countDoubles = 0;
	srand(time(NULL));
	for(int i = 0; i < 100; i++)
	{
		die1 = rand() % 6 + 1;
		die2 = rand() % 6 + 1;
		if(die1 == die2)
			countDoubles++;
	}

	cout << "I rolled " << countDoubles << " doubles";
	return 0;
}