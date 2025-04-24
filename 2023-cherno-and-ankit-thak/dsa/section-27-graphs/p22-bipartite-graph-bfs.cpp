/*
We have two colors, if we color the graph with this two colors in such a way that no
two adjacent nodes have same color than the graph is called as the bipartite graph.

A linear graph is always bipartite.alignas
A graph with cycle is bipartite if number of nodes in cycel are even else
it will not bipartite.

Solution approach - simple brute force traversal, we traverse the graph if we reach
to a node with same color, means graph is not
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool bipartiteHelper(vector<vector<int>> &graph, vector<int> &nodeColors, int source)
{
    queue<int> q;
    q.push(source);
    nodeColors[source] = 0;

    while (!q.empty())
    {
        int curNode = q.front();
        q.pop();

        for (int neib : graph[curNode])
        {
            if (nodeColors[neib] == -1)
            {
                nodeColors[neib] = !nodeColors[curNode];
                q.push(neib);
            }
            else if (nodeColors[neib] == nodeColors[curNode])
            {
                return false;
            }
        }
    }

    return true;
}

bool isBipartite(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> nodeColors(n, -1);

    for (int i = 0; i < nodeColors.size(); i++)
    {
        if (nodeColors[i] == -1)
        {
            if (bipartiteHelper(graph, nodeColors, i) == false)
            {
                return false;
            }
        }
    }
    return true;
}

int main() {}