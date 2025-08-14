#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
using namespace std;

string topoSort(unordered_map<char, set<char>> &dag)
{
    string toposort = "";
    unordered_map<char, int> indegree;

    for (auto neibList : dag)
    {
        if (!indegree[neibList.first])
        {
            indegree[neibList.first] = 0;
        }
        for (char el : neibList.second)
        {
            indegree[el]++;
        }
    }

    queue<char> bfsQ;

    for (auto el : indegree)
    {
        if (el.second == 0)
        {
            bfsQ.push(el.first);
        }
    }

    while (!bfsQ.empty())
    {
        char el = bfsQ.front();
        toposort += el;
        bfsQ.pop();

        for (auto neib : dag[el])
        {
            indegree[neib]--;
            if (indegree[neib] == 0)
            {
                bfsQ.push(neib);
            }
        }
    }
    return toposort.size() < indegree.size() ? "" : toposort;
}

string findOrder(vector<string> &words)
{
    unordered_map<char, set<char>> dag;

    for (auto word : words)
    {
        for (char letter : word)
        {
            dag[letter] = {};
        }
    }

    for (int i = 1; i < words.size(); i++)
    {
        int j = 0;
        int wordIsize = words[i].size();
        int wordILessSize = words[i - 1].size();
        int minWordLength = min(wordIsize, wordILessSize);
        int isWordMatch = false;
        while (j < minWordLength)
        {
            if (words[i][j] == words[i - 1][j])
                j++;
            else
            {
                dag[words[i - 1][j]].insert(words[i][j]);
                isWordMatch = true;
                break;
            }
        }
        if (!isWordMatch && (wordILessSize > wordIsize))
            return "";
    }
    return topoSort(dag);
}

int main()
{

    vector<string> words = {"abc", "ab"};
    cout << findOrder(words) << endl;
    unordered_map<char, int> indegree;
    indegree['t'] = 0;
    cout << indegree.size() << endl;
}