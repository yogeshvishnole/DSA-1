#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

// User function Template for C++

class Solution
{
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination)
    {
        vector<pair<int, int>> adjacentNodesDelta = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> bfsQ;
        bfsQ.push({{source.first, source.second}, 0});
        visited[source.first][source.second] = 1;

        while (!bfsQ.empty())
        {
            auto curNode = bfsQ.front();
            int curNodeX = curNode.first.first;
            int curNodeY = curNode.first.second;
            int curNodeDist = curNode.second;

            bfsQ.pop();

            if (source.first == destination.first && source.second == destination.second)
            {
                return 0;
            }

            for (int i = 0; i < adjacentNodesDelta.size(); i++)
            {
                int neibX = adjacentNodesDelta[i].first + curNodeX;
                int neibY = adjacentNodesDelta[i].second + curNodeY;

                if (neibX >= 0 && neibX < n && neibY >= 0 && neibY < m && !visited[neibX][neibY] && grid[neibX][neibY] == 1)
                {
                    if (neibX == destination.first && neibY == destination.second)
                    {
                        return curNodeDist + 1;
                    }
                    bfsQ.push({{neibX, neibY}, curNodeDist + 1});
                }
            }
        }
        return -1;
    }
};

int main()
{
    vector<vector<int>> grid = {
        {1, 1, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0},
        {1, 0, 0, 1}};
    pair<int, int> source = {0, 1};
    pair<int, int> dest = {2, 2};
    Solution soln;
    cout << soln.shortestPath(grid, source, dest) << endl;
}