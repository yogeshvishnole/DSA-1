/*
Very interesting problem

Below is the problem statement -

Equal Sum Partition Problem - Problem Statement
Given an array nums of N positive integers, determine whether it can be partitioned into two
subsets such that the sum of both subsets is equal.

Formally:
Find if there exists a subset whose sum is equal to half of the total sum of the array.

Constraints:
Each number in nums is positive.
The array contains at least one element.

Approach

If the total sum of the array is odd, partitioning into two equal halves is impossible.
Return false.

If the total sum is even, check whether there exists a subset with sum equal to totalSum / 2.
This reduces the problem to the Subset Sum Problem where target = totalSum / 2.

Examples -
Input - nums = {1, 5, 11, 5};
Output - True

Input - nums = {1, 2, 3, 5};
Output - False

 */

#include <iostream>
#include <vector>
using namespace std;

bool subsetSum(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

    // Base Case: sum 0 is always possible
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    // Fill the DP table
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            if (nums[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][target];
}

bool canPartition(vector<int> &nums)
{
    int totalSum = 0;
    for (int num : nums)
        totalSum += num;

    // If total sum is odd, we cannot partition into two equal subsets
    if (totalSum % 2 != 0)
        return false;

    // Find if subset with sum = totalSum / 2 exists
    return subsetSum(nums, totalSum / 2);
}

int main()
{
    vector<int> nums = {1, 5, 11, 5};
    cout << (canPartition(nums) ? "True" : "False") << endl; // Output: True

    vector<int> nums2 = {1, 2, 3, 5};
    cout << (canPartition(nums2) ? "True" : "False") << endl; // Output: False

    return 0;
}
