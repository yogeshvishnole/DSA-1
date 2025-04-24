/* 
Very interesting problem, read it and solve it again and see how you can use the modulus mathematics
effectively here in this problem, this hard problem keep its root in the simple problem
sum of digits of a number.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// void getPermutationHelper(string s, int k, vector<string> &ans, int start, int &count)
// {
//     if (start == s.size())
//     {
//         ans.push_back(s);
//     }

//     for (int i = start; i < s.size(); i++)
//     {
//         swap(s[start], s[i]);
//         getPermutationHelper(s, k, ans, start + 1, count);
//         swap(s[start], s[i]);
//     }
// }

// string getPermutation(int n, int k)
// {
//     string s = "";
//     for (int i = 1; i <= n; i++)
//     {
//         s += '0' + i;
//     }
//     vector<string> ans;
//     int count = 0;
//     getPermutationHelper(s, k, ans, 0, count);

//     sort(ans.begin(), ans.end());

//     return ans[k - 1];
// }

int fact(int n)
{
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans *= i;
    }
    return ans;
}

void getPermutationHelper(string s, string &ans, int k, int n)
{
    if (s.length() == 0)
    {
        return;
    }
    int multiples = fact(n - 1);
    int ansPartIndex = (k) / multiples;
    int newK = (k) % multiples;
    ans += s[ansPartIndex];
    s.erase(ansPartIndex, 1);
    getPermutationHelper(s, ans, newK, n - 1);
}

string getPermutation(int n, int k)
{
    string s = "";
    for (int i = 1; i <= n; i++)
    {
        s += '0' + i;
    }
    string ans = "";
    getPermutationHelper(s, ans, k - 1, n);
    return ans;
}

int main()
{
    cout << getPermutation(3, 5);
}