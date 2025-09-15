#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include "./p52-disjoint-set-datastructure.cpp";
using namespace std;

class Solution
{

    vector<pair<int, int>> edgesDelta = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        DisjointSet ds(n * n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    int curNodeNumber = n * i + j;
                    for (int k = 0; k < edgesDelta.size(); k++)
                    {
                        int neibx = edgesDelta[k].first + i;
                        int neiby = edgesDelta[k].second + j;
                        if (neibx >= 0 && neibx < n && neiby >= 0 && neiby < n && grid[neibx][neiby] == 1)
                        {
                            int niebNodeNumber = n * neibx + neiby;
                            ds.unionBySize(niebNodeNumber, curNodeNumber);
                        }
                    }
                }
            }
        }

        // now make a map of parents key as parent and nodesCount as value

        unordered_map<int, int> compToNodeCountMap;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    int curNodeNumber = n * i + j;
                    compToNodeCountMap[ds.findUlParent(curNodeNumber)]++;
                }
            }
        }

        auto it = compToNodeCountMap.begin();
        if (it == compToNodeCountMap.end())
        {
            return 1;
        }
        int maxNumberOfComponents = it->second;
        ++it; // Move to the second element

        for (; it != compToNodeCountMap.end(); ++it)
        {
            maxNumberOfComponents = max(maxNumberOfComponents, it->second);
            // it->first is the key, it->second is the value
            // Your code here
        }

        // try adding 1 at each 0 and find the max

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    int curIslandLen = 1;

                    vector<int> parList(4, -1);
                    for (int k = 0; k < edgesDelta.size(); k++)
                    {
                        int neibx = edgesDelta[k].first + i;
                        int neiby = edgesDelta[k].second + j;
                        if (neibx >= 0 && neibx < n && neiby >= 0 && neiby < n && grid[neibx][neiby] == 1)
                        {
                            int curNeibNodeNumber = n * neibx + neiby;
                            int curNeibParent = ds.findUlParent(curNeibNodeNumber);
                            bool isUpdateCount = true;
                            for (int l = 0; l < k; l++)
                            {
                                if (parList[l] == curNeibParent)
                                {
                                    isUpdateCount = false;
                                }
                            }
                            if (isUpdateCount)
                            {
                                curIslandLen += compToNodeCountMap[curNeibParent];
                                parList[k] = curNeibParent;
                            }
                        }
                    }
                    parList.assign(4, -1);
                    maxNumberOfComponents = max(maxNumberOfComponents, curIslandLen);
                }
            }
        }
        return maxNumberOfComponents;
    }
};

int main()
{
    vector<vector<int>> test = {{0, 1},
                                {1, 1}};
    Solution soln;
    soln.largestIsland(test);
}