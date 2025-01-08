/*
Given a binary tree, find the data with the maximum value that is present in any node
of binary tree.
 */

#pragma once
#include <iostream>
#include <cmath>
#include "p1-binary-tree-node.cpp"
#include "p4-take-input-level-wise.cpp"
using namespace std;

template <typename T>
int maxNode(BTNode<T> *root)
{
    if (root == nullptr)
        return -INFINITY;
    return max(root->data, max(maxNode(root->left), maxNode(root->right)));
}

int main()
{
    BTNode<int> *root = takeBTTreeLevelWise<int>();
    cout << endl;
    cout << maxNode(root) << endl;
}
