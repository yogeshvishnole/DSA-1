/*

IMP question for interviews

Solution Approach Comments
Base Case for Recursion:

The function correctly identifies nullptr as the base case, returning a pair of 0 (height) and 0 (diameter). This is critical for ensuring recursion terminates gracefully and works with leaf nodes.
Divide and Conquer:

The problem is solved by splitting it into smaller subproblems: calculating the height and diameter of the left and right subtrees. This follows the divide-and-conquer paradigm.
Height Calculation:

Height is computed as 1 + max(leftHeight, rightHeight), which is standard for binary trees. This ensures the height propagates correctly up the recursion stack.
Diameter Calculation:

The diameter is calculated as the maximum of:
The sum of the heights of the left and right subtrees (l.first + r.first).
The diameters of the left and right subtrees (l.second and r.second).
This approach ensures the diameter is computed for every subtree and correctly propagates the maximum value.
Efficient Use of Pair:

Using std::pair<int, int> to return both height and diameter in one recursive call avoids redundant calculations. This is an efficient design choice.
Input and Output:

The tree is taken as input using takeBTTreeLevelWise (assumed to read the tree level by level), and the computed diameter is printed. This makes the solution easy to test and verify.
Key Concepts and Insights
Binary Tree Height and Diameter:

Height: The number of edges on the longest path from the root to a leaf.
Diameter: The number of edges on the longest path between any two nodes in the tree. It can pass through or not pass through the root.
Postorder Traversal:

The function uses a postorder traversal (left → right → root) to calculate the height and diameter for each node. This ensures that all subtrees are processed before the parent node.
Recursive Design:

Recursion is the natural choice for tree problems because of the hierarchical structure. The base case and recursive step are designed well to handle all scenarios.
Time Complexity:

The time complexity is O(n), where n is the number of nodes in the tree. This is because each node is visited once, and both height and diameter are calculated in a single traversal.
Space Complexity:

The space complexity is O(h), where h is the height of the tree. This is due to the recursion stack. In the worst case (a skewed tree), it can go up to O(n).
Pair Usage:

The use of std::pair<int, int> for height and diameter simplifies the code and reduces redundancy. This is a good example of clean and concise coding.
Input Handling:

The use of takeBTTreeLevelWise (assumed to be implemented elsewhere) ensures the tree is constructed correctly, which is essential for testing.
 */

#pragma once
#include <iostream>
#include <utility>
#include "p1-binary-tree-node.cpp"
#include "p4-take-input-level-wise.cpp"
using namespace std;

template <typename T>
pair<int, int> heightAndDiameterOfBinaryTree(BTNode<T> *root)
{
    if (root == nullptr)
        return make_pair(0, 0);

    pair<int, int> l = heightAndDiameterOfBinaryTree(root->left);
    pair<int, int> r = heightAndDiameterOfBinaryTree(root->right);

    int height = 1 + max(l.first, r.first);
    int diameter = max(l.first + r.first, max(l.second, r.second));

    return make_pair(height, diameter);
}

template <typename T>
int diameterOfBinaryTree(BTNode<T> *root)
{
    pair<int, int> ans = heightAndDiameterOfBinaryTree(root);
    return ans.second;
}

int main()
{
    BTNode<int> *root = takeBTTreeLevelWise<int>();
    cout << endl;
    cout << diameterOfBinaryTree(root) << endl;
}
