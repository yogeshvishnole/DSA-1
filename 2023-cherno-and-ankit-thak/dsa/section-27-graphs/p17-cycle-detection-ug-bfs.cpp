#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool bfs(vector<vector<int>> &graph, vector<int> &visited, vector<int> &parent, int source)
{
    queue<int> q;
    q.push(source);
    visited[source] = 1;

    while (!q.empty())
    {
        int curNode = q.front();
        q.pop();

        for (auto curN : graph[curNode])
        {
            if (!visited[curN])
            {
                q.push(curN);
                visited[curN] = 1;
                parent[curN] = curNode;
            }
            else
            {
                if (parent[curNode] != curN)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool detectCycle(vector<vector<int>> &graph)
{
    vector<int> visited(graph.size() + 1, 0);
    vector<int> parent(graph.size() + 1, -1);

    for (int i = 1; i < graph.size(); i++)
    {
        if (!visited[i])
        {
            if (bfs(graph, visited, parent, i))
            {
                return true;
            }
        }
    }
}

int main()
{
    vector<vector<int>> graph = {
        {},
        {2, 3},
        {1, 5},
        {1, 4, 6},
        {3},
        {2, 7},
        {3, 7},
        {5, 6}};

    cout << detectCycle(graph) << endl;
}