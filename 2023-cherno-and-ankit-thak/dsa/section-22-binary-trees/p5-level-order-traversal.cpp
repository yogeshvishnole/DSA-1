#pragma once
#include <iostream>
#include "p1-binary-tree-node.cpp"
#include "p4-take-input-level-wise.cpp"
#include <queue>
using namespace std;

template <typename T>
void printTreeLevelWise(BTNode<T> *root)
{
    if (!root)
        return;

    queue<BTNode<T> *> helperQueue;

    helperQueue.push(root);

    while (!helperQueue.empty())
    {
        BTNode<T> *curNode = helperQueue.front();
        helperQueue.pop();

        cout << curNode->data << " : ";

        if (curNode->left)
        {
            cout << "L" << curNode->left->data << " ";
            helperQueue.push(curNode->left);
        }

        if (curNode->right)
        {
            cout << "R" << curNode->right->data << " ";
            helperQueue.push(curNode->right);
        }
        cout << endl;
    }
}

template <typename T>
vector<vector<T>> storeTreeLevelWise(BTNode<T> *root)
{

    vector<vector<T>> resultVector{};
    if (!root)
        return resultVector;

    queue<BTNode<T> *> helperQueue;

    helperQueue.push(root);
    helperQueue.push(nullptr);

    vector<T> level0{};
    resultVector.push_back(level0);

    int level = 0;

    while (!helperQueue.empty())
    {
        BTNode<T> *curNode = helperQueue.front();
        helperQueue.pop();

        if (curNode == nullptr)
        {
            if (helperQueue.empty())
            {
                continue;
            }
            else
            {
                helperQueue.push(nullptr);
                vector<T> newLevel{};
                resultVector.push_back(newLevel);
                level++;
                continue;
            }
        }

        resultVector[level].push_back(curNode->data);

        if (curNode->left)
        {
            helperQueue.push(curNode->left);
        }

        if (curNode->right)
        {
            helperQueue.push(curNode->right);
        }
    }
    return resultVector;
}

// int main()
// {

//     BTNode<int> *root = takeBTTreeLevelWise<int>();
//     printTreeLevelWise(root);
//     vector<vector<int>> resultVector = storeTreeLevelWise(root);

//     cout << endl;
//     int level = 1;
//     for (auto vec : resultVector)
//     {
//         cout << "Level " << level << endl;
//         for (auto item : vec)
//         {
//             cout << item << " ";
//         }
//         level++;
//         cout << endl;
//     }

//     delete root;
// }
