/*
Given two sorted linked lists, merge them in to a single list in a new list using the same nodes
and in a sorted manner
LL1 -> 1->5->9->NULL
LL2 -> 2->7->10->NULL

NOTE do it using recurison

The result should be -
LL1 = 1->2->5->7->9->10->NULL

Solution Approach:


 */

#include <iostream>
using namespace std;

// Lets defined the node of linked list
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
};

Node *mergeLL(Node *&l1, Node *&l2)
{
    // Base Case 1: If the first list is empty, return the second list.
    if (!l1)
        return l2;

    // Base Case 2: If the second list is empty, return the first list.
    if (!l2)
        return l1;

    // Declare a node pointer to store the merged list's head.
    Node *head = nullptr;

    // If the current node of l1 has a smaller value, make it the head.
    if (l1->data < l2->data)
    {
        head = l1; // Set l1 as the current head.

        // Recursively merge the remaining nodes of l1 and l2, setting the next of l1.
        head->next = mergeLL(l1->next, l2);
    }
    else
    {
        // If l2's current node has a smaller or equal value, set it as the head.
        head = l2; // Set l2 as the current head.

        // Recursively merge the remaining nodes of l1 and l2, setting the next of l2.
        head->next = mergeLL(l1, l2->next);
    }

    // Return the merged list with the smaller node as the new head.
    return head;
}

Node *print(Node *head)
{
    while (head)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "nullptr" << endl;
}
int main()
{
    LinkedList *l1 = new LinkedList();
    LinkedList *l2 = new LinkedList();

    cout << "Enter the elements of the linked list l1 and press -1 to stop giving input:  "
         << endl;

    while (true)
    {
        int userInput;
        cin >> userInput;
        if (userInput == -1)
            break;
        l1->insert(userInput);
    }
    cout << "Enter the elements of the linked list l2 and press -1 to stop giving input:  "
         << endl;

    while (true)
    {
        int userInput;
        cin >> userInput;
        if (userInput == -1)
            break;
        l2->insert(userInput);
    }

    cout << "Linked lists before merge: " << endl;
    l1->print();
    l2->print();
    Node *l3 = mergeLL(l1->head, l2->head);
    cout << "Linked list after merge: " << endl;
    print(l3);
}
