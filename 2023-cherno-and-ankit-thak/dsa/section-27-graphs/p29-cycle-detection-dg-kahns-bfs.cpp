#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool kahnsCycleDetection(vector<vector<int>> &graph)
{
    vector<int> topoSort;
    int n = graph.size();
    vector<int> indegrees(n, 0);

    for (int i = 0; i < n; i++)
    {
        for (auto el : graph[i])
        {
            indegrees[el]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < indegrees.size(); i++)
    {
        if (indegrees[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int curNode = q.front();
        topoSort.push_back(curNode);
        q.pop();

        for (auto el : graph[curNode])
        {
            indegrees[el]--;
            if (indegrees[el] == 0)
            {
                q.push(el);
            }
        }
    }
    return topoSort.size() != n;
}

int main() {}