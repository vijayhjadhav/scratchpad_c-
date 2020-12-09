#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void insertNode(ListNode** head, ListNode **tail, int val)
{
    if (*head == nullptr)
    {
        *head = new ListNode(val);
        *tail = *head;
    }
    else
    {
        (*tail)->next = new ListNode(val);
        *tail = (*tail)->next;
    }
}

void printList(ListNode* head)
{
    ListNode* q = head;
    while (q != nullptr)
    {
        cout << q->val << "-->";
        q = q->next;
    }
    cout << "nullptr" << endl;
}

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddHead = nullptr;
        ListNode* oddTail = nullptr;
        ListNode* evenHead = nullptr;
        ListNode* evenTail = nullptr;
        ListNode* currentNode = head;
        bool isOdd = true;
        while (currentNode != nullptr)
        {
            if (isOdd)
            {
                if (oddHead == nullptr)
                {
                    oddHead = currentNode;
                    currentNode = currentNode->next;
                    oddHead->next = nullptr;
                    oddTail = oddHead;
                }
                else
                {
                    oddTail->next = currentNode;
                    currentNode = currentNode->next;
                    oddTail = oddTail->next;
                    oddTail->next = nullptr;
                }
                isOdd = false;
            }
            else
            {
                if (evenHead == nullptr)
                {
                    evenHead = currentNode;
                    currentNode = currentNode->next;
                    evenHead->next = nullptr;
                    evenTail = evenHead;
                }
                else
                {
                    evenTail->next = currentNode;
                    currentNode = currentNode->next;
                    evenTail = evenTail->next;
                    evenTail->next = nullptr;
                }
                isOdd = true;
            }
        }
        if (oddTail != nullptr)
            oddTail->next = evenHead;
        return oddHead;
    }
    bool isPalindrome(ListNode* head) {
        // find middle of linked list
        if (head == nullptr || head->next == nullptr)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* tail = nullptr;
        while (fast->next != nullptr)
        {
            slow = slow->next;
            if (fast->next->next != nullptr)
                fast = fast->next->next;
            else
                fast = fast->next;
        }
        tail = fast;

        // Reverse second half of linked list
        ListNode* mid = slow;
        if (slow != nullptr)
            slow = slow->next;

        // This is to make sure that both the list does not point to same node resulting 
        // in deleting it twice
        mid->next = nullptr;

        ListNode* next = nullptr;
        while (slow != nullptr)
        {
            next = slow->next;
            slow->next = mid;
            mid = slow;
            slow = next;
        }
        // check if list is Palindrome
        ListNode* start = head;
        ListNode* end = tail;
        while (start != nullptr && end != nullptr)
        {
            if (start->val != end->val)
                return false;
            if ((start->next == end) || (start == end))
                break;
            start = start->next;
            end = end->next;
        }
        return true;
    }
};
int main()
{
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    insertNode(&head, &tail, 1);
    insertNode(&head, &tail, 0);
    insertNode(&head, &tail, 0);
    //insertNode(&head, &tail, 2);
    //insertNode(&head, &tail, 3);
    //insertNode(&head, &tail, 3);
    //insertNode(&head, &tail, 2);
    //insertNode(&head, &tail, 1);
    printList(head);
    Solution obj;
    //ListNode *oeLL = obj.oddEvenList(head);
    //printList(oeLL);
    bool isPal = obj.isPalindrome(head);
    
    return 0;
}