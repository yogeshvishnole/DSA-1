/*
We need to count the leaf nodes of the tree, simple recursion problem
 */

#pragma once
#include <iostream>
#include "p1-tree-node.cpp"
#include "p3-level-wise-tree-input.cpp"
using namespace std;

template <typename T>
int countLeafNodes(TreeNode<T> *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    if (root->children.size() == 0)
    {
        return 1;
    }

    int numberOfLeafNodes = 0;

    for (int i = 0; i < root->children.size(); i++)
    {
        numberOfLeafNodes += countLeafNodes(root->children[i]);
    }
    return numberOfLeafNodes;
}

int main()
{
    TreeNode<int> *root = takeTreeInputLevelWise<int>();
    cout << countLeafNodes(root) << " ";
}