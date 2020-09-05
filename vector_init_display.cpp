#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <iterator>
using namespace std;

bool throwX( std::string const& s ) { throw std::runtime_error( s ); }

void cppMain()
{
	long N;
    cin >> N;	
    //long long number;
    vector<long long> num_array;
    string str;
    getline(cin, str);
	while(getline(cin, str) && !str.empty())
	{

	istringstream ss(str);
    //vector<string> strnums;
    copy(istream_iterator<long long>(ss), istream_iterator<long long>(), back_inserter(num_array));
	}
  //  for(auto i = 0; i < N; i++)
  //  {
		//scanf_s("ld", &num_array[i]);
  //      //cin >> num_array[i]  || throwX("Oops input failed"); 
  //      //num_array[i] = stoi(strnums[i]);
  //      //num_array.push_back(number);
  //  }
    
    long Q;
    cin >> Q;
/*    vector<long long>::iterator pos;
    for(auto i = 0; i < Q; i++)
    {
        cin >> number;
        pos = find(num_array.begin(), num_array.end(), number);    
        if(pos != num_array.end())
        {
            cout << "Yes " <<  (pos-num_array.begin())+1 << endl;    
        }
        else
        {
			pos = lower_bound(num_array.begin(), num_array.end(), number);
            cout << "No " << (pos-num_array.begin())+1 << endl;
        }
    }  */ 
}

int main() {
    
    try
    {
        cppMain();
        return EXIT_SUCCESS;
    }
    catch( std::exception const& x )
    {
        cerr << "!" << x.what() << endl;
    }
    return EXIT_FAILURE;
    
    return 0;
}

// Submitted-not working code
//#include <cmath>
//#include <cstdio>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//#include <sstream>
//#include <iterator>
//using namespace std;
//
//
//int main() {
//    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
//    long long N;
//    cin >> N;
//    long long number;
//    vector<long long> num_array(N);
//
//    for(long long i = 0; i < N; i++)
//    {
//        cin >> num_array[i];
//    }
//    
//    long long Q;
//    cin >> Q;
//    vector<long long>::iterator pos;
//    for(long long i = 0; i < Q; i++)
//    {
//        cin >> number;
//        pos = find(num_array.begin(), num_array.end(), number);    
//        if(pos != num_array.end())
//        {
//            cout << "Yes " <<  (pos-num_array.begin())+1 << endl;    
//        }
//        else
//        {
//			pos = lower_bound(num_array.begin(), num_array.end(), number);
//            cout << "No " << (pos-num_array.begin())+1 << endl;
//        }
//    }   
//    
//    return 0;
//}