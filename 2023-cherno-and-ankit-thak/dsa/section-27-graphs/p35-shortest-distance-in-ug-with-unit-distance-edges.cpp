/*
BFS is the best approach here, because BFS will traverse level wise, so if a node has two paths from
the source node, the BFS will reach the node from shorter path first and it will not traverse at the
another level because node is already visited. In DFS node can be traversed either from the shorter
path or can be from the larger path not in our control.So BFS is best as per me. Lets implement.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to find the shortest path from source to all other nodes
vector<int> shortestPath(vector<vector<int>> &adj, int src)
{
    int numberOfVertices = adj.size();
    vector<int> shortDists(numberOfVertices, -1);
    vector<int> visited(numberOfVertices, 0);
    queue<pair<int, int>> q;

    q.push({src, 0});
    visited[src] = 1;
    shortDists[src] = 0;

    while (!q.empty())
    {
        int curNode = q.front().first;
        int curLevel = q.front().second;
        q.pop();

        for (auto neib : adj[curNode])
        {
            if (!visited[neib])
            {
                visited[neib] = 1;
                q.push({neib, curLevel + 1});
                shortDists[neib] = curLevel;
            }
        }
    }
    return shortDists;
}