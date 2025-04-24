/*
I code it by myself.

ubderstand the order of directions in imp for lexicoigraphical sorting.abort
understand the visited matrix is also the key.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<pair<pair<int, int>, char>> directions = {{{1, 0}, 'D'}, {{-1, -1}, 'L'}, {{0, 1}, 'R'}, {{-1, 0}, 'U'}};

void ratInaMazeHelper(vector<vector<int>> &grid, vector<vector<int>> &visited, string path, int srci, int srcj, vector<string> &ans)
{

    int n = grid.size();
    if (srci == n - 1 && srcj == n - 1)
    {
        ans.push_back(path);
        return;
    }

    for (int i = 0; i < directions.size(); i++)
    {
        int neibx = srci + directions[i].first.first;
        int neiby = srcj + directions[i].first.second;

        char direction = directions[i].second;

        if (neibx >= 0 && neiby >= 0 && neibx < n && neiby < n && visited[neibx][neiby] == 0 && grid[neibx][neiby] == 1)
        {
            visited[neibx][neiby] = 1;
            path.push_back(direction);
            ratInaMazeHelper(grid, visited, path, neibx, neiby, ans);
            visited[neibx][neiby] = 0;
            path.pop_back();
        }
    }
}

vector<string> findPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<string> ans;
    vector<vector<int>> visited(n, vector<int>(n, 0));
    visited[0][0] = 1;
    ratInaMazeHelper(grid, visited, "", 0, 0, ans);
    return ans;
}

int main()
{
    vector<vector<int>> grid =
        {{1, 0, 0, 0},
         {1, 1, 0, 1},
         {1, 1, 0, 0},
         {0, 1, 1, 1}};

    vector<string>
        ans = findPath(grid);

    for (auto el : ans)
    {
        cout << el << endl;
    }
}