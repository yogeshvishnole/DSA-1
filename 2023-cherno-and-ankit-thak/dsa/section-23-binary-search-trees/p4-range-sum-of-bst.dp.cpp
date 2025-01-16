#pragma once
#include <iostream>
#include <utility>
#include <cmath>
#include "../section-22-binary-trees/p1-binary-tree-node.cpp"
#include "../section-22-binary-trees/p4-take-input-level-wise.cpp"
using namespace std;

// Search in BST recursive
template <typename T>
int rangeSumOfBST(BTNode<T> *root, pair<T, T> range)
{
    if (root == nullptr)
        return 0;

    int sum = 0;

    if (range.first <= root->data && root->data <= range.second)
    {
        sum += root->data;
    }

    // understand the below if else carefully, it represent a design pattern for BST's
    // This three conditions can be used in a lot of problems

    if (root->data > range.second)
    {
        sum += rangeSumOfBST(root->left, range);
    }
    else if (root->data < range.first)
    {
        sum += rangeSumOfBST(root->right, range);
    }
    else
    {
        sum += rangeSumOfBST(root->left, range) + rangeSumOfBST(root->right, range);
    }

    return sum;
}

int main()
{
    BTNode<int> *root = takeBTTreeLevelWise<int>();
    cout << endl;
    cout << rangeSumOfBST(root, make_pair(7, 15)) << endl;
}

// 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1