What is a Binary Search Tree (BST)?
A Binary Search Tree (BST) is a special type of binary tree where the nodes are organized in a way that allows efficient searching, insertion, and deletion operations.

Definition:
A binary search tree is a binary tree with the following properties:

Node Structure: Each node contains a key (or value), and two child pointers (left and right).
Binary Tree Property: Every node can have at most two children.
BST Property:
For every node N:
All nodes in the left subtree of N have values less than N's value.
All nodes in the right subtree of N have values greater than N's value.
No Duplicate Keys: Typically, BSTs do not allow duplicate keys. (Some variations may allow duplicates.)
Structure Example:
Here is an example of a Binary Search Tree:
Copy code
         8
       /   \
      3     10
     / \      \
    1   6      14
       / \     /
      4   7   13
The left child of 8 is 3, and it satisfies the property: 3 < 8.
The right child of 8 is 10, and it satisfies the property: 10 > 8.
This property holds true recursively for every node in the tree.

Key Operations in a BST
Search:

To find a value, compare it with the root.
If the value equals the root, the search is complete.
If the value is smaller, search in the left subtree.
If the value is larger, search in the right subtree.
Time Complexity:
Best case (balanced tree): 
O(logn)
Worst case (skewed tree): 
O(n)
Example: Searching for 7 in the BST above:

scss
Copy code
Start at root (8) → go left to (3) → go right to (6) → go right to (7).
Insertion:

Traverse the tree to find the correct position where the new value should be placed.
Insert it as a leaf node while maintaining the BST property.
Time Complexity:
Best case (balanced tree): 
O(logn)
Worst case (skewed tree): 
O(n)
Example: Inserting 5 in the BST above:


Start at root (8) → go left to (3) → go right to (6) → go left to (5).
Deletion:

Locate the node to be deleted and handle the following cases:
Node has no children (leaf node): Remove the node.
Node has one child: Remove the node and connect its child to its parent.
Node has two children:
Find the in-order successor (smallest node in the right subtree) or in-order predecessor (largest node in the left subtree).
Replace the node's value with the successor/predecessor value.
Delete the successor/predecessor node.
Time Complexity:
Best case (balanced tree): 
O(logn)
Worst case (skewed tree): 
O(n)
Example: Deleting 3 in the BST above:

markdown
Copy code
- Find in-order successor (4).
- Replace `3` with `4`.
- Delete node `4` from the left subtree of `6`.
Traversal: Traversals allow visiting nodes in a specific order:

In-order Traversal (LNR): Produces a sorted sequence of the BST.
Pre-order Traversal (NLR): Visits the root before its children.
Post-order Traversal (LRN): Visits children before the root.
Level-order Traversal: Visits nodes level by level.
Example:

In-order Traversal of the BST: 1, 3, 4, 6, 7, 8, 10, 13, 14.
Advantages of Binary Search Tree
Efficient Operations:

Search, insertion, and deletion can be performed in 
O(logn) for a balanced BST.
In-order Traversal:

Produces the elements in sorted order, which is useful in many applications.
Dynamic Data Structure:

Can dynamically grow or shrink with insertion and deletion.
Disadvantages of Binary Search Tree
Skewed Trees:

If the tree becomes unbalanced (e.g., all elements are inserted in sorted order), the time complexity for operations degrades to 
O(n), making it as inefficient as a linked list.
Example of a skewed BST:

markdown
Copy code
    1
     \
      2
       \
        3
         \
          4
           \
            5
Balancing Requirement:

BSTs do not self-balance, which can lead to inefficiency. Variants like AVL Trees and Red-Black Trees address this issue.
Applications of Binary Search Tree
Searching and Sorting:

BSTs are the foundation of many searching and sorting algorithms.
Databases:

BSTs are used in database indexing to enable fast lookups.
Symbol Tables in Compilers:

BSTs store and retrieve variable names or function names efficiently.
Dynamic Sets:

BSTs allow efficient set operations like union, intersection, and difference.
Balanced Variants of BST
To avoid skewness, there are balanced versions of BST:

AVL Tree:
A self-balancing BST where the difference in height between the left and right subtrees is at most 1.
Red-Black Tree:
A self-balancing BST with additional properties that enforce balance through color-coding.
B-Trees:
Used in databases and file systems, they are generalizations of BSTs where nodes can have more than two children.
