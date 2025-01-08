/*
// Two trees are symmetric if:
// 1. Their roots are equal.
// 2. The left subtree of one is symmetric with the right subtree of the other.
// 3. The right subtree of one is symmetric with the left subtree of the other.

// A tree as a whole is symmetric if its left and right subtrees are symmetric.
// This question demonstrates a common design pattern for tree problems:
// To determine a property of a tree, we may need to break it into two parts
// and compare them side by side.

// For such problems, creating a helper function is often essential for solving
// the main problem effectively.
*/

#pragma once
#include <iostream>
#include "p1-binary-tree-node.cpp"
#include "p4-take-input-level-wise.cpp"
using namespace std;

template <typename T>
bool compareLeftAndRight(BTNode<T> *left, BTNode<T> *right)
{
    if (left == nullptr && right == nullptr)
        return true;
    if (left == nullptr || right == nullptr)
        return false;

    // Two trees are symmetric if:
    // 1. Their roots are equal.
    // 2. The left subtree of one is symmetric with the right subtree of the other.
    // 3. The right subtree of one is symmetric with the left subtree of the other.
    return left->data == right->data && compareLeftAndRight(left->left, right->right) && compareLeftAndRight(left->right, right->left);
}

template <typename T>
bool isTreeSymmetric(BTNode<T> *root)
{
    // Base case: An empty tree is symmetric.
    if (root == nullptr)
        return true;

    // Compare the left and right subtrees.
    return compareLeftAndRight(root->left, root->right);
}

int main()
{
    BTNode<int> *root = takeBTTreeLevelWise<int>();
    cout << endl;
    cout << "Is the given tree symmetric? " << endl;
    cout << isTreeSymmetric(root) << endl;

    delete root;
}
