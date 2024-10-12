#include <iostream>
#include <sstream>
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

    Node *head = nullptr;
    Node *tail = nullptr;

public:
    void
    insert(int data)
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
        /* Node *temp = head;
        while (true)
        {
            cout << temp->data << " ";
            if (temp->next == nullptr)
                break;
            temp = temp->next;
        }
        cout << endl; */

        // ABove is mine soln but simpler version is as follows -
        Node *temp = head;

        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }

    void printIthNode(int pos)
    {
        if (pos < 1 || pos > this->length())
        {
            cout << "Invalid postition " << pos << " inputted for printing" << endl;
            return;
        }
        // lets reach to ith node
        Node *temp = head;
        int count = 1;
        while (count < pos)
        {
            temp = temp->next;
            count++;
        }
        cout << "Elemet at pos " << pos << " is : " << temp->data << endl;
    }

    int length()
    {
        if (head == nullptr)
            return 0;
        int count = 0;
        Node *temp = head;
        while (true)
        {
            count++;
            if (temp->next == nullptr)
                break;
            temp = temp->next;
        }
        return count;
    }

    void insertIthNode(int data, int pos)
    {
        const int lengthOfLL = this->length();
        if (pos < 1 || pos > lengthOfLL + 1)
        {
            cout << "Invalid postition " << pos << " inputted for inserting" << endl;
            return;
        }
        if (head == nullptr || pos == lengthOfLL + 1)
        {
            this->insert(data);
            return;
        }
        int count = 1;
        Node *temp = head;
        while (count < pos - 1)
        {
            temp = temp->next;
            count++;
        }
        if (pos == 1)
        {
            Node *newNode = new Node(data);
            newNode->next = temp;
            head = newNode;
        }
        else
        {
            Node *newNode = new Node(data);
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void deleteIthNode(int pos)
    {
        const int lengthOfLL = this->length();
        if (pos < 1 || pos > lengthOfLL)
        {
            cout << "Invalid postition " << pos << " inputted for deleting" << endl;
            return;
        }
        int count = 1;
        Node *temp = head;
        while (count < pos - 1)
        {
            temp = temp->next;
            count++;
        }
        if (pos == 1)
        {

            head = head->next;
            delete temp;
        }
        else
        {
            Node *nodeToDelete = temp->next;
            temp->next = nodeToDelete->next;
            delete nodeToDelete;
        }
    }
};

int main()
{
    LinkedList *l1 = new LinkedList();

    cout << "Enter the elements of the linked list:  "
         << endl;

    cout << "Length of l1 before insertion : " << l1->length() << endl;
    while (true)
    {
        int userInput;
        cin >> userInput;
        if (userInput == -1)
            break;
        l1->insert(userInput);
    }
    cout << "Length of l1 after insertion : " << l1->length() << endl;

    l1->print();
    l1->printIthNode(2);
    l1->printIthNode(6);
    l1->printIthNode(0);
    l1->insertIthNode(6, 6);
    l1->print();
    cout << "Length of l1 after insertion : " << l1->length() << endl;

    l1->insertIthNode(54, 1);
    l1->print();
    cout << "Length of l1 after insertion : " << l1->length() << endl;

    l1->insertIthNode(0, 0);
    l1->print();
    cout << "Length of l1 after insertion : " << l1->length() << endl;

    l1->insertIthNode(76, 8);
    l1->print();
    cout << "Length of l1 after insertion : " << l1->length() << endl;

    l1->deleteIthNode(4);
    cout << "Length of l1 after deletion : " << l1->length() << endl;
    l1->print();

    l1->deleteIthNode(1);
    cout << "Length of l1 after deletion : " << l1->length() << endl;
    l1->print();
    l1->deleteIthNode(6);
    cout << "Length of l1 after deletion : " << l1->length() << endl;
    l1->print();
    l1->deleteIthNode(6);
    cout << "Length of l1 after deletion : " << l1->length() << endl;
    l1->print();
}