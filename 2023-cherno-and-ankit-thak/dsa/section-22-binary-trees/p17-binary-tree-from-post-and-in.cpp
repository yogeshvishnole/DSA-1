/*

Given the post and in order traversals of a binary tree,
build the binary tree out of that.

Solution Approach Comments
Base Condition for Recursion:

The function checks (ios > ioe) and (pos > poe) as the base case to terminate recursion. This ensures that the function stops when there are no elements left to process in the inorder or postorder vectors.
Root Identification:

The last element in the postorder traversal (postorder[poe]) is used to identify the root of the current subtree. This is correct because postorder traversal visits nodes in the order: left → right → root.
Finding the Root in the Inorder Traversal:

A linear search is performed in the inorder array to find the root (postorder[poe]). This step is essential to divide the inorder array into left and right subtrees.
Improvement Note: A hash map can be used for faster lookups, reducing the time complexity of this operation from O(n) to O(1).
Subtree Index Calculations:

After finding the root index in the inorder traversal, the indices for the left and right subtrees are calculated for both inorder and postorder.
Left Subtree:
iosl to ioel (inorder range).
posl to poel (postorder range).
Right Subtree:
iosr to ioer (inorder range).
posr to poer (postorder range).
Recursive Tree Construction:

The left and right child nodes of the root are constructed recursively using the calculated indices. This ensures the tree is built correctly in a bottom-up manner.
Dynamic Memory Allocation:

A new node is created for the root (BTNode<T>), and pointers are used to link the left and right children. This is appropriate for tree construction, though modern C++ best practices might suggest using smart pointers.
Final Output:

The printTreeLevelWise function is called after the tree is constructed to verify the output visually. This is a helpful debugging step.
Key Concepts and Insights
Binary Tree Traversals:

The problem combines the properties of postorder (left → right → root) and inorder (left → root → right) traversals to reconstruct the tree. These properties are fundamental to solving tree-building problems.
Divide and Conquer:

The tree is constructed recursively by dividing the problem into smaller subproblems for the left and right subtrees. This approach makes the solution elegant and modular.
Recursive Tree Building:

The function builds the tree in a recursive manner, with each recursive call handling one subtree. The base case ensures that recursion stops at the leaf nodes.
Dynamic Memory Management:

The use of new for node creation demonstrates dynamic memory management, which is common in tree problems. Modern alternatives like std::unique_ptr or std::shared_ptr could make memory management safer.
Time Complexity:

The time complexity is O(n^2) in the worst case because of the linear search for the root in the inorder array at every recursive step. This can be reduced to O(n) by using a hash map.
Space Complexity:

The space complexity is O(h), where h is the height of the tree, due to the recursion stack. In the worst case (skewed tree), this can go up to O(n).
Template Usage:

Templates (BTNode<T> and buildTree<T>) allow the code to handle different data types, improving generality and reusability.
Tree Traversal Verification:

Printing the tree in level order after construction ensures that the tree has been built correctly and provides a clear way to visualize the result.
Suggestions for Improvement
Optimize Root Search in inorder:

Use a hash map to store the indices of elements in the inorder array. This reduces the lookup time from O(n) to O(1), improving the overall time complexity to O(n).
Use Modern C++ Features:

Replace raw pointers with smart pointers (std::unique_ptr or std::shared_ptr) to avoid memory leaks and improve safety.
Use std::unordered_map for efficient lookups.
Code Readability:

Add comments for variable names like iosl, ioel, posl, etc., to clarify their roles. For example, iosl could be renamed to inorderStartLeft for better understanding.
Handle Edge Cases:

Ensure the solution handles edge cases like:
Empty inorder and postorder arrays.
A single-node tree.
Error Handling:

Add error messages or exceptions if the input arrays are invalid (e.g., sizes do not match, duplicate elements when uniqueness is assumed). 

 */

#pragma once
#include <iostream>
#include "p1-binary-tree-node.cpp"
#include "p5-level-order-traversal.cpp"
using namespace std;

template <typename T>
BTNode<T> *buildTree(vector<int> &inorder, vector<int> &postorder, int ios, int ioe, int pos, int poe)
{

    if ((ios > ioe) || (pos > poe))
        return nullptr;

    BTNode<T> *root = new BTNode<T>(postorder[poe]);

    int iosl, ioel, posl, poel;

    int rootIndex;

    for (int i = ios; i <= ioe; i++)
    {
        if (inorder[i] == postorder[poe])
        {
            rootIndex = i;
            break;
        }
    }
    iosl = ios;
    ioel = rootIndex - 1;
    posl = pos;
    poel = posl + (ioel - iosl);

    int iosr, ioer, posr, poer;

    iosr = rootIndex + 1;
    ioer = ioe;
    posr = poel + 1;
    poer = poe - 1;

    root->left = buildTree<T>(inorder, postorder, iosl, ioel, posl, poel);
    root->right = buildTree<T>(inorder, postorder, iosr, ioer, posr, poer);

    return root;
}

int main()
{
    vector<int> postorder{9, 15, 7, 20, 3};
    vector<int> inorder{9, 3, 15, 20, 7};
    BTNode<int> *root = buildTree<int>(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    cout << "Level wise print of the tree: " << endl;
    printTreeLevelWise(root);
}