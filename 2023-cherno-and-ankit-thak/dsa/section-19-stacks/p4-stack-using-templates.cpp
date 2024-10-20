#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Stack
{
    vector<T> store;
    int size = 0;

public:
    void push(T data)
    {
        store.push_back(data);
        size++;
    }
    void pop()
    {
        if (size == 0)
        {
            cout << "Stack underflow" << endl;
        }
        size--;
    }
    T top()
    {
        if (size == 0)
        {
            cout << "Stack underflow" << endl;
            return 0;
        }
        return store[size - 1];
    }
    bool isEmpty()
    {
        return size == 0;
    }
    int length()
    {
        return size;
    }
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