#include <iostream>
using namespace std;

class Stack
{
    int *store;
    int capacity;
    int size = 0;

public:
    Stack(int size) : capacity(size)
    {
        store = new int[capacity];
    }

    void push(int el)
    {
        if (size < capacity)
        {
            store[size] = el;
            size++;
        }
        else
        {
            cout << "stack overflow" << endl;
        }
    }
    int pop()
    {
        if (this->isEmpty())
        {
            cout << "stack underflow" << endl;
            return -1;
        }

        size--;
        return store[size];
    }
    int top()
    {
        if (this->isEmpty())
        {
            cout << "stack is empty" << endl;
            return -1;
        }
        return store[size - 1];
    }
    bool isEmpty()
    {
        if (size == 0)
        {
            return true;
        }
        return false;
    }
    int length()
    {
        return size;
    }
    bool isFull()
    {
        if (size == capacity)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Stack s1(5);
    cout << s1.pop() << endl;
    cout << s1.isEmpty() << endl;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.push(6);
    cout << s1.length() << endl;
    cout << s1.isFull() << endl;
    cout << s1.isEmpty() << endl;
    cout << s1.top() << endl;
    cout << s1.pop() << endl;
    cout << s1.top() << endl;
}