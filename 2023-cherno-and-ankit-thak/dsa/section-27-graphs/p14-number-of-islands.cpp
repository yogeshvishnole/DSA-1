/*
Its a matrix problem to which we have to assume as a graph.
NOTE - any matirx can be assumed as a graph, where i,j is a node
and we can define the definition of edge in a question or a problems as per the need of the problem.

Here the all the neighbours of the i,j will be the connected to the node i,j
{{-1,0},{-1,-1},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}}

and in normal questions visited array is 1d array, but here one node is represented by i and j,
so its visted status storer will also have i,j position to store i,j's visited status.

and queue should also store i and j, so queue will be queue of pair


*/

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

void bfs(vector<vector<char>> &graph, vector<vector<int>> &visited, int sourcei, int sourcej)
{

    // when diagnols are also considered as neighbours
    // vector<pair<int, int>> directions = {{-1, 0}, {-1, -1}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    queue<pair<int, int>> q;

    visited[sourcei][sourcej] = 1;
    q.push(make_pair(sourcei, sourcej));

    while (!q.empty())
    {
        pair<int, int> curNode = q.front();
        q.pop();

        for (int i = 0; i < directions.size(); i++)
        {
            int x = directions[i].first + curNode.first;
            int y = directions[i].second + curNode.second;
            if (x >= 0 && x < graph.size() && y >= 0 && y < graph[0].size() && !visited[x][y] && graph[x][y] == '1')
            {
                q.push(make_pair(x, y));
                visited[x][y] = 1;
            }
        }
    }
}

int numberOfIslands(vector<vector<char>> &graph)
{
    vector<vector<int>> visited(graph.size(), vector<int>(graph[0].size(), 0));

    int numberOfIslands = 0;

    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            if (graph[i][j] == '1' && !visited[i][j])
            {
                numberOfIslands++;
                bfs(graph, visited, i, j);
            }
        }
    }

    return numberOfIslands;
}

int main()
{

    // vector<vector<char>> grid = {
    //     {'1', '1', '0', '0', '0'},
    //     {'1', '1', '0', '0', '0'},
    //     {'0', '0', '1', '0', '0'},
    //     {'0', '0', '0', '1', '1'}};

    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}};
    cout << numberOfIslands(grid)
         << endl;
}
