/*
If we analyze the recursion tree of the p1, we will find that the number of repeated
recursive calls is lot, means we repeatedly calculate the same thing again and again which
increases the time complexity of  the problem.

so what we will do is store the results of the function calls in an array and utilize
them later.

Now what should be the dimensions of the 2D array that will be used for memoization
simple enough what are the variable arguments in our function.
a.) size of the array
b.) capacity

So all the permutations of n and W can stored in a n*W array, so the dimensions of the
memoization array will be n*W
 */

#include <iostream>

using namespace std;

int knapsackMemoization[1001][1001];

int knapsack(int wt[], int val[], int W, int n)
{
    // Base condtion code
    if (n == 0 || W == 0)
    {
        return 0;
    }

    if (knapsackMemoization[n][W] != -1)
    {
        return knapsackMemoization[n][W];
    }
    // Choice diagram implementation
    // Choice diagram implementation
    if (wt[n - 1] <= W)
    {
        knapsackMemoization[n][W] = max(val[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1), knapsack(wt, val, W, n - 1));
        return knapsackMemoization[n][W];
    }
    else if (wt[n - 1] > W)
    {
        knapsackMemoization[n][W] = knapsack(wt, val, W, n - 1);
        return knapsackMemoization[n][W];
    }
}

int main(int argc, char **argv)
{

    // initialize the memoization array
    for (int i = 0; i < 1001; ++i)
    {
        fill(knapsackMemoization[i], knapsackMemoization[i] + 1001, -1); // Fill each row with -1
    }

    // int wt[] = {};
    // int val[] = {};
    // int W = 0;
    // int n = 0;

    int wt[] = {4, 5, 1};
    int val[] = {1, 2, 3};
    int W = 4;
    int n = 3;

    // int wt[] = {4, 5, 6};
    // int val[] = {1, 2, 3};
    // int W = 3;
    // int n = 3;

    cout << knapsack(wt, val, W, n) << endl;
}
