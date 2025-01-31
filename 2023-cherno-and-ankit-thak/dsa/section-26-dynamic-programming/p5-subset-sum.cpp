/*

The Subset Sum Problem is a classic Dynamic Programming problem where we determine whether
a subset with a given sum exists in a given set of numbers.

Problem Statement
Given an array of integers nums and a target sum S, determine whether there exists a subset
of nums whose sum is equal to S.

Approach
We can solve this problem using:

Iterative (Bottom-up Dynamic Programming)
Recursive (Top-down with Memoization)

If we don't include nums[i]:
dp[i][j]=dp[i−1][j]
If we include nums[i]:
dp[i][j]=dp[i−1][j−nums[i−1]]
Base Case: dp[0][0] = true (empty subset for sum 0)
 */

#include <iostream>
#include <vector>
using namespace std;

bool subsetSumIterative(vector<int> &nums, int S)
{
    int n = nums.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(S + 1, false));

    // Base case: sum 0 is always possible with an empty subset
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    // Fill the DP table
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= S; j++)
        {
            if (nums[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][S];
}

// recursive solution
class Solution
{
public:
    vector<vector<int>> memo;

    bool dfs(vector<int> &nums, int i, int target)
    {
        if (target == 0)
            return true;
        if (i == 0)
            return nums[0] == target;
        if (memo[i][target] != -1)
            return memo[i][target];

        // Exclude the current element
        bool exclude = dfs(nums, i - 1, target);

        // Include the current element if within target range
        bool include = (nums[i] <= target) ? dfs(nums, i - 1, target - nums[i]) : false;

        return memo[i][target] = exclude || include;
    }

    bool subsetSumRecursive(vector<int> &nums, int S)
    {
        int n = nums.size();
        memo.assign(n, vector<int>(S + 1, -1));
        return dfs(nums, n - 1, S);
    }
};

int main()
{
    vector<int> nums = {3, 34, 4, 12, 5, 2};
    int S = 9;
    cout << (subsetSumIterative(nums, S) ? "True" : "False") << endl;
    Solution sol;
    cout << (sol.subsetSumRecursive(nums, S) ? "True" : "False") << endl;
    return 0;
}
