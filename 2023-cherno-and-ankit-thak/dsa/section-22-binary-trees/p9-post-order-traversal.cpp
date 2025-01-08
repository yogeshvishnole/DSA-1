#pragma once
#include <iostream>
#include "p1-binary-tree-node.cpp"
#include "p4-take-input-level-wise.cpp"
using namespace std;

template <typename T>
void postOrderTraversal(BTNode<T> *root)
{
    // Base case
    if (root == nullptr)
        return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

int main()
{

    BTNode<int> *root = takeBTTreeLevelWise<int>();
    cout << endl;
    cout << "Inorder Traversal Of Given tree is : " << endl;
    postOrderTraversal(root);

    delete root;
}
