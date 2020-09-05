#include <iostream>
#include <string>
using namespace std;
#define NUMDAYS_LEAPYEAR    669
#define NUMDAYS_NONLEAPYEAR 668
#define NUM_MONTHS  24

int getDaysMonth(int day, int Month, bool bLeafYear)
{
	int numDays = 0;
	if (Month % 6 == 0)
	{
		if (!bLeafYear)
			numDays = 27;
		else
		{
			if (Month == 24)
				numDays = 28;
			else
				numDays = 27;
		}
	}
	else
		numDays = 28;

	if (day == 0)
		return numDays;

	return numDays - day;
}

int getNumDaysYear(int day, int month, int year)
{
	bool bLeafYear = false;
	if ((year % 2 != 0) || (year % 10 == 0))
		bLeafYear = true;

	if (day == 0 && month == 0)
		return bLeafYear == true ? NUMDAYS_LEAPYEAR : NUMDAYS_NONLEAPYEAR;

	int totalDays = 0;
	totalDays = totalDays + getDaysMonth(day, month, bLeafYear);
	for (int mIndex = month + 1; mIndex <= NUM_MONTHS; mIndex++)
	{
		totalDays = totalDays + getDaysMonth(0, mIndex, bLeafYear);
	}

	return totalDays;
}

int getNumDaysYearBeforeThisDate(int day, int month, int year)
{
	bool bLeafYear = false;
	if ((year % 2 != 0) || (year % 10 == 0))
		bLeafYear = true;
	
	int totalDays = 0;
	
	for (int mIndex = 1; mIndex < month; mIndex++)
	{
		totalDays = totalDays + getDaysMonth(0, mIndex, bLeafYear);
	}

	totalDays += day;

	return totalDays;
}

// Complete the calc_days_between function below.
int calc_days_between(string start, string end) {
	int stDay = stoi(start.substr(0, 2));
	int stMonth = stoi(start.substr(2, 2));
	int stYear = stoi(start.substr(4, 4));

	int edDay = stoi(end.substr(0, 2));
	int edMonth = stoi(end.substr(2, 2));
	int edYear = stoi(end.substr(4, 4));

	int numYears = edYear - stYear;
	int numMonths = edMonth - stMonth;
	//int numDays = edDay - stDay;

	int totalNumDays = 0;

	if (numYears >= 1)
	{
		// Get number of days in start year
		totalNumDays += getNumDaysYear(stDay, stMonth, stYear);

		// Get number of days in intermediate years
		for (auto index = stYear + 1; index < edYear; index++)
		{
			totalNumDays += getNumDaysYear(0, 0, index);
		}
		// Get number of days in end year
		totalNumDays += getNumDaysYearBeforeThisDate(edDay, edMonth, edYear);
	}
	else if (numMonths >= 1)
	{
		bool bLeafYear = false;
		if ((stYear % 2 != 0) || (stYear % 10 == 0))
			bLeafYear = true;

		totalNumDays = getDaysMonth(stDay, stMonth, bLeafYear);
		for (auto index = stMonth + 1; index < edMonth; index++)
		{
			totalNumDays = getDaysMonth(0, index, bLeafYear);
		}
		
		totalNumDays += edDay;
	}
	else
		totalNumDays = edDay - stDay;	

	return totalNumDays;
}

int main()
{
	int numDays = calc_days_between("01012010", "01012011");
	return 0;
}