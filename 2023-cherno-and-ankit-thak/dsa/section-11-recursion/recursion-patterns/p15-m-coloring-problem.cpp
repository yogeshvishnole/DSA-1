#include <iostream>
#include <vector>
using namespace std;

bool isMColoringHelper(int n, int M, vector<vector<int>> &adjList, int curNode, vector<int> &nodeColor)
{
    if (curNode == n)
    {
        return true;
    }
    for (int i = 1; i <= M; i++)
    {
        nodeColor[curNode] = i;
        bool isUseColor = true;
        for (int j = 0; j < adjList[curNode].size(); j++)
        {
            if (nodeColor[adjList[curNode][j]] == nodeColor[curNode])
            {
                isUseColor = false;
            }
        }

        if (!isUseColor)
            continue;

        if (isMColoringHelper(n, M, adjList, curNode + 1, nodeColor) == true)
        {
            return true;
        }
        nodeColor[curNode] = 0;
    }
    return false;
}

bool isMColoring(int n, int M, vector<vector<int>> edges)
{
    vector<vector<int>> adjList(n);
    for (int i = 0; i < edges.size(); i++)
    {
        adjList[edges[i][0]].push_back(edges[i][1]);
        adjList[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int> nodeColor(n, 0);
    return isMColoringHelper(n, M, adjList, 0, nodeColor);
}

int main()
{
    int n = 4;
    int M = 3;
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 0},
        {0, 2}};
    cout << endl;
    cout << isMColoring(n, M, edges) << endl
         << endl;
    ;
}