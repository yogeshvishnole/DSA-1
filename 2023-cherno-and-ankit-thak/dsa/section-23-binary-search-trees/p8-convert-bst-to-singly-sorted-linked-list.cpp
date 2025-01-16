

#pragma once
#include <iostream>
#include <utility>
#include <cmath>
#include "../section-22-binary-trees/p1-binary-tree-node.cpp"
#include "../section-22-binary-trees/p4-take-input-level-wise.cpp"
#include "../section-22-binary-trees/p5-level-order-traversal.cpp"
using namespace std;

pair<BTNode<int> *, BTNode<int> *> convertBSTToLL(BTNode<int> *root)
{
    if (root == nullptr)
        return make_pair(nullptr, nullptr);

    auto leftResult = convertBSTToLL(root->left);

    BTNode<int> *head;
    if (leftResult.second == nullptr)
    {
        head = root;
    }
    else
    {
        leftResult.second->right = root;
        head = leftResult.first;
    }

    auto rightResult = convertBSTToLL(root->right);

    root->right = rightResult.first;

    BTNode<int> *tail;
    if (rightResult.second == nullptr)
        tail = root;
    else
        tail = rightResult.second;

    return make_pair(head, tail);
}

int main()
{
    BTNode<int> *root = takeBTTreeLevelWise<int>();
    auto ll = convertBSTToLL(root);
    BTNode<int> *head = ll.first;
    // print the ll
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->right;
    }
    cout
        << endl;
}

// 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1