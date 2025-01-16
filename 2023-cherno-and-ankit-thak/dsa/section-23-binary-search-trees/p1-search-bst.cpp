#pragma once
#include <iostream>
#include "../section-22-binary-trees/p1-binary-tree-node.cpp"
#include "../section-22-binary-trees/p4-take-input-level-wise.cpp"
#include "../section-22-binary-trees/p5-level-order-traversal.cpp"
using namespace std;

// Search in BST recursive
template <typename T>
bool searchInBST(BTNode<T> *root, T key)
{
    if (root == nullptr)
        return false;

    if (key == root->data)
        return true;

    if (key > root->data)
    {
        return searchInBST(root->right, key);
    }
    else
    {
        return searchInBST(root->left, key);
    }
}

// Search in BST iterative
template <typename T>
bool searchInBSTIterative(BTNode<T> *root, T key)
{
    BTNode<T> *temp = root;

    while (temp != nullptr)
    {
        if (temp->data == key)
            return true;
        else if (key > temp->data)
            temp = (temp->right);
        else
            temp = (temp->left);
    }
    return false;
}

// int main()
// {
//     BTNode<int> *root = takeBTTreeLevelWise<int>();
//     cout << endl;
//     cout << searchInBST(root, 4) << " " << searchInBSTIterative(root, 4) << endl;
//     cout << searchInBST(root, 2) << " " << searchInBSTIterative(root, 2) << endl;
//     cout << searchInBST(root, 6) << " " << searchInBSTIterative(root, 6) << endl;
//     cout << searchInBST(root, 1) << " " << searchInBSTIterative(root, 1) << endl;
//     cout << searchInBST(root, 3) << " " << searchInBSTIterative(root, 3) << endl;
//     cout << searchInBST(root, 5) << " " << searchInBSTIterative(root, 5) << endl;
//     cout << searchInBST(root, 7) << " " << searchInBSTIterative(root, 7) << endl;
//     cout << searchInBST(root, 8) << " " << searchInBSTIterative(root, 8) << endl;
// }

// 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1