#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfsTopoSort(vector<vector<int>> &graph, vector<int> &visited, stack<int> &ansStack, int source)
{
    visited[source] = 1;

    for (auto neigbour : graph[source])
    {
        if (!visited[neigbour])
        {
            dfsTopoSort(graph, visited, ansStack, neigbour);
        }
    }

    ansStack.push(source);
}

vector<int> topologicalSort(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> visited(n);
    stack<int> ansStack;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfsTopoSort(graph, visited, ansStack, i);
        }
    }

    vector<int> ans;

    while (!ansStack.empty())
    {
        ans.push_back(ansStack.top());
        ansStack.pop();
    }
    return ans;
}

int main()
{
}