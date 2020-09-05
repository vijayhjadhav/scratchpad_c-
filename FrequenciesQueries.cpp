#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
vector<int> freqQuery(vector<vector<int>> queries);
int main()
{
	vector<int> ans;
	vector<vector<int>> queries = { { 1,5 }, { 1,6 }, {3,2} };
	ans = freqQuery(queries);
	return 0;
}

//vector<int> freqQuery(vector<vector<int>> queries)
//{
//	map<int, int> mpFreq;
//	vector<int> ans;
//	auto itr = queries.begin();
//
//	while (itr != queries.end())
//	{
//		switch ((*itr)[0])
//		{
//		case 1:  // Add
//			mpFreq[(*itr)[1]] ++;
//			break;
//		case 2:  // remove
//		{
//			//auto itr2 = mpFreq.find((*itr)[1]);
//			//if (itr2 != mpFreq.end())
//			if(mpFreq.count((*itr)[1]) > 0)
//			{			
//				if (mpFreq[(*itr)[1]] == 1)
//					mpFreq.erase((*itr)[1]);
//				else
//					mpFreq[(*itr)[1]]--;
//			}
//		}
//		break;
//		default: // Check
//		{
//			auto inputFreq = (*itr)[1];
//			auto ifFreq = [&inputFreq](const pair<int, int>& p1) {
//				return p1.second >= inputFreq;
//			};
//			auto itr =
//				find_if(mpFreq.begin(), mpFreq.end(), ifFreq);
//			if (itr != mpFreq.end())
//				ans.push_back(1);
//			else
//				ans.push_back(0);
//		}
//		break;
//		}
//		itr++;
//	}
//	return ans;
//}

vector<int> freqQuery(vector<vector<int>> queries)
{
	map<int, int> mpFreq;
	vector<int> ans;
	auto itr = queries.begin();

	while (itr != queries.end())
	{
		switch ((*itr)[0])
		{
		case 1:  // Add
			mpFreq[(*itr)[1]] ++;			
			break;
		case 2:  // remove
		{
			//auto itr2 = mpFreq.find((*itr)[1]);
			//if (itr2 != mpFreq.end())
			if (mpFreq.count((*itr)[1]) > 0)
			{
				if (mpFreq[(*itr)[1]] == 1)
					mpFreq.erase((*itr)[1]);
				else
					mpFreq[(*itr)[1]]--;
			}
		}
		break;
		default: // Check
		{
			auto inputFreq = (*itr)[1];
			auto ifFreq = [&inputFreq](const pair<int, int>& p1) {
				return p1.second >= inputFreq;
			};
			auto itr =
				find_if(mpFreq.begin(), mpFreq.end(), ifFreq);
			if (itr != mpFreq.end())
				ans.push_back(1);
			else
				ans.push_back(0);
		}
		break;
		}
		itr++;
	}
	return ans;
}