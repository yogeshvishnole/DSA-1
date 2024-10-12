/*
Remove kth node from end, in single traversal.

Now we know removal of a node is easy task just points the previos node next to the next node
of node to be deleted, here in this question imp task is to reach the kth node from end.

SO there are two approached -
1. Find the length of node by tarversing the list and then kth node from end will be
(n-k)+1 node from start, reach that node and delete that, this approach needs two traversals.

2. Step1 Take two pointers on head named first and second.
Step2 move second pointer two K steps
Step 3 move first and second pointer one step at a time.
Step 4 when second will reach at null first pointer will be on k+1 element from last.


Edge case  -
1. When kth from last is not in list
2. When kth from last in first node
3. When kth from last is last node

DO test the above edge cases code should work in these cases.
 */
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList
{

public:
    Node *head = nullptr;
    Node *tail = nullptr;
    void insert(int data)
    {

        Node *newNode = new Node(data);
        if (this->head == nullptr)
        {
            head = newNode;
        }
        if (tail == nullptr)
        {
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void print()
    {

        Node *temp = head;

        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void removeKthNodeFromEnd(int k)
    {
        Node *first = head;
        Node *second = head;

        for (int i = 0; i < k; i++)
        {
            if (second == nullptr)
            {
                // handling when kth from last is not in list
                cout << "Given kth element from end does not exist" << endl;
                return;
            }
            second = second->next;
        }

        // handling when kth element is first node
        if (second == nullptr)
        {
            first = first->next;
            delete head;
            head = first;
            return;
        }

        while (second->next)
        {
            second = second->next;
            first = first->next;
        }

        Node *kthNode = first->next;
        if (kthNode)
        {
            first->next = kthNode->next;
        }
        else
        {
            // handling when kth element os last node
            first->next = nullptr;
        }
        if (kthNode == head)
        {
            head = first;
        }
        delete kthNode;
    }
};

int main()
{
    LinkedList *l1 = new LinkedList();

    cout << "Enter the elements of the linked list and press -1 to stop giving input:  "
         << endl;

    while (true)
    {
        int userInput;
        cin >> userInput;
        if (userInput == -1)
            break;
        l1->insert(userInput);
    }

    cout << "Linked list before remove kth node from last: " << endl;
    l1->print();
    l1->removeKthNodeFromEnd(6);
    cout << "Linked list after removing kth node from last: " << endl;
    l1->print();
}