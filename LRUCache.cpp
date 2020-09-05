#include <iostream>
#include <map>
#include <string>
using namespace std;
struct Node
{
	Node *next;
	Node *prev;
	int value;
	int key;
	Node(Node *p, Node *n, int k, int val):prev(p), next(n), key(k), value(val){};
	Node(int k, int val):key(k), value(val){};
};

class Cache
{
public:
	virtual void set(int, int) = 0;
	virtual int get(int) = 0;

protected:
	map<int, Node*> mp;
	int cp;
	Node *tail;
	Node *head;
};

class LRUCache : public Cache
{
public:
	LRUCache(int capacity)
	{
		tail = NULL;
		head = NULL;
		cp = capacity;
		count = 0;
	};

	void addNewNode(int key, int value);
	void deleteLRUNode();
	void moveNodeToRecent(Node *currentNode);
	void set(int key, int val);
	int get(int key);
	void printCache();

private:
	int count;
};

void LRUCache::addNewNode(int key, int value)
{
	Node *newNode = NULL;
	newNode = new Node(key, value);
	mp[key] = newNode;
	if(head == NULL)
	{
		newNode->next = NULL;
		newNode->prev = NULL;
		head = newNode;
		tail = newNode;
		count++;
		return;
	}
	newNode->next = head;
	newNode->prev = NULL;
	head->prev = newNode;
	head = newNode;
	count++;
}

void LRUCache::deleteLRUNode()
{
	Node *newTailNode = tail->prev;
	mp.erase(tail->key);
	delete tail;
	newTailNode->next = NULL;
	tail = newTailNode;
	count--;
}

void LRUCache::moveNodeToRecent(Node *currentNode)
{
	Node *currentPrev = currentNode->prev;
	Node *currentNext = currentNode->next;
	currentPrev->next = currentNext;
	if(currentNext != NULL)
		currentNext->prev = currentPrev;
	currentNode->prev = NULL;
	currentNode->next = head;
	head = currentNode;
}

void LRUCache::set(int key, int val)
{	
	auto it = mp.find(key);
	if(it == mp.end())
	{		
		if(count >= cp)
			deleteLRUNode();
		addNewNode(key, val);
	}
	else
	{
		Node *existingNode = it->second;
		existingNode->value = val;  //Update the value
		if(existingNode->prev != NULL)
			moveNodeToRecent(existingNode);
	}	
}

int LRUCache::get(int key)
{
	int value = -1;
	auto it = mp.find(key);
	if(it != mp.end())
	{		
		value = it->second->value;
		Node *existingNode = it->second;
		if(existingNode->prev != NULL)
			moveNodeToRecent(existingNode);
	}

	return value;
}

void LRUCache::printCache()
{
	Node *temp = head;
	while(temp != NULL)
	{
		cout << temp->key << "\t" << temp->value << endl;
		temp = temp->next;
 	}
}

int main()
{
	long int NQ;
	int capacity;

	cin >> NQ >> capacity;
	LRUCache objCache(capacity);

	string command;
	int key, value;
	for(auto i = 0; i < NQ; i++)
	{
		cin >> command;
		cin >> key;
		if(command == "set")
		{
			cin >> value;
			objCache.set(key, value);
		}
		else
		{
			cout << objCache.get(key) << endl;
		}
	}
	
	//objCache.set(1, 2);
	//objCache.printCache();
	//cout << objCache.get(1) << endl;
	//cout << objCache.get(2) << endl;
	//objCache.set(2, 4);
	//objCache.set(4, 16);
	//objCache.set(5, 25);
	//objCache.set(7, 49);
	//objCache.set(6, 36);
	//objCache.printCache();
	//cout << endl;
	//
	//objCache.set(8, 64);
	//objCache.printCache();
	//cout << endl;

	//cout << objCache.get(5) << endl;
	//cout << endl;
	//objCache.printCache();
	//cout << endl;
	return 0;
}
