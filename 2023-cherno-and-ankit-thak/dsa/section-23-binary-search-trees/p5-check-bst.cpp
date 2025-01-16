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
using namespace std;

template <typename T>
bool checkBSThelper(BTNode<T> *root, long long minV = -10000000000, long long maxV = 10000000000)
{
    if (root == nullptr)
        return true;
    bool isLeftBST = checkBSThelper(root->left, minV, root->data);
    bool isRightBST = checkBSThelper(root->right, root->data, maxV);
    bool isRootDataInCorrectRange = (minV < root->data) && (root->data < maxV);
    return isLeftBST && isRightBST && isRootDataInCorrectRange;
}

// Search in BST recursive
template <typename T>
bool checkIsBTaBST(BTNode<T> *root)
{
    if (root == nullptr)
        return true;

    return checkBSThelper(root);
}

int main()
{
    BTNode<int> *root = takeBTTreeLevelWise<int>();
    cout << endl;
    cout << checkIsBTaBST(root) << endl;
}

// 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1