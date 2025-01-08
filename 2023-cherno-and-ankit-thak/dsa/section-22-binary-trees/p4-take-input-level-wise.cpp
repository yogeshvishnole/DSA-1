#pragma once
#include <iostream>
#include "p1-binary-tree-node.cpp"
#include "p2-print-tree-recursive.cpp"
#include <queue>
using namespace std;

template <typename T>
BTNode<T> *takeBTTreeLevelWise()
{
    T data;
    cout << "Enter the root data: ";
    cin >> data;
    if (data == -1)
    {
        return nullptr;
    }

    queue<BTNode<T> *> helperQueue;

    BTNode<T> *root = new BTNode<T>(data);
    helperQueue.push(root);

    while (!helperQueue.empty())
    {
        BTNode<T> *curNode = helperQueue.front();
        helperQueue.pop();

        cout << "Enter the left child of " << curNode->data << " : ";
        T leftData;
        cin >> leftData;
        curNode->left = leftData == -1 ? nullptr : new BTNode<T>(leftData);
        if (curNode->left)
            helperQueue.push(curNode->left);

        cout << "Enter the right child of " << curNode->data << " : ";
        T rightData;
        cin >> rightData;
        curNode->right = rightData == -1 ? nullptr : new BTNode<T>(rightData);
        if (curNode->right)
            helperQueue.push(curNode->right);
    }
    return root;
}

// int main()
// {

//     BTNode<int> *root = takeBTTreeLevelWise<int>();
//     printTreeRecursive(root);

//     delete root;
// }

