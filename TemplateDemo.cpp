#include <iostream>
using namespace std;

template<typename T>
T add(T x, T y)
{
	return x + y;
}

template<typename T, typename U>
T ArraySum(T *pArr, U arrSize)
{
	T sumArr{};
	for (int i = 0; i < arrSize; i++)
	{
		sumArr = sumArr + pArr[i];
	}

	return sumArr;
}

template<typename T, typename U>
T Max(T* pArr, U arrSize)
{
	T maxNum{};
	for (int i = 0; i < arrSize; i++)
	{
		if (pArr[i] > maxNum)
		{
			maxNum = pArr[i];
		}
	}

	return maxNum;
}

template<typename T, typename V>
std::pair<T, T> MinMax(T* pArr, V arrSize)
{
	T Min{};
	T Max{};
	for (int i = 0; i < arrSize; i++)
	{
		if (pArr[i] > Max)
			Max = pArr[i];
		if (pArr[i] > Min)
			Min = pArr[i];
	}

	return std::make_pair(Max, Min);
}

// C++17 feature
//template<typename ... T>
//auto sumv(T ... t)
//{
//	return (t + ...);
//}

template<typename T, int Buffsize>
class buffer_t
{
public:
	T& alloc();
	void free(T& item);
private:
	T data[Buffsize];
};


int main()
{
	buffer_t<int, 100> buffObject;
	auto sum = add(30, 45);
	auto sum2 = add(30.5, 45.6);

	// C++17 feature
	//auto sumVar = sumv(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);


	int arr[5] = { 2, 3, 6, 10, 45 };
	auto arrSum = ArraySum(arr, 5);

	float farr[5] = { 3.5f, 4.3f, 5.0f, 12.4f, 15.5f };
	auto fArrSum = ArraySum(farr, 5);

	auto maxI = Max(arr, 5);
	auto maxF = Max(farr, 5);

	std::pair<int, int> iMinMax = MinMax(arr, 5);

	std::pair<float, float> fMinMax = MinMax(farr, 5);
	return 0;
}