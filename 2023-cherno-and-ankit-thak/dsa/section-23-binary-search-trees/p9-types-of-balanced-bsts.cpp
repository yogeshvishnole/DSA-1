/*

What is balance binary search tree ?

A balanced binary search tree (BST) is a type of binary search tree that maintains a balance
condition to ensure that the height of the tree remains as small as possible. This balancing
ensures that operations like insertion, deletion, and search can be performed in O(log n) time,
where n is the number of nodes in the tree.

Characteristics of a Balanced BST:

1. Binary Search Tree Property:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.

2. Balance Condition:
A tree is balanced if the height of the left and right subtrees of any node differ by at most
 1 (or satisfy another defined balancing criterion depending on the type of the tree).

Common Types of Balanced BSTs:

1. AVL Tree:
Maintains the condition that the height difference (balance factor) between the left and
right subtrees of any node is at most 1.
Rotations (single or double) are used to restore balance after insertions or deletions.

2. Red-Black Tree:
Balances the tree by ensuring no path from the root to a leaf is more than twice as long as
any other path.
Nodes are colored red or black, and specific coloring rules are followed to maintain balance.

3. B-trees:
Used primarily in databases and file systems.
Balances the tree by ensuring all leaf nodes are at the same depth and keeps nodes partially
filled to maintain efficiency.

4.Splay Tree:
Balances the tree by bringing recently accessed elements closer to the root using rotations.

Advantages of a Balanced BST:
Ensures O(logn) complexity for search, insert, and delete operations.
Avoids degeneration into a skewed tree (where the tree becomes a linked list with
O(n) complexity).

Example: An AVL Tree
For a sequence of values 
[10,20,30], if we insert them into an unbalanced BST:

    10
      \
       20
         \
          30
It degenerates into a skewed tree. In an AVL tree, rotations are performed to balance it:

      20
     /  \
   10    30

When to Use:
Balanced BSTs are ideal when:
Data needs to be searched, inserted, or deleted frequently.
Consistent performance is required for these operations.

 */