#include <iostream>
#include <vector>
#include <set>
using namespace std;

/*
Since according to question graph does not contain any negative weights thats why I will use the
Djikstra's algorithm to find the shortest path from each node.
Because Djikstra will have time complexity = V * (ElogV)
and Floyd Warshall Will have the time complexity of V*V*V
*/

const int INF = 1e9 + 7;

class Solution
{
public:
    vector<int> djkistra(vector<vector<pair<int, int>>> &adjList, int src)
    {
        int V = adjList.size();
        set<pair<int, int>> distNodeSet;
        vector<int> distance(V, INF);
        distance[src] = 0;

        distNodeSet.insert({0, src});

        while (!distNodeSet.empty())
        {
            int curDist = (*distNodeSet.begin()).first;
            int curNode = (*distNodeSet.begin()).second;
            distNodeSet.erase({curDist, curNode});

            int neibCount = adjList[curNode].size();
            for (int i = 0; i < neibCount; i++)
            {
                int curNeib = adjList[curNode][i].first;
                int neibCurDist = distance[curNeib];
                int neibDist = adjList[curNode][i].second;
                int newEstDist = distance[curNode] + neibDist;

                if (neibCurDist > newEstDist)
                {
                    if (distance[curNeib] != INF)
                    {
                        distNodeSet.erase({distance[curNeib], curNeib});
                    }
                    distance[curNeib] = newEstDist;
                    distNodeSet.insert({newEstDist, curNeib});
                }
            }
        }

        return distance;
    }

    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {

        vector<vector<int>> ansMatrix;
        vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());

        for (int i = 0; i < edges.size(); i++)
        {
            graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            graph[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }

        vector<int> thresholdDistCityCountsForNodes(n);

        for (int i = 0; i < n; i++)
        {
            vector<int> minDists = djkistra(graph, i);
            int thresholdDistNodesCount = 0;
            for (int j = 0; j < minDists.size(); j++)
            {
                if (minDists[j] <= distanceThreshold)
                {
                    if (j == i)
                        continue;
                    thresholdDistNodesCount++;
                }
            }
            thresholdDistCityCountsForNodes[i] = thresholdDistNodesCount;
        }

        int minCount = INF;
        int ansNode;

        for (int i = 0; i < n; i++)
        {
            if (thresholdDistCityCountsForNodes[i] < minCount)
            {
                minCount = thresholdDistCityCountsForNodes[i];
            }
            if (minCount == thresholdDistCityCountsForNodes[i])
            {
                ansNode = i;
            }
        }

        return ansNode;
    }
};