/*
What is the problem ?

Given an undirected weighted graph with only positive edge weights, you need to find the shortest
path from a source to all the nodes.

We will solve it using the Djikstra's algorithm.

There are three ways to implement the Djikstra's algorithm, in order of their performane high to
low -
1. Using the set
2. Using the priority queue
3. Using the queue
*/

#include <iostream>
#include <set>
#include <vector>
using namespace std;

/* HEY HEY HEY the below solution is not optimized although I used
the set because I am not ordering by distances in set
I am just storing nodes in sorted order which does not has
any benefit. 
I will implement the correct set based implementation in the next
revision. HA HA HA.
*/
const int INF = 1e9 + 7;

vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
{

    vector<vector<pair<int, int>>> graph(V, vector<pair<int, int>>());

    for (int i = 0; i < edges.size(); i++)
    {
        graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        graph[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }

    set<int> bfsQueue;
    vector<int> distanceFromSrc(V, INF);

    bfsQueue.insert(src);
    distanceFromSrc[src] = 0;

    while (!bfsQueue.empty())
    {
        int curNode = *bfsQueue.begin();
        bfsQueue.erase(curNode);
        int curDist = distanceFromSrc[curNode];

        for (auto neib : graph[curNode])
        {
            int neibNode = neib.first;
            int neibDist = neib.second;
            int neibDistFromSrc = distanceFromSrc[neibNode];
            if (neibDistFromSrc == INF || (curDist + neibDist) < neibDistFromSrc)
            {
                distanceFromSrc[neibNode] = curDist + neibDist;
                bfsQueue.insert(neibNode);
            }
        }
    }
    return distanceFromSrc;
}

int main()
{

    vector<vector<int>> edges = {
        {0, 1, 4},
        {0, 2, 8},
        {1, 4, 6},
        {2, 3, 2},
        {3, 4, 10}};

    vector<int> dists = dijkstra(5, edges, 0);

    for (auto dist : dists)
    {
        cout << dist << " ";
    }
}