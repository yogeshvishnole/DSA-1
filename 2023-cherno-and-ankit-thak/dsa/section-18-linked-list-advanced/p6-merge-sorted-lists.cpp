/*
Given two sorted linked lists, merge them in to a single list the first list and in a sorted
 manner
LL1 -> 1->5->9->NULL
LL2 -> 2->7->10->NULL

The result should be -
LL1 = 1->2->5->7->9->10->NULL

Solution Approach:
Edge Cases: If either l1 or l2 is null, return the other list immediately.
Pointer Setup: Use two pointers, one for traversing l1 and one for l2.
Merging Logic: Compare the values at each pointer:
If the current node in l1 has a smaller or equal value, move the l1 pointer.
If the current node in l2 is smaller, insert it before the current l1 node.
End Case: If you reach the end of l1 while l2 still has nodes left, append all remaining nodes of l2 to the end of l1.

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

    Node *mergeLL(LinkedList *&ll2)
    {
        // p1 is a pointer to traverse the first linked list (this list).
        Node *p1 = head;

        // ll1PrevNode keeps track of the previous node in the first list (used for insertion).
        Node *ll1PrevNode = nullptr;

        // p2 is a pointer to traverse the second linked list (ll2).
        Node *p2 = ll2->head;

        // Iterate while both lists have nodes to compare.
        while (p1 && p2)
        {
            // If the current node of the first list is smaller than the current node of the second list.
            if (p1->data < p2->data)
            {
                // Move ll1PrevNode to the current node in the first list (p1).
                ll1PrevNode = p1;

                // Move the p1 pointer to the next node in the first list.
                p1 = p1->next;
            }
            else
            {
                // Temporary pointer to store the next node in the second list (ll2).
                Node *temp = p2->next;

                // If there is a previous node in the first list (ll1PrevNode is not null).
                if (ll1PrevNode)
                {
                    // Insert the current p2 node between ll1PrevNode and p1 in the first list.
                    Node *temp = ll1PrevNode->next; // Save p1's current node.
                    ll1PrevNode->next = p2;         // Link ll1PrevNode to p2.
                    p2->next = temp;                // Link p2 to p1.
                }
                else
                {
                    // If there is no previous node (p1 is at the head), insert p2 at the beginning.
                    head = p2;        // Make p2 the new head of the first list.
                    p2->next = p1;    // Link p2 to p1.
                    ll1PrevNode = p2; // Set p2 as the previous node.
                }

                // Move the p2 pointer to the next node in the second list.
                p2 = temp;
            }
        }

        // If there are remaining nodes in the second list after p1 reaches the end.
        if (p2)
        {
            // Attach the remaining nodes of the second list (p2) to the first list.
            ll1PrevNode->next = p2;

            // Update the tail of the first list to be the tail of the second list.
            tail = ll2->tail;
        }
    }
};

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
    l1->mergeLL(l2);
    cout << "Linked list after merge: " << endl;
    l1->print();
    l2->print();
}
