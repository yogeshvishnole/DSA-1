#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Queue
{

    vector<T> store;

public:
    void enqueue(T data)
    {
        store.push_back(data);
    }

    void dequeue()
    {
        if (store.empty())
        {
            cout << "Queue is empyty" << endl;
        }
        else
        {
            store.erase(store.begin());
        }
    }

    T front()
    {
        if (store.empty())
        {
            cout << "Queue is empyty" << endl;
            return 0;
        }
        return store[0];
    }

    bool isEmpty()
    {
        return store.empty();
    }

    T size()
    {
        return store.size();
    }
};

int main()
{
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    cout << q.front() << endl;
    q.dequeue();
    cout << q.front() << endl;
    q.dequeue();
    cout << "Queue size now : " << q.size() << endl;
    cout << q.front() << endl;
    q.dequeue();
    cout << q.front() << endl;
    q.dequeue();
    cout << q.front() << endl;
    q.dequeue();
}