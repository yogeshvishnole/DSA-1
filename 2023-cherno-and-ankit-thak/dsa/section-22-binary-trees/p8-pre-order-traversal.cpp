#pragma once
#include <iostream>
#include "p1-binary-tree-node.cpp"
#include "p4-take-input-level-wise.cpp"
using namespace std;

template <typename T>
void preOrderTraversal(BTNode<T> *root)
{
    // Base case
    if (root == nullptr)
        return;

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int main()
{

    BTNode<int> *root = takeBTTreeLevelWise<int>();
    cout << endl;
    cout << "Inorder Traversal Of Given tree is : " << endl;
    preOrderTraversal(root);

    delete root;
}
