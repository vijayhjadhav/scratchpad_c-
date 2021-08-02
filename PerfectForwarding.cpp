#include <iostream>
#include <string>
#include "Integer.h"
using namespace std;

class employee
{
	string emp_name;
	Integer emp_id;
public:
	/*employee(const string& name, const Integer& id) : emp_name(name), emp_id(id)
	{
		cout << __FUNCSIG__ << endl;
	}*/
	template <typename T1, typename T2>
	employee(T1&& name, T2&& id) : emp_name(forward<T1>(name)), emp_id(forward<T2>(id))
	{
		cout << __FUNCSIG__ << endl;
	}
};

template<typename T1, typename T2>
employee* create(T1&& name, T2&& id)
{
	return new employee(forward<T1>(name), forward<T2>(id));
}

int main()
{
	{
		auto emp = create("Vijay", 10);
	}

	{
		auto emp = create( "Anita", Integer{23} );
	}

	{
		employee obj("Vijay", 10);
	}
	
	{
		string name = "Anita";
		employee obj(name, 10);
	}
	
	{
		Integer id{ 5 };
		employee obj("Rudra", id);
	}

	{
		Integer id{ 23 };
		string name{ "Shivani" };
		employee obj(name, id);
	}

	return 0;
}