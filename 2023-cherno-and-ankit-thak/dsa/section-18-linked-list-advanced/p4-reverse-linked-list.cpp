/*

Given a linked list
1->2->3->4->5->NULL
Reverse it to -
5->4->3->2->1->NULL

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

    Node *reverseTheList()
    {
        Node *prevNode = nullptr;
        Node *currentNode = head;
        Node *nextNode = head->next;

        while (currentNode != nullptr)
        {
            nextNode = currentNode->next;
            currentNode->next = prevNode;
            prevNode = currentNode;
            currentNode = nextNode;
        }

        head = prevNode;
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

    cout << "Linked list before reverse: " << endl;
    l1->print();
    l1->reverseTheList();
    cout << "Linked list after reverse: " << endl;
    l1->print();
}