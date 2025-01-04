/*
Currently we are printing recursively, means first we go to first depth and print elements
of it, then we start from another child and track that to its last descendant and so on.
But now we have to print in a breadth first manner means first print first level elements then
second level and so on.
 */
#pragma once
#include <iostream>
#include <queue>
#include "p1-tree-node.cpp"
#include "p2-print-tree.cpp"
#include "p3-level-wise-tree-input.cpp"
using namespace std;

template <typename T>
void levelWisePrint(TreeNode<T> *root)
{
    queue<TreeNode<T> *> helperQueue;
    helperQueue.push(root);

    while (!helperQueue.empty())
    {
        TreeNode<T> *curNode = helperQueue.front();
        helperQueue.pop();
        cout << curNode->data << " : ";
        for (int i = 0; i < curNode->children.size(); i++)
        {
            helperQueue.push(curNode->children[i]);
            if (i == curNode->children.size() - 1)
            {
                cout << curNode->children[i]->data;
                break;
            }
            cout << curNode->children[i]->data << ", ";
        }
        cout << endl;
    }
}

// int main()
// {
//     TreeNode<int> *root = takeTreeInputLevelWise<int>();
//     levelWisePrint<int>(root);
// }
