/*
Bhai Bhai Bhai, the unbounded knapack is same as same as 01 knapsack, but
here in this problem we can take an element in knapsack bag any number of times
we have unlimited supply of an item, we can take the same item repeatedly until
our bag capacity not reached.

The code of the problem is also similar just 1 (i-1) in 01 knapsack will be
replaced by i, because we can take the same item again.

Formally -

Problem Statement: Unbounded Knapsack
Given N items, each with a weight and a value, and a knapsack with a maximum
capacity W, you need to determine the maximum value you can obtain by putting
items into the knapsack.

Unlike the 0/1 Knapsack problem, in this problem, you can take unlimited
instances of each item.

Constraints:

Each item has infinite supply (i.e., you can take the same item multiple times).
You cannot exceed the knapsack's weight capacity W.

Example 1
Input:
N = 3
W = 8
weights = {2, 3, 4}
values  = {5, 10, 15}

Output:
30

Explanation:
We can take multiple instances of items:

Take item 2 (weight 4, value 15) twice → Total weight = 8, Total value = 30
Thus, the maximum value that can be obtained is 30.

Example 2
Input:
N = 3
W = 10
weights = {1, 3, 4}
values  = {10, 40, 50}

Output:
130

Explanation:
Take item 1 (weight 1, value 10) ten times → Total value = 100
Thus, the maximum value is 100.

Example 3
Input:
N = 2
W = 7
weights = {5, 2}
values  = {30, 10}

Output:
40

Explanation:
Take item 2 (weight 2, value 10) twice (total weight = 4, value = 20)
Take item 1 (weight 5, value 30) once (total weight = 5, value = 30)
The best combination: Item 1 once + Item 2 once → Total value = 40
 */

#include <iostream>
#include <vector>
using namespace std;

int unboundedKnapsack(vector<int> &values, vector<int> &weights, int capacity)
{

    // number of items
    int n = values.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= capacity; j++)
        {
            if (weights[i - 1] <= j)
            {
                dp[i][j] = max(values[i - 1] + dp[i][j - weights[i - 1]], dp[i - 1][j]);
            }
            else if (weights[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][capacity];
}

int main(int argc, char **argv)
{
    // vector<int> values{5, 10, 15};
    // vector<int> weights{2, 3, 4};
    // int capacity = 8;

    // vector<int> values{10, 40, 50};
    // vector<int> weights{1, 3, 4};
    // int capacity = 10;

    vector<int> values{30, 10};
    vector<int> weights{5, 2};
    int capacity = 7;

    cout << unboundedKnapsack(values, weights, capacity) << endl;
}