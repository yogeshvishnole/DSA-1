#include <iostream>
using namespace std;

template <typename T>
class Queue
{
    int store[5];
    int nI = 0;
    int fI = -1;
    int length = 0;

public:
    void push(T data)
    {
        if (this->length == 5)
        {
            cout << "Queue is full" << endl;
            return;
        }

        if (fI == -1)
        {
            fI = 0;
        }

        store[nI] = data;
        this->length = this->length + 1;
        nI = (nI + 1) % 5;
    }

    int size()
    {
        return this->length;
    }

    void pop()
    {
        if (this->size() == 0)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        this->length = this->length - 1;
        fI = (fI + 1) % 5;
    }

    bool empty()
    {
        return this->length == 0;
    }

    T front()
    {
        if (this->length == 0)
        {
            cout << "Queue is empty" << endl;
            return 0;
        }
        return store[fI];
    }
};

int main()
{
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    cout << q.empty() << endl;
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    cout << q.empty() << endl;
}