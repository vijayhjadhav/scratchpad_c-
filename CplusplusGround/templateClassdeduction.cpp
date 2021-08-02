#include <iostream>
#include <opencv2/opencv.hpp>
//#include <utility>
#include <tuple>
using namespace cv;
using namespace std;

int main()
{
	std::pair<int,int> d = make_pair<int, int>(1, 2);
	std::pair s(3, 4.5);
	std::tuple t(4, 6, 8);

	cout << std::get<0>(d) << "\t" << std::get<1>(d) << endl;

	cout << std::get<0>(s) << "\t" << std::get<1>(s) << endl;

	cout << std::get<0>(t) << "\t" << std::get<1>(t) << "\t" << std::get<2>(t) << endl;
}