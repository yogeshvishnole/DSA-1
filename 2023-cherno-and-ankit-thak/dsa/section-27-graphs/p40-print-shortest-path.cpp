#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <algorithm>
using namespace std;

const int INF = 1e9 + 7;

class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {

        vector<vector<pair<int, int>>> graph(n + 1, vector<pair<int, int>>());

        for (int i = 0; i < edges.size(); i++)
        {
            graph[edges[i][0]].push_back({edges[i][1],
                                          edges[i][2]});
            graph[edges[i][1]].push_back({edges[i][0],
                                          edges[i][2]});
        }

        // Storing the paths in queue solution worked but we have a more space optimized version
        // of O(n) space
        // set<pair<pair<int, int>, vector<int>>> bfsQ;
        set<pair<int, int>> bfsQ;
        bfsQ.insert({0, 1});
        vector<int> minDistList(n + 1, INF);
        minDistList[1] = 0;

        // new way create a parent vector which will keep the track which node parent is whom in
        // the shortest path
        vector<int> parent(n + 1, 0);
        for (int i = 0; i < parent.size(); i++)
        {
            parent[i] = i;
        }

        vector<int> ansShortPathToN = {-1};

        while (!bfsQ.empty())
        {
            auto curNodeIter = bfsQ.begin();
            int curNode = (*curNodeIter).second;
            int curDist = (*curNodeIter).first;
            bfsQ.erase(bfsQ.begin());
            for (auto neib : graph[curNode])
            {
                int neibNode = neib.first;
                int edgeWeight = neib.second;
                int newDistFromSrc = curDist + edgeWeight;
                if (newDistFromSrc < minDistList[neibNode])
                {
                    // curShortPath.push_back(neibNode);
                    // if (neibNode == n)
                    // {
                    //     ansShortPathToN = curShortPath;
                    //     ansShortPathToN.insert(ansShortPathToN.begin(), newDistFromSrc);
                    // }
                    parent[neibNode] = curNode;
                    minDistList[neibNode] = newDistFromSrc;
                    // bfsQ.insert({{neibNode, newDistFromSrc}, curShortPath});
                    bfsQ.insert({newDistFromSrc, neibNode});
                    // curShortPath.pop_back();
                }
            }
        }

        if (minDistList[n] == INF)
        {
            return ansShortPathToN;
        }

        int tracker = n;

        ansShortPathToN.pop_back();
        ansShortPathToN.push_back(minDistList[n]);
        ansShortPathToN.push_back(tracker);

        while (parent[tracker] != tracker)
        {
            ansShortPathToN.push_back(parent[tracker]);
            tracker = parent[tracker];
        }

        reverse(ansShortPathToN.begin() + 1, ansShortPathToN.end());
        return ansShortPathToN;
    }
};

int main()
{
    Solution soln;
    int n = 5;
    int m = 6;
    vector<vector<int>> edges = {
        {1, 2, 2},
        {2, 5, 5},
        {2, 3, 4},
        {1, 4, 1},
        {4, 3, 3},
        {3, 5, 1}};
    vector<int> ans = soln.shortestPath(n, m, edges);
    for (int el : ans)
    {
        cout << el << " ";
    }
    cout << endl;
}