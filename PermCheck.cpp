#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <string>

using namespace std;

//int solution(vector<int>& A) {
//	sort(A.begin(), A.end());
//
//	auto itr = unique(A.begin(), A.end());
//	if (itr != A.end())
//	{
//		return 0;
//	}
//		
//	size_t sz = A.size();
//	if (A[0] == 1 && A.back() == sz)
//		return 1;
//
//	return 0;
//}

int solution(int N) {

	string binary = bitset<32>(N).to_string();
	size_t spos = 0;
	size_t cpos = binary.find('1', spos);
	spos = cpos;
	size_t maxGap = 0;
	size_t cGap = 0;
	while (cpos != string::npos)
	{
		cGap = cpos - spos;
		if (cGap >= 1 && cGap > maxGap)
			maxGap = cGap;
		spos = cpos + 1;
		cpos = binary.find('1', spos);
	}
	return maxGap;
}

int main()
{
	int N = 1024;
	cout << solution(N) << endl;
	return 0;
}
