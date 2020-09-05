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
    
    bool operator <= (const struct Order &rhs)
    {
        return dPrice <= rhs.dPrice;
    }

    bool operator > (const struct Order &rhs)
    {
        return dPrice > rhs.dPrice;
    }

    bool operator >= (const struct Order &rhs)
    {
        return dPrice >= rhs.dPrice;
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
    void addNewOrder(OPERATIONS &op, ORDER_TYPE &ot, double &price, long &quantity, string &orderID);           void modifyOrder(string &orderID, OPERATIONS &op, double &newprice, long &newquantity);
    void cancelOrder(string &orderID);
    void Print();
    
private:
    void processTrade(ORDER &od);
    void processSellTrade(ORDER &sellOrder);
    void processBuyTrade(ORDER &buyOrder);
    void PrintAsPerOps(list<ORDER> &odlst);
    bool validateInput(string &orderID, double &price, long &quantity);
    bool IsOrderIdUnique(string &orderID);
    void addtoBuyList(ORDER &od);
    void addtoSellList(ORDER &od);
    
private:
    map<OPERATIONS, list<ORDER>> m_priceBook;        
};

bool OrderMatchingEngine::IsOrderIdUnique(string &orderID)
{
        for(auto itrm = m_priceBook.begin(); itrm != m_priceBook.end(); itrm++)
        {
            auto itrv = find_if((*itrm).second.begin(), (*itrm).second.end(), [&orderID](ORDER &od){ return orderID == od.strOrderID;});
            if(itrv != (*itrm).second.end())
                return false;
        }
    return true;
}

bool OrderMatchingEngine::validateInput(string &orderID, double &price, long &quantity)
{    
    if(orderID.empty() || price <= 0 || quantity <= 0)
        return false;    
    return true;
}

void OrderMatchingEngine::addNewOrder(OPERATIONS &op, ORDER_TYPE &ot, double &price, long &quantity, string &orderID)
{
    if(validateInput(orderID, price, quantity) == false)
        return;
    
    if(IsOrderIdUnique(orderID))
    {
        ORDER od(op, ot, price, quantity, orderID);
        processTrade(od);
    }        
}

void OrderMatchingEngine::modifyOrder(string &orderID, OPERATIONS &op, double &newprice, long &newquantity)
{
    if(validateInput(orderID, newprice, newquantity) == false)
        return;
    
    for (auto itrm = m_priceBook.begin(); itrm != m_priceBook.end(); itrm++)
    {
        auto itrv = find_if((*itrm).second.begin(), (*itrm).second.end(), [&orderID](ORDER &od) { return orderID.compare(od.strOrderID) == 0 ? true : false; });
        if (itrv != (*itrm).second.end())
        {
            // Erase that element from the current position in the list
            (*itrm).second.erase(itrv);
    
            ORDER od(op, GFD, newprice, newquantity, orderID);
            processTrade(od);
            return;
        }
    }    
    return;    
}

void OrderMatchingEngine::addtoBuyList(ORDER &od)
{
    OPERATIONS op = od.opOperation;
    list<ORDER>::iterator itr;
    if(!m_priceBook[op].empty())
    {
        for(itr = m_priceBook[op].begin(); itr != m_priceBook[op].end(); itr++)
        {
            // Active Buy order list is maintained in decending order
            if( od <= *itr)
            {
                continue;
            }
            else
            {
                m_priceBook[op].insert(itr, od);
                return;
            }
        }
    }
    
    if(m_priceBook[op].empty() || itr == m_priceBook[op].end())
        m_priceBook[op].push_back(od);
}

void OrderMatchingEngine::addtoSellList(ORDER &od)
{
    OPERATIONS op = od.opOperation;
    list<ORDER>::iterator itr;
    if(!m_priceBook[op].empty())
    {
        for(itr = m_priceBook[op].begin(); itr != m_priceBook[op].end(); itr++)
        {
            // Active Sell list is maintained in ascending order
            if( od >= *itr)
            {
                continue;
            }
            else
            {
                m_priceBook[op].insert(itr, od);
                return;
            }
        }
    }
    
    if(m_priceBook[op].empty() || itr == m_priceBook[op].end())
        m_priceBook[op].push_back(od);
}

void OrderMatchingEngine::processSellTrade(ORDER &sellOrder)
{   
    bool bTraded = true;
    for(auto itrBuy = m_priceBook[BUY].begin(); itrBuy != m_priceBook[BUY].end(); )
    {
        if(*itrBuy >= sellOrder)
        {
            int QuantityUnSold = sellOrder.lQuantity - (*itrBuy).lQuantity;
            if(QuantityUnSold == 0)
            {
                cout << "TRADE " << (*itrBuy).strOrderID << " " << (*itrBuy).dPrice << " " << (*itrBuy).lQuantity 
                    << " " <<  sellOrder.strOrderID << " " << sellOrder.dPrice << " " << sellOrder.lQuantity << endl;

                itrBuy = m_priceBook[BUY].erase(itrBuy);
                break;
            }

            if (QuantityUnSold > 0)
            {
                cout << "TRADE " << (*itrBuy).strOrderID << " " << (*itrBuy).dPrice << " " << (*itrBuy).lQuantity 
                    << " " <<  sellOrder.strOrderID << " " << sellOrder.dPrice << " " << (sellOrder.lQuantity - QuantityUnSold) << endl;
                sellOrder.lQuantity = QuantityUnSold;

                itrBuy = m_priceBook[BUY].erase(itrBuy);
            }

            if (QuantityUnSold < 0)
            {
                cout << "TRADE " << (*itrBuy).strOrderID << " " << (*itrBuy).dPrice << " " << ((*itrBuy).lQuantity + QuantityUnSold) 
                    << " " <<  sellOrder.strOrderID << " " << sellOrder.dPrice << " " << sellOrder.lQuantity << endl;

                (*itrBuy).lQuantity =  abs(QuantityUnSold);
                break;
            }
        }
        else
        {
            bTraded = false;            
            break;
        }
    }
    
    if(bTraded == false || m_priceBook[BUY].empty())
    {
        if(sellOrder.otOrderType != IOC)
        {          
          addtoSellList(sellOrder);
        }
    }
}

void OrderMatchingEngine::processBuyTrade(ORDER &buyOrder)
{
    bool bTraded = true;
    for(auto itrSell = m_priceBook[SELL].begin(); itrSell != m_priceBook[SELL].end(); )
    {
        if(*itrSell <= buyOrder)
        {
            int QuantityUnBought= buyOrder.lQuantity - (*itrSell).lQuantity;

            if(QuantityUnBought == 0)
            {
                cout << "TRADE " << (*itrSell).strOrderID << " " << (*itrSell).dPrice << " " << (*itrSell).lQuantity 
                    << " " <<  buyOrder.strOrderID << " " << buyOrder.dPrice << " " << buyOrder.lQuantity << endl;

                itrSell = m_priceBook[SELL].erase(itrSell);

                break;
            }

            if(QuantityUnBought > 0)
            {                      
                cout << "TRADE " << (*itrSell).strOrderID << " " << (*itrSell).dPrice << " " <<  (*itrSell).lQuantity
                    << " " <<  buyOrder.strOrderID << " " << buyOrder.dPrice << " " << (buyOrder.lQuantity - QuantityUnBought) << endl;
                
                buyOrder.lQuantity = QuantityUnBought;

                itrSell = m_priceBook[SELL].erase(itrSell);
            }

            if(QuantityUnBought < 0)
            {                
                cout << "TRADE " << (*itrSell).strOrderID << " " << (*itrSell).dPrice << " " << ((*itrSell).lQuantity +  QuantityUnBought)  
                    << " " <<  buyOrder.strOrderID << " " << buyOrder.dPrice << " " << buyOrder.lQuantity << endl;

                (*itrSell).lQuantity =  abs(QuantityUnBought);
                break;
            }
        }
        else
        {
            bTraded = false;           
            break;
        }
    }    
    
    if(bTraded == false || m_priceBook[SELL].empty())
    {
        if(buyOrder.otOrderType != IOC)
        {         
          addtoBuyList(buyOrder);
        }
    }
}

void OrderMatchingEngine::processTrade(ORDER &od)
{
    if (od.opOperation == SELL)
    {
        processSellTrade(od);        
    }
    else
    {
        processBuyTrade(od);
    }            
}

void OrderMatchingEngine::cancelOrder(string &orderID)
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

void OrderMatchingEngine::PrintAsPerOps(list<ORDER> &odlst)
{
    if(odlst.empty())
        return;    
         
    long totalQuantity = 0;
    double prePrice = -1;
    auto itr = odlst.begin();
    prePrice = (*itr).dPrice;
        
    while(itr != odlst.end())
    {
        if((*itr).dPrice == prePrice)
            totalQuantity += (*itr).lQuantity;
        else
        {
            cout << prePrice << " " << totalQuantity << endl;
            //cout << prePrice << " " << totalQuantity << " " << (*itr).strOrderID << endl;
            prePrice = (*itr).dPrice;
            totalQuantity = (*itr).lQuantity;
        }
        itr++;
    }

    cout << prePrice << " " << totalQuantity << endl;       
}

void OrderMatchingEngine::Print()
{   
    // Reverse SELL list to make it decreasing order of price
     m_priceBook[SELL].reverse();
    
    cout << "SELL:" << endl;
    PrintAsPerOps(m_priceBook[SELL]);
    
    // Reverse the list to it original stage.
    m_priceBook[SELL].reverse();
    
    cout << "BUY:" << endl;
    PrintAsPerOps(m_priceBook[BUY]);
}

int main() {
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
        istringstream ss(line);
        do
        {
            ss >> word;
            columns.push_back(word);
            word = "";
        }while(ss);
        
        line = "";
        
        if (columns[0] == "BUY" || columns[0] == "SELL")
        {
            operation = (columns[0] == "BUY") ? BUY : SELL;
            orderType = (columns[1] == "GFD") ? GFD : IOC;
            price = stod(columns[2]);
            quantity = stol(columns[3]);
            orderID = columns[4];
            
            odMatchEng.addNewOrder(operation, orderType, price, quantity, orderID);
        }
        else if (columns[0] == "MODIFY")
        {
            orderID = columns[1];
            operation = (columns[2] == "BUY") ? BUY : SELL;  // new operation
            price = stod(columns[3]);
            quantity = stol(columns[4]);
            
            odMatchEng.modifyOrder(orderID, operation, price, quantity);
        }
        else if (columns[0] == "CANCEL")
        {            
            odMatchEng.cancelOrder(columns[1]);
        }
        else if(columns[0] == "PRINT")
        {            
            odMatchEng.Print();
        }
    }
    return 0;
}