#include <iostream>
#include <map>
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
	map<int, int> nodeFrequency;
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
	NODE* loopStartingPoint();
	NODE* loopEndingPoint();
	void removeDuplicatesN2();
	void removeDuplicatesSinglePass();
	void printList();
};

SinglyLinkedList::~SinglyLinkedList()
{
	NODE* ptrLastNodeLoop = loopEndingPoint();
	if (ptrLastNodeLoop != NULL)
		ptrLastNodeLoop->nextNode = NULL;

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
	nodeFrequency[iNewNode]++;
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
	nodeFrequency[iNewNode]++;
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
			tmp = NULL;
			nodeFrequency[iNode]--;
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
					nodeFrequency[iNode]--;
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
				
		//cout << "Ptr1 " << ptr1->data << "\tPtr2 " << ptr2->data << endl;
		
	} while (ptr1->data != ptr2->data);

	return ptr1;
}

//https://stackoverflow.com/questions/1536944/detecting-the-start-of-a-loop-in-a-singly-linked-link-list
NODE* SinglyLinkedList::loopStartingPoint()
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

NODE* SinglyLinkedList::loopEndingPoint()
{
	NODE* ptrLoopEndingPoint = NULL;
	NODE* ptrLoopStartingPoint = loopStartingPoint();
	if (ptrLoopStartingPoint != NULL)
	{
		ptrLoopEndingPoint = ptrLoopStartingPoint->nextNode;
		while (ptrLoopEndingPoint->nextNode != ptrLoopStartingPoint)
		{
			ptrLoopEndingPoint = ptrLoopEndingPoint->nextNode;
		}
	}
	return ptrLoopEndingPoint;
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

// This one has O(N2) runtime and is not using temporary buffer
void SinglyLinkedList::removeDuplicatesN2()
{
	// Input 23 25 2 56 25 12 25 56 67 4
	// Output 23 25 2 56 12 67 4
	NODE* ptrCurrent = head;
	NODE* ptrNext = NULL;
	NODE* prevNode = NULL;
	NODE* tmp = NULL;
	while (ptrCurrent != NULL)
	{
		ptrNext = ptrCurrent->nextNode;
		prevNode = ptrCurrent;
		while (ptrNext != NULL)
		{
			if (ptrCurrent->data == ptrNext->data)
			{
				// Delete this node and continue search for more such nodes		
				prevNode->nextNode = ptrNext->nextNode;
				tmp = ptrNext;
				delete tmp;
				tmp = NULL;
				nodeFrequency[ptrCurrent->data]--;
				ptrNext = prevNode;
			}
			prevNode = ptrNext;
			ptrNext = ptrNext->nextNode;
		}
		ptrCurrent = ptrCurrent->nextNode;
	}	
}

// This one is using temporary buffer for hash table and is O(N)
void SinglyLinkedList::removeDuplicatesSinglePass()
{
	// Input 23 25 2 56 25 12 25 56 67 4
	// Output 23 2 12 25 56 67 4
	NODE* ptr = head;
	NODE* prev = NULL;
	NODE* tmp = NULL;
	while (ptr != NULL)
	{
		if (nodeFrequency[ptr->data] > 1)
		{
			nodeFrequency[ptr->data]--;
			tmp = ptr;
			ptr = ptr->nextNode;
			
			if (prev == NULL)
				head = ptr;				
			else
				prev->nextNode = ptr;
			
			delete tmp;
			tmp = NULL;
		}
		else
		{
			prev = ptr;
			ptr = ptr->nextNode;
		}		
	}
}

int main()
{
	SinglyLinkedList objSLL;
	objSLL.appendNode(23);
	objSLL.appendNode(25);
	objSLL.appendNode(2);
	objSLL.appendNode(56);
	objSLL.appendNode(25);
	objSLL.appendNode(12);
	objSLL.appendNode(25);
	objSLL.appendNode(56);
	objSLL.appendNode(67);
	objSLL.appendNode(4);
	//objSLL.linkNode(4, 1);
	/*NODE* ptr = objSLL.loopStartingPoint();
	if (ptr != NULL)
	{
		cout << "First node of the Loop is " << ptr->data << endl;
	}
	else
		cout << "Loop not found" << endl;

	NODE* ptr2 = objSLL.loopEndingPoint();
	if (ptr2 != NULL)
	{
		cout << " Last node of the Loop is " << ptr2->data << endl;
	}
	else
		cout << "Loop not found" << endl;*/
	objSLL.printList();
	objSLL.removeDuplicatesSinglePass();
	objSLL.printList();

	//objSLL.addNode(2, 30);
	//objSLL.printList();

	//objSLL.deleteNode(56);
	//objSLL.printList();	

	return 0;
}