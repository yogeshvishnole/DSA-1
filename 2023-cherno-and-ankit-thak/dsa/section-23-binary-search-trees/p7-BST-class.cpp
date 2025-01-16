#pragma once
#include <iostream>
#include "../section-22-binary-trees/p1-binary-tree-node.cpp"
#include "../section-22-binary-trees/p4-take-input-level-wise.cpp"
#include "../section-22-binary-trees/p5-level-order-traversal.cpp"
#include "./p1-search-bst.cpp"

using namespace std;

class BST
{
    BTNode<int> *bstRoot;

    void insertHelper(BTNode<int> *&root, BTNode<int> *newNode)
    {
        if (newNode == nullptr)
            return;
        if (root == nullptr)
        {
            root = newNode;
            return;
        }

        BTNode<int> *temp = root;
        while (temp != nullptr)
        {
            BTNode<int> *tempTemp = temp;
            if (newNode->data < temp->data)
            {
                temp = temp->left;
                if (temp == nullptr)
                {
                    tempTemp->left = newNode;
                    return;
                }
            }
            else if (newNode->data > temp->data)
            {
                temp = temp->right;
                if (temp == nullptr)
                {
                    tempTemp->right = newNode;
                    return;
                }
            }
        }
    }

public:
    BST()
    {
        this->bstRoot = nullptr;
    }

    ~BST()
    {
        delete bstRoot;
    }

    void insert(int data)
    {
        BTNode<int> *newNode = new BTNode<int>(data);
        insertHelper(this->bstRoot, newNode);
    }

    void deleteData(int data)
    {
        BTNode<int> *temp = this->bstRoot;
        while (temp != nullptr)
        {
            BTNode<int> *curTemp = temp;

            if (data < temp->data)
            {
                temp = temp->left;
                if (data == temp->data)
                {
                    if (temp->left && !(temp->right))
                    {
                        curTemp->left = temp->left;
                        temp->left = nullptr;
                        delete temp;
                        return;
                    }
                    else if (temp->right && !(temp->left))
                    {
                        curTemp->left = temp->right;
                        temp->right = nullptr;
                        delete temp;
                        return;
                    }
                    // do the deletion process
                    BTNode<int> *curLeft = curTemp->left->right;
                    curTemp->left = temp->left;
                    insertHelper(temp->left, curLeft);
                    temp->left = nullptr;
                    temp->right = nullptr;
                    delete temp;
                    return;
                }
            }
            else
            {
                temp = temp->right;
                if (data == temp->data)
                {
                    if (temp->left && !(temp->right))
                    {
                        curTemp->right = temp->left;
                        temp->left = nullptr;
                        delete temp;
                        return;
                    }
                    else if (temp->right && !(temp->left))
                    {
                        curTemp->right = temp->right;
                        temp->right = nullptr;
                        delete temp;
                        return;
                    }
                    // do the deletion process
                    BTNode<int> *curRight = curTemp->right->right;
                    curTemp->right = temp->left;
                    insertHelper(temp->left, curRight);
                    temp->left = nullptr;
                    temp->right = nullptr;
                    delete temp;
                    return;
                }
            }
        }
    }

    bool
    hasData(int data)
    {
        return searchInBSTIterative(this->bstRoot, data);
    }

    bool printTree()
    {
        printTreeLevelWise(this->bstRoot);
    }
};

int main()
{
    BST *bst = new BST();
    bst->insert(10);
    bst->insert(5);
    bst->insert(20);
    bst->insert(7);
    bst->insert(3);
    bst->insert(15);
    bst->printTree();
    
    bst->deleteData(10);
    cout << endl;

    bst->deleteData(5);
    bst->printTree();
    cout << endl;

    bst->deleteData(100);
    bst->printTree();
    // bst->deleteData(3);
    // bst->printTree();
}