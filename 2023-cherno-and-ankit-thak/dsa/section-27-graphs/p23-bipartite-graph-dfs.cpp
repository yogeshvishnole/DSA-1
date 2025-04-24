#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool isBipartiteHelper(vector<vector<int>> &graph, vector<int> &nodeColors, int source)
{
    stack<int> s;
    s.push(source);
    nodeColors[source] = 0;

    while (!s.empty())
    {
        int curNode = s.top();
        s.pop();

        for (int neib : graph[curNode])
        {
            if (nodeColors[neib] == -1)
            {
                nodeColors[neib] = !nodeColors[curNode];
                s.push(neib);
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
            if (isBipartiteHelper(graph, nodeColors, i) == false)
            {
                return false;
            }
        }
    }
    return true;
}

int main() {}