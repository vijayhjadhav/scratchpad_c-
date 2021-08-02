#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
using namespace std;
#define new new(_CLIENT_BLOCK, __FILE__, __LINE__)
int main()
{
	_CrtMemState s1, s2, s3;
	_CrtMemCheckpoint(&s1);
	int* ptr = new int[10];
	_CrtMemCheckpoint(&s2);
	int diff = _CrtMemDifference(&s3, &s1, &s2);
	if (diff != 0)
		_CrtDumpMemoryLeaks();

	return 0;
}