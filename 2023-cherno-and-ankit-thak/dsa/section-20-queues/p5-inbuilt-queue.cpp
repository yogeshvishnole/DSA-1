#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char **argv)
{
    queue<int> *dq = new queue<int>();
    dq->push(1);
    dq->push(2);
    dq->push(3);
    dq->push(4);
    dq->push(5);
    dq->push(6);
    dq->push(7);
    cout << dq->front() << endl;
    dq->pop();
    cout << dq->front() << endl;
    dq->pop();
    cout << dq->front() << endl;
    dq->pop();
    cout << "is queue empty : " << dq->empty() << endl;
    cout << "Queue Length : " << dq->size() << endl;

    cout << dq->front() << endl;
    dq->pop();
    cout << dq->front() << endl;
    dq->pop();
    cout << dq->front() << endl;
    dq->pop();
    cout << dq->front() << endl;
    dq->pop();
    cout << dq->front() << endl;
    dq->pop();
    cout << "is queue empty : " << dq->empty() << endl;
    cout << "Queue Length : " << dq->size() << endl;
}