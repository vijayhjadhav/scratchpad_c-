#include <iostream>
#include <vector>
#include <algorithm>
#include <regex>
//#include <initializer_list>
using namespace std;
#include "templates.h"
struct Object 
{
	float first;
	float second;
};
//using funcType = void(*)(int);

enum MCOLORS;
enum MCOLORS2 : unsigned int;
enum class MCOLORS3;
enum class MCOLORS4 : unsigned int {val1=1, val2};
enum class MCOLORS5 : unsigned short;

//Object getObject()
//{
//	return {0.50f, 12};
//}

//class Sq
//{
//public:
//	//Sq(initializer_list<int> list){};
//};

class base
{
public:
	virtual void func(double n){cout << n << endl;};
};

class derived : public base
{
public:
	virtual void func(double d) override final {cout << d << endl;};
};

class d2 : public derived
{
public:
	virtual void funct(double f) {cout << f << endl;};
};

//class A
//{
//public:
//	A() = default;
//	A(const &A) = delete;
//	A& operator=(const &A) = delete; 
//private:
//	int n;
//};

void print(int obj)
{
	cout << obj << endl;
}

typedef void (*fun)(int);
fun PRINT = &print;

template <class T>
void print(T obj)
{
	cout << obj << endl;
}

template <class T>
class funObj
{
public:
	void operator()(T n)
	{
		cout << n << endl;
	}
};

int main()
{

	//funObj<int> aobj;
	//int num = aobj(20);
	vector<int> test;
	test.push_back(23);
	test.push_back(45);
	test.push_back(43);

	//for_each(test.begin(), test.end(), aobj);
	for_each(test.begin(), test.end(), print);


	const char *p = "11";
	char *q = "Hi";
	//p = q;  //ok
	//strcpy(p, q);  // not ok
	char const *p1  = "12";

	char* const p2 = "13";
	//p2 = q; //not ok
	//strcpy(p2, q);  //ok

	const char* const p3 = "14";
	//p3 = q;  // Not ok
	//strcpy(p3, q);  // Not ok

	const char * reg_esp = "[,.\\t\\n;:]";
	regex rgx(reg_esp);
	cmatch match;
	const char *target = "Unseen University ; Ankh-Morpork.";
	if(regex_search(target, match, rgx))
	{
		const size_t n = match.size();
		for(size_t a = 0; a < n; a++)
		{
			string str(match[a].first, match[a].second);
			cout << str << endl;
		}
	}
	//A a() = 2;
	//vector<int> mintt{4);
	Object scalar = {0.43f, 10};
	Object anArray[] = {{13.4f, 3}, {43.28f, 29}};
	//maths<int> mint(1, 2);
	//cout << mint.add();
	//maths<double> mdouble(2.0, 3.0);
	//cout << mdouble.add();
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	for(auto& x : v)
	{
		cout << x << endl;
	}
	
	auto c = 2.4;
	decltype(c) d;
	d = 12.45;
	cout << d << endl;

	auto disp = [&scalar]() 
	{
		cout << "lamba function called" << endl;
		cout << scalar.first << "\t"<< scalar.second << endl;
		scalar.first = 0.65f;
		scalar.second = 12;		
	};
	disp();
	cout << scalar.first <<"\t"<< scalar.second << endl;
	char s[] = "Hello World";
	int ucase = 0;
	for_each(s, s+sizeof(s), [&](char c){
	  if(isupper(c))
		  ucase++;
	});
	cout << ucase << endl;
	int arr[] = {1, 2, 3};
	
	auto factorial = [](int i, int j) {return i * j;};
	auto sumI = [](int i, int j) -> decltype(i+j) {return i+j;};
	auto sumD = [](int i, double j) -> decltype(i+j) {return i+j;};
	auto I = sumI(12, 34); 
	cout << I  << endl;
	auto D = sumD(12, 13.90); 
	cout << D << endl;

	int prod;
	[&](int i, int j) {prod = i+j;}(2,3);

	cout << prod << endl;
	return 0;
}