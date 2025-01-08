/*
Given a binary tree and a key, we have to find that whether that key is present in the
binary tree or not.
 */

#pragma once
#include <iostream>
#include "p1-binary-tree-node.cpp"
#include "p4-take-input-level-wise.cpp"
using namespace std;

template <typename T>
bool isKeyPresentInBinaryTree(BTNode<T> *root, T key)
{
    if (root == nullptr)
        return false;
    return root->data == key || isKeyPresentInBinaryTree(root->left, key) || isKeyPresentInBinaryTree(root->right, key);
}

int main()
{
    BTNode<int> *root = takeBTTreeLevelWise<int>();
    cout << endl;
    cout << isKeyPresentInBinaryTree(root, 10) << endl;
}
