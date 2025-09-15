#include <iostream>
#include <vector>
#include "p52-disjoint-set-datastructure.cpp"
using namespace std;

// User function Template for C++

class Solution
{
public:
    int Solve(int n, vector<vector<int>> &edge)
    {
        DisjointSet ds(n);
        int m = edge.size();

        for (int i = 0; i < edge.size(); i++)
        {
            ds.unionBySize(edge[i][0], edge[i][1]);
        }

        int numberOfConnComp = 0;

        for (int i = 0; i < n; i++)
        {
            if (ds.findUlParent(i) == i)
            {
                numberOfConnComp++;
            }
        }

        if (m >= n)
        {
            return numberOfConnComp - 1;
        }
        return -1;
    }
};