#include <iostream>
#include <vector>
using namespace std;

class Stack
{
    vector<int> store;
    int capacity;
    int size = 0;

public:
    Stack()
    {
    }

    void push(int el)
    {

        store.push_back(el);
        size++;
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
};

int main()
{
    Stack s1;
    cout << s1.pop() << endl;
    cout << s1.isEmpty() << endl;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.push(6);
    cout << s1.length() << endl;
    cout << s1.isEmpty() << endl;
    cout << s1.top() << endl;
    cout << s1.pop() << endl;
    cout << s1.top() << endl;
}