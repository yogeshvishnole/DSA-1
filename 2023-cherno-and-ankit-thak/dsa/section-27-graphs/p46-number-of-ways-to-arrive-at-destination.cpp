#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int countPaths(int n, vector<vector<int>> &roads)
{
    const int INF = 1e9 + 7;
    vector<vector<pair<int, int>>> intersectionGraph(n, vector<pair<int, int>>());

    for (int i = 0; i < roads.size(); i++)
    {
        intersectionGraph[roads[i][0]].push_back({roads[i][1], roads[i][2]});
        intersectionGraph[roads[i][1]].push_back({roads[i][0], roads[i][2]});
    }

    vector<int> minDist(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    minDist[0] = 0;
    pq.push({0, 0});
    int numberOfWays = 0;

    while (!pq.empty())
    {
        int curNode = pq.top().second;
        int curDist = pq.top().first;

        pq.pop();

        if (curNode == (n - 1))
        {
            numberOfWays++;
            continue;
        }

        for (auto neib : intersectionGraph[curNode])
        {
            int neibNode = neib.first;
            int curNodeToNeibTime = neib.second;

            int curOverallTime = curDist + curNodeToNeibTime;
            if (curOverallTime < minDist[neibNode])
            {
                minDist[neibNode] = curOverallTime;
                pq.push({curOverallTime, neibNode});
            }
        }
    }

    return numberOfWays % INF;
}

int main()
{
}