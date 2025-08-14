/*
This is a cycle detection and finding the topological sort problem.
It can solved in multiple ways like -
recursive dfs
iterative dfs
kahns algorithm

But I will do it using toughest that is the iterative DFS

Link - https://leetcode.com/problems/course-schedule-ii/?envType=study-plan-v2&envId=top-interview-150
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> topoSort(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> visited(n, 0);
    vector<int> pathVisited(n, 0);
    vector<int> topoSort;

    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            continue;

        stack<pair<int, int>> dfsStack;
        dfsStack.push({i, 0});
        visited[i] = true;
        pathVisited[i] = true;

        while (!dfsStack.empty())
        {
            int curNode = dfsStack.top().first;
            int neibIndex = dfsStack.top().second;
            if (neibIndex < graph[curNode].size())
            {
                int neib = graph[curNode][neibIndex];
                dfsStack.top().second++;
                if (!visited[neib])
                {
                    visited[neib] = true;
                    pathVisited[neib] = true;
                    dfsStack.push({neib, 0});
                }
                else
                {
                    if (pathVisited[neib])
                    {
                        topoSort.clear();
                        return topoSort;
                    }
                }
            }
            else
            {
                dfsStack.pop();
                pathVisited[curNode] = false;
                topoSort.push_back(curNode);
            }
        }
    }
    reverse(topoSort.begin(), topoSort.end());
    return topoSort;
}

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> graph(numCourses);
    for (int i = 0; i < prerequisites.size(); i++)
    {
        graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }
    return topoSort(graph);
}

int main()
{
    vector<vector<int>> prereq = {{1, 0}};
    vector<int> ans = findOrder(2, prereq);
    for (auto el : ans)
    {
        cout << el << " ";
    }
    cout << endl;
}