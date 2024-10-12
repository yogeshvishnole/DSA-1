/*
Given a linked list(means its head), and a target key, find out if key is present in the linked
list.
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

    static bool search(Node *head, int target)
    {
        while (head != nullptr)
        {
            if (target == head->data)
                return true;

            head = head->next;
        }
        return false;
    }

    static bool searchRecursive(Node *head, int target)
    {
        if (head == nullptr)
            return false;
        return head->data == target || searchRecursive(head->next, target);
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

    /*
    // code for testing of search function
      const bool isPresent = LinkedList::search(l1->head, 7);
     if (isPresent)
     {
         cout << "Element found in LL";
     }
     else
     {
         cout << "Not found";
     } */

    // Code for testing of searchRecursive function
    const bool isPresent = LinkedList::searchRecursive(l1->head, 7);
    if (isPresent)
    {
        cout << "Element found in LL";
    }
    else
    {
        cout << "Not found";
    }
}