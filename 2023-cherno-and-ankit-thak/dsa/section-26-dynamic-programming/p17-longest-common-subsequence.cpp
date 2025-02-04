/*

Problem Statement: Longest Common Subsequence (LCS)

Given two strings X and Y, find the length of the longest subsequence that is
common in both strings. A subsequence is a sequence that appears in the same
order but not necessarily contiguous.

Example 1
Input:
X = "AGGTAB"
Y = "GXTXAYB"
Output:
4
Explanation:
The longest common subsequence is "GTAB" of length 4.

Example 2
Input:
X = "ABCBDAB"
Y = "BDCAB"
Output:
4
Explanation:
The longest common subsequence is "BCAB" or "BDAB" of length 4.

 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int lcsRecursive(string s1, string s2, int n, int m)
{

    // Base condtion using smallest valid inputs
    if (n == 0 || m == 0)
    {
        return 0;
    }

    // Choice diagram implementation
    if (s1[n - 1] == s2[m - 1])
    {
        return 1 + lcsRecursive(s1, s2, n - 1, m - 1);
    }
    else
    {
        return max(lcsRecursive(s1, s2, n, m - 1), lcsRecursive(s1, s2, n - 1, m));
    }
}
class LcsMemoized
{
    vector<vector<int>> memo;
    int lcsHelper(string s1, string s2, int n, int m)
    {
        if (n == 0 || m == 0)
            return 0;

        if (memo[n][m] != -1)
        {
            return memo[n][m];
        }

        if (s1[n - 1] == s2[m - 1])
        {
            memo[n][m] = 1 + lcsHelper(s1, s2, n - 1, m - 1);
        }
        else
        {
            memo[n][m] = max(lcsHelper(s1, s2, n - 1, m), lcsHelper(s1, s2, n, m - 1));
        }
        return memo[n][m];
    }

public:
    int
    lcsMemoized(string s1, string s2, int n, int m)
    {
        memo.assign(n + 1, vector<int>(m + 1, -1));
        return lcsHelper(s1, s2, n, m);
    }
};

int lcsBottomUpDP(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();

    // initialization
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
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[n][m];
}

int main(int argc, char **argv)
{
    // string s1 = "AGGTAB";
    // string s2 = "GXTXAYB";

    // string s1 = "ABCBDAB";
    // string s2 = "BDCAB";

    string s1 = "";
    string s2 = "";

    cout << lcsRecursive(s1, s2, s1.length(), s2.length()) << endl;
    LcsMemoized *lcs = new LcsMemoized();
    cout << lcs->lcsMemoized(s1, s2, s1.length(), s2.length()) << endl;
    cout << lcsBottomUpDP(s1, s2) << endl;
}