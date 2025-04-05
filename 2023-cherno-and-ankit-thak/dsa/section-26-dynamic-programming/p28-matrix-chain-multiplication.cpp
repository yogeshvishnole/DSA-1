/*

Format or sequence of solving MCM DP problems -
1. Find values of i and j
2. determin the base condition
3. find the k loop scheme
4. calculate final ans from temp ans by applying min/max or any type
of function on temp ans.

Problem Statement: Matrix Chain Multiplication
Given a sequence of matrices, the task is to find the minimum number of scalar
multiplications needed to multiply the matrices together.

The matrices are given in the form of their dimensions, and the multiplication is
associative. The goal is to determine the optimal way to parenthesize the matrix
product so that the total number of scalar multiplications is minimized.

Input:
An array arr[] where arr[i] represents the number of rows of matrix i and arr[i+1] represents the number of columns of matrix i.
Output:
An integer representing the minimum number of scalar multiplications required to
multiply the matrices.

Example 1:
Input:
arr = {2,1,3,4}
Output:
Minimum number of multiplications = 20

Example 2:
Input:
arr = {1,2,3,4,3}
Output:
Minimum number of multiplications = 30
 */

#include <iostream>
#include <climits>
#include <vector>
using namespace std;

// Note i will take i as 0+1'st index of given array
int mcm(int arr[], int i, int j)
{
    // Base condition
    if (i >= j)
    {
        return 0;
    }

    int minCost = INT_MAX;

    // k loop scheme
    for (int k = i; k < j; k++)
    {
        int tempAns = mcm(arr, i, k) + mcm(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        if (tempAns < minCost)
        {
            minCost = tempAns;
        }
    }

    return minCost;
}

class McmMemoized
{
    vector<vector<int>> dp;

    int mcmHelper(int arr[], int i, int j)
    {

        if (i >= j)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int minAns = INT_MAX;
        for (int k = i; k < j; k++)
        {
            int tempAns = mcmHelper(arr, i, k) + mcmHelper(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);
            minAns = min(minAns, tempAns);
        }
        dp[i][j] = minAns;
        return minAns;
    }

public:
    int mcmMemoized(int arr[], int i, int j)
    {
        dp.assign(j+1, vector<int>(j+1, -1));
        return this->mcmHelper(arr, i, j);
    }
};

int main(int argc, char **argv)
{
    // int arr[] = {2, 1, 3, 4};
    int arr[] = {1, 2, 3, 4, 3};
    cout << mcm(arr, 1, 4) << endl;

    McmMemoized *test = new McmMemoized();
    cout << test->mcmMemoized(arr, 1, 4);
}