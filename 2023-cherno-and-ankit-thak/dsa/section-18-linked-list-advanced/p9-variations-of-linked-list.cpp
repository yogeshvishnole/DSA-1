// NOTE - I have to implement them all when I get time.

/*
There are several variations of linked lists, each with its own advantages and disadvantages depending on the use case. Below is a comprehensive list of linked list types, along with their pros and cons:

1. Singly Linked List
In a singly linked list, each node has two parts: data and a pointer (next) to the next node in the sequence. It only allows traversal in one direction (forward).

Structure:
css
Copy code
[Data | Next] -> [Data | Next] -> ... -> [Data | NULL]
Advantages:
Simple structure: Easier to implement than more complex lists.
Efficient insertion/deletion: Insertions and deletions at the head are efficient (O(1)), as no shifting is required like in arrays.
Dynamic size: Can grow and shrink at runtime as nodes are added or removed.
Disadvantages:
Unidirectional: Can only traverse in one direction, making certain operations (like reverse traversal) inefficient.
No tail reference: If you need to access the tail, you have to traverse the entire list (O(n)).
Extra memory: Uses extra memory for storing pointers.
2. Doubly Linked List
Each node in a doubly linked list contains a pointer to both the next and previous nodes. It allows bidirectional traversal.

Structure:
css
Copy code
NULL <- [Prev | Data | Next] <-> [Prev | Data | Next] <-> ... <-> [Prev | Data | NULL]
Advantages:
Bidirectional traversal: You can traverse in both directions (forward and backward), making some operations easier (like reverse traversal).
Efficient deletion: Deletion of a given node is more efficient because you can access the previous node directly without needing to traverse from the head.
Efficient insertions: Insertion before or after a node is easier since you have access to both next and previous nodes.
Disadvantages:
Extra memory: Requires extra space for the additional prev pointer in each node.
Complexity: More complex to implement than a singly linked list, especially when updating pointers during insertion or deletion.
More memory overhead: Both next and prev pointers consume memory.
3. Circular Linked List
In a circular linked list, the last node points back to the first node. This can be done in either a singly or doubly linked list format.

Structure (Singly Circular):
css
Copy code
[Data | Next] -> [Data | Next] -> ... -> [Data | Head]
Structure (Doubly Circular):
mathematica
Copy code
Head <-> [Prev | Data | Next] <-> ... <-> [Prev | Data | Head]
Advantages:
Circular structure: It can represent cyclic processes, like round-robin scheduling, where you need continuous traversal.
Efficient traversal: You can traverse the entire list from any node, looping back to the start if necessary.
No NULL reference: The list never ends, so handling the end of the list becomes easier (no NULL checks).
Disadvantages:
Complexity: More complex to implement and manage the circular structure compared to non-circular linked lists.
Traversal risk: If you are not careful, it can result in infinite loops during traversal if exit conditions are not well-defined.
Doubly Circular Overhead: In doubly circular linked lists, there is additional space overhead for both next and prev pointers.
4. Singly Circular Linked List
A singly linked list where the last node points to the first node, forming a loop.

Structure:
css
Copy code
[Data | Next] -> [Data | Next] -> ... -> [Data | Head]
Advantages:
Efficient looping: Ideal for applications like task scheduling where repeated traversal of the list is needed (e.g., in operating system scheduling).
No need for null checks: Since it loops back to the start, there are no NULL checks needed for the last node.
Disadvantages:
Unidirectional: Like the singly linked list, it only supports traversal in one direction.
Infinite loop risk: Without proper checks, you may get stuck in an infinite loop.
5. Doubly Circular Linked List
A doubly linked list where the last node’s next pointer points to the head, and the head’s prev pointer points to the last node.

Structure:
mathematica
Copy code
Head <-> [Prev | Data | Next] <-> ... <-> [Prev | Data | Head]
Advantages:
Bidirectional traversal: You can traverse both forward and backward.
Efficient cyclic operations: Useful for cyclic processes, and it allows easy navigation in both directions with no NULL references.
Disadvantages:
More complex: More complex to implement due to the circular and bidirectional nature.
Extra memory: Extra memory for storing both prev and next pointers.
6. Skip List
A skip list is a layered linked list structure that allows faster search, insertion, and deletion operations by allowing nodes to be skipped over in each layer.

Structure:
Each node may have multiple forward pointers that allow skipping to farther nodes.
Typically used to speed up search operations.
Advantages:
Fast lookups: Search operations can be done in O(log n) time, as opposed to O(n) in a regular linked list.
Dynamic resizing: Unlike balanced trees, skip lists can easily adjust when nodes are inserted or deleted without needing rotations.
Disadvantages:
More complex: Requires a more complex setup and maintenance than a regular linked list.
Extra memory: Requires additional forward pointers (layers) in nodes, consuming more memory.
7. Unrolled Linked List
In an unrolled linked list, each node holds an array of elements instead of a single element. This optimizes space usage and speeds up access by storing multiple elements in a node.

Structure:
css
Copy code
[Data[] | Next] -> [Data[] | Next] -> ... -> [Data[] | NULL]
Advantages:
Faster traversal: Traversal can be faster because fewer nodes need to be accessed due to each node storing multiple elements.
Space-efficient: Less memory overhead because fewer pointers are needed (one pointer per block instead of one pointer per element).
Disadvantages:
Complex insertion/deletion: Managing insertions and deletions within a node (array) can be more complex and may involve shifting elements.
Wasted space: If node arrays are not fully populated, there may be wasted memory.
8. Self-adjusting Lists (e.g., Move-to-front Linked List)
In a self-adjusting linked list, frequently accessed elements are moved to the front of the list to speed up future accesses.

Advantages:
Adaptive access: Frequently accessed elements are faster to access due to their proximity to the front of the list.
No additional space overhead: The list adjusts itself based on access patterns without requiring extra memory.
Disadvantages:
Poor for uniformly accessed elements: If all elements are accessed equally, the move-to-front strategy may not provide any benefit.
Complexity: The algorithm may increase the complexity of insertions and deletions.
Conclusion:
Different types of linked lists have their own strengths and weaknesses, and the choice of which one to use depends on the specific requirements of the problem, such as:

Singly linked list for simpler structures.
Doubly linked list for bidirectional traversal.
Circular linked list for cyclic data structures.
Skip lists for faster searches.
Unrolled linked list for space optimization in large data sets.
Choosing the appropriate linked list variation can optimize both time and space for specific use cases.
 */
