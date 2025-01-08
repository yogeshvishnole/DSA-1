/* 
height of tree maximum number of levels in the binary tree, it is also called as the max
depth of the tree.
 */

#pragma once
#include <iostream>
#include "p1-binary-tree-node.cpp"
#include "p4-take-input-level-wise.cpp"
using namespace std;

template <typename T>
int heightOfTree(BTNode<T> *root)
{
    // Base case
    if (root == nullptr)
        return 0;

    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);
    return 1+max(leftHeight,rightHeight);
}

int main()
{

    BTNode<int> *root = takeBTTreeLevelWise<int>();
    cout << endl;
    cout << "Height Of Given tree is : " << endl;
    cout << heightOfTree(root) << endl;

    delete root;
}
