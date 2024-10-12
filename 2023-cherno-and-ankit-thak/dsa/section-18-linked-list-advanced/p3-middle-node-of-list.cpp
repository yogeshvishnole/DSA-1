/*
Given a linked list, get the address of its mid node.
lets say we have list -
1->2->3->4->5->NULL , in this case 3 is mid
And for even length list like -
1->2->3->4->5->6->NULL
consider the 4 as mid, the righter side element.

There are two approaches -
Approach1 - Find the length by traversing over the list.
and then traverse till length/2 to find the mid of the list.

The approach 1 need two traversals, we have one better approach that only need single traversal

Approach - slow and fast pointer approach
As per this approach take two pointer slow and fast
initialize slow with head and fast with head->next

Now move slow by node and fast by two nodes so -
slow = slow->next ANd
fast = fast->next->next

Now move them till fasy = null OR fast->next becomes NULL.

In case of odd numbered list fast will become null in the end AND in even numbered list
fast->next will become null, so and slow->next will be our mid as per the problems requirement.
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

    Node *findMid()
    {
        Node *slow = head;
        Node *fast = head->next;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        if (!fast)
        {
            return slow;
        }
        else
        {
            return slow->next;
        }
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

    cout << "Mid of LL is: " << l1->findMid()->data << endl;
}