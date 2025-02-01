/*
Problem Statement: Coin Change II (Minimum Number of Coins for a Given Sum)
You are given an array coins[] representing different denominations of coins and
an integer sum.Your task is to determine the minimum number of coins required to
make the amount sum.

Each coin can be used an unlimited number of times (i.e., Unbounded Knapsack).
If it is not possible to make the sum, return -1.

Constraints
You have infinite supply of each coin.
If no combination adds up to sum, return -1.

Example 1
Input:
coins = {1, 2, 3}
sum = 5
Output:
2
Explanation:
The minimum number of coins to make sum = 5 is 2, using {2,3}.

Example 2
Input:
coins = {2, 5, 3, 6}
sum = 10
Output:
2
Explanation:
The minimum number of coins to make sum = 10 is 2, using {5,5}.

Example 3
Input:
coins = {2, 6}
sum = 3
Output:
-1
Explanation:
Since 3 cannot be formed using {2, 6}, the output is -1.
 */

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minNoOfCoins(vector<int> coins, int sum)
{
    int n = coins.size();

    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, INT_MAX - 1));

    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 0;
    }

    for (int j = 1; j <= sum; j++)
    {
        dp[1][j] = j % coins[0] == 0 ? j / coins[0] : INT_MAX - 1;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (coins[i - 1] <= sum)
            {

                dp[i][j] = min(dp[i][j - coins[i - 1]] + 1, dp[i - 1][j]);
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

    // vector<int> coins{1, 2, 3};
    // int sum = 5;

    // vector<int> coins{2, 5, 3, 6};
    // int sum = 10;

    vector<int> coins{2, 6};
    int sum = 3;

    cout << minNoOfCoins(coins, sum) << endl;
}