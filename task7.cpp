#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

bool isAccountNoValid(const vector<int> &balances, int &accountNo)
{
    return (accountNo > 0 && accountNo <= balances.size()) ? true : false;
}

vector<int> bankRequests(vector<int> balances, vector<string> requests) {

    size_t numRequests = requests.size();
    int depositAccount = 0;
    int WithdrawAccount = 0;
    for (auto i = 0; i < numRequests; i++)
    {
        std::istringstream iss(requests[i]);
        vector<string> splittedStr((std::istream_iterator<string>(iss)), std::istream_iterator<string>());

        size_t numtokens = splittedStr.size();
        bool bInvalid = false;
        for (auto j = 0; j < numtokens; j++)
        {
            if (splittedStr[j] == "deposit")
            {
                // Deposit the amount to jth account
                depositAccount = stoi(splittedStr[1]);
                if (!isAccountNoValid(balances, depositAccount))
                {
                    bInvalid = true;
                    break;
                }
                balances[depositAccount - 1] = balances[depositAccount - 1] + stoi(splittedStr[2]);
                cout << "Deposit" << endl;
                cout << "Deposit account : " << depositAccount << " " << "Amount : " << stoi(splittedStr[2]) << endl;
            }
            else if (splittedStr[j] == "withdraw")
            {
                WithdrawAccount = stoi(splittedStr[1]);
                cout << "Withdraw" << endl;
                cout << "Withdraw account : " << WithdrawAccount << " " << "Amount : " << stoi(splittedStr[2]) << endl;
                // check if request results in invalid state
                if ((!isAccountNoValid(balances, WithdrawAccount)) || (balances[WithdrawAccount - 1] < stoi(splittedStr[2])))
                {
                    bInvalid = true;
                    break;
                }

                // Withdraw the amount from ith account
                balances[WithdrawAccount - 1] = balances[WithdrawAccount - 1] - stoi(splittedStr[2]);
            }
            else if (splittedStr[j] == "transfer")
            {
                depositAccount = stoi(splittedStr[2]);
                WithdrawAccount = stoi(splittedStr[1]);
                cout << "Transfer" << endl;
                cout << "Deposit account : " << depositAccount << " " << "Amount : " << stoi(splittedStr[3]) << endl;
                cout << "Withdraw account : " << WithdrawAccount << " " << "Amount : " << stoi(splittedStr[3]) << endl;
                // check if request results in invalid state
                if (((!isAccountNoValid(balances, depositAccount)) || (!isAccountNoValid(balances, WithdrawAccount))) || (balances[WithdrawAccount - 1] < stoi(splittedStr[3])))
                {
                    bInvalid = true;
                    break;
                }

                // Withdraw the amount from ith account
                balances[WithdrawAccount - 1] = balances[WithdrawAccount - 1] - stoi(splittedStr[3]);

                // Deposit the amount to jth account
                balances[depositAccount - 1] = balances[depositAccount - 1] + stoi(splittedStr[3]);
            }
        }

        if (bInvalid)
        {
            vector<int> output(1, 0 - (i + 1));
            return output;
        }
    }

    return balances;

}

int main()
{
    vector<int> balances = { 10, 100, 20, 50, 30 };
    vector<string> requests = { ("withdraw 2 10"),
                                ("transfer 5 1 20"),
                                ("deposit 5 20"),
                                ("transfer 3 4 15") };
    /*vector<int> balances = { 20, 1000, 500, 40, 90 };
    vector<string> requests = { ("deposit 3 400"),
                                ("transfer 1 2 30"),
                                ("withdraw 4 50") };*/
    vector<int> output = bankRequests(balances, requests);
}