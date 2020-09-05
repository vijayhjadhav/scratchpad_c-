#include <iostream>
#include <map>
#include <vector>
#include <utility>
using namespace std;
long countTriplets(vector<long> arr, long r);
int main()
{
	vector<long> arr;
	arr.push_back(1);
	arr.push_back(3);
	arr.push_back(9);
	arr.push_back(9);
	arr.push_back(27);
	arr.push_back(81);

	countTriplets(arr, 3);
	return 0;
}

//long countTriplets(vector<long> arr, long r)
//{
//	map<long, vector<pair<long, long>>> mpNextProg;
//	long count = 0;
//	for (auto i = 0; i < arr.size(); i++)
//	{
//		for (auto j = i+1; j < arr.size(); j++)
//		{
//			if (arr[j] == r * arr[i])
//			{
//				for (auto k = j + 1; k < arr.size(); k++)
//				{
//					if (arr[k] == r * arr[j])
//					{
//						mpNextProg[i].push_back(make_pair(j, k));
//						count++;
//					}
//					else if(arr[k] > r * arr[j])
//						break;
//				}
//			}
//			else if(arr[j] > r * arr[i])
//				break;				
//		}
//	}	
//	return count;
//}

long countTriplets(vector<long> arr, long r)
{	
	map<long, vector<long>> mpProg;
	long index2 = 0;
	long size = arr.size();
	for (auto index = 0; index < size; index++)
	{
		index2 = index + 1;
		while (index2 < size && arr[index2] <= arr[index] * r)
		{
			if(arr[index2] == arr[index] * r)
				mpProg[index].push_back(index2);
			index2++;
		}	
	}

	long long count = 0;
	vector<long> arrNextP, arrNextNextP;	
	long size2 = mpProg.size() - 1;
	for (auto index = 0; index < size2; index++)
	{		
		arrNextP = mpProg[index];		
		for (auto index2 = 0; index2 < arrNextP.size(); index2++)
		{
			arrNextNextP = mpProg[arrNextP[index2]];
			count = count + arrNextNextP.size();			
		}
	}
	return count;
}

//long countTriplets(vector<long> arr, long r)
//{
//	map<int, long> mp2, mp3;
//	int count = 0;
//	auto itr = arr.begin();
//	while (itr != arr.end())
//	{
//		if (mp3.count(*itr))
//			count = count + mp3[*itr];
//		if (mp2.count(*itr))
//			mp3[(*itr) * r] = mp3[(*itr) * r] + mp2[*itr];
//		mp2[(*itr) * r]++;
//		itr++;
//	}
//	return count;
//}