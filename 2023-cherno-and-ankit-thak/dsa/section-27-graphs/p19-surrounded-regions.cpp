/*
A very very good graph application problem, bhai if you are connected to the edge
O's it means you are not surrounded.

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
void dfs(vector<vector<int>> &visited, vector<vector<char>> &graph, int sourcei, int sourcej)
{
    int n = graph.size();
    int m = graph[0].size();
    visited[sourcei][sourcej] = 1;

    for (int i = 0; i < directions.size(); i++)
    {
        int neibi = sourcei + directions[i][0];
        int neibj = sourcej + directions[i][1];

        if (neibi >= 0 && neibj >= 0 && neibi < n && neibj < m && graph[neibi][neibj] == 'O')
        {
            if (!visited[neibi][neibj])
            {
                dfs(visited, graph, neibi, neibj);
            }
        }
    }
}

void solve(vector<vector<char>> &board)
{
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || j == 0 || j == m - 1 || i == n - 1)
            {
                if (board[i][j] == 'O')
                {
                    dfs(visited, board, i, j);
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'O' && visited[i][j] != 1)
            {
                board[i][j] = 'X';
            }
        }
    }
}

int main() {}