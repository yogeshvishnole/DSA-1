/*
Subset Sum : Sum of all Subsets



Problem Statement: Given an array print all the sum of the subset generated from it,
in the increasing order.

Examples:

Example 1:

Input: N = 3, arr[] = {5,2,1}

Output: 0,1,2,3,5,6,7,8

Explanation: We have to find all the subset’s sum and print them.in this case the
generated subsets are [ [], [1], [2], [2,1], [5], [5,1], [5,2]. [5,2,1],so the sums
we get will be  0,1,2,3,5,6,7,8


Input: N=3,arr[]= {3,1,2}

Output: 0,1,2,3,3,4,5,6

Explanation: We have to find all the subset’s sum and print them.in this case the
generate
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void subsetSumHelper(int index, int sum, vector<int> &set, vector<int> &subsetSums)
{
    if (index >= set.size())
    {
        subsetSums.push_back(sum);
        return;
    }

    // not take
    subsetSumHelper(index + 1, sum, set, subsetSums);
    // take
    subsetSumHelper(index + 1, sum + set[index], set, subsetSums);
}

void subsetSum(vector<int> &set)
{
    vector<int> subsetSums;
    subsetSumHelper(0, 0, set, subsetSums);
    sort(subsetSums.begin(), subsetSums.end());
    for (int el : subsetSums)
    {
        cout << el << " ";
    }
    cout << endl;
}

int main()
{
    // vector<int> set = {5, 2, 1};
    vector<int> set = {3, 1, 2};
    subsetSum(set);
}