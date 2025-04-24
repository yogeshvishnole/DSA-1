/*
It is a copy of surrounded regions problem
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int numEnclaves(vector<vector<int>> &grid)
{
    vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i, j});
                    visited[i][j] = 1;
                }
            }
        }
    }

    while (!q.empty())
    {
        int curNodei = q.front().first;
        int curNodej = q.front().second;
        q.pop();

        for (int i = 0; i < directions.size(); i++)
        {
            int neibi = curNodei + directions[i][0];
            int neibj = curNodej + directions[i][1];

            if (neibi >= 0 && neibj >= 0 && neibi < n && neibj < m && grid[neibi][neibj] == 1 && !visited[neibi][neibj])
            {
                q.push({neibi, neibj});
                visited[neibi][neibj] = 1;
            }
        }
    }

    int numberOfEnclaves = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && !visited[i][j])
            {
                numberOfEnclaves++;
            }
        }
    }
    return numberOfEnclaves;
}

int main()
{
    vector<vector<int>> grid = {{0, 0, 0, 0},
                                {1, 0, 1, 0},
                                {0, 1, 1, 0},
                                {0, 0, 0, 0}};
    cout << numEnclaves(grid) << endl;
}