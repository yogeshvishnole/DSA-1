/*
Pattern USED - Multisource BFS

Given a binary grid of n*m. Find the distance of the nearest 1 in the grid for each cell.
The distance is calculated as |i1  - i2| + |j1 - j2|, where i1, j1 are the row number 
and column number of the current cell, and i2, j2 are the row number and column number of 
the nearest cell having value 1. There should be atleast one 1 in the grid.

Example 1:

Input:
grid = [[0,1,1,0], [1,1,0,0], [0,0,1,1]]
Output:
[[1,0,0,1], [0,0,1,1], [1,1,0,0]]
Explanation:
The grid is-
0 1 1 0
1 1 0 0
0 0 1 1
- 0's at (0,0), (0,3), (1,2), (1,3), (2,0) and (2,1) are at a distance of 1 from 1's at 
(0,1), (0,2), (0,2), (2,3), (1,0) and (1,1) respectively.

Example 2:

Input:
grid = [[1,0,1], [1,1,0], [1,0,0]]
Output:
[[0,1,0], [0,0,1], [0,1,2]]
Explanation:
The grid is-
1 0 1
1 1 0
1 0 0
- 0's at (0,1), (1,2), (2,1) and (2,2) are at a  distance of 1, 1, 1 and 2 from 1's at (0,0), (0,2), (2,0) and (1,1) respectively.

*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

vector<vector<int>>
nearest(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    vector<vector<int>> distanceMatrix(n, vector<int>(m, 0));

    queue<pair<pair<int, int>, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                q.push({{i, j}, 0});
                visited[i][j] = 1;
                distanceMatrix[i][j] = 0;
            }
        }
    }

    while (!q.empty())
    {
        int curNodei = q.front().first.first;
        int curNodej = q.front().first.second;
        int curNodeDis = q.front().second;
        q.pop();

        for (int i = 0; i < directions.size(); i++)
        {
            int neibi = curNodei + directions[i][0];
            int neibj = curNodej + directions[i][1];

            if (neibi >= 0 && neibj >= 0 && neibi < n && neibj < m && !visited[neibi][neibj])
            {
                q.push({{neibi, neibj}, curNodeDis + 1});
                visited[neibi][neibj] = 1;
                distanceMatrix[neibi][neibj] = curNodeDis + 1;
            }
        }
    }
    return distanceMatrix;
}

int main(int argc, char **argv)
{
    vector<vector<int>> grid = {
        {0, 1, 1, 0},
        {1, 1, 0, 0},
        {0, 0, 1, 1}};

    vector<vector<int>> distanceGrid = nearest(grid);

    for (auto row : distanceGrid)
    {
        for (auto col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }
}
