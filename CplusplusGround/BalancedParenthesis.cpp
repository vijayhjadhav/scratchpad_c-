#include <iostream>
#include <stack>
using namespace std;
const char Tokens[3][2] = { {'{','}'}, {'[',']'}, {'(',')'}};

bool isOpenTerm(char openTerm)
{
	for (auto token : Tokens)
	{
		if (openTerm == token[0])
			return true;
	}

	return false;
}

bool matchTerms(char openTerm, char closeTerm)
{
	for (auto token : Tokens)
	{
		if (openTerm == token[0] && closeTerm == token[1])
			return true;
	}
	return false;
}

bool isBalanced(string expression)
{
	stack<char> expStack;
	for (auto c : expression)
	{
		if (isOpenTerm(c))
			expStack.push(c);
		else
		{
			if (expStack.empty() || !matchTerms(expStack.top(), c))
			{
				return false;
			}
			expStack.pop();
		}
	}

	return expStack.empty();
}

int main()
{
	//string str = "[]{[()]}";
	//string str = "{[]{[()]}}";
	string str = "[{[(]{[()]}}]";

	cout << str << " is " << (isBalanced(str) == true ? "Balanced" : "not Balanced") << endl;

	return 0;
}