/*
Given a binary tree, count number of nodes which has both left and right child as null
 */

#pragma once
#include <iostream>
#include <cmath>
#include "p1-binary-tree-node.cpp"
#include "p4-take-input-level-wise.cpp"
using namespace std;

template <typename T>
int countLeafNodes(BTNode<T> *root)
{
    if (root == nullptr)
        return 0;

    if (root->left == nullptr && root->right == nullptr)
        return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main()
{
    BTNode<int> *root = takeBTTreeLevelWise<int>();
    cout << endl;
    cout << countLeafNodes(root) << endl;
}
