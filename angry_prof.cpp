#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct studentInfo
{
	int nTotalStudents;
	int nArrivedStudents;
	vector<int> nTimeofArrival;
}STUDENT_INFO;

int main(){
    int t;
    cin >> t;
	vector<STUDENT_INFO> listStudentInfo;
	vector<int> TotalStudents;
	vector<int> ArrivedStudents;
    for(int a0 = 0; a0 < t; a0++){
		STUDENT_INFO obj;
        cin >> obj.nTotalStudents >> obj.nArrivedStudents;
		
        int nTimeofArrival;
        for(int a_i = 0;a_i < obj.nTotalStudents;a_i++){
           cin >> nTimeofArrival;

		   obj.nTimeofArrival.push_back(nTimeofArrival);
        }
		listStudentInfo.push_back(obj);
    }

	for(int index = 0; index < t; index++)
	{
		int nArrivalCount = listStudentInfo[index].nTimeofArrival.size();
		int nArrivedCount = 0;
		for(int j = 0; j < nArrivalCount; j++)
		{
			if(listStudentInfo[index].nTimeofArrival[j] <= 0)
			{
				nArrivedCount++;
			}
		}
		if(nArrivedCount >= listStudentInfo[index].nArrivedStudents)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}

    return 0;
}
