/*
Use same pattern as combination sum 2 no but this question has some fundamental
differences from combination sum 2 like in combination sum 2 we don not have to find
subset we have to find sum, so draw its recursion tree then you will understand the
pattern.

Problem Statement: Given an array of integers that may contain duplicates the task is to return all possible subsets. Return only unique subsets and they can be in any order.

Examples:

Example 1:

Input: array[] = [1,2,2]

Output: [ [ ],[1],[1,2],[1,2,2],[2],[2,2] ]

Explanation: We can have subsets ranging from  length 0 to 3. which are listed above. Also the subset [1,2] appears twice but is printed only once as we require only unique subsets.

Input: array[] = [1]

Output: [ [ ], [1] ]

Explanation: Only two unique subsets are available
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void subsetsWithDupHelper(int index, vector<int> &subset, vector<int> &set, vector<vector<int>> &uniqueSubsets)
{

    uniqueSubsets.push_back(subset);

    for (int i = index; i < set.size(); i++)
    {

        if (i > index && set[i] == set[i - 1])
        {
            continue;
        }
        // take
        subset.push_back(set[i]);
        subsetsWithDupHelper(i + 1, subset, set, uniqueSubsets);
        // dont take
        subset.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> uniqueSubsets;
    vector<int> subset;
    sort(nums.begin(), nums.end());
    subsetsWithDupHelper(0, subset, nums, uniqueSubsets);
    return uniqueSubsets;
}

int main()
{
    vector<int> set = {1, 2, 2};
    subsetsWithDup(set);
}