#include <iostream>
using namespace std;

int knapsack(int wt[], int val[], int W, int n)
{
    int t[n + 1][W + 1];

    // initialization -> derive it from base condtion
    for (int i = 0; i <= n; i++)
    {
        t[i][0] = 0;
    }
    for (int j = 0; j <= W; j++)
    {
        t[0][j] = 0;
    }

    // iterative implementation of the choice diagram
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (wt[i - 1] <= j)
            {
                t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
            }
            else if (wt[i - 1] > j)
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[n][W];
}

int main(int argc, char **argv)
{
    // int wt[] = {};
    // int val[] = {};
    // int W = 0;
    // int n = 0;

    // int wt[] = {4, 5, 1};
    // int val[] = {1, 2, 3};
    // int W = 4;
    // int n = 3;

    int wt[] = {4, 5, 6};
    int val[] = {1, 2, 3};
    int W = 3;
    int n = 3;

    cout << knapsack(wt, val, W, n) << endl;
}