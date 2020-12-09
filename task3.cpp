#include <iostream>
#include <set>
#include <vector>
using namespace std;
class Base
{
public:
	virtual void f()
	{
		cout << "Base::f" << endl;
	}
};

class Derived : public Base
{
public:
	void f()
	{
		cout << "Derived::f" << endl;
	}
};

class A
{
public:
	A() { cout << "Const A\n"; }
	~A() { cout << "Dest A\n"; }
};

class B : public A
{
public:
	B() { cout << "Const B\n"; }
	~B() { cout << "Dest B\n"; }
};

int main()
{
	//std::set<int> s;
	//s.insert(3);
	//s.insert(3);
	//s.insert(2);
	//for (auto it = s.begin(); it != s.end(); ++it)
	//{
	//	std::cout << *it << " ";
	//}

	/// <summary>
	/// ////////////////////
	/// </summary>
	/// <returns></returns>
	/*std::vector<int> v = { 1,2,3 };
	auto it = v.begin();
	v.push_back(4);
	std::cout << *it;*/

	//Base* b = new Derived;
	//b->f();
	/// <summary>
	/// //////////////////////
	/// </summary>
	/// 
	/// 
	/// <returns></returns>
	
	B b;
	A* p = new B;
	delete p;
	return 0;
}