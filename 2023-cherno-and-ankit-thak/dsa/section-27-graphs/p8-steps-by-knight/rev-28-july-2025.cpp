#include <iostream>
#include <utility>
#include <queue>
#include <vector>

using namespace std;
/*
I will use BFS as I have to find the min number of steps
And I will emulate the next moves possible on the board as the edges.
Then we know for a non weighted undirected graph the bfs gives the min
*/

vector<pair<int, int>> knightMoves = {{-2, -1}, {2, -1}, {-2, 1}, {2, 1}, {-1, 2}, {1, 2}, {-1, -2}, {1, -2}};

int minStepToReachTarget(vector<int> &knightPos, vector<int> &targetPos, int n)
{
    // Code here
    vector<vector<int>> visited(n + 1, vector<int>(n + 1, 0));

    queue<pair<pair<int, int>, int>> q;
    q.push({{knightPos[0], knightPos[1]}, 0});
    visited[knightPos[0]][knightPos[1]] = 1;

    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int level = q.front().second;
        q.pop();

        for (int i = 0; i < knightMoves.size(); i++)
        {
            int neibx = knightMoves[i].first + x;
            int neiby = knightMoves[i].second + y;

            if (neibx >= 1 && neibx <= n && neiby >= 1 && neiby <= n && (visited[neibx][neiby] == 0))
            {
                q.push({{neibx, neiby}, level + 1});
                visited[neibx][neiby] = 1;
                if (neibx == targetPos[0] && neiby == targetPos[1])
                {
                    return level + 1;
                }
            }
        }
    }
    return 0;
}

int main()
{
    vector<int> knightPos = {3, 3};
    vector<int> targetPos = {1, 2};
    int n = 3;
    cout << minStepToReachTarget(knightPos, targetPos, n) << endl;
}