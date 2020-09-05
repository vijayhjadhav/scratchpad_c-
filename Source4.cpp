#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
#define MAX 10000

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    char input[MAX];
    char strN[3];
    int N;
    int len;
    int pivot;
    gets(strN);
    N = atoi(strN);
    for (int i = 0; i < N; i++)
        {
            memset(input, 0, MAX);
            gets(input);
            len = strlen(input);
            int count = 0;
            if(len%2 == 0)
                {
                   for(int k = 0; k < len/2; k++)
                    {
                        while(input[k] != input[len-1-k])
                            {
                                if(input[k] < input[len-1-k])
                                    input[len-1-k]--;
                                else
                                    input[k]--;
                                count++;
                            }
                    }                    
                }
            else
                {
                    pivot = (len/2)+(len%2);    
                    for(int j = 1; j <= pivot; j++)
                        {
                         while(input[pivot-1-j] != input[pivot-1+j])
                           {
                            if(input[pivot-1-j] < input[pivot-1+j])
                                input[pivot-1+j]--;
                            else
                                input[pivot-1-j]--;
                             count++;
                           }                    
                        }
                }            
            printf("%d\n", count);
        }
   return 0;
}
