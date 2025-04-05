/*
Same approach as cycle detection using the bfs that you will store the parent of the current element
if any of neigbour of current element that is already visited and not equal to parent of curNode
means there is cycle in the graph
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool dfs(vector<vector<int>> &graph, vector<int> &visited, int source)
{
    // pair elements  <node,parent>
    stack<pair<int, int>> s;
    s.push({source, -1});
    visited[source] = 1;

    while (!s.empty())
    {
        int curNode = s.top().first;
        int parentNode = s.top().second;
        s.pop();

        for (auto neib : graph[curNode])
        {
            if (!visited[neib])
            {
                s.push({neib, curNode});
                visited[neib] = 1;
            }
            else
            {
                if (neib != parentNode)
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
    vector<int> visited(graph.size(), 0);
    for (int i = 0; i < graph.size(); i++)
    {
        if (!visited[i])
        {
            if (dfs(graph, visited, i))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{

    // graph without cycle

    vector<vector<int>> graph1 = {
        {1, 3},
        {0, 2},
        {1, 4},
        {0},
        {2}};

    // graph with cycle
    cout << detectCycle(graph1) << endl;

    vector<vector<int>> graph2 = {
        {1, 2},
        {0, 2},
        {0, 1}};

    cout << detectCycle(graph2) << endl;

    vector<vector<int>> graph = {
        {},
        {2, 3},
        {1, 5},
        {1, 4, 6},
        {3},
        {2},
        {3, 7},
        {6}};

    cout << detectCycle(graph) << endl;
}
