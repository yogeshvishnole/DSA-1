/*
In this we see how to represent the single node of a generic or n-arry tree in code
and will create a small tree with that node.
we will use vector or dynamic array for storing the childs of a node. Why not array and linked
list because -
array - has limited size but tree node can have many childrens.
linked list - we have to traverse the complete list to reach to a child.

vector or dyanamic queue provides idefinite size and random acces with the help
of which we can access any number childe in O(1)

 */

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
};

// int main(int argc, char **argv)
// {
//     TreeNode<int> *root = new TreeNode<int>(1);
//     TreeNode<int> *n1 = new TreeNode<int>(2);
//     TreeNode<int> *n2 = new TreeNode<int>(3);

//     root->children.push_back(n1);
//     root->children.push_back(n2);
// }