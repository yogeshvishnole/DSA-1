#include <iostream>
#include <vector>
#include <unordered_map>
#include "./p52-disjoint-set-datastructure.cpp"
using namespace std;

class Solution
{
public:
    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();
        int maxRow = 0;
        int maxCol = 0;

        for (auto it : stones)
        {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        DisjointSet ds(maxRow + maxCol + 1);

        unordered_map<int, bool> stonesMap;

        for (auto it : stones)
        {
            ds.unionBySize(it[0], it[1] + maxRow + 1);
            stonesMap[it[0]] = 1;
            stonesMap[it[1] + maxRow + 1] = 1;
        }

        int compCount = 0;
        for (auto it : stonesMap)
        {
            if (ds.findUlParent(it.first) == it.first)
            {
                compCount++;
            }
        }

        return n - compCount;
    }
};