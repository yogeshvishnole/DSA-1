/*

Simple - length of string - lps = number of deletions/number of insertions

Problem Statement

Problem Statement: Minimum Number of Insertions/Deletions to Make a String
Palindrome
Given a string X, the task is to find the minimum number of insertions and
deletions required to transform X into a palindrome.

Input:
A single string X.
Output:
An integer representing the minimum number of insertions and deletions
required to make X a palindrome.

Example 1:
Input:
X = "agbcba"
Output:
Minimum operations = 1

Example 2:
Input:
X = "abcd"
Output:
Minimum operations = 3

 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minDOrIToMakePalindrome(string s)
{
    int n = s.length();
    string s2 = s;
    reverse(s2.begin(), s2.end());

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return (n - dp[n][n]);
}

int main(int argc, char **argv)
{
    // string s = "agbcba";
    string s = "abcd";
    cout << minDOrIToMakePalindrome(s) << endl;
}