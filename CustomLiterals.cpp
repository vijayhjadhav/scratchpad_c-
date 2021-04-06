#include <iostream>
using namespace std;

class weight
{
public:
	weight(long double wgKg) : mwght(wgKg) {}

	long double getWgKg() { return mwght; }

	void setWgKg(long double wgKg) { mwght = wgKg; }

private:
	long double mwght;
};

weight operator"" _gms(long double wgKg)
{
	return weight(wgKg / 1000);
}

weight operator"" _tons(long double wgkg)
{
	return weight(wgkg * 100);
}
int main()
{
	weight wght(1000.0_gms);
	cout << "Weight in kg " << wght.getWgKg() << endl;

	weight wght2(100.0_tons);
	cout << "Weight in kg " << wght2.getWgKg() << endl;

	return 0;
}