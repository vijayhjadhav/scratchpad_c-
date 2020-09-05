#include<map>
#include<vector>
#include<string>
#include <iostream>
using namespace std;
struct account
{
	account(int id, int accNo):customer_id(id), customer_account(accNo)
	{
	}
	int customer_id;
	int customer_account;
};

void mapIdtoAccounts(vector<account *> &accountsTable, map<int, string> &mpIdsToAccount)
{
	for(auto itr = accountsTable.begin(); itr != accountsTable.end(); itr++)
	{
		mpIdsToAccount[(*itr)->customer_id].append(to_string((*itr)->customer_account));
	}
}

void mapAccountstoID(map<int, string> &mpIdsToAccount, map<string, vector<int>> &mpAccountstoID)
{
	for(auto itr = mpIdsToAccount.begin(); itr != mpIdsToAccount.end(); itr++)
	{
		mpAccountstoID[(*itr).second].push_back((*itr).first);
	}
}

int main()
{	
	vector<account *> accountInfo;	
	accountInfo.push_back(new account(1,1));
	accountInfo.push_back(new account(2,2));
	accountInfo.push_back(new account(3,1));
	accountInfo.push_back(new account(4,3));
	accountInfo.push_back(new account(5,2));
	accountInfo.push_back(new account(1,4));
	accountInfo.push_back(new account(3,4));
	map<int, string> mpIdsToAccount;
	mapIdtoAccounts(accountInfo, mpIdsToAccount);
	
	map<string, vector<int>> mpAccountstoID;
	mapAccountstoID(mpIdsToAccount, mpAccountstoID);

	/*for(auto itr = accountInfo.begin(); itr != accountInfo.end(); itr++)
	{
		delete *itr;
	}*/
	return 0;
}