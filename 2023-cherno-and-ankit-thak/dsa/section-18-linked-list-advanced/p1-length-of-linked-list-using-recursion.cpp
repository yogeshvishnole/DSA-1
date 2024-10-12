/*
Find length of linked list using recursion
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

    static int lengthRecursive(Node *head)
    {
        if (head == nullptr)
        {
            return 0;
        }

        return 1 + lengthRecursive(head->next);
    }
};

int main()
{
    LinkedList *l1 = new LinkedList();

    cout << "Enter the elements of the linked list and press -1 to stop giving input:  "
         << endl;

    cout << "Length of l1 before insertion : " << LinkedList::lengthRecursive(l1->head) << endl;
    while (true)
    {
        int userInput;
        cin >> userInput;
        if (userInput == -1)
            break;
        l1->insert(userInput);
    }
    cout << "Length of l1 after insertion : " << LinkedList::lengthRecursive(l1->head) << endl;
}