/*

APPROACH - Are bhai LCS is the common part between two strings right ?
then length of shortest supersequence of two strings will be
= length of string 1 + length of string 2 - lcs of 1 and 2 string

Problem Statement: Length of Shortest Common Supersequence
Given two strings X and Y, the task is to find the length of the Shortest Common
Supersequence (SCS) of X and Y.

A Shortest Common Supersequence (SCS) of two strings is the shortest string that
contains both X and Y as subsequences.

Input:
Two strings X and Y.
Output:
An integer representing the length of the shortest common supersequence of X and Y.

Example 1:
Input:
X = "AGGTAB"
Y = "GXTXAYB"
Output:
Length of SCS = 9

Example 2:
Input:
X = "ABCBDAB"
Y = "BDCAB"
Output:
Length of SCS = 9
 */

#include <iostream>
#include <vector>
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

int shortestCommonSupersequenceLength(string s1, string s2)
{
    return s1.length() + s2.length() - lcs(s1, s2);
}

int main()
{

    // string s1 = "AGGTAB";
    // string s2 = "GXTXAYB";

    // string s1 = "ABCBDAB";
    // string s2 = "BDCAB";

    string s1 = "";
    string s2 = "";

    cout << shortestCommonSupersequenceLength(s1, s2) << endl;
}