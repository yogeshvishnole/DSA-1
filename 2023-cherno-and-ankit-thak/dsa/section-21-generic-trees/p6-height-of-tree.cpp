/*
Simple recursion problem

find heights of all subtrees + 1

 */
#include <iostream>
#include <vector>
#include <algorithm>
#include "p1-tree-node.cpp"
#include "p3-level-wise-tree-input.cpp"
using namespace std;

template <typename T>
int heightOfTree(TreeNode<T> *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    vector<int> heightOfSubTrees;
    for (int i = 0; i < root->children.size(); i++)
    {
        heightOfSubTrees.push_back(heightOfTree(root->children[i]));
    }

    auto maxIt = max_element(heightOfSubTrees.begin(), heightOfSubTrees.end());

    return 1 + (maxIt != heightOfSubTrees.end() ? *maxIt : 0);
}

int main(int argc, char **argv)
{
    TreeNode<int> *root = takeTreeInputLevelWise<int>();
    cout << "Height of  given tree is : " << heightOfTree(root) << endl;
}
