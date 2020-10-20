#include <iostream>
#include <vector>
using namespace std;
class Point
{
public:
	int x, y;
};

typedef vector<Point> LIST_POINTS;

LIST_POINTS closestPair_BruteForce(LIST_POINTS &lstPoints, float& min);
float distance(Point P1, Point P2);

float distance(Point P1, Point P2)
{
	return sqrtf(((P1.x - P2.x) * (P1.x - P2.x)) + ((P1.y - P2.y) * (P1.y - P2.y)));
}

LIST_POINTS closestPair_BruteForce(LIST_POINTS &lstPoints, float &min)
{
	size_t szList = lstPoints.size();
	min = FLT_MAX;
	LIST_POINTS lstClosestPair(2);
	for (size_t i = 0; i < szList; i++)
	{
		for (size_t j = i + 1; j < szList; j++)
		{
			if (distance(lstPoints[i], lstPoints[j]) < min)
			{
				min = distance(lstPoints[i], lstPoints[j]);
				lstClosestPair[0] = lstPoints[i];
				lstClosestPair[1] = lstPoints[j];
			}				
		}
	}
	return lstClosestPair;
}

int main()
{
	LIST_POINTS P = { {2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4} };
	float min;
	LIST_POINTS  lstClosestPair = closestPair_BruteForce(P, min);
	return 0;
}