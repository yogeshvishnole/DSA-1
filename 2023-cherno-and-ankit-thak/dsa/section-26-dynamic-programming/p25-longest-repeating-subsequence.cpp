/*
Boss LCS of same string with one more condition do not 1+ if i!=j

Problem Statement -

Given a string X, the task is to find the length of the Longest Repeating
Subsequence (LRS) in X.

A Repeating Subsequence is a subsequence that appears at least twice in the
string, but the repeated occurrences must not be at the same positions.

Input:
A single string X.
Output:
An integer representing the length of the longest repeating subsequence in X.

Example 1:
Input:
X = "AABEBCDD"
Finding the Longest Repeating Subsequence (LRS):
A subsequence is a sequence derived by deleting some or no elements from a
string while maintaining the relative order of the remaining elements.
The Longest Repeating Subsequence (LRS) is a subsequence that appears at
least twice in the string but at different positions.
For "AABEBCDD", the longest repeating subsequence is "ABD".

"AABEBCDD"
"ABD" appears more than once in different positions.
The length of "ABD" is 3.
Output:
Length of LRS = 3

Example 2:
Input:
X = "axxxy"
Finding the Longest Repeating Subsequence (LRS):
The longest repeating subsequence in "axxxy" is "xx".

"axxxy"

"xx" appears more than once at different indices.
The length of "xx" is 2.
Output:
Length of LRS = 2
 */

#include <iostream>
#include <vector>
using namespace std;

int longestRepeatingSubsequence(string s)
{
    int n = s.length();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if ((s[i - 1] == s[j - 1]) && i != j)
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][n];
}

int main(int argc, char **argv)
{
    // string s = "AABEBCDD";
    string s = "axxxy";
    cout << longestRepeatingSubsequence(s) << endl;
}