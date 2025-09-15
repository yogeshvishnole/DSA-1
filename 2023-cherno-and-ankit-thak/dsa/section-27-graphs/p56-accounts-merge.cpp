#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class DisjointSetUnion
{

    vector<int> rank;
    int nodes;

public:
    vector<int> parent;
    DisjointSetUnion(int n) : nodes(n)
    {
        rank.resize(this->nodes, 0);
        parent.resize(this->nodes);
        for (int i = 0; i < this->nodes; i++)
        {
            this->parent[i] = i;
        }
    }

    int findUlParent(int n)
    {
        if (this->parent[n] == n)
        {
            return n;
        }
        return parent[n] = findUlParent(parent[n]);
    }

    void unionByRank(int u, int v)
    {

        int u_ulp = findUlParent(u);
        int v_ulp = findUlParent(v);

        if (rank[u_ulp] < rank[v_ulp])
        {
            parent[u_ulp] = v_ulp;
        }
        else if (rank[u_ulp] > rank[v_ulp])
        {
            parent[v_ulp] = u_ulp;
        }
        else
        {
            parent[v_ulp] = u_ulp;
            rank[u_ulp]++;
        }
    }
};

class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        // mark each element as node
        unordered_map<string, int> emailToNodeMap;
        DisjointSetUnion ds(accounts.size());

        for (int i = 0; i < accounts.size(); i++)
        {

            for (int j = 1; j < accounts[i].size(); j++)
            {
                if (!emailToNodeMap.count(accounts[i][j]))
                {
                    emailToNodeMap[accounts[i][j]] = i;
                }
                else
                {
                    ds.unionByRank(emailToNodeMap[accounts[i][j]], i);
                }
            }
        }
        vector<vector<string>> nodeToEmailMap(accounts.size(), vector<string>());

        for (auto el : emailToNodeMap)
        {
            int ul_p = ds.findUlParent(emailToNodeMap[el.first]);
            if (nodeToEmailMap[ul_p].size() == 0)
            {
                nodeToEmailMap[ul_p].push_back(accounts[ul_p][0]);
            }
            nodeToEmailMap[ul_p].push_back(el.first);
        }

        vector<vector<string>> ans;
        for (int i = 0; i < accounts.size(); i++)
        {
            if (ds.parent[i] == i)
            {
                sort(nodeToEmailMap[i].begin() + 1, nodeToEmailMap[i].end());
                ans.push_back(nodeToEmailMap[i]);
            }
        }
        return ans;
    }
};