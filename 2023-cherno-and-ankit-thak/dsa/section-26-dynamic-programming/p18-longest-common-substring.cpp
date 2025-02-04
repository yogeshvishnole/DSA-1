/*

Very special DP question because in this problem I observed that dp[i][j] does
not represent the answer instead it represents the length of substring ending
at position i and j.

Problem Statement: Longest Common Substring
Given two strings X and Y, find the length of the longest contiguous substring
that is common in both strings. A substring is a sequence of characters that
appear contiguously in the same order in both strings.

Example 1

Input:
X = "ABABC"
Y = "BABCAC"
Output:
4
Explanation:
The longest common substring is "BABC" of length 4.

Example 2
Input:
X = "abcdef"
Y = "zbcdf"
Output:
3
Explanation:
The longest common substring is "bcd" of length 3.
 */

#include <iostream>
#include <vector>
using namespace std;

int lcSubstring(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    int maxLength = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                maxLength = max(maxLength, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return maxLength;
}

int main(int argc, char **argv)
{
    // string s1 = "";
    // string s2 = "";

    // string s1 = "ABABC";
    // string s2 = "BABCAC";

    string s1 = "abcdef";
    string s2 = "zbcdf";

    cout << lcSubstring(s1, s2) << endl;
}