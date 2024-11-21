/*
Given a queue we have to reverse its order
Like if queue has 1 2 3 4 5 6
so in above queue 1 is front and 6 is rear
then we have to turn the above queue as follows -
6 5 4 3 2 1
so the front = 6 and rear = 1

There are multiple ways to solve this problemm but we could efficiently or in a easily
understandable manner with the help of stack.

Approach is as follows -
1. take the front element from queue and put it in stack
2. pop the element from queue
3. Repeat step 1 and step 2 until queue is not empty
4. take the front element from stack and insert it inside the queue
5. pop the element from stack
6. repeat step 4 and 5 until stack not empty.
7. Queue will now have elements in reverse order as that of original one.

Other approaches - We can use vectors or other data structure for storing queue elements, but
stack provides a straight forward approach as it functions exactly opposite of queue.
 */

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main(int argc, char **argv)
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << "size of queue " << q.size() << " Front of queue " << q.front() << endl;

    // lets reverse the queue

    stack<int> s;

    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

    // front of queue after reversal
    cout << "size of queue " << q.size() << " Front of queue " << q.front() << endl;
}