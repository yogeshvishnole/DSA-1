#pragma once
#include <iostream>
#include "p1-binary-tree-node.cpp"
#include "p2-print-tree-recursive.cpp"
using namespace std;

template <typename T>
BTNode<T> *takeBTTreeRecursive()
{
    T data;
    cin >> data;
    if (data == -1)
    {
        return nullptr;
    }
    BTNode<T> *root = new BTNode<T>(data);
    cout << "Enter the left child of : " << data << " : ";
    // Take left subtree as input
    root->left = takeBTTreeRecursive<T>();
    cout << "Enter the right child of : " << data << " : ";

    // Take right subtree as input
    root->right = takeBTTreeRecursive<T>();
}

int main()
{

    cout << "Enter the root node: ";
    BTNode<int> *root = takeBTTreeRecursive<int>();
    printTreeRecursive(root);

    delete root;
}