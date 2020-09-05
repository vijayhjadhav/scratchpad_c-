#include <iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node* nextNode;
	struct node(int idata)
	{
		data = idata;
		nextNode = NULL;
	}

	struct node(int idata, struct node* ptrNextNode)
	{
		data = idata;
		nextNode = ptrNextNode;
	}
}NODE;

class SinglyLinkedList
{
	NODE* head;
public:
	SinglyLinkedList()
	{
		head = NULL;
	}

	~SinglyLinkedList();

	SinglyLinkedList(NODE* newNode);
	void appendNode(int iNewNode);
	void addNode(int iPrevNode, int iNewNode);
	void deleteNode(int iNode);
	void findNode(int iNode);
	void printList();
};

SinglyLinkedList::~SinglyLinkedList()
{
	NODE* iter = head;
	NODE* tmp;
	while (iter != NULL)
	{
		tmp = iter;
		iter = iter->nextNode;
		delete tmp;		
	}
	head = NULL;
}

SinglyLinkedList::SinglyLinkedList(NODE* newNode)
{
	head = newNode;
}

void SinglyLinkedList::appendNode(int iNewNode)
{
	NODE* newNode = new NODE(iNewNode);
	if (head == NULL)
		head = newNode;
	else
	{
		NODE* iter = head;
		while (iter->nextNode != NULL)
			iter = iter->nextNode;
		iter->nextNode = newNode;
	}
}

void SinglyLinkedList::addNode(int iPrevNode, int iNewNode)
{
	NODE* newNode = new NODE(iNewNode);

	NODE* iter = head;
	
	while (iter != NULL)
	{
		if (iter->data == iPrevNode)
		{
			newNode->nextNode = iter->nextNode;
			iter->nextNode = newNode;
			break;
		}
		iter = iter->nextNode;
	}
}

void SinglyLinkedList::deleteNode(int iNode)
{
	if (head == NULL)
		cout << "Linked List is empty" << endl;
	else
	{
		if (head->data == iNode)
		{
			NODE* tmp = head;
			head = head->nextNode;
			delete tmp;
		}
		else
		{			
			NODE* previous = head;
			NODE* iter = head->nextNode;
			while (iter != NULL)
			{
				if (iter->data == iNode)
				{
					previous->nextNode = iter->nextNode;
					delete iter;
					break;
				}
				previous = iter;
				iter = iter->nextNode;
			}
		}
		
	}

}

void SinglyLinkedList::findNode(int iNode)
{
	NODE* iter = head;
	while (iter != NULL)
	{
		if (iter->data == iNode)
		{
			cout << iNode << " found" << endl;
			return;
		}			

		iter = iter->nextNode;
	}
	
	cout << iNode << " not found" << endl;
	return;
}

void SinglyLinkedList::printList()
{
	NODE* iter = head;
	while (iter != NULL)
	{
		cout << iter->data << "\t";
		iter = iter->nextNode;
	}
	cout << endl;
}

int main()
{
	SinglyLinkedList objSLL;
	objSLL.appendNode(23);
	objSLL.appendNode(25);
	objSLL.appendNode(2);
	objSLL.appendNode(56);
	objSLL.appendNode(1);

	objSLL.printList();

	objSLL.addNode(2, 30);
	objSLL.printList();

	objSLL.deleteNode(56);
	objSLL.printList();

	objSLL.findNode(2);

	objSLL.findNode(34);

	return 0;
}