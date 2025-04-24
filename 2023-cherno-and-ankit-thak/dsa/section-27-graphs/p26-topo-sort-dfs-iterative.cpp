/*
DAG - Directed Acyclic Graph.
DCG - Directed Cyclic Graph.

DAG's has the feature of topological sorting, that DCG's doesn't have.

What is topological sorting ?
Topological sorting is the linear ordering of vertices in a Directed Acyclic Graph (DAG) such that
for every directed edge U → V, vertex U appears before V in the ordering.

Two common approaches:

Kahn’s Algorithm (BFS-based):

Count in-degrees.

Start with nodes having 0 in-degree.

Remove them and reduce in-degrees of neighbors.

DFS-based:

Perform DFS and push nodes to a stack after exploring their neighbors.

Reverse the stack for the topological order.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> topologicalSort(
    vector<vector<int>> &graph)
{
    int n = graph.size();
    stack<int> st;
    vector<int> topSort;
    vector<int> visited(n, 0);

    for (int i = 0; i < n; i++)
    {

        if (visited[i])
            continue;

        stack<pair<int, int>> dfs;
        dfs.push({i, 0});
        visited[i] = 1;

        while (!dfs.empty())
        {
            int curNode = dfs.top().first;
            int neibIndex = dfs.top().second;

            if (neibIndex < graph[curNode].size())
            {
                int neighbour = graph[curNode][neibIndex];
                dfs.top().second++;
                if (!visited[neighbour])
                {
                    visited[neighbour] = 1;
                   
                    dfs.push({neighbour, 0});
                }
            }
            else
            {
                topSort.push_back(curNode);
                dfs.pop();
            }
        }
    }
    reverse(topSort.begin(), topSort.end());
    return topSort;
}
vector<int> topoSort(int V, vector<vector<int>> &edges)
{

    vector<vector<int>> graph(V);

    // edges to adjacency list
    for (int i = 0; i < edges.size(); i++)
    {
        graph[edges[i][0]].push_back(edges[i][1]);
    }

    return topologicalSort(graph);
}

int main()
{
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}};
    vector<int> ans = topoSort(4, edges);
    for (auto el : ans)
    {
        cout << el << " ";
    }
    cout << endl;
}