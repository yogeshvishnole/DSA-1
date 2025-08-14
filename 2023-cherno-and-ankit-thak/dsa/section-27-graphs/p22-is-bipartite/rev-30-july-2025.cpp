#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isConnectedBiPartite(vector<vector<int>> &graph, int source, vector<int> &visitedWithColor)
{
    queue<int> bfsQ;
    bfsQ.push(source);
    visitedWithColor[source] = 1;

    while (!bfsQ.empty())
    {
        int curNode = bfsQ.front();
        bfsQ.pop();

        // traverse the neigbours
        for (int el : graph[curNode])
        {
            if (!visitedWithColor[el])
            {
                bfsQ.push(el);
                visitedWithColor[el] = visitedWithColor[curNode] == 1 ? 2 : 1;
            }
            else
            {
                if (visitedWithColor[el] == visitedWithColor[curNode])
                {
                    return false;
                }
            }
        }
    }

    return true;
}

bool isBipartite(vector<vector<int>> &graph)
{
    vector<int> visitedWithColor(graph.size(), 0);

    for (int i = 0; i < visitedWithColor.size(); i++)
    {
        if (!visitedWithColor[i])
        {
            if (isConnectedBiPartite(graph, i, visitedWithColor) == false)
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    vector<vector<int>> notbipartite = {{1, 2, 3},
                                        {0, 2},
                                        {0, 1, 3},
                                        {0, 2}};
    vector<vector<int>> bipartite = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};

    cout << "For Non Bipartite : " << isBipartite(notbipartite) << endl;
    cout << "For  Bipartite : " << isBipartite(bipartite) << endl;
}
