/*
There are two approached to solve this problem.
1. Find inorder traversal of the binary tree, if it is sorted means the given tree is
BST.
2. every node value in BST has a range, if that nodes value is lie with in that range
it means given tree is BST

Since second method is hard to understand thats why we implement that.
 */

#pragma once
#include <iostream>
#include <utility>
#include <cmath>
#include "../section-22-binary-trees/p1-binary-tree-node.cpp"
#include "../section-22-binary-trees/p4-take-input-level-wise.cpp"
#include "../section-22-binary-trees/p5-level-order-traversal.cpp"
using namespace std;

template <typename T>

BTNode<T> *constructBSTHelper(vector<T> &v, int startIndex, int endIndex)
{
    if (startIndex > endIndex)
        return nullptr;

    int mid = ((endIndex - startIndex) / 2) + startIndex;

    BTNode<T> *root = new BTNode<T>(v[mid]);
    root->left = constructBSTHelper(v, startIndex, mid - 1);
    root->right = constructBSTHelper(v, mid + 1, endIndex);
    return root;
}

template <typename T>
BTNode<T> *constructBST(vector<T> &v)
{
    return constructBSTHelper(v, 0, v.size() - 1);
}

int main()
{
    vector<int> v{1, 2, 3, 4, 5, 6, 7};
    cout << endl;
    BTNode<int> *root = constructBST(v);
    printTreeLevelWise(root);
}

// 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1