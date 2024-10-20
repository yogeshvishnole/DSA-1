/*
Abstract Data Types (ADT)
An Abstract Data Type (ADT) is a data structure that is defined by its behavior 
(operations that can be performed on it) rather than its implementation. 

ADTs focus on what operations are available and not how they are performed internally.

Key Characteristics of ADTs:

Encapsulation: The data and operations on the data are bundled together.

Abstraction: The internal details of how the operations are performed are hidden from the user.\

User-defined: Users can interact with the ADT using predefined operations without knowing its 
internal structure.

Common ADTs:
Stack: A collection of elements that follows the LIFO (Last In, First Out) principle.
Queue: A collection of elements that follows the FIFO (First In, First Out) principle.
List: A collection of ordered elements where elements can be inserted, removed, or accessed by 
position.
Set: A collection of unique elements without any specific order.

Stack ADT
A Stack is an ADT that follows the Last In, First Out (LIFO) principle. This means that the last element added to the stack is the first one to be removed.

Basic Operations:
Push(x): Insert element x at the top of the stack.
Pop(): Remove the top element from the stack.
Top() / Peek(): Retrieve the top element without removing it.
IsEmpty(): Check if the stack is empty.
IsFull(): Check if the stack is full (in case of an array implementation with limited size).
Use Cases:
Undo operations: In text editors or applications where users can undo the last operation.
Expression evaluation: Stacks are used to evaluate and convert expressions like infix to postfix.
Function call management: The system's function call stack manages function calls and returns in programming languages.
Stack Implementation:
Array-based Stack: Fixed-size stack where a predefined size is set, and elements are stored in contiguous memory.
Linked List-based Stack: Dynamically sized stack where elements are added or removed from a linked list.
 */