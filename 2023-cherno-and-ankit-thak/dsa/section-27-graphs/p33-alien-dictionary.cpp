#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
using namespace std;

string toposort(unordered_map<char, vector<char>> &graph)
{
    unordered_map<char, int> visitedMap;
    unordered_map<char, int> pathVisitedMap;

    string topoSort = "";

    for (auto el : graph)
    {
        if (visitedMap[el.first] == 1)
            continue;
        stack<pair<char, int>>
            s;
        s.push({el.first, 0});
        visitedMap[el.first] = true;
        pathVisitedMap[el.first] = true;

        while (!s.empty())
        {
            char curNode = s.top().first;
            int neibIndex = s.top().second;

            if (neibIndex < graph[curNode].size())
            {
                char neib = graph[curNode][neibIndex];
                s.top().second++;

                if (!visitedMap[neib])
                {
                    s.push({neib, 0});
                    visitedMap[neib] = true;
                    pathVisitedMap[neib] = true;
                }
                else
                {
                    if (pathVisitedMap[neib])
                    {
                        return "";
                    }
                }
            }
            else
            {
                topoSort.push_back(curNode);
                s.pop();
                pathVisitedMap[curNode] = false;
            }
        }
    }
    reverse(topoSort.begin(), topoSort.end());
    return (graph.size() == topoSort.size() ? topoSort : "");
}

string findOrder(vector<string> &words)
{
    unordered_map<char, vector<char>> worddg;
    for (int i = 0; i < words.size(); i++)
    {
        for (auto el : words[i])
        {
            worddg[el] = {};
        }
    }
    for (int i = 0; i < words.size() - 1; i++)
    {
        int k = 0;
        int wordsALength = words[i].size();
        int wordsBLength = words[i + 1].size();
        int wordsLength = min(wordsALength, wordsBLength);
        int isWordMatch = false;
        while (k < wordsLength)
        {
            if (words[i][k] == words[i + 1][k])
                k++;
            else
            {
                worddg[words[i][k]].push_back(words[i + 1][k]);
                isWordMatch = true;
                break;
            }
        }
        if (!isWordMatch && (wordsALength > wordsBLength))
            return "";
    }
    string order = toposort(worddg);
    return order;
}

int main()
{
    vector<string> s = {
        "abc", "ab"};
    string ans = findOrder(s);
    cout << ans << endl;
}