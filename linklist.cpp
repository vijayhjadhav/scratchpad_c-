#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;


struct node {
   int data;
   struct node *next;
};


struct node *current = NULL;

//display the list
void printList(node *head) {
	struct node *ptr = head;
//   //start from the beginning
   while(ptr != NULL) {
		cout << ptr->data << " ";
		ptr = ptr->next;
   }
   cout << endl;
}


// You’re given the pointer to the head node of a linked list, 
// an integer to add to the list and the position at which the 
// integer must be inserted. Create a new node with the given 
// integer, insert this node at the desired position and return
// the head node. A position of 0 indicates head, a position of
// 1 indicates one node away from the head and so on. The head 
// pointer given may be null meaning that the initial list is empty.
node* InsertNth(node *head, int data, int position)
{
    node *newNode = new node();
    newNode->data = data;
    newNode->next = NULL;
    int tposition = -1;
    if(NULL == head || position == 0)
    {
        newNode->next = head;
        head = newNode;    
    }else
    {
        node *iter = head;
		node *prev = head;
        while(iter != NULL)
        {
			tposition++;
            if(tposition == position)
            {			   
               newNode->next = prev->next;
			   prev->next = newNode;               
               break;
            }
			prev = iter;
            iter = iter->next;
        }
        
        if(tposition < position)
        {
           prev->next = newNode;    
        }
     }
    return head;
}

// You’re given the pointer to the head node of a linked list 
// and the position of a node to delete. Delete the node at the
// given position and return the head node. A position of 0 
// indicates head, a position of 1 indicates one node away from 
// the head and so on. The list may become empty after you delete
// the node.
node* Delete(node *head, int position)
{
  int tposition = -1;
  node *iter = head;
  node *prev = head;
  node *temp = NULL;
  while(iter != NULL)
  {
	tposition++;
    
    if(tposition == position)
    {
      if(tposition == 0)
      {
        temp = head;        
        head = iter->next;
      }
      else
      {
        temp = iter;
        prev->next = iter->next;
      }
      delete temp;
      temp = NULL;  
      break;  
    }
	prev = iter;
    iter = iter->next;    
  }
  return head;  
}

// You are given the pointer to the head node of a linked list
// and you need to print all its elements in reverse order from
// tail to head, one element per line. The head pointer may be 
// null meaning that the list is empty - in that case, do not
// print anything!
void ReversePrint(node *head)
{
  if(head == NULL)
      return;
    
  ReversePrint(head->next);
  cout << head->data << endl; 
}

node* Reverse(node *head)
{
	/*if(head->next == NULL)
		return head;
	
	node * newHead = Reverse(head->next);
	head->next->next = head;
	return newHead;		*/
	node *current = head;
	node *prev = NULL;
	node *next = NULL;
	while(current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
	return head;
}

int CompareLists(node *headA, node* headB)
{
  if(headA == NULL && headB == NULL)
      return 1;
  if(headA == NULL || headB == NULL)
	  return 0;
  if(headA->data == headB->data)      
     return CompareLists(headA->next, headB->next);
  else
    return 0;
}

node* MergeLists1(node *headA, node* headB)
{
  // This is a "method-only" submission. 
  // You only need to complete this method 
  int count = 0;
  node *headC = NULL;
  node *iterA = headA;
  node *iterB = headB;

  while(iterA != NULL && iterB != NULL)
  {
	  if(iterA->data < iterB->data)
	  {
		  headC = InsertNth(headC, iterA->data, count);
		  count++;
		  iterA = iterA->next;
	  }
	  else
	  {
		  headC = InsertNth(headC, iterB->data, count);
		  count++;
		  iterB = iterB->next;
	  }
  }

  while(iterA != NULL)
  {
	  headC = InsertNth(headC, iterA->data, count);
	  count++;
	  iterA = iterA->next;
  }

  while(iterB != NULL)
  {
	  headC = InsertNth(headC, iterB->data, count);
	  count++;
	  iterB = iterB->next;
  }

  return headC;
}

node* MergeLists(node *headA, node* headB)
{  
	if(headA == NULL && headB != NULL)
		return headB;
	else if(headA != NULL && headB == NULL)
		return headA;
	else if(headA == NULL && headB == NULL)
		return NULL;

	node *iterA = headA;
	node *iterB = headB;
	node *current = NULL;

	while(iterA != NULL && iterB != NULL)
	{
		if(iterA->data < iterB->data)
		{
			while(iterA->data < iterB->data)
			{
				current = iterA;		  
				iterA = iterA->next;
				if(iterA == NULL)
					break;
			}
			current->next = iterB;
		}
		else
		{
			while(iterB->data < iterA->data)
			{
				current = iterB;
				iterB = iterB->next;
				if(iterB == NULL)
					break;
			}
			current->next = iterA;
		}
	}

	return headA->data < headB->data ? headA: headB;  
}

int GetNode(node *head,int positionFromTail)
{
  // This is a "method-only" submission. 
  // You only need to complete this method. 
  node *temp = head;
  int count = 0;
  while(temp != NULL)
  {
	  temp = temp->next;
	  count++;
  }
  
  temp = head;
  int data = 0;
  int pos = count-1-positionFromTail;
  while(temp != NULL)
  {
	  if(pos == 0)
	  {
		  data = temp->data;
		  break;
	  }
	  pos--;
	  temp = temp->next;
  }

  return data;
}

node* RemoveDuplicates(node *head)
{
    if(head == NULL)
        return NULL;
    
    node *current = head;    
    while(current != NULL)
    {
        if(current->next != NULL)
        {
            if(current->data == current->next->data)
            {
				node *temp = current->next;
                current->next = current->next->next;    
				delete temp;
				temp = NULL;
            }
            else
            {
                current = current->next;    
            }
        }
		else
			break;
    }
    
    return head;  
}

bool has_cycle(node* head) {

	node *hare = head;
	node *tortoise = head;
	while(hare != NULL || tortoise != NULL)
	{
		if(hare->next == NULL || hare->next->next == NULL || tortoise->next == NULL)
		{
			return 0;
		}

		hare = hare->next->next;
		tortoise = tortoise->next;
		if(tortoise == hare)
		{
			return 1;
		}
	}

	return 0;    
}

int FindMergeNode(node *headA, node *headB)
{
	node *iterA = headA;
    node *iterB = headB;
    bool bfound = false;
    while(iterA != NULL)
    {
		iterB = headB;
        while(iterB != NULL)
        {
            if(iterB == iterA)
             {
                bfound = true;
                break;   
            }
            iterB = iterB->next;
        }
        if(bfound == true)
            break;
        iterA = iterA->next;
    }
    return iterB->data;
}

int main()
{
	node *headA = NULL;
	node *headB = NULL;
	//bool hcycle = has_cycle(headA);
	int data = FindMergeNode(headA, headB);

	headA = InsertNth(NULL, 1, 0);
	headA = InsertNth(headA, 1, 1);
	headA = InsertNth(headA, 3, 2);
	headA = InsertNth(headA, 3, 3);
	headA = InsertNth(headA, 5, 4);
	headA = InsertNth(headA, 56, 5);
	//headA = InsertNth(headA, 725, 6);
	/*headA = InsertNth(headA, 954, 7);
	headA = InsertNth(headA, 410, 8);
	headA = InsertNth(headA, 207, 9);*/
	cout << "Linkedlist A" << endl;
	printList(headA);
	
	headA = RemoveDuplicates(headA);
	cout << "After removing duplicates" << endl;
	printList(headA);
	cout << "Data at position 1 from tail:  " << GetNode(headA, 1) << endl;
	cout << "Data at position 3 from tail:  " << GetNode(headA, 3) << endl;

	
	headB = InsertNth(NULL, 2, 0);
	headB = InsertNth(headB, 3, 1);
	headB = InsertNth(headB, 9, 2);
	headB = InsertNth(headB, 11, 3);
	//headB = InsertNth(headB, 52, 4);
	//headB = InsertNth(headB, 217, 5);
	//headB = InsertNth(headB, 410, 6);
	/*headB = InsertNth(headB, 954, 7);
	headB = InsertNth(headB, 410, 8);*/
	//headB = InsertNth(headB, 217, 9);
	cout << "Linkedlist B" << endl;
	printList(headB);

	int result = CompareLists(headA, headB);
	cout << "Result of comparision : "<< result << endl;


	node * headC = MergeLists(headA, headB);
	cout << "After merging Linkedlist A and B" << endl;
	printList(headC);

	//node *newhead = Reverse(head);
	//head->next = NULL;
	//printList(newhead);
	return 0;   
}