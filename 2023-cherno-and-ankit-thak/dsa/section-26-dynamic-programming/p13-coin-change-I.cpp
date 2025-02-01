/*

Problem Statement: Coin Change I (Maximum Number of Ways to Make a Sum)
You are given an array coins[] representing different denominations of coins and
an integer sum.Your task is to determine the number of ways to make the amount
sum using any number of coins.

Each coin can be used an unlimited number of times (i.e., Unbounded Knapsack).

Constraints
You have infinite supply of each coin.
The order of coins does not matter (i.e., {1,2} and {2,1} count as the same way).
If no combination adds up to sum, return 0.

Example 1
Input:
coins = {1, 2, 3}
sum = 4
Output:
4
Explanation:
The 4 ways to make sum = 4 are:
{1,1,1,1}
{1,1,2}
{2,2}
{1,3}


Example 2
Input:
coins = {2, 5, 3, 6}
sum = 10
Output:
5
Explanation:
The 5 ways to make sum = 10 are:
{2,2,2,2,2}
{2,2,3,3}
{2,2,6}
{5,5}
{2,3,5}

 */

#include <iostream>
#include <vector>
using namespace std;

int noOfWaysToCoinSum(vector<int> coins, int sum)
{
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (coins[i - 1] <= j)
            {
                dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
            }
            else if (coins[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][sum];
}

int main(int argc, char **argv)
{
    vector<int> coins{1, 2, 3};
    int sum = 4;

    // vector<int> coins{2, 5, 3, 6};
    // int sum = 10;

    cout << noOfWaysToCoinSum(coins, sum) << endl;
}