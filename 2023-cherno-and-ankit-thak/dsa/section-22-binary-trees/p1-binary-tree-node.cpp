#pragma once
#include <iostream>
using namespace std;

template <typename T>
class BTNode
{
public:
    T data;
    BTNode<T> *left;
    BTNode<T> *right;

    BTNode(T data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }

    ~BTNode()
    {
        delete this->left;
        delete this->right;
    }
};

// int main()
// {
//     // lets construct a simple binary tree
//     BTNode<int> *root = new BTNode<int>(1);
//     BTNode<int> *left = new BTNode<int>(2);
//     BTNode<int> *right = new BTNode<int>(3);

//     root->left = left;
//     root->right = right;

//     delete root;
// }