#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node() : next(nullptr) {}
};

template <typename T>
class QueueLL
{

    Node<T> *front = nullptr, *rear = nullptr;
    int length = 0;

public:
    void push(T el)
    {
        Node<T> *newNode = new Node<T>();
        newNode->data = el;

        if (length == 0)
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            Node<T> *temp = rear;
            rear = newNode;
            temp->next = rear;
        }
        length++;
    }
    void pop()
    {
        if (length == 0)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        Node<T> *temp = front;
        front = front->next;
        temp->next = nullptr;
        delete temp;
        length--;
    }
    T getFront()
    {
        if (length == 0)
        {
            cout << "Queue is empty" << endl;
            return 0;
        }
        return front->data;
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
    QueueLL<int> *dq = new QueueLL<int>();
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