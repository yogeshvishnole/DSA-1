/*
To implement a stack using a linked list, you leverage the dynamic nature of linked lists,
 allowing for efficient push and pop operations without worrying about fixed size constraints
  (like in arrays). Here's a brief approach:

Key Components:
Node Structure:
Each node of the linked list will store:
Data: The value stored in the stack.
Next Pointer: A reference to the next node in the stack.
Stack Operations:
Push (Insertion):
Create a new node.
Point the new node's next pointer to the current top.
Update the top to the new node.
Pop (Removal):
Return the data at the top.
Update the top pointer to the next node.
Delete the old top node.
Peek (Top Element):
Return the value of the top node without removing it.
IsEmpty:
Check if the top is nullptr to determine if the stack is empty.
Advantages:
Dynamic Size: Stack size is only limited by the memory available.
Efficient Operations: Both push and pop operations are performed in constant time, O(1).
This approach avoids the need to resize the stack (as in array-based stacks) and is more memory-efficient when the number of elements varies significantly.







 */

#include <iostream>
using namespace std;

template <typename T>
class ListNode
{

public:
    T data;
    ListNode<T> *next;

    ListNode(T data) : data(data), next(nullptr) {}
};

template <typename T>
class Stack
{

    ListNode<T> *head = nullptr;
    int size = 0;

public:
    // ADT of stack
    void
    push(T data)
    {
        ListNode<T> *node = new ListNode<T>(data);

        node->next = head;
        head = node;

        size++;
    }

    void pop()
    {
        if (!head)
        {
            cout << "Stack empty" << endl;
            return;
        }
        ListNode<T> *temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
        size--;
    }

    T top()
    {
        if (!head)
        {
            cout << "Stack empty" << endl;
            return 0;
        }
        return head->data;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    int length()
    {
        return size;
    };
};
int main()
{
    Stack<int> s;
    Stack<string> ss;

    s.push(1);
    s.push(2);
    ss.push("hi");
    ss.push("hello");
    cout << s.top() << endl;
    cout << ss.top() << endl;
    cout << s.length() << endl;
    cout << ss.length() << endl;

    s.pop();
    s.pop();
    ss.pop();
    cout << s.isEmpty() << endl;
    cout << ss.isEmpty() << endl;
};