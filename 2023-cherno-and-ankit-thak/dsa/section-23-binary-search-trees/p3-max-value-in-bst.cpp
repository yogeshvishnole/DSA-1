#pragma once
#include <iostream>
#include <cmath>
#include "../section-22-binary-trees/p1-binary-tree-node.cpp"
#include "../section-22-binary-trees/p4-take-input-level-wise.cpp"
using namespace std;

// Search in BST recursive
template <typename T>
int maxValueInBST(BTNode<T> *root)
{
    if (root == nullptr)
        return -1;

    if (root->right == nullptr)
        return root->data;

    return maxValueInBST(root->right);
}

// Search in BST iterative
template <typename T>
int maxValueInBSTIterative(BTNode<T> *root)
{
    BTNode<T> *temp = root;

    while (temp && temp->right != nullptr)
    {

        temp = (temp->right);
    }
    return temp->data;
}

int main()
{
    BTNode<int> *root = takeBTTreeLevelWise<int>();
    cout << endl;
    cout << maxValueInBST(root) << " " << maxValueInBSTIterative(root) << endl;
}

// 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1