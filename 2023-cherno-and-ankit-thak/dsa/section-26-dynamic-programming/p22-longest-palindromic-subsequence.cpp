/*

Problem Statement: Longest Palindromic Subsequence
Given a string X, the task is to find the length of the Longest Palindromic Subsequence (LPS)
in X.

A Palindromic Subsequence is a subsequence of X that reads the same forward and backward.

Input:
A single string X.
Output:
An integer representing the length of the longest palindromic subsequence in X.
Example 1:
Input:
X = "bbabcbcab"
Output:
Length of LPS = 7

Example 2:
Input:
X = "agbdba"
Output:
Length of LPS = 5
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lcs(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

int lps(string s)
{
    string s2 = s;
    reverse(s2.begin(), s2.end());
    return lcs(s, s2);
}

int main(int argc, char **argv)
{
    string s1 = "bbabcbcab";
    string s2 = "agbdba";
    cout << lps(s1) << endl;
    cout << lps(s2) << endl;
}