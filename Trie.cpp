#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Alphabet size (# of symbols) 
#define ALPHABET_SIZE (26) 

class TrieNode
{
public:
	TrieNode():m_isEndOfWord(false), m_children(ALPHABET_SIZE, nullptr){}
	bool IsEndOfWorld() { return m_isEndOfWord; }
	void setIsEndOfWorld(bool bVal) { m_isEndOfWord = bVal; }
	//auto Children() { return m_children; }
	auto child(int index) { return m_children[index]; }
	void setChild(int index, TrieNode *node) { m_children[index] = node; }
private:
	bool m_isEndOfWord;
	vector<TrieNode *> m_children;
};

class PrefixTree
{
public:
	PrefixTree() :m_root(new TrieNode()) {}
	void insert(string key);
	bool search(string key);
private:
	int getCharCode(char c) { return c - 'a'; }
	
private:
	TrieNode * m_root;
};

void PrefixTree::insert(string key)
{	
	auto pCrawl = m_root;
	int CharCode;
	size_t keyLength = key.size();
	for (size_t index = 0; index < keyLength; index++)
	{
		CharCode = getCharCode(key[index]);
		if (pCrawl->child(CharCode) == nullptr)
		{
			pCrawl->setChild(CharCode, new TrieNode());			
		}

		pCrawl = pCrawl->child(CharCode);		
	}

	pCrawl->setIsEndOfWorld(true);
}

bool PrefixTree::search(string key)
{
	auto pCrawl = m_root;
	int CharCode;
	size_t keyLength = key.size();
	for (size_t index = 0; index < keyLength; index++)
	{
		CharCode = getCharCode(key[index]);
		if (pCrawl->child(CharCode) == nullptr)
		{
			return false;
		}

		pCrawl = pCrawl->child(CharCode);
	}

	return ((pCrawl != NULL) && pCrawl->IsEndOfWorld());
}

int main()
{
	PrefixTree obj;
	obj.insert("hello");
	obj.insert("dog");
	obj.insert("hell");
	obj.insert("cat");
	obj.insert("a");
	obj.insert("hel");
	obj.insert("help");
	obj.insert("helps");
	obj.insert("helping");
	bool bkeyFound = obj.search("help");
	bkeyFound = obj.search("helping");
	bkeyFound = obj.search("cast");
	bkeyFound = obj.search("hel");
	bkeyFound = obj.search("held");
	return 0;
}