/*
A Queue is an Abstract Data Type (ADT) that follows the FIFO (First In, First Out) principle. 
In this structure, the element that is added first is the one to be removed first. 
It is conceptually similar to a line of people waiting for service, where the person at the 
front of the line is served first.

Key Operations in Queue ADT:

1.cenqueue/push: Add an element to the rear of the queue.
2. dequeue/pop: Remove and return the element from the front of the queue.
3. front/peek: Return the element at the front of the queue without removing it.
4. isEmpty: Check if the queue is empty.
5. isFull (for a bounded queue): Check if the queue is full.
6. size: Return the number of elements in the queue.

Types of Queues:
Simple Queue: Basic queue following FIFO, with enqueue at the rear and dequeue from the front.
Circular Queue: The last position connects back to the first, improving space efficiency.
Priority Queue: Elements are dequeued based on priority rather than order of insertion.
Double-Ended Queue (Deque): Allows insertion and deletion at both ends (front and rear).

Example of Queue Operations (in pseudocode):

Copy code
// Initialize an empty queue
queue = []

// Enqueue operation
enqueue(queue, element):
    queue.append(element)

// Dequeue operation
dequeue(queue):
    if not isEmpty(queue):
        return queue.pop(0)
    else:
        return "Queue is empty"

// Peek operation
peek(queue):
    if not isEmpty(queue):
        return queue[0]
    else:
        return "Queue is empty"

// Check if queue is empty
isEmpty(queue):
    return len(queue) == 0

Applications of Queue:

1. Task scheduling: In operating systems, jobs or processes are managed in queues.
2. Breadth-first search in graph traversal.
3. Printer spooling: Print jobs are queued and processed in order.
 */