/*
Problem -
https://leetcode.com/problems/combination-sum/description/

Given an array of distinct integers candidates and a target integer target, return a list of all
unique combinations of candidates where the chosen numbers sum to target. You may return the
combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are
unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is
less than 150 combinations for the given input.

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []
*/

#include <iostream>
#include <vector>
using namespace std;

void findCombinations(int index, vector<int> &ds, vector<int> &candidates, vector<vector<int>> &ans, int curSum, int target)
{
    if (index >= candidates.size() || curSum >= target)
    {
        if (curSum == target)
        {
            vector<int> combination;
            for (auto combEl : ds)
            {
                combination.push_back(combEl);
            }
            ans.push_back(combination);
        }

        return;
    }

    if (candidates[index] <= target)
    {
        ds.push_back(candidates[index]);
        findCombinations(index, ds, candidates, ans, curSum + candidates[index], target);
        ds.pop_back();
    }

    findCombinations(index + 1, ds, candidates, ans, curSum, target);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> ds;
    findCombinations(0, ds, candidates, ans, 0, target);
    return ans;
}

int main()
{
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> combinations = combinationSum(candidates, target);
    for (auto combination : combinations)
    {
        for (auto el : combination)
        {
            cout << el << " ";
        }
        cout << endl;
    }
}