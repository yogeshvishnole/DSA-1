/*
Definition of a bridge - Any edges whose removal will break the graph into two connected
components such edges is called as a Bridge.

We will use Tarjan's Algorithm to find the bridge.
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int INF = 1e9 + 7;
class Solution
{
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<vector<int>> adj(n, vector<int>());
        vector<vector<int>> bridges;

        for (int i = 0; i < connections.size(); i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }

        // dfs
        vector<int> nodeStartTimes(n, 0);
        vector<int> lowerStartTime(n, INF);
        vector<int> visited(n, 0);

        stack<pair<pair<int, int>, int>> dfsStack;
        int startTime = 1;

        for (int i = 0; i < n; i++)
        {
            if (visited[i])
                continue;

            visited[i] = 1;
            dfsStack.push({{i, 0},
                           -1});
            nodeStartTimes[i] = startTime;
            startTime++;

            while (!dfsStack.empty())
            {
                int curNode = dfsStack.top().first.first;
                int neibIndex = dfsStack.top().first.second;

                if (neibIndex < adj[curNode].size())
                {
                    dfsStack.top().first.second++;
                    int neibNode = adj[curNode][neibIndex];
                    if (!visited[neibNode])
                    {
                        visited[neibNode] = 1;
                        nodeStartTimes[neibNode] = startTime;
                        startTime++;
                        dfsStack.push({{neibNode, 0}, curNode});
                    }
                }
                else
                {
                    int parentNode = dfsStack.top().second;
                    int lowTime = nodeStartTimes[curNode];
                    for (auto neibNode : adj[curNode])
                    {
                        if (neibNode != parentNode)
                        {
                            int compTime = lowerStartTime[neibNode] == INF ? nodeStartTimes[neibNode] : lowerStartTime[neibNode];
                            lowTime = min(lowTime, compTime);
                        }
                    }
                    lowerStartTime[curNode] = lowTime;

                    if (parentNode != -1 && lowTime > nodeStartTimes[parentNode])
                    {
                        bridges.push_back({parentNode, curNode});
                    }
                    dfsStack.pop();
                }
            }
        }
        return bridges;
    }
};

int main()
{
    vector<vector<int>> connections = {
        {0, 1},
        {1, 2},
        {2, 0},
        {1, 3}};
    Solution soln;
    vector<vector<int>> ans = soln.criticalConnections(4, connections);
    for (auto it : ans)
    {
        for (auto el : it)
        {
            cout << el << " ";
        }
        cout << endl;
    }
    cout << endl;
}