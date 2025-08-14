/*
Its simply a cycle detection problem.
*/

#include <iostream>
#include <vector>
using namespace std;

// find the cycle in graph using dfs
bool dfsDg(vector<vector<int>> &graph, vector<int> &visited, vector<int> &pathVisited, int source)
{
    visited[source] = 1;
    pathVisited[source] = 1;

    for (auto neib : graph[source])
    {
        if (!visited[neib])
        {

            if (dfsDg(graph, visited, pathVisited, neib) == true)
            {
                return true;
            }
        }
        else
        {
            if (pathVisited[neib])
                return true;
        }
    }
    pathVisited[source] = 0;
    return false;
}

bool cycleDgDetect(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> visited(n, 0);
    vector<int> pathVisited(n, 0);

    for (int i = 0; i < visited.size(); i++)
    {
        if (!visited[i])
        {
            if (dfsDg(graph, visited, pathVisited, i) == true)
            {
                return true;
            }
        }
    }
    return false;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> graph(numCourses);
    for (int i = 0; i < prerequisites.size(); i++)
    {
        graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }
    return !cycleDgDetect(graph);
}

int main() {}