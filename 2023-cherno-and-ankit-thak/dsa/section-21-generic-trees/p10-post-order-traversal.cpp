/*
PostOrder Traversal - First print the children then its parent
 */

#pragma once
#include <iostream>
#include "p1-tree-node.cpp"
#include "p3-level-wise-tree-input.cpp"
using namespace std;

template <typename T>
void postOrderTraversal(TreeNode<T> *root)
{
    if (root == nullptr)
        return;
    for (int i = 0; i < root->children.size(); i++)
    {
        postOrderTraversal(root->children[i]);
    }
    cout << root->data << " ";
}

int main()
{
    TreeNode<int> *root = takeTreeInputLevelWise<int>();
    postOrderTraversal(root);
    cout << endl;
}
