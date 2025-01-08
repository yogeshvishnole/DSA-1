/*
Given a binary tree and a target key, find the path from the root to the node containing the key.
 */

#pragma once
#include <iostream>
#include <vector>
#include "p1-binary-tree-node.cpp"
#include "p4-take-input-level-wise.cpp"
using namespace std;

template <typename T>
bool rootToNodePathHelper(BTNode<T> *root, T key, vector<T> &path)
{
    if (root == nullptr)
        return false;

    // Add the current node to the path
    path.push_back(root->data);

    // Check if this is the target node
    if (root->data == key)
        return true;

    // Recursively check left and right subtrees
    if (rootToNodePathHelper(root->left, key, path) || rootToNodePathHelper(root->right, key, path))
        return true;

    // If not found, backtrack by removing the current node from the path
    path.pop_back();
    return false;
}

template <typename T>
vector<T> rootToNodePath(BTNode<T> *root, T key)
{
    vector<T> path;
    if (rootToNodePathHelper(root, key, path))
        return path; // Return the path if the key is found
    return {};       // Return an empty vector if the key is not found
}

int main()
{
    BTNode<int> *root = takeBTTreeLevelWise<int>();
    cout << endl;

    int key = 9; // Change this to test with different values
    vector<int> ans = rootToNodePath(root, key);

    if (ans.empty())
    {
        cout << "Key " << key << " not found in the tree." << endl;
    }
    else
    {
        cout << "Path from root to node " << key << ": ";
        for (auto item : ans)
        {
            cout << item << " ";
        }
        cout << endl;
    }

    return 0;
}
