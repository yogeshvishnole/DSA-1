/*
Given a depth d we have to print all the nodes present at depth d.

What is depth of a node ?
The number of edges from the root to that node.

 */
#pragma once
#include <iostream>
#include "p1-tree-node.cpp"
#include "p3-level-wise-tree-input.cpp"
using namespace std;

template <typename T>
void printAllNodesAtDepthD(TreeNode<T> *root, int d, int curDepth)
{
    if (root == nullptr)
        return;

    if (curDepth == d)
    {
        cout << root->data << " ";
        return;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        printAllNodesAtDepthD(root->children[i], d, curDepth + 1);
    }
}

int main()
{
    TreeNode<int> *root = takeTreeInputLevelWise<int>();
    printAllNodesAtDepthD(root, 2, 0);
}