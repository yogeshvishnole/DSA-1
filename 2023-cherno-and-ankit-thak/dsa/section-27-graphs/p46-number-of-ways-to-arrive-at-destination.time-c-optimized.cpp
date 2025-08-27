/*
Learn the cpp concept of #define macro from below commented solution
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int countPaths(int n, vector<vector<int>> &roads)
{
    const long long ansRange = 1e9 + 7;
    const long long INF = 1e18;
    vector<vector<pair<long long, long long>>> intersectionGraph(n, vector<pair<long long, long long>>());

    for (int i = 0; i < roads.size(); i++)
    {
        intersectionGraph[roads[i][0]].push_back({roads[i][1], roads[i][2]});
        intersectionGraph[roads[i][1]].push_back({roads[i][0], roads[i][2]});
    }

    vector<long long> minDist(n, INF);
    vector<long long> numberOfWays(n, 0);
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    minDist[0] = 0;
    numberOfWays[0] = 1;
    pq.push({0, 0});

    while (!pq.empty())
    {
        long long curNode = pq.top().second;
        long long curDist = pq.top().first;

        pq.pop();

        for (auto neib : intersectionGraph[curNode])
        {
            long long neibNode = neib.first;
            long long curNodeToNeibTime = neib.second;

            long long curOverallTime = curDist + curNodeToNeibTime;
            if (curOverallTime < minDist[neibNode])
            {
                minDist[neibNode] = curOverallTime;
                numberOfWays[neibNode] = numberOfWays[curNode];
                pq.push({curOverallTime, neibNode});
            }
            else if (curOverallTime <= minDist[neibNode])
            {
                numberOfWays[neibNode] = (numberOfWays[neibNode] + numberOfWays[curNode]) % ansRange;
            }
        }
    }

    return numberOfWays[n - 1];
}

/*
#define ll long long
#define pll pair<ll, ll>
class Solution {
public:
    int MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pll>> graph(n);
        for(auto& road: roads) {
            ll u = road[0], v = road[1], time = road[2];
            graph[u].push_back({v, time});
            graph[v].push_back({u, time});
        }
        return dijkstra(graph, n, 0);
    }
    int dijkstra(const vector<vector<pll>>& graph, int n, int src) {
        vector<ll> dist(n, LONG_MAX);
        vector<ll> ways(n);
        ways[src] = 1;
        dist[src] = 0;
        priority_queue<pll, vector<pll>, greater<>> minHeap;
        minHeap.push({0, 0}); // dist, src
        while (!minHeap.empty()) {
            auto[d, u] = minHeap.top(); minHeap.pop();
            if (d > dist[u]) continue; // Skip if `d` is not updated to latest version!
            for(auto [v, time] : graph[u]) {
                if (dist[v] > d + time) {
                    dist[v] = d + time;
                    ways[v] = ways[u];
                    minHeap.push({dist[v], v});
                } else if (dist[v] == d + time) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
        return ways[n-1];
    }
};
*/
int main()
{
}