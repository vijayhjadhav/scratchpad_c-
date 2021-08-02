#include "Integer.h"
#include <iostream>
using namespace std;

void Print()
{

}

template<typename T, typename...Params> // Template parameter pack
void Print(T&& a, Params&&...args)  // Function parameter pack
{
	cout << sizeof...(args) << endl;
	cout << "Argument: " << a << endl;
	//Print(args...);
	Print(forward<Params>(args)...);  // With Perfect Forwarding
}

int main()
{
	Integer val{ 2 };
	Print(1, 2.3f, "Vijay", val);
	return 0;
}