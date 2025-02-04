/*

Relate it to print LCS jaha pe kuch nhi print karate ab vha dono karao.



Problem Statement: Print Shortest Common Supersequence
Given two strings X and Y, the task is to find and print the Shortest Common
Supersequence (SCS) of X and Y.

A Shortest Common Supersequence (SCS) of two strings is the shortest string
that contains both X and Y as subsequences.

Input:
Two strings X and Y.
Output:
A string representing the shortest common supersequence of X and Y.

Example 1:
Input:
X = "AGGTAB"
Y = "GXTXAYB"
Output:
SCS = "AGXGTXAYB"


Example 2:
Input:
X = "ABCBDAB"
Y = "BDCAB"
Output:
SCS = "ABDCBDAB"
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string printShortestCommonSupersequence(string s1, string s2)
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

    int i = n,
        j = m;

    string ans = "";

    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            ans.push_back(s1[i - 1]);
            i--;
            j--;
        }
        else if (dp[i][j - 1] >= dp[i - 1][j])
        {
            ans.push_back(s2[j - 1]);
            j--;
        }
        else
        {
            ans.push_back(s1[i - 1]);
            i--;
        }
    }

    while (i > 0)
    {
        ans.push_back(s1[i - 1]);
        i--;
    }

    while (j > 0)
    {
        ans.push_back(s2[j - 1]);
        j--;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main(int argc, char **argv)
{
    // string s1 = "AGGTAB";
    // string s2 = "GXTXAYB";

    // string s1 = "ABCBDAB";
    // string s2 = "BDCAB";

    string s1 = "";
    string s2 = "";

    cout << printShortestCommonSupersequence(s1, s2) << endl;
}