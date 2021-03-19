typedef struct listnode
{
    int val;
    struct listnode *next;
    listnode(int val):val(val), next(nullptr){};
}ListNode;

class MyLinkedList {

    ListNode* head, * tail;
public:
    /** Initialize your data structure here. */
    MyLinkedList()
    {
        head = nullptr;
        for (int i = 0; i < 5; i++)
        {
            ListNode* newNode = new ListNode(i * 5 + 1);
            if (head == nullptr)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                newNode->next = head;
                head = newNode;
            }
        }
    }

    MyLinkedList(int val)
    {
        head = new ListNode(val);
        tail = head;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        ListNode* currentNode = head;
        while (currentNode != nullptr && index >= 0)
        {
            currentNode = currentNode->next;
            index--;
        }
        return currentNode->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        if (tail != nullptr)
            tail->next = newNode;
        tail = newNode;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        ListNode* currentNode = head;
        while (currentNode != nullptr && index > 0)
        {
            currentNode = currentNode->next;
            index--;
        }

        if (index > 1 && currentNode == nullptr)
            return;

        ListNode* newNode = new ListNode(val);
        newNode->next = currentNode->next;
        currentNode->next = newNode;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        ListNode* currentNode = head;
        ListNode* prevNode = nullptr;
        while (currentNode != nullptr && index >= 0)
        {
            prevNode = currentNode;
            currentNode = currentNode->next;
            index--;
        }

        if (index > 0 && currentNode == nullptr)
            return;

        prevNode->next = currentNode->next;
        delete currentNode;
        currentNode = nullptr;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main()
{
    MyLinkedList* obj = new MyLinkedList();
    int param_1 = obj->get(2);
    obj->addAtHead(43);
    obj->addAtTail(56);
    obj->addAtIndex(4, 65);
    obj->deleteAtIndex(7);
    return 0;
}