#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> shortestPath(int V, int E, vector<vector<int>> &edges)
{
    // lets build the adjacency list
    vector<vector<pair<int, int>>> graph(V);

    for (int i = 0; i < edges.size(); i++)
    {
        graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
    }

    vector<int> visited(V);
    vector<int> paths(V, -1);

    paths[0] = 0;

    for (int i = 0; i < V; i++)
    {
        if (visited[i])
            continue;

        stack<pair<int, int>> dfsStack;
        dfsStack.push({i, 0});
        visited[i] = 1;

        while (!dfsStack.empty())
        {
            int curNode = dfsStack.top().first;
            int curPathLength = dfsStack.top().second;
            dfsStack.pop();

            for (auto neib : graph[curNode])
            {
                if (!visited[neib.first])
                {
                    visited[neib.first] = true;
                    dfsStack.push({neib.first, curPathLength + neib.second});
                    if (paths[neib.first] == -1 || paths[neib.first] > (curPathLength + neib.second))
                    {
                        paths[neib.first] = curPathLength + neib.second;
                    }
                }
                else
                {
                    if (paths[neib.first] == -1 || paths[neib.first] > (curPathLength + neib.second))
                    {
                        paths[neib.first] = curPathLength + neib.second;
                    }
                }
            }
        }
    }
    return paths;
}

int main()
{
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 2, 1},
        {0, 3, 3},
        {2, 3, 1}};
    vector<int>
        paths = shortestPath(4, 4, edges);

    for (auto el : paths)
    {
        cout << el << " ";
    }
    cout << endl;
}