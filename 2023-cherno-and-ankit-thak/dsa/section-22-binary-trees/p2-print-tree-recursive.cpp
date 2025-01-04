#pragma once
#include <iostream>
#include "p1-binary-tree-node.cpp"
using namespace std;

template <typename T>
void printTreeRecursive(BTNode<T> *root)
{
    // base case
    if (!root)
        return;

    cout << root->data << " : ";
    if (root->left)
        cout << "L" << root->left->data << "  ";

    if (root->right)
        cout << "R" << root->right->data << " ";

    cout << endl;

    // print left sub tree
    printTreeRecursive(root->left);

    // print right subtree
    printTreeRecursive(root->right);
}

// int main()
// {
//     BTNode<int> *root = new BTNode<int>(1);
//     BTNode<int> *left = new BTNode<int>(2);
//     BTNode<int> *right = new BTNode<int>(3);

//     root->left = left;
//     root->right = right;

//     printTreeRecursive(root);

//     delete root;
// }