/*
Given an array nums of N positive integers, partition it into two subsets such that the
absolute difference of their sums is minimized. Return this minimum possible difference.

Mathematical Formulation:
Let S1 and S2 be the sums of two subsets. We need to minimize:
min(∣S1−S2∣)
Since the total sum S = S1 + S2, we rewrite:
min(∣S−2S1∣)
This means we need to find a subset whose sum S1 is as close as possible to S/2.

Example 1
Input:
nums = {1, 6, 11, 5};
Output:
1
Explanation:
Total sum = 1 + 6 + 11 + 5 = 23
Possible partitions:
{1, 6, 5} → Sum = 12
{11} → Sum = 11
Difference = |12 - 11| = 1
Minimum difference = 1
Example 2
Input:
nums = {3, 1, 4, 2, 2};
Output:
0
Explanation:
Total sum = 3 + 1 + 4 + 2 + 2 = 12
Possible partitions:
{3, 4, 1} → Sum = 8
{2, 2} → Sum = 4
Difference = |8 - 4| = 0
Minimum difference = 0
 */

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<bool> subsetSumLastRow(int arr[], int sum, int n)
{
    bool t[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
    {
        t[i][0] = true;
    }
    for (int j = 1; j <= sum; j++)
    {
        t[0][j] = false;
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
            }
            else if (arr[i - 1] > j)
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    vector<bool> ans;

    for (int i = 0; i <= sum; i++)
    {
        ans.push_back(t[n][i]);
    }

    return ans;
}

int minimumSubsetDiff(int arr[], int n)
{
    int sumOfArray = 0;
    for (int i = 0; i < n; i++)
    {
        sumOfArray += arr[i];
    }

    vector<bool> subsetSumsExist = subsetSumLastRow(arr, sumOfArray, n);

    int halfSum = sumOfArray / 2;

    int minimum = INT_MAX;
    for (int i = 0; i <= halfSum; i++)
    {
        if (subsetSumsExist[i])
            minimum = min(minimum, sumOfArray - 2 * i);
    }
    return minimum;
}

int main(int argc, char **argv)
{
    int arr[] = {1, 6, 11, 5};
    int n = 4;

    cout << minimumSubsetDiff(arr, n) << endl;
}