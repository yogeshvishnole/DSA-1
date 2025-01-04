/*
PreOrder Traversal - First print the parent then its childrens
 */

#pragma once
#include <iostream>
#include "p1-tree-node.cpp"
#include "p3-level-wise-tree-input.cpp"
using namespace std;

template <typename T>
void preOrderTraversal(TreeNode<T> *root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++)
    {
        preOrderTraversal(root->children[i]);
    }
}

int main()
{
    TreeNode<int> *root = takeTreeInputLevelWise<int>();
    preOrderTraversal(root);
    cout << endl;
}
