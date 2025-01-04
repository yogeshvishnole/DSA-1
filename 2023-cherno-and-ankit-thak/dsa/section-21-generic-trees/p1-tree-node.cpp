/*
In this we see how to represent the single node of a generic or n-arry tree in code
and will create a small tree with that node.
we will use vector or dynamic array for storing the childs of a node. Why not array and linked
list because -
array - has limited size but tree node can have many childrens.
linked list - we have to traverse the complete list to reach to a child.

vector or dyanamic queue provides idefinite size and random acces with the help
of which we can access any number childe in O(1)

Deleting tree via destructor -
It is interesting for this you should well aware about the working
of delete keyword, what delete keyword do is first call the destructor
execute its code and then delete the object, so when we delete root
then in its destructor we will delete its childs and then the parent/root
itself will be deleted in recursive post order manner.

 */
#pragma once
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data)
    {
        this->data = data;
    }

    ~TreeNode()
    {
        for (int i = 0; i < this->children.size(); i++)
        {
            delete this->children[i];
        }
    }
};

// int main(int argc, char **argv)
// {
//     TreeNode<int> *root = new TreeNode<int>(1);
//     TreeNode<int> *n1 = new TreeNode<int>(2);
//     TreeNode<int> *n2 = new TreeNode<int>(3);

//     root->children.push_back(n1);
//     root->children.push_back(n2);
// }