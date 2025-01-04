# Tree Data Structure

A **tree** is a hierarchical data structure consisting of nodes, where each node has a value and pointers to its child nodes. It is used to organize data efficiently for retrieval, insertion, and deletion.

---
## Why Trees Are Needed
1. **Hierarchical Data Representation**: Useful for representing hierarchical relationships, such as file systems or organizational charts.
2. **Faster Operations**: Enables efficient searching, insertion, and deletion (e.g., O(log n) in a balanced binary search tree).
3. **Data Organization**: Structures data for better usability, like in tries for string search.
4. **Memory Efficiency**: Optimizes memory usage for specific applications.
5. **Algorithm Applications**: Fundamental to algorithms like data compression (Huffman trees) and decision trees.

---

## Basic Terminology

### **Node**
- **Root**: The topmost node of the tree (no parent).
- **Leaf**: A node with no children.
- **Child**: A node directly connected and descending from another node (the parent).
- **Parent**: A node that has one or more child nodes.
- **Sibling**: Nodes with the same parent.

### **Ancestors**
- **Definition**: All nodes along the path from the root to the given node, excluding the node itself.
  - **Example**: Ancestors of node `E` in the tree below are `B` and `A`.

### **Descendants**
- **Definition**: All nodes that can be reached by traversing downward from a node, including children, grandchildren, etc.
  - **Example**: Descendants of node `B` are `D` and `E`.

### **Edge**
- A connection between two nodes (parent and child).

### **Path**
- A sequence of nodes and edges from one node to another.

### **Height**
- **Height of a Node**: The number of edges on the longest path from the node to a leaf.
- **Height of a Tree**: The height of the root node.

### **Depth**
- **Depth of a Node**: The number of edges from the root to that node.

### **Degree**
- **Degree of a Node**: The number of children the node has.
- **Degree of a Tree**: The maximum degree of any node in the tree.

### **Subtree**
- A tree formed by any node and its descendants.

### **Level**
- The distance of a node from the root (root is at level 0).

---

## Illustration

    A
   / \
  B   C
 / \   \
D   E   F


- **Ancestors of Node E**: `B, A`
- **Descendants of Node B**: `D, E`
- **Height of Node A**: `2` (path to leaf nodes D/E/F).
- **Depth of Node F**: `2` (distance from root A).

---

## Common Tree Variants
1. **Binary Tree**: Each node has at most two children.
2. **Binary Search Tree (BST)**: A binary tree with ordered nodes; left child < parent < right child.
3. **AVL Tree**: A self-balancing binary search tree.
4. **B-Trees**: Used in databases and file systems for balanced searching.
5. **Heap**: A specialized tree used to implement priority queues.

---

## Applications of Trees
- File systems and directory structures.
- Binary search for fast lookup.
- Expression parsing and evaluation in compilers.
- Network routing algorithms.
- Artificial intelligence (decision trees).
