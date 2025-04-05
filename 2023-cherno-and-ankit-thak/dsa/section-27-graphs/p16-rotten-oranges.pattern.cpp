/*
This question introduces a very good pattern where we run bfs on multiple sources at once, as per
a condition which reduces the time of traversal.
Pattern USED - Multisource BFS

*/

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>
using namespace std;

vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int bfs(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<pair<int, int>, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({{i, j}, 0});
            }
        }
    }

    int maxTime = 0;

    while (!q.empty())
    {
        int curi = q.front().first.first;
        int curj = q.front().first.second;
        int time = q.front().second;
        q.pop();
        for (int i = 0; i < directions.size(); i++)
        {
            int deli = directions[i][0] + curi;
            int delj = directions[i][1] + curj;

            if (deli >= 0 && delj >= 0 && deli < n && delj < m && grid[deli][delj] == 1)
            {
                grid[deli][delj] = 2;
                q.push({{deli, delj}, time + 1});
                if (time + 1 > maxTime)
                {
                    maxTime = time + 1;
                }
            }
        }
    }
    return maxTime;
}

int orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    int minTime = bfs(grid);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                return -1;
            }
        }
    }

    return minTime;
}

int main()
{
    // vector<vector<int>> grid = {
    //     {2, 1, 1},
    //     {1, 1, 0},
    //     {0, 1, 1}};
    // vector<vector<int>> grid = {
    //     {2, 1, 1},
    //     {0, 1, 1},
    //     {1, 0, 1}};
    vector<vector<int>> grid = {{0, 2}};
    cout << orangesRotting(grid) << endl;
}