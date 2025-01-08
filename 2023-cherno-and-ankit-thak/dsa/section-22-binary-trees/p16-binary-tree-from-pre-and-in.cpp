/*

Given the pre and in order traversals of a binary tree,
build the binary tree out of that.

Solution Approach Comments
Base Condition for Recursion:

The code checks whether the input is invalid (inorder and preorder sizes differ, empty vectors, or invalid indices). This ensures the function doesn't proceed with invalid data, making the base case robust.
Another base condition handles when the indices become invalid (ios > ioe or pres > pree), which marks the end of recursion.
Root Identification:

The first element of the preorder vector is used to identify the root of the current subtree (preorder[pres]). This is a fundamental property of preorder traversal and is correctly utilized here.
Finding the Root in the Inorder Traversal:

A linear search is performed in the inorder array to find the index of the root (preorder[pres]). This helps partition the inorder traversal into left and right subtrees.
Improvement Note: A hash map can be used to store the indices of elements in the inorder array to reduce the search time from O(n) to O(1) for each recursive call.
Recursive Division:

The left and right subtree boundaries for both inorder and preorder are calculated correctly based on the indices.
Recursive calls are made to build the left and right subtrees. This adheres to the Divide and Conquer strategy.
Tree Construction:

New nodes are dynamically created using BTNode<T> for each root identified, and pointers are set for the left and right children recursively.
Final Output:

After constructing the tree, the printTreeLevelWise function is called to print the tree in level order. This is a good way to verify the correctness of the constructed tree.
Key Concepts and Insights
Binary Tree Traversals:

The problem relies on the fundamental properties of preorder (root → left → right) and inorder (left → root → right) traversals.
By combining the two traversals, the tree structure can be uniquely determined.
Divide and Conquer:

The solution splits the problem into smaller subproblems: constructing the left and right subtrees recursively. This approach is a classic example of divide-and-conquer in tree problems.
Recursive Tree Building:

Recursion is key to building the tree. Each recursive call handles a subtree, with the base condition ensuring the recursion stops at leaf nodes.
Dynamic Memory Allocation:

Nodes are created dynamically using new, and pointers are used to connect nodes. This highlights the use of raw pointers, though modern C++ practices might prefer smart pointers (e.g., std::unique_ptr).
Time Complexity:

The linear search in the inorder array for the root element makes the time complexity O(n^2) in the worst case (for skewed trees). Using a hash map for lookup reduces this to O(n).
Space Complexity:

The function uses O(h) stack space for recursion, where h is the height of the tree. In the worst case (skewed tree), this can be O(n).
Template Usage:

Using templates (BTNode<T> and buildTree<T>) allows the function to work with different data types. This demonstrates good design for generality.
Level-Order Traversal:

The inclusion of printTreeLevelWise ensures that the constructed tree can be visualized easily, aiding in debugging and verification.
Suggestions for Improvement
Optimize Root Search in inorder:

Use a hash map to store the indices of elements in the inorder traversal. This reduces the time complexity of finding the root from O(n) to O(1) per call.
Use Modern C++ Features:

Replace raw pointers (new) with smart pointers (std::unique_ptr or std::shared_ptr) to manage memory safely and avoid leaks.
Use std::unordered_map for faster lookups instead of manually iterating through the inorder array.
Code Readability:

Add comments to clarify the roles of variables like iosl, ioel, presl, etc., as their naming might not be immediately intuitive to all readers.
Boundary Case Testing:

Ensure the function handles edge cases like empty trees (inorder and preorder empty) or trees with only one node.

 */

#pragma once
#include <iostream>
#include "p1-binary-tree-node.cpp"
#include "p5-level-order-traversal.cpp"
using namespace std;

template <typename T>
BTNode<T> *buildTree(vector<int> &inorder, vector<int> &preorder, int ios, int ioe, int pres, int pree)
{

    if (inorder.size() != preorder.size() || inorder.size() == 0 || ((ioe - ios) != (pree - pres)) || (ios > ioe) || (pres > pree))
        return nullptr;

    BTNode<T> *root = new BTNode<T>(preorder[pres]);

    int iosl, ioel, presl, preel;

    iosl = ios;

    for (int i = ios; i <= ioe; i++)
    {
        if (inorder[i] == preorder[pres])
        {
            ioel = i - 1;
            break;
        }
    }

    presl = pres + 1;
    preel = pres + (ioel - iosl + 1);

    int iosr, ioer, presr, preer;

    iosr = ioel + 2;
    ioer = ioe;
    presr = preel + 1;
    preer = pree;

    root->left = buildTree<T>(inorder, preorder, iosl, ioel, presl, preel);
    root->right = buildTree<T>(inorder, preorder, iosr, ioer, presr, preer);

    return root;
}

int main()
{
    vector<int> preorder{1, 2, 4, 3, 5, 7, 8, 6};
    vector<int> inorder{4, 2, 1, 7, 5, 8, 3, 6};
    BTNode<int> *root = buildTree<int>(inorder, preorder, 0, inorder.size() - 1, 0, preorder.size() - 1);
    cout << "Level wise print of the tree: " << endl;
    printTreeLevelWise(root);
}