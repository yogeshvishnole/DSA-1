#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

/*
NOTES for this time.

I start solving it using backtracking then I realize I have go through all the solutions or all the
paths from startWord to targetWord if I use backtracking to find the smallest path.
Then I get the idea of BFS which gives the min path in one go in a directed graph. SO I applied it and it gives
the path.
As per my evaluation if all paths are required then we may need to go through the backtracking soln -> not sure.
*/

class Solution
{
public:
    vector<vector<string>> findSequences(string startWord, string targetWord,
                                         vector<string> &wordList)
    {
        vector<vector<string>> ans;
        unordered_map<string, bool> wordListMap;

        for (string word : wordList)
        {
            wordListMap[word] = true;
        }

        unordered_map<string, bool> isVisited;
        queue<pair<string, vector<string>>> bfsQ;

        bfsQ.push({startWord, {startWord}});

        while (!bfsQ.empty())
        {
            string currentWord = bfsQ.front().first;
            vector<string> curPath = bfsQ.front().second;
            bfsQ.pop();

            for (int i = 0; i < currentWord.size(); i++)
            {
                char startChar = currentWord[i];
                for (int j = 0; j < 26; j++)
                {
                    currentWord[i] = 'a' + j;
                    if (startChar == currentWord[i] || !wordListMap[currentWord] || (find(curPath.begin(), curPath.end(), currentWord) != curPath.end()))
                    {
                        continue;
                    }
                    else
                    {
                        if (targetWord == currentWord)
                        {
                            curPath.push_back(targetWord);
                            if (ans.size() > 0)
                            {
                                if (ans[0].size() == curPath.size())
                                {
                                    ans.push_back(curPath);
                                }
                            }
                            else
                            {

                                ans.push_back(curPath);
                            }
                        }
                        else
                        {

                            if (ans.size() > 0)
                            {
                                continue;
                            }
                            curPath.push_back(currentWord);

                            bfsQ.push({currentWord, curPath});
                            curPath.pop_back();
                            isVisited[currentWord] = true;
                        }
                    }
                }
                currentWord[i] = startChar;
            }
        }

        return ans;
    }
};

int main()
{

    string startWord = "bbccc";
    vector<string> wordList = {
        "ccbcb", "acbcb", "abbab", "cbccc", "cacba", "accbc", "ccbab", "abcac", "bcccc", "aaacc",
        "bbbcb", "bcbca", "aabcb", "aacba", "cbbcc", "cccca", "bccac", "ccbbb", "caccb", "ccabb",
        "bccbb", "baabc", "ababa", "cbbab", "bbcaa", "bbbaa", "aacbb", "caaba", "ccaab", "bccab",
        "cbaac", "bccaa", "abcab", "cbcac", "bbabc", "bbccc", "acccb", "abacb", "bbcbc", "acaac",
        "ccbba", "ccaca", "acaca", "ccabc", "ccbca", "bacab", "bcaca", "aacbc", "bbaac", "cbaba",
        "abcaa", "cabab", "cbcbc", "acbac", "cabba", "cabaa", "cacaa", "bacbb", "abbac", "aaacb",
        "aabbb", "bbcac", "bcabb", "abbaa", "bbbbb", "acaab", "acbaa", "aaabb", "cbcaa", "ccacb",
        "aaaba", "baaab", "ccccc", "acabc", "cbaab", "cccbc", "bacba", "bbccc", "cccca"};
    string targetWord = "cccca";

    Solution sol;
    vector<vector<string>> ans = sol.findSequences(startWord, targetWord, wordList);

    for (auto ansList : ans)
    {
        for (auto word : ansList)
        {
            cout << word << " ";
        }
        cout << endl;
    }
}