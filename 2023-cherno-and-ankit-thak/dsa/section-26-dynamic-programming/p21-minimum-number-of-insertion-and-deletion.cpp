/*

Bawa approach is simple -

dekho jo dono me common he and alos in order means LCS voh toh hatana hi nhi he so baki jo
not common he string a me unhe delete kardo aur jo LCS ke alawa he b string me unhe delete
kardo.
for a->b
minmum number of insertions = a.length - lcs
minimum number of deletions  = b.length - lcs

Problem Statement
Minimum number of deletions and insertions to transform one string into another
Given two strings ‘str1’ and ‘str2’ of size m and n respectively. The task is to remove/delete
and insert minimum number of characters from/in str1 so as to transform it into str2. It could
be possible that the same character needs to be removed/deleted from one point of str1 and
inserted to some another point.
Example:
Input : str1 = "geeksforgeeks", str2 = "geeks"
Output : Minimum Deletion = 8
         Minimum Insertion = 0

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

pair<int, int> minimumIandDToS1ToS2(string s1, string s2)
{
    int lcsLength = lcs(s1, s2);
    int minD = s1.length() - lcsLength;
    int minI = s2.length() - lcsLength;
    return make_pair(minD, minI);
}

int main(int argc, char **argv)
{
    // string s1 = "geeksforgeeks";
    // string s2 = "geeks";

    string s1 = "heap";
    string s2 = "pea";

    auto ans = minimumIandDToS1ToS2(s1, s2);
    cout << "D -> " << ans.first << " I ->  " << ans.second << endl;
}