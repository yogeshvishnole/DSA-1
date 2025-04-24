/*
USE of set is the most imp pattern of this problem, it denotes you can use the set
data structure with vectors and array as well. Also explore the custom comparator
in set stl container when used with vector<int>
 */

#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
void dfs(vector<vector<int>> &grid, vector<vector<int>> &visited, int sourcei, int sourcej, vector<pair<int, int>> &compNodes, int parSrci, int parSrcj)
{
    int n = grid.size();
    int m = grid[0].size();

    visited[sourcei][sourcej] = 1;
    compNodes.push_back({sourcei - parSrci, sourcej - parSrcj});

    for (int i = 0; i < directions.size(); i++)
    {
        int neibi = sourcei + directions[i][0];
        int neibj = sourcej + directions[i][1];

        if (neibi >= 0 && neibj >= 0 && neibi < n && neibj < m && !visited[neibi][neibj] && grid[neibi][neibj] == 1)
        {
            dfs(grid, visited, neibi, neibj, compNodes, parSrci, parSrcj);
        }
    }
}

int countDistinctIslands(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m + 1, 0));
    vector<vector<pair<int, int>>> dims;
    set<vector<pair<int, int>>> st;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && grid[i][j] == 1)
            {
                vector<pair<int, int>> compNodes;
                dfs(grid, visited, i, j, compNodes, i, j);
                st.insert(compNodes);
            }
        }
    }

    return st.size();
}

int main() {}