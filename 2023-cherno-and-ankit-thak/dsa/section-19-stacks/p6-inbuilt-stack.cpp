/* 
C++ Inbuilt stack Class
The stack class in C++ is part of the Standard Template Library (STL) and provides a simple 
way to implement stack data structures. It follows the LIFO (Last In, First Out) principle, 
where the last element added to the stack is the first one to be removed.

Key Features:
Container Adaptor: stack is a container adaptor that operates on an underlying container like
vector, deque, or list, and it restricts access to the container by providing only
stack operations.

Operations:
Push: Insert an element at the top.
Pop: Remove the element at the top.
Top: Access the top element.
Empty: Check if the stack is empty.
Size: Return the number of elements in the stack.

Header file - 
#include <stack>

Commonly Used Functions:
push(): Inserts an element on top of the stack.
pop(): Removes the element from the top.
top(): Returns the element at the top of the stack.
empty(): Returns true if the stack is empty.
size(): Returns the number of elements in the stack.
 */

#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;  // Declare a stack of integers

    // Push elements onto the stack
    s.push(10);
    s.push(20);
    s.push(30);

    // Accessing the top element
    cout << "Top element: " << s.top() << endl;  // Output: 30

    // Removing the top element
    s.pop();
    cout << "After pop, top element: " << s.top() << endl;  // Output: 20

    // Stack size
    cout << "Stack size: " << s.size() << endl;  // Output: 2

    // Checking if stack is empty
    if (s.empty())
        cout << "Stack is empty!" << endl;
    else
        cout << "Stack is not empty!" << endl;

    return 0;
}
