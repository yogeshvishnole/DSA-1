#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class DynamicQueue
{
    vector<T> store;
    int front, next, length;

public:
    DynamicQueue(int initialCapacity = 4) : store(initialCapacity), front(-1), next(0), length(0)
    {
    }

    void push(T data)
    {
        if (length == 0)
        {
            front = 0;
        }

        int capacity = store.capacity();
        if (length == capacity)
        {
            vector<T> newStore(2 * capacity);
            for (int i = 0; i < store.size(); i++)
            {
                newStore[i] = store[(front + i) % capacity];
            }
            cout << endl;
            store = move(newStore);
            next = length;
            // cout
            //     << "ola" << next << endl;
        }

        store[next] = data;
        next = (next + 1) % store.capacity();
        // cout << next << " ";
        // cout << endl;
        length++;
    }

    void pop()
    {
        // cout << front << " ";
        // cout << endl;
        // for (auto const item : store)
        // {
        //     cout << item << " ";
        // }
        cout << endl;
        if (length == 0)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        front = (front + 1) % store.capacity();
        length--;
        if (length == 0)
        {
            front = -1;
        }
    }

    T getFront()
    {
        if (length == 0)
        {
            cout << "Queue is empty" << endl;
            return 0;
        }
        return store[front];
    }

    bool isEmpty()
    {
        return length == 0;
    }

    int size()
    {
        return length;
    }
};

int main(int argc, char **argv)
{
    DynamicQueue<int> *dq = new DynamicQueue<int>();
    dq->push(1);
    dq->push(2);
    dq->push(3);
    dq->push(4);
    dq->push(5);
    dq->push(6);
    dq->push(7);
    cout << dq->getFront() << endl;
    dq->pop();
    cout << dq->getFront() << endl;
    dq->pop();
    cout << dq->getFront() << endl;
    dq->pop();
    cout << "is queue empty : " << dq->isEmpty() << endl;
    cout << "Queue Length : " << dq->size() << endl;

    cout << dq->getFront() << endl;
    dq->pop();
    cout << dq->getFront() << endl;
    dq->pop();
    cout << dq->getFront() << endl;
    dq->pop();
    cout << dq->getFront() << endl;
    dq->pop();
    cout << dq->getFront() << endl;
    dq->pop();
    cout << "is queue empty : " << dq->isEmpty() << endl;
    cout << "Queue Length : " << dq->size() << endl;
}