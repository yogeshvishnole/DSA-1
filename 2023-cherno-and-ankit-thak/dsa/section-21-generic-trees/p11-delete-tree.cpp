/*
As we are dynamic allocating memory while creating tree using the new keyword
so we have to deallocate that memory before we close our program. so thats why we write
deleteTree function for it. Now if we delete the root node first then we are not able to
reach its childrens because parent is the only way to reach childs. Thats why we have to
delete the children first, then root.
So deleting tree is a perfect example of Post Order Traversal.
 */

/*
PostOrder Traversal - First print the children then its parent
 */

#pragma once
#include <iostream>
#include "p1-tree-node.cpp"
#include "p3-level-wise-tree-input.cpp"
using namespace std;

template <typename T>
void deleteTree(TreeNode<T> *root)
{
    if (root == nullptr)
        return;

    for (int i = 0; i < root->children.size(); i++)
    {
        postOrderTraversal(root->children[i]);
    }
    delete root;
}

int main()
{
    TreeNode<int> *root = takeTreeInputLevelWise<int>();
    deleteTree(root);
}
