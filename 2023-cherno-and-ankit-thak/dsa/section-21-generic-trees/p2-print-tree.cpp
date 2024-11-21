/*
We will print tree in the following fashion
1:2,3
2:4,5
3:
4:
5:

parent:children
....
....

 */

#include <iostream>
#include "p1-tree-node.cpp"
using namespace std;

template <typename T>
void printTree(TreeNode<T> *root)
{
    // Edge case
    if (root == nullptr)
    {
        return;
    }

    cout << root->data << " : ";
    for (int i = 0; i < root->children.size(); i++)
    {
        if (i == (root->children.size() - 1))
        {
            cout << root->children[i]->data;
            break;
        }
        cout << root->children[i]->data << ", ";
    }
    cout << endl;

    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

int main()
{
    TreeNode<int> *root = new TreeNode<int>(1);
    TreeNode<int> *n1 = new TreeNode<int>(2);
    TreeNode<int> *n2 = new TreeNode<int>(3);

    root->children.push_back(n1);
    root->children.push_back(n2);

    printTree(root);
}