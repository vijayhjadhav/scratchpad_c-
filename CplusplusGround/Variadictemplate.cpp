#include <iostream>
#include <string>
using namespace std;


// C++11
auto sumCpp11()
{
	return 0;
}

template<typename T1, typename ...T>
auto sumCpp11(T1 s, T ...ts)
{
	return s + sumCpp11(ts...);
}

// C++17
template<typename ...Args> auto sum(Args ...args)
{
	return (args + ... + 0);
}

template<typename ...Args> auto sum2(Args ...args)
{
	return (args + ...);
}

int main()
{
	cout << sumCpp11(1, 2, 3, 4, 5, 6, 7) << endl;
	cout << sum(1, 2, 3, 4, 5, 6, 7) << endl;
	cout << sum2(1, 2, 3, 4, 5, 6, 7) << endl;
}