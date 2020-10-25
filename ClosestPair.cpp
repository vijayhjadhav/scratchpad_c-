#include <iostream>
#include <vector>
#include <algorithm>
#include "MergeSort.hpp"
using namespace std;

#pragma once

PointsArray closestPair_BruteForce(PointsArray &lstPoints, float& min);
float distance(Point P1, Point P2);
PointsArray closestPair_BruteForce(PointsArray& ArrayPoints);
//int compareX(void* a, void* b);
//int compareY(void* a, void* b);

float min(float x, float y);

float min(float x, float y)
{
	return (x < y) ? x : y;
}

float distance(Point P1, Point P2)
{
	return sqrtf(((P1.x - P2.x) * (P1.x - P2.x)) + ((P1.y - P2.y) * (P1.y - P2.y)));
}

PointsArray closestPair_BruteForce(PointsArray& ArrayPoints)
{
	size_t szList = ArrayPoints.size();
	float minDistance = FLT_MAX;
	PointsArray lstClosestPair(2);
	for (size_t i = 0; i < szList; i++)
	{
		for (size_t j = i + 1; j < szList; j++)
		{
			if (distance(ArrayPoints[i], ArrayPoints[j]) < minDistance)
			{
				minDistance = distance(ArrayPoints[i], ArrayPoints[j]);
				lstClosestPair[0] = ArrayPoints[i];
				lstClosestPair[1] = ArrayPoints[j];
			}
		}
	}
	return lstClosestPair;
}

PointsArray closestSplitPair(PointsArray& strip, float minDistance)
{
	PointsArray lstClosestPair(2);
	size_t szArray = strip.size();
	for (size_t i = 0; i < szArray; i++)
	{
		for (size_t j = i + 1; j < szArray && (strip[j].y - strip[i].y) < minDistance; j++)
		{
			if (distance(strip[i], strip[j]) < minDistance)
			{
				lstClosestPair[0] = strip[i];
				lstClosestPair[1] = strip[j];
				minDistance = distance(strip[i], strip[j]);
			}
		}
	}
	return lstClosestPair;
}

PointsArray closestPair(PointsArray& Px, int Left, int Right)
{
	size_t szArray = Right-Left+1;
	if (szArray <= 3)
		return closestPair_BruteForce(Px);
	
	int mid = szArray / 2;
	Point midPoint = Px[mid];
	
	PointsArray closestPairLeftArray = closestPair(Px, Left, mid);
	PointsArray closestPairRightArray = closestPair(Px, mid + 1, Right);

	float minDistanceLeft = distance(closestPairLeftArray[0], closestPairLeftArray[1]);
	float minDistantRight = distance(closestPairRightArray[0], closestPairRightArray[1]);

	PointsArray closestPairArray;
	if (minDistanceLeft < minDistantRight)
		closestPairArray = closestPairLeftArray;
	else
		closestPairArray = closestPairRightArray;

	float minDistance = min(minDistanceLeft, minDistantRight);

	PointsArray strip;
	for (size_t i = 0; i < szArray; i++)
	{
		if (abs(Px[i].x - midPoint.x) < minDistance)
		{
			strip.push_back(Px[i]);
		}	
	}

	MergeSort objSort;
	objSort.mgSort(strip, 0, strip.size(), compareY);
	//sort(strip.begin(), strip.end(), compareY);
	PointsArray closestPairSplitPair = closestSplitPair(strip, minDistance);
	float minDistanceSplitPair = distance(closestPairSplitPair[0], closestPairSplitPair[1]);
	if (minDistance > minDistanceSplitPair)
		closestPairArray = closestPairSplitPair;

	return closestPairArray;
}

/*PointsArray closestPair(PointsArray& Px, PointsArray& Py, int Left, int Right)
{
	size_t szArray = Px.size();
	float minDistance;
	if (szArray <= 3)
	{
		PointsArray ClosestPairPx = closestPair_BruteForce(Px);
		PointsArray ClosestPairPy = closestPair_BruteForce(Py);

		if (distance(ClosestPairPx[0], ClosestPairPx[1]) < distance(ClosestPairPy[0], ClosestPairPy[1]))
			return ClosestPairPx;
		else
			return ClosestPairPy;
	}		

	int mid = szArray / 2;
	Point midPointX = Px[mid];
	//Point midPointY = Py[mid];
		
	PointsArray closestPairLeftArray = closestPair(Px, Py, Left, mid);
	PointsArray closestPairRightArray = closestPair(Px, Py, mid + 1, Right);

	minDistance = min(distance(closestPairLeftArray[0], closestPairLeftArray[1]),
		              distance(closestPairRightArray[0], closestPairRightArray[1]));
	PointsArray stripUnsorted(szArray);
	for (size_t i = 0; i < szArray; i++)
	{
		if (abs(Px[i].x - midPointX.x) < minDistance)
		{
			stripUnsorted.push_back(Px[i]);
		}
	}

	PointsArray stripSorted(stripUnsorted.size());
	for (size_t j = 0; j < szArray; j++)
	{
		if(Py[j] == )
	}

	return closestSplitPair(stripSorted, minDistance);
}*/

int main()
{
	PointsArray P = { {2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4} };

	PointsArray Px = P;
	PointsArray Py = P;
	MergeSort objMsort;
	objMsort.mgSort(Px, 0, Px.size()-1, compareX);
	//objMsort.mgSort(Py, 0, Py.size()-1, compareY);
	
	PointsArray ClosestPairBF = closestPair_BruteForce(P);
	PointsArray ClosestPairDC = closestPair(Px, 0, Px.size() - 1);
	return 0;
}