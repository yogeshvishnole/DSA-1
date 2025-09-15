#include <iostream>
#include <vector>
#include <utility>
#include "./p52-disjoint-set-datastructure.cpp"
using namespace std;

// User function Template for C++
class Solution
{
    vector<pair<int, int>> neibEdgesDelta = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
    {

        int numberOfNodes = n * m;
        DisjointSet ds(numberOfNodes);
        vector<vector<int>> visited(n, vector<int>(m, 0));

        int numberOfIslands = 0;
        vector<int> ans;

        for (int i = 0; i < operators.size(); i++)
        {
            numberOfIslands = numberOfIslands + 1;
            int x = operators[i][0];
            int y = operators[i][1];
            if (visited[x][y])
            {
                ans.push_back(numberOfIslands);
                continue;
            }
            visited[x][y] = 1;

            // go to the neigbours of the operator and check if they are already connected or
            // we are connecting them the first time.

            int nodeNumber = m * x + y;

            for (int k = 0; k < neibEdgesDelta.size(); k++)
            {
                int neibx = x + neibEdgesDelta[k].first;
                int neiby = y + neibEdgesDelta[k].second;

                if (neibx < 0 || neibx >= n || neiby < 0 || neiby >= m || visited[neibx][neiby] == 0)
                {
                    continue;
                }

                int nodeNumberNeib = m * neibx + neiby;

                if (ds.findUlParent(nodeNumber) != ds.findUlParent(nodeNumberNeib))
                {
                    ds.unionBySize(nodeNumberNeib, nodeNumber);
                    numberOfIslands--;
                }
            }
            ans.push_back(numberOfIslands);
        }

        return ans;
    }
};

int main() {}

