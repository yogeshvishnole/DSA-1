#pragma once
#include <iostream>
#include <cmath>
#include "../section-22-binary-trees/p1-binary-tree-node.cpp"
#include "../section-22-binary-trees/p4-take-input-level-wise.cpp"
using namespace std;

// Search in BST recursive
template <typename T>
int minValueInBST(BTNode<T> *root)
{
    if (root == nullptr)
        return INFINITY;

    if (root->left == nullptr)
        return root->data;

    return minValueInBST(root->left);
}

// Search in BST iterative
template <typename T>
int minValueInBSTIterative(BTNode<T> *root)
{
    BTNode<T> *temp = root;

    while (temp && temp->left != nullptr)
    {

        temp = (temp->left);
    }
    return temp->data;
}

int main()
{
    BTNode<int> *root = takeBTTreeLevelWise<int>();
    cout << endl;
    cout << minValueInBST(root) << " " << minValueInBSTIterative(root) << endl;
}

// 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1