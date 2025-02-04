/*

Problem Statement: Sequence Pattern Matching
Given two strings X and Y, the task is to determine whether X is a
subsequence of Y.

A subsequence of a string is formed by deleting some or no characters from
the string while maintaining the relative order of the remaining characters.

Input:
Two strings X and Y.
Output:
A boolean value (true or false) indicating whether X is a subsequence of Y.
Example 1:
Input:
X = "abc"
Y = "adbce"
Output:
true

Example 2:
Input:
X = "axc"
Y = "ahbgdc"
Output:
false

 */

#include <iostream>
#include <vector>
using namespace std;

bool sequencePatternMatching(string s1, string s2)
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

    if (dp[n][m] == s1.length())
    {
        return true;
    }
    return false;
}

int main(int argc, char **argv)
{
    // string X = "abc";
    // string Y = "adbce";

    // string X = "axc";
    // string Y = "ahbgdc";

    string X = "";
    string Y = "";

    cout << sequencePatternMatching(X, Y) << endl;
}