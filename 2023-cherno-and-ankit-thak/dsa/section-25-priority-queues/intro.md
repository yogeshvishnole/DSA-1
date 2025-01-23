1. Priority Queue
   A priority queue is a special type of queue where each element is associated with a priority.
   Instead of following a strict First In, First Out (FIFO) order like a regular queue, elements are dequeued based on their priority:
   High-priority elements are dequeued before lower-priority elements.
   If two elements have the same priority, they follow the insertion order.

Use Cases
Task scheduling (e.g., CPU scheduling).
Dijkstra’s algorithm for finding the shortest path.
Huffman coding for data compression.

Key Properties
Can be implemented using heaps for efficient insertion and deletion operations.
Insertions: O(logn)
Deletion of the highest/lowest priority element: O(logn)

2. Complete Binary Tree
   A complete binary tree is a binary tree where:
   Every level, except possibly the last, is completely filled.
   All nodes in the last level are as far left as possible.
   Example
   markdown
   Copy
   Edit
   1
   / \
    2 3
   / \ /
   4 5 6
   This is a complete binary tree because:
   The first two levels are completely filled.
   The last level (4, 5, 6) is filled from left to right.
   Key Property
   A complete binary tree is often used to represent heaps because it can be efficiently stored in arrays.
3. Heaps
   A heap is a special tree-based data structure that satisfies the heap property:

Max-Heap: For every node n:
The value of n is greater than or equal to the values of its children.
The maximum element is at the root.
Min-Heap: For every node n:
The value of n is less than or equal to the values of its children.
The minimum element is at the root.
Example of a Max-Heap
10
/ \
 9 8
/ \ / \
 5 6 4 3

Every parent node is larger than its children.
How Heaps and Complete Binary Trees Relate
A heap is always a complete binary tree.
Because of this, heaps can be stored compactly in arrays, with the following relationships:
Parent index: i
Left child index: 2i+1
Right child index: 2i+2

For a node at index i:
Parent Index = ⌊(i−1)/2⌋
Left Child from Parent:

For a node at index i:
Left Child Index = 2i+1
Right Child from Parent:

For a node at index i:
Right Child Index = 2i+2

Applications of Heaps
Implementing priority queues.
Heap Sort algorithm.
Finding the k-largest or k-smallest elements in an array.

Summary of Relationships
Priority Queue: Abstract data structure, often implemented using a heap for efficiency.
Heap: A complete binary tree that satisfies the heap property.
Complete Binary Tree: The foundation for efficiently storing heaps.
