/*

Sorted he bhai
min deletion = string length - lps(s)

Problem Statemet
Minimum number of deletions to make a string palindrome
Given a string of size ‘n’. The task is to remove or delete minimum number of characters from the string so that the resultant string is palindrome.
Examples :

Input : aebcbda
Output : 2
Remove characters 'e' and 'd'
Resultant string will be 'abcba'
which is a palindromic string
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

int minDToPalin(string s)
{
    return s.length() - lps(s);
}

int main(int argc, char **argv)
{
    string s1 = "aebcbda";
    cout << minDToPalin(s1) << endl;
}