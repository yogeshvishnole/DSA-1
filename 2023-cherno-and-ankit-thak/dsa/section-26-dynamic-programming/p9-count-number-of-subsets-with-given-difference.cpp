/*
Problem Statement: Count the Number of Subsets with Given Difference
Given an array nums of N positive integers and a target difference D, find the number of
ways to partition the array into two subsets (S1 and S2) such that:
S1−S2=D
Mathematical Formulation
Since the total sum of the array is:
S=S1+S2
Rearranging the given condition:
S1= (S+D)/2
​
Thus, the problem reduces to finding the number of subsets whose sum is (S + D) / 2.

Constraints:
All elements in nums are positive.
The sum of elements should be greater than or equal to D, i.e., S >= D.
(S + D) should be even, otherwise, a valid partition is not possible.
Example 1
Input:
nums = {1, 1, 2, 3};
D = 1;
Output:
3
Explanation:
Total sum = 1 + 1 + 2 + 3 = 7
Subset sum to find:
S1 = (7+1)/2 = 4
Possible subsets with sum 4 are:
{1, 3}
{1, 3} (another occurrence)
{2, 2}
Thus, the count is 3.

Example 2
Input:
nums = {1, 2, 3, 4, 5};
D = 3;
Output:
3
Explanation:

Total sum = 1 + 2 + 3 + 4 + 5 = 15
Subset sum to find:


S1= (15+3)/2 =9
Valid subsets with sum 9:

{4, 5}
{1, 3, 5}
{2, 3, 4}
Thus, count = 3.

 */
#include <iostream>
#include <vector>
using namespace std;

int countOfSubsetSum(vector<int> arr, int sum)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
            }
            else if (arr[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}
int countOfSubsetWithGivenDiff(vector<int> arr, int diff)
{

    int sumOfArray = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        sumOfArray += arr[i];
    }

    // Are bawa s1-s2 = diff and s2 = (sumOfarray) - s1 solving the two equation will give
    // below equation

    int sum = (sumOfArray - diff) / 2;

    return countOfSubsetSum(arr, sum);
}

int main(int argc, char **argv)
{
    // vector<int> arr{1, 1, 2, 3};
    // int diff = 1;
    vector<int> arr{1, 2, 3, 4, 5};
    int diff = 3;
    cout << countOfSubsetWithGivenDiff(arr, diff) << endl;
}
