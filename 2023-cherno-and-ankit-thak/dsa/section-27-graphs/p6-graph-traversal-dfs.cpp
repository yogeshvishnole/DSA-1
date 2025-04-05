#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;

void dfs(unordered_map<int, vector<int>> &graph, int source)
{
    int n = graph.size();
    vector<int> visited(n + 1, 0);

    stack<int> s;
    s.push(source);
    visited[source] = 1;

    while (!s.empty())
    {
        int curVertex = s.top();
        s.pop();

        cout << curVertex << " ";

        for (int nbr : graph[curVertex])
        {
            if (!visited[nbr])
            {
                s.push(nbr);
                visited[nbr] = 1;
            }
        }
    }
}

void dfsRecursiveHelper(unordered_map<int, vector<int>> &graph, int source, vector<int> &visited)
{
    if (visited[source])
    {
        return;
    }
    cout << source << " ";
    visited[source] = 1;
    for (int nbr : graph[source])
    {
        dfsRecursiveHelper(graph, nbr, visited);
    }
}

void dfsRecursive(unordered_map<int, vector<int>> &graph, int source)
{
    int n = graph.size();
    vector<int> visited(n + 1, 0);

    dfsRecursiveHelper(graph, source, visited);
}

int main()
{
    vector<vector<int>> edgeList = {
        {1, 0},
        {0, 5},
        {0, 2},
        {3, 2},
        {3, 4}};

    unordered_map<int, vector<int>> graph;

    for (int i = 0; i < edgeList.size(); i++)
    {
        int a = edgeList[i][0], b = edgeList[i][1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(graph, 0);
    cout << endl;
    dfsRecursive(graph, 0);
}