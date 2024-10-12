#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data) : data(data), next(nullptr) {}
};

void printLinkedList(Node *head)
{
    Node *temp = head;
    while (true)
    {
        cout << temp->data << " ";
        if (temp->next == nullptr)
            break;
        temp = temp->next;
    }
    cout << endl;
}

int main()
{

    // Lets create some nodes in stack
    Node n1(1);
    Node n2(2);
    Node n3(3);
    Node n4(4);

    // Lets create a linked list using the above nodes
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;

    Node *head = &n1;

    printLinkedList(head);
}