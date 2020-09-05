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
	void linkNode(int iFromNode, int iToNode);
	void deleteNode(int iNode);
	NODE* findNode(int iNode);
	NODE* meetingPoint();
	NODE* BeginningLoopNode();
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
		tmp = NULL;
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

void SinglyLinkedList::linkNode(int iFromNode, int iToNode)
{
	NODE *ptrFromNode = findNode(iFromNode);
	NODE* ptrToNode = findNode(iToNode);

	if (NULL == ptrFromNode && NULL == ptrToNode)
	{
		cout << "Nodes " << iFromNode << " and " << iToNode << " does not exist" << endl;
		return;
	}

	if (NULL == ptrFromNode)
	{
		cout << "Node " << iFromNode << " does not exist" << endl;
		return;
	}

	if (NULL == ptrToNode)
	{
		cout << "Node " << iToNode << " does not exist" << endl;
		return;
	}
	
	ptrFromNode->nextNode = ptrToNode;

	cout << "From Node " << iFromNode << " is linked to To Node " << iToNode << endl;
	
	return;
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

NODE *SinglyLinkedList::findNode(int iNode)
{
	NODE* iter = head;
	while (iter != NULL)
	{
		if (iter->data == iNode)
		{
			return iter;			
		}			

		iter = iter->nextNode;
	}
		
	return NULL;
}

NODE *SinglyLinkedList::meetingPoint()
{
	if (head == NULL)
		return NULL;
	
	NODE *ptr1 = head;
	NODE* ptr2 = head;
	do 
	{
		if ((ptr1->nextNode == NULL) ||
			(ptr2->nextNode == NULL || ptr2->nextNode->nextNode == NULL))
			return NULL;
		
		ptr1 = ptr1->nextNode;
		ptr2 = ptr2->nextNode->nextNode;
				
		cout << "Ptr1 " << ptr1->data << "\tPtr2 " << ptr2->data << endl;
		
	} while (ptr1->data != ptr2->data);

	return ptr1;
}

//https://stackoverflow.com/questions/1536944/detecting-the-start-of-a-loop-in-a-singly-linked-link-list
NODE* SinglyLinkedList::BeginningLoopNode()
{
	NODE* ptr2 = meetingPoint();
	if (ptr2 != NULL)
	{
		NODE* ptr1 = head;
		while (ptr1->data != ptr2->data)
		{
			ptr1 = ptr1->nextNode;
			ptr2 = ptr2->nextNode;
		}
	}
	return ptr2;
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
	objSLL.appendNode(12);
	objSLL.appendNode(5);
	objSLL.appendNode(50);
	objSLL.appendNode(67);
	objSLL.appendNode(4);
	//objSLL.linkNode(4, 1);
	NODE* ptr = objSLL.BeginningLoopNode();
	if (ptr != NULL)
	{
		cout << "Beginning of Loop Node is " << ptr->data << endl;
	}
	else
		cout << "Loop not found" << endl;
	//objSLL.printList();

	//objSLL.addNode(2, 30);
	//objSLL.printList();

	//objSLL.deleteNode(56);
	//objSLL.printList();	

	return 0;
}