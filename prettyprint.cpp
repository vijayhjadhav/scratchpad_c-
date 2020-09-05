#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	double T;
	cin >> T;
			
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--)
	{
		
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;

		cout.unsetf(ios::uppercase);
		cout.setf(ios::hex, ios::basefield);
		cout.setf(ios::showbase);		
		//cout.width(10);		
		cout << std::left << long long(A) << endl;
		cout.unsetf(ios::hex|ios::basefield|ios::showbase);

		char prev;	
		
		prev = cout.fill('_');	
		cout.setf(ios::showpos);	
		cout.width(15);
		cout.precision(2);
		cout.setf(ios::fixed);
		cout << std::right << B << endl;
		cout.fill(prev);
		cout.unsetf(ios::showpos);
		std::cout.unsetf ( ios::fixed ); 
				
		cout.width(13);
		cout.precision(9);
		cout.setf(ios::scientific | ios::uppercase);
		cout << std::left << C << endl;
		cout.unsetf(ios::scientific);
		cout.unsetf(ios::uppercase);
	}
	return 0;
}