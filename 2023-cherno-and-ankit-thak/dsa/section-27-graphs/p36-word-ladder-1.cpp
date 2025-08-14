/*
 */

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
using namespace std;

int wordLadderLength(string startWord, string targetWord,
                     vector<string> &wordList)
{
    // put the wordList in a set
    set<string> wordSet;
    for (int i = 0; i < wordList.size(); i++)
    {
        wordSet.insert(wordList[i]);
    }

    queue<pair<string, int>> wordQueue;

    wordQueue.push({startWord, 1});
    wordSet.erase(startWord);

    while (!wordQueue.empty())
    {
        string curWord = wordQueue.front().first;
        int curLadderLength = wordQueue.front().second;
        wordQueue.pop();

        for (int i = 0; i < curWord.size(); i++)
        {
            char curChar = curWord[i];
            for (int charCount = 0; charCount < 26; charCount++)
            {
                if (('a' + charCount) == curChar)
                    continue;
                curWord[i] = 'a' + charCount;
                if (wordSet.find(curWord) != wordSet.end())
                {
                    if (curWord == targetWord)
                        return curLadderLength + 1;
                    wordQueue.push({curWord,
                                    curLadderLength + 1});
                    wordSet.erase(curWord);
                    curWord[i] = curChar;
                }
            }
            curWord[i] = curChar;
        }
    }
    return 0;
}

int main()
{
    // string startWord = "der";
    // string targetWord = "dfs";
    // vector<string> wordList =
    //     {
    //         "des",
    //         "der",
    //         "dfr",
    //         "dgt",
    //         "dfs",
    //     };
    string startWord = "a";
    string targetWord = "c";
    vector<string> wordList =
        {
            "a", "b", "c"};
    cout
        << wordLadderLength(startWord, targetWord, wordList) << endl;
}