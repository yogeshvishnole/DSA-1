/*
Problem Statement: Print Longest Common Subsequence
Given two strings X and Y, the task is to print the Longest Common Subsequence
(LCS) between them.

The Longest Common Subsequence (LCS) of two sequences is the longest subsequence
that appears in both sequences in the same order, but not necessarily
consecutively.

Input:
Two strings X and Y.
Output:
A string representing the longest common subsequence of X and Y.

Example 1:
Input:
X = "AGGTAB"
Y = "GXTXAYB"
Output:
LCS = "GTAB"

Example 2:
Input:
X = "ABCBDAB"
Y = "BDCAB"
Output:
LCS = "BDAB"
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// this func is not much space optimized because here we are storing the
// 2d array of strings lets see second way in below func.
string getLCS(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();

    // initialization
    vector<vector<string>> dp(n + 1, vector<string>(m + 1, ""));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + s1[i - 1];
            }
            else
            {
                string substr1 = dp[i - 1][j];
                string substr2 = dp[i][j - 1];
                if (substr1.length() >= substr2.length())
                {
                    dp[i][j] = substr1;
                }
                else
                {
                    dp[i][j] = substr2;
                }
            }
        }
    }

    return dp[n][m];
}

// 2nd way of printing LCS, in this way we just backtrack
string lcs(string s1, string s2)
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

    int i = n;
    int j = m;
    string ans = "";
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            ans.push_back(s1[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] >= dp[i][j - 1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(int argc, char **argv)
{
    // string s1 = "";
    // string s2 = "";

    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";

    // string s1 = "ABCBDAB";
    // string s2 = "BDCAB";

    cout << getLCS(s1, s2) << endl;
    cout << lcs(s1, s2) << endl;
}