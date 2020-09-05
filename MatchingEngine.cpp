#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

typedef enum op
{
	BUY = 0,
	SELL,
	MODIFY,
	CANCEL,
	PRINT
}OPERATIONS;

typedef enum ot
{
	IOC = 0,
	GFD
}ORDER_TYPE;

typedef struct Order
{
	Order(OPERATIONS op, ORDER_TYPE ot, double pc, long qty, string oID)
		:opOperation(op), otOrderType(ot), dPrice(pc), lQuantity(qty), strOrderID(oID)
	{}

	Order() {}

	bool operator < (const struct Order &rhs)
	{
		return dPrice < rhs.dPrice;
	}

	bool operator > (const struct Order &rhs)
	{
		return dPrice > rhs.dPrice;
	}

	OPERATIONS opOperation;
	ORDER_TYPE otOrderType;
	double dPrice;
	long lQuantity;
	string strOrderID;
}ORDER;

class OrderMatchingEngine
{
public:

	void placeTrade(OPERATIONS op, ORDER_TYPE ot, double price, long quantity, string orderID);	
	void modifyOrder(string orderID, OPERATIONS op, double newprice, long newquantity);
	void cancelOrder(string orderID);
	void Print();
	
private:
	void processTrade(OPERATIONS op, string orderID);
	void PrintAsPerOps(OPERATIONS op);
	
private:
	map<OPERATIONS, list<ORDER>> m_priceBook;
	double m_maxBuyingPrice;	
};

void OrderMatchingEngine::placeTrade(OPERATIONS op, ORDER_TYPE ot, double price, long quantity, string orderID)
{
	ORDER od(op, ot, price, quantity, orderID);
	m_priceBook[op].push_back(od);
	processTrade(op, orderID);
}

void OrderMatchingEngine::processTrade(OPERATIONS op, string orderID)
{
	if (op == SELL)
	{
		list<ORDER> temp(m_priceBook[BUY]);
		temp.sort([](ORDER& first, ORDER& second) {return first > second; });
		// Get list of trades with buying price higher or equal 
	}
	else
	{
		list<ORDER> temp(m_priceBook[SELL]);
		temp.sort([](ORDER& first, ORDER& second) {return first < second; });
		// Get list of trades with selling price lower than or equal
	}			
}

void OrderMatchingEngine::modifyOrder(string orderID, OPERATIONS op, double newprice, long newquantity)
{
	for (auto itrm = m_priceBook.begin(); itrm != m_priceBook.end(); itrm++)
	{
		auto itrv = find_if((*itrm).second.begin(), (*itrm).second.end(), [&orderID](ORDER &od) { return orderID.compare(od.strOrderID) == 0 ? true : false; });
		if (itrv != (*itrm).second.end())
		{
			if ((*itrv).otOrderType == IOC)
				return;

			if (op == CANCEL)
			{
				(*itrm).second.erase(itrv);
				return;
			}

			// Erase that element from the current position in the list
			(*itrm).second.erase(itrv);

			// place the modified order at the end of the list
			placeTrade(op, GFD, newprice, newquantity, orderID);

			return;
		}
	}	
	return;	
}

void OrderMatchingEngine::cancelOrder(string orderID)
{
	for (auto itrm = m_priceBook.begin(); itrm != m_priceBook.end(); itrm++)
	{
		auto itrv = find_if((*itrm).second.begin(), (*itrm).second.end(), [&orderID](ORDER &od) { return orderID.compare(od.strOrderID) == 0 ? true : false; });
		if (itrv != (*itrm).second.end())
		{
			(*itrm).second.erase(itrv);
			return;
		}	
	}
	return;
}

void OrderMatchingEngine::PrintAsPerOps(OPERATIONS op)
{
	// Sort the list as per price
	list<ORDER> temp(m_priceBook[op]);
	temp.sort([](ORDER& first, ORDER& second) {return first > second; });

	// print the sorted list
	for (auto itr = temp.begin(); itr != temp.end(); itr++)
	{
		cout << (*itr).dPrice << " " << (*itr).lQuantity << endl;
	}
}

void OrderMatchingEngine::Print()
{
	cout << "SELL:" << endl;
	PrintAsPerOps(SELL);
	cout << "BUY:" << endl;
	PrintAsPerOps(BUY);
}

int main() 
{
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */	
	OPERATIONS operation;
	ORDER_TYPE orderType;
	double price;
	long quantity;
	string orderID;
	OrderMatchingEngine odMatchEng;
	string line;
	
	while(getline(cin, line))
	{
		vector<string> columns;
		string word = "";
		for (auto ch : line)
		{
			if (ch != ' ')
			{
				word += ch;				
			}
			else
			{
				columns.push_back(word);
				word = "";
			}
		}

		if (columns[0] == "BUY" || columns[0] == "SELL")
		{
			operation = (columns[0] == "BUY") ? BUY : SELL;
			orderType = (columns[1] == "GFD") ? GFD : IOC;
			price = stod(columns[2]);
			quantity = stol(columns[3]);
			orderID = columns[4];
			// call placeOrder();
			odMatchEng.placeTrade(operation, orderType, price, quantity, orderID);
		}
		else if (columns[0] == "MODIFY")
		{
			orderID = columns[1];
			operation = (columns[2] == "BUY") ? BUY : SELL;  // new operation
			price = stod(columns[3]);
			quantity = stol(columns[4]);
			// call modifyOrder();
			odMatchEng.modifyOrder(orderID, operation, price, quantity);
		}
		else if (columns[0] == "CANCEL")
		{
			// cancelOrder(col2)
			odMatchEng.cancelOrder(columns[1]);
		}
		else
		{
			// Print Operation
			odMatchEng.Print();
		}
	}
	return 0;
}