#include <iostream>
#include <vector>
#include <algorithm>
#include "MergeSort.hpp"
using namespace std;

#pragma once

float min(float x, float y);
float distance(Point P1, Point P2);
PointsArray closestPair_BruteForce(PointsArray& ArrayPoints, int Left, int Right);
PointsArray closestSplitPair(PointsArray& strip, float minDistance);
PointsArray closestPair(PointsArray& Px, int Left, int Right);

float min(float x, float y)
{
	return (x < y) ? x : y;
}

float distance(Point P1, Point P2)
{
	return sqrtf(((P1.x - P2.x) * (P1.x - P2.x)) + ((P1.y - P2.y) * (P1.y - P2.y)));
}

PointsArray closestPair_BruteForce(PointsArray& ArrayPoints, int Left, int Right)
{
	float minDistance = FLT_MAX;
	PointsArray lstClosestPair(2);
	for (size_t i = Left; i <= Right; i++)
	{
		for (size_t j = i + 1; j <= Right; j++)
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
		return closestPair_BruteForce(Px, Left, Right);
	
	int mid = (szArray / 2) - 1;
	Point midPoint = Px[mid];
	
	PointsArray closestPairLeftArray = closestPair(Px, Left, mid);
	PointsArray closestPairRightArray = closestPair(Px, mid + 1, Right);

	float minDistanceLeft = FLT_MAX;
	float minDistantRight = FLT_MAX;
	minDistanceLeft = distance(closestPairLeftArray[0], closestPairLeftArray[1]);
	minDistantRight = distance(closestPairRightArray[0], closestPairRightArray[1]);

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
	objSort.mgSort(strip, 0, strip.size()-1, compareY);
	
	PointsArray closestPairSplitPair;
	float minDistanceSplitPair = FLT_MAX;
	if (strip.size() > 1)
	{
		closestPairSplitPair = closestSplitPair(strip, minDistance);
		minDistanceSplitPair = distance(closestPairSplitPair[0], closestPairSplitPair[1]);
	}
	
	if (minDistance > minDistanceSplitPair)
		closestPairArray = closestPairSplitPair;

	return closestPairArray;
}

int main()
{
	PointsArray P = { {2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4} };

	PointsArray Px = P;
	PointsArray Py = P;
	MergeSort objMsort;
	objMsort.mgSort(Px, 0, Px.size()-1, compareX);
	
	PointsArray ClosestPairBF = closestPair_BruteForce(P, 0, P.size()-1);
	PointsArray ClosestPairDC = closestPair(Px, 0, Px.size() - 1);
	return 0;
}