#pragma once
#include <iostream>
#include "p1-binary-tree-node.cpp"
#include "p4-take-input-level-wise.cpp"
using namespace std;

template <typename T>
void inOrderTraversal(BTNode<T> *root)
{
    // Base case
    if (root == nullptr)
        return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

int main()
{

    BTNode<int> *root = takeBTTreeLevelWise<int>();
    cout << endl;
    cout << "Inorder Traversal Of Given tree is : " << endl;
    inOrderTraversal(root);

    delete root;
}
