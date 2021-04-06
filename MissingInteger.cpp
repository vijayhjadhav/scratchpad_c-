/*
Write a function:

class Solution { public int solution(int[] A); }

that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.

For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.

Given A = [1, 2, 3], the function should return 4.

Given A = [−1, −3], the function should return 1.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [−1,000,000..1,000,000].
*/

// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    sort(A.begin(), A.end());
    size_t sz = A.size();
    if(A[sz-1] < 0)
       return 1;

    if(sz == 1 && A[sz-1] > 0)
        return A[sz-1]+1;

    // 1 1 2 3 4 6
    int smallestPosInt = 0;
    for(size_t i = 0; i < sz; i++)
    {
        if(A[i] > 0)
        {
            smallestPosInt = A[i]+1;
            for(size_t j = i+1; j < sz; j++)
            {
                if(A[j] < smallestPosInt)
                    continue;

                if(A[j] == smallestPosInt)
                {
                    smallestPosInt++;
                    continue;
                }
                break;                        
            }
            break;           
        }
    }
    return smallestPosInt > 1000000 ? 1 : smallestPosInt;          
}