/*
Approach is simple, but here you have to see if the element is earlier visited in the same recursion
path then only the directed graph have the cycle.
*/
#include <iostream>
#include <vector>
using namespace std;

bool detectCycleDfsHelper(vector<vector<int>> &graph, vector<int> &visited, vector<int> &pathVisited, int source)
{
    visited[source] = 1;
    pathVisited[source] = 1;

    for (int neib : graph[source])
    {
        if (!visited[neib])
        {
            if (detectCycleDfsHelper(graph, visited, pathVisited, neib) == true)
            {
                return true;
            }
        }
        else
        {
            if (pathVisited[neib])
            {
                return true;
            }
        }
    }
    pathVisited[source] = 0;
    return false;
}

bool detetCycleDirectedG(vector<vector<int>> &graph)
{
    vector<int> visited(graph.size(), 0);
    vector<int> pathVisited(graph.size(), 0);

    for (int i = 0; i < graph.size(); i++)
    {
        if (!visited[i])
        {
            if (detectCycleDfsHelper(graph, visited, pathVisited, i) == true)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> graph = {
        {1, 2},
        {2},
        {}};
    cout << detetCycleDirectedG(graph) << endl;
}