#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> IntArray;
class Point
{
public:
	int x, y;
	Point() { x = 0; y = 0; }
	Point(int ix, int iy) :x(ix), y(iy){};
	// copy constructor
	/*Point(Point& other)
	{
		x = other.x;
		y = other.y;
	}*/

	// assignment operator
	Point& operator=(Point& other)
	{
		x = other.x;
		y = other.y;
		return *this;
	}

	//comparison operators
	friend bool operator==(Point& P1, Point& P2)
	{
		return ((P1.x == P2.x) && (P1.y == P2.y));
	}

};
typedef vector<Point> PointsArray;

int compareX(void* a, void* b);
int compareY(void* a, void* b);

class MergeSort
{
public:
	MergeSort()	{};
	~MergeSort() {};

	int merge(IntArray& vArray, int left, int middle, int right);
	int mgSort(IntArray& vArray, int left, int right);

	int merge(PointsArray& vArray, int left, int middle, int right, int (*compare)(void*, void*));
	int mgSort(PointsArray& vArray, int left, int right, int (*compare)(void*, void*));
};

