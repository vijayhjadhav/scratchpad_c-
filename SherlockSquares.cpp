#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int is_perfect_square(unsigned long n);
int isSquare(unsigned long n);
bool isPerfectSquare(long long n);
long long numSquares(long long start, long long end);
int main() {
	int noTestCases;
	cin >> noTestCases;
	long long *start = new long long[noTestCases];
	long long *end = new long long[noTestCases];
	for(int i = 0; i < noTestCases; i++)
	{
		cin >> start[i] >> end[i];
	}

	for(int j = 0; j < noTestCases; j++)
	{
		printf("%lld\n", numSquares(start[j], end[j]));
	}
    
    return 0;
}

int is_perfect_square(unsigned long n)
{
  unsigned long m;
  m = n & 127;
  if ((m*0x8bc40d7d) & (m*0xa1e2f5d1) & 0x14020a) return 0;
  /* This cuts out another 80%, it may or may not be faster to use it: */
  /* m = n % 63; if ((m*0x3d491df7) & (m*0xc824a9f9) & 0x10f14008) return 0; */
  /* If you need even more reduction: */
  /* m = n % 25; if ((m*0x1929fc1b) & (m*0x4c9ea3b2) & 0x51001005) return 0; */
  /* Proper isqrt call should go here */
  m = (unsigned long) (sqrt((double)n) + 0.5);
  return m*m == n;
}

int isSquareRT(unsigned long n)
{
	int m = n & 31;
if (m==0||m==1||m==4||m==9||m==16||m==17||m==25) {
    unsigned long t = (unsigned long) (sqrt((double)n) + 0.5);
    if (t*t == n) return 1;
}
return 0;
}

int isSquare(unsigned long n)
{
	if ( (n&2) == 0 && (n&7) != 5 && (n&11) != 8 ) {
    unsigned long t = (unsigned long) (sqrt((double)n) + 0.5);
    if (t*t == n) return 1;
}
return 0;
}

bool isPerfectSquare(long long n)
{
  if (n < 0)
    return false;

  switch((int)(n & 0x3F))
  {
  case 0x00: case 0x01: case 0x04: case 0x09: case 0x10: case 0x11:
  case 0x19: case 0x21: case 0x24: case 0x29: case 0x31: case 0x39:
  long long sqt;
    /*if(n < 410881L)
    {
      //John Carmack hack, converted to Java.
      // See: http://www.codemaestro.com/reviews/9
      int i;
      float x2, y;

      x2 = n * 0.5F;
      y  = n;
      i  = Float.floatToRawIntBits(y);
      i  = 0x5f3759df - ( i >> 1 );
      y  = Float.intBitsToFloat(i);
      y  = y * ( 1.5F - ( x2 * y * y ) );

      sqrt = (long)(1.0F/y);
    }
    else*/
    {
      //Carmack hack gives incorrect answer for n >= 410881.
      sqt = (long)sqrt(n);
    }
    return sqt*sqt == n;

  default:
    return false;
  }
}

long long numSquares(long long start, long long end)
{
	long long countSquares = 0;
	for(long long i = start; i <= end; i++)
	{

		//double dSqrt = sqrt(i);
		//long long lSqrt = dSqrt;
		//if(dSqrt == lSqrt)
		//if(is_perfect_square(i))
		//if(isSquareRT(i))
		if(isPerfectSquare(i))
			countSquares++;
	}
	return countSquares;
}