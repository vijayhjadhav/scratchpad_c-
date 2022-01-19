#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
const int ALHABET_SIZE = 26;

class TrieNode;
using TRIENODE = shared_ptr<TrieNode>;
class TrieNode
{
public:
	TrieNode() :isEndOfWord(false)
	{
		cout << "constructor called" << endl;
		children.resize(ALHABET_SIZE, nullptr);
		/*for (int i = 0; i < ALHABET_SIZE; i++)
		{
			children[i] = nullptr;
		}*/
	}

	// copy constructor 
	TrieNode(const TrieNode& other)
	{
		cout << "copy constructor called" << endl;
		for (int i = 0; i < ALHABET_SIZE; i++)
		{
			children[i] = other.children[i];
		}
		isEndOfWord = other.isEndOfWord;
	}

	// assignment operator
	TrieNode& operator=(const TrieNode& other)
	{
		cout << "assignment operator called" << endl;
		if (this != &other)
		{
			for (int i = 0; i < ALHABET_SIZE; i++)
			{
				children[i] = other.children[i];
			}
			isEndOfWord = other.isEndOfWord;
		}
		return *this;
	}

	// move copy constructor
	TrieNode(TrieNode&& other)
	{
		cout << "move copy constructor called" << endl;
		for (int i = 0; i < ALHABET_SIZE; i++)
		{
			children[i] = other.children[i];
		}

		isEndOfWord = other.isEndOfWord;
		other.children.clear();
	}

	//move assignment operator
	TrieNode& operator=(TrieNode&& other)
	{
		cout << "move assignment operator called" << endl;
		if (this != &other)
		{
			for (int i = 0; i < ALHABET_SIZE; i++)
			{
				children[i] = other.children[i];
			}
			isEndOfWord = other.isEndOfWord;
			other.children.clear();
		}
		return *this;
	}

public:
	vector<TRIENODE> children;
	bool isEndOfWord;
};

class Tries
{
public:
	Tries():root(getNode()){}
	TRIENODE getNode();
	void insert(string key);
	bool search(string key);

private:
	TRIENODE root;

};

TRIENODE Tries::getNode()
{
	return make_shared<TrieNode>();
}

void Tries::insert(string key)
{
	TRIENODE currentNode = root;
	int index;
	for (int i = 0; i < key.length(); i++)
	{
		index = key[i] - 'a';
		if (currentNode->children[index] == nullptr)
			currentNode->children[index] = getNode();
		currentNode = currentNode->children[index];
	}

	currentNode->isEndOfWord = true;
}


bool Tries::search(string key)
{
	TRIENODE currentNode = root;
	int index;
	for (int i = 0; i < key.length(); i++)
	{
		index = key[i] - 'a';
		if (currentNode->children[index] == nullptr)
			return false;

		currentNode = currentNode->children[index];
	}

	return currentNode->isEndOfWord;
}

int main()
{
	vector<string> keys{ "the", "a", "there",
					"answer", "any", "by",
					 "bye", "their" };
	Tries TS;
	for (auto key : keys)
		TS.insert(key);

	cout << "String : the " << (TS.search("the") == true ? "found" : "not found") << endl;
	cout << "String : these " << (TS.search("these") == true ? "found" : "not found") << endl;
	cout << "String : answering " << (TS.search("answering") == true ? "found" : "not found") << endl;
	cout << "String : ans " << (TS.search("answering") == true ? "found" : "not found") << endl;

	return 0;
}