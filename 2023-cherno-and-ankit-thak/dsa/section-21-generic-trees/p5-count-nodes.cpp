/*
Simple recursion problem
 */

#pragma once
#include <iostream>
#include "p1-tree-node.cpp"
#include "p3-level-wise-tree-input.cpp"
using namespace std;

template <typename T>
int countNodes(TreeNode<T> *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int numberOfNodes = 1;

    for (int i = 0; i < root->children.size(); i++)
    {
        numberOfNodes += countNodes(root->children[i]);
    }
    return numberOfNodes;
}

int main()
{
    TreeNode<int> *root = takeTreeInputLevelWise<int>();
    cout << "Number of nodes in given tree is : " << countNodes(root) << endl;
}