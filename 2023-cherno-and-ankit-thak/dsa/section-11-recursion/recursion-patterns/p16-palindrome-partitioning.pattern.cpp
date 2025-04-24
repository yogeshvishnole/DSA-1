/*
In this question the pattern part is how you are storing your final ans
and with the help of backtracking how you are popping out.
*/

#include <iostream>
#include <vector>
using namespace std;

bool isPalin(string s)
{
    int start = 0;
    int end = s.size() - 1;
    while (start < end)
    {
        if (s[start] != s[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void palinPart(string s, int start, vector<vector<string>> &finalAns, vector<string> &curAns)
{
    if (start == s.size())
    {
        finalAns.push_back(curAns);
        return;
    }
    for (int i = start; i < s.size(); i++)
    {
        string curSubStr = s.substr(start, i - start + 1);
        // cout << curSubStr << endl;
        if (isPalin(curSubStr))
        {
            curAns.push_back(curSubStr);
            palinPart(s, i + 1, finalAns, curAns);
            curAns.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> partitions;
    vector<string> curPart;
    palinPart(s, 0, partitions, curPart);
    return partitions;
}

int main(int argc, char **argv)
{
    vector<vector<string>> ans = partition("aab");
    for (auto partitions : ans)
    {
        for (auto substr : partitions)
        {
            cout << substr << "  ";
        }
        cout << endl;
    }
}