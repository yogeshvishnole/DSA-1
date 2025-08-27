/*
A very good question, limited application on questions having mod of answer for
further calculations.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9 + 7;

int minimumMultiplications(vector<int> &arr, int start, int end)
{
    const int numOfNodes = 100000;
    vector<int> minDist(numOfNodes, INF);

    queue<pair<int, int>> bfsQueue;
    minDist[start] = 0;
    bfsQueue.push({0, start});

    while (!bfsQueue.empty())
    {
        int curNode = bfsQueue.front().second;
        int curDist = bfsQueue.front().first;

        bfsQueue.pop();

        for (int i = 0; i < arr.size(); i++)
        {
            int neibNode = (arr[i] * curNode) % numOfNodes;
            int niebNodeCurDist = curDist + 1;
            if (minDist[neibNode] > niebNodeCurDist)
            {
                minDist[neibNode] = niebNodeCurDist;
                bfsQueue.push({niebNodeCurDist, neibNode});
            }
        }
    }

    return minDist[end] == INF ? -1 : minDist[end];
}

int main()
{
}