#include <iostream>
#include <vector>
//#include <string>
using namespace std;

vector < int > solve(vector < int > grades){
    vector<int> results;
    int nearest;
    for (size_t i = 0; i < grades.size(); i++) 
    {
		if(grades[i] >= 38)
		{
			nearest = grades[i] + (5-grades[i]%5);
			if(nearest-grades[i] < 3)
				results.push_back(nearest);
			else
				results.push_back(grades[i]);
		}
		else
		{
			results.push_back(grades[i]);
		}
    }
	return results;    
}

int main() {
    int n;
    cin >> n;
    vector<int> grades(n);
    for(int grades_i = 0; grades_i < n; grades_i++){
       cin >> grades[grades_i];
    }
    vector < int > result = solve(grades);
    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? "\n" : "");
    }
    cout << endl;
    return 0;
}
