/*
 * Node class implementation for a linked list
 */

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor using initializer list
    Node(int data) : data(data), next(nullptr) {}
};

int main()
{
    // create a independent node in stack memory
    Node n1(1);
    Node n2(2);

    // Lets link n1 to n2 to form a linked list with two nodes n1 and n2
    n1.next = &n2;

    // Now lets print the linked list nodes data
    cout << n1.data << endl;
    cout << n2.data << endl;

    // The first node of the linked list is also called as head and last node is also
    // called as tail
    // Lets create a head pointer for our above linkedlist
    Node *head = &n1;
    cout << head->data << endl;

    // Lets create the linked list dynamically
    Node *dn1 = new Node(1);
    Node *dn2 = new Node(2);

    // lets create the linked list from above two nodes present in heap memory
    dn1->next = dn2;
    cout << dn1->data << endl;
    cout << (*dn2).data << endl;

    // Lets create the head pointer for the dynamic list
    Node *dhead = dn1;
    cout << dhead->data << endl;
}
