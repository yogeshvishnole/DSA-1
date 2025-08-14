#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
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
    int wordLadderLength(string startWord, string targetWord,
                         vector<string> &wordList)
    {
        unordered_map<string, bool> wordListMap;

        for (string word : wordList)
        {
            wordListMap[word] = true;
        }

        unordered_map<string, bool> isVisited;
        queue<pair<string, int>> bfsQ;

        bfsQ.push({startWord, 1});
        isVisited[startWord] = true;

        while (!bfsQ.empty())
        {
            string currentWord = bfsQ.front().first;
            int level = bfsQ.front().second;
            bfsQ.pop();

            for (int i = 0; i < currentWord.size(); i++)
            {
                char startChar = currentWord[i];
                for (int j = 0; j < 26; j++)
                {
                    currentWord[i] = 'a' + j;
                    if (startChar == currentWord[i] || !wordListMap[currentWord] || isVisited[currentWord])
                    {
                        continue;
                    }
                    else
                    {
                        if (targetWord == currentWord)
                        {
                            return level + 1;
                        }
                        else
                        {
                            bfsQ.push({currentWord, level + 1});
                            isVisited[currentWord] = true;
                        }
                    }
                }
                currentWord[i] = startChar;
            }
        }
        return 0;
    }
};

int main()
{

    string startWord = "der";
    vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
    string targetWord = "dfs";

    Solution sol;
    cout << sol.wordLadderLength(startWord, targetWord, wordList) << endl;
}