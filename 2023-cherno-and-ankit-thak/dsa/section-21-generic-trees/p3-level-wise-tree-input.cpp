/*
Level wise means first level 1 nodes
then level 2 nodes
then level 3 nodes

OH OH OH OH OH the solution of this problem is quite interesting, we will use
a queue for taking level wise input with iteration, try to grasp it and think about it
it is very unlikely to be thought in first go.
 */
#pragma once
#include <iostream>
#include <queue>
#include "p1-tree-node.cpp"
#include "p2-print-tree.cpp"

template <typename T>
TreeNode<T> *takeTreeInputLevelWise()
{
    queue<TreeNode<T> *> helperQueue;
    cout << "Enter the root node : ";

    int data;
    cin >> data;
    TreeNode<T> *root = new TreeNode<T>(data);
    helperQueue.push(root);

    while (!helperQueue.empty())
    {
        TreeNode<T> *curNode = helperQueue.front();
        helperQueue.pop();
        int numberOfChildren;
        cout << "Enter the number children of " << curNode->data << " : ";
        cin >> numberOfChildren;
        for (int i = 0; i < numberOfChildren; i++)
        {

            cout << "Enter the " << i + 1 << " th children of " << curNode->data << " : ";
            T n;
            cin >> n;
            TreeNode<T> *treeNode = new TreeNode<T>(n);
            curNode->children.push_back(treeNode);
            helperQueue.push(treeNode);
        }
    }

    return root;
}

// int main(int argc, char **argv)
// {
//     TreeNode<int> *root = takeTreeInputLevelWise<int>();
//     printTree<int>(root);
// }
