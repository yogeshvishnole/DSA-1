#include <iostream>
#include <vector>
#include "p52-disjoint-set-datastructure.cpp"
using namespace std;

class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {

        int n = isConnected.size();
        DisjointSet ds(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j] == 1)
                {
                    ds.unionBySize(i, j);
                }
            }
        }

        int provinceCount = 0;
        for (int i = 1; i <= n; i++)
        {
            if (ds.findUlParent(i) == i)
            {
                provinceCount++;
            }
        }
        return provinceCount;
    }
};