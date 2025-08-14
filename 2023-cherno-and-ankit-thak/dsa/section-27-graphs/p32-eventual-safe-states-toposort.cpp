/*
This is a very interesting problem to understand the toposort in depth and how its usecases
can be derived in multiple scenarios.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> eventualSafeNodes(int V, vector<int> adj[])
{
    // reverse the edges to make the indegree of terminal nodes 0
    // then we can run kahns algo on all  the terminal nodes to find the toposorts
    // of all the terminal nodes, the edges in the toposort of terminal nodes will only be the safe
    // nodes

    vector<int> adjRev[V];
    vector<int> indegree(V);
    queue<int> topoQ;
    vector<int> topoSort;

    for (int i = 0; i < V; i++)
    {
        for (auto el : adj[i])
        {
            adjRev[el].push_back(i);
            indegree[i]++;
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            topoQ.push(i);
        }
    }
    while (!topoQ.empty())
    {
        int curNode = topoQ.front();
        topoSort.push_back(curNode);

        topoQ.pop();
        for (auto neib : adjRev[curNode])
        {
            indegree[neib]--;
            if (indegree[neib] == 0)
            {
                topoQ.push(neib);
            }
        }
    }

    sort(topoSort.begin(), topoSort.end());
    return topoSort;
}

int main() {}