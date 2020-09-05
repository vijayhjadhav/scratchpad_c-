#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int syncLengths(string &num1, string &num2)
{
	int lenNum1 = num1.size();
	int lenNum2 = num2.size();
	if (lenNum1 > lenNum2)
	{
		for (auto count = 0; count < (lenNum1 - lenNum2); count++)
		{
			num2 = "0" + num2;
		}
	}
	else
	{
		for (auto count = 0; count < (lenNum2 - lenNum1); count++)
		{
			num1 = "0" + num1;
		}
	}

	return lenNum1 >= lenNum2 ? lenNum1 : lenNum2;
}

string addintegerStrings(string str1, string str2) {
	// Before proceeding further, make sure length
	// of str2 is larger.
	if (str1.length() > str2.length())
		swap(str1, str2);

	// Take an empty string for storing result
	string str = "";

	// Calculate lenght of both string
	int n1 = str1.length(), n2 = str2.length();

	// Reverse both of strings
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());

	int carry = 0;
	for (int i = 0; i < n1; i++) {
		// compute sum of
		// current digits and carry
		int sum = ((str1[i] - '0') + (str2[i] - '0') + carry);
		str.push_back(sum % 10 + '0');

		// Calculate carry for next step
		carry = sum / 10;
	}

	// Add remaining digits of larger number
	for (int i = n1; i < n2; i++) {
		int sum = ((str2[i] - '0') + carry);
		str.push_back(sum % 10 + '0');
		carry = sum / 10;
	}

	// Add remaining carry
	if (carry)
		str.push_back(carry + '0');

	// reverse resultant string
	reverse(str.begin(), str.end());

	return str;
}

long int product(string num1, string num2)
{
	// Synchronize lengths
	int syncLength = syncLengths(num1, num2);

	// Empty strings
	if (syncLength == 0)
		return 0;

	// one digit numbers
	if (syncLength == 1)
		return stoi(num1) * stoi(num2);

	int lenFirstHalf = syncLength / 2; // Length of 1st half of the string also called as floor(syncLength/2)
	int lenSecondHalf = syncLength - lenFirstHalf;  // Length of 2nd half of the string also called as ceil(syncLength/2)

													// extract the first half of the num1 string
	string xLeft = num1.substr(0, lenFirstHalf);

	// extract the second half of the num1 string
	string xRight = num1.substr(lenFirstHalf, lenSecondHalf);

	// extract the first half of the num2 string
	string yLeft = num2.substr(0, lenFirstHalf);

	// extract the seconf half of the num2 string
	string yRight = num2.substr(lenFirstHalf, lenSecondHalf);

	// Calculate the products (xLeft, yLeft), (xRight, yRight), (bits(xLeft, xRight), bits(yLeft, yRight))
	// of size  syncLength/2
	long int productLeft = product(xLeft, yLeft);
	long int productRight = product(xRight, yRight);
	long int productlpr = product(addintegerStrings(xLeft, xRight), addintegerStrings(yLeft, yRight));

	// Compute the final output
	return (productLeft * pow(10, (2 * lenSecondHalf))) + ((productlpr - productLeft - productRight) * pow(10, lenSecondHalf)) + productRight;
}

// Complete the multiply function below.
string multiply(string num1, string num2) {
	return to_string(product(num1, num2));
}

int main()
{
	//cout << multiply("25", "11") << endl;
	cout << multiply("18446744073709551617", "4");
	return 0;
}