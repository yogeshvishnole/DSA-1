/*
Problem Statement: Count of Subsets with Given Sum
Given an array nums of N positive integers and a target sum S, find the number of subsets
whose sum is exactly equal to S.

Constraints:
Each number in nums is positive.
The array contains at least one element.
Multiple subsets can have the same sum, and each should be counted separately.

Example 1
Input:
nums = {2, 3, 5, 6, 8, 10};
S = 10;
Output:
3
Explanation:
The subsets that sum to 10 are:
{2, 3, 5}
{10}
{2, 8}
Thus, the count is 3.

Example 2
Input:
nums = {1, 2, 3, 3};
S = 6;
Output:
3
Explanation:
The subsets that sum to 6 are:
{1, 2, 3}
{1, 2, 3} (second occurrence)
{3, 3}
Thus, the count is 3.

Example 3
Input:
nums = {1, 1, 1, 1};
S = 1;
Output:
4
Explanation:
Each 1 in the array forms a subset {1} separately.
Thus, the count is 4.

 */

#include <iostream>
using namespace std;

int countOfSubsets(int arr[], int n, int sum)
{
    int t[n + 1][sum + 1];

    // initialization
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (j == 0)
            {
                t[i][j] = 1;
            }
            else
            {
                t[i][j] = 0;
            }
        }
    }

    // implementation of the choice diagram
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];
            }
            else if (arr[i - 1] > j)
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][sum];
}

int main(int argc, char **argv)
{
    // int arr[] = {2, 3, 5, 6, 8, 10};
    // int sum = 10;
    // int n = 6;

    int arr[] = {1, 2, 3, 3};
    int sum = 6;
    int n = 4;

    // int arr[] = {1, 1, 1, 1};
    // int sum = 1;
    // int n = 4;

    cout << countOfSubsets(arr, n, sum) << endl;
}