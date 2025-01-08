#pragma once
#include <iostream>
#include "p1-binary-tree-node.cpp"
#include "p4-take-input-level-wise.cpp"
#include <queue>
using namespace std;

template <typename T>
int countBTNodes(BTNode<T> *root)
{
    // Base case
    if (root == nullptr)
        return 0;
    return 1 + countBTNodes(root->left) + countBTNodes(root->right);
}

int main()
{

    BTNode<int> *root = takeBTTreeLevelWise<int>();
    cout << endl;
    cout << countBTNodes(root) << endl;

    delete root;
}
