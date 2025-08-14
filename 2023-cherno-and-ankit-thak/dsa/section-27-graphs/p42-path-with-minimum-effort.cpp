/*
Think through the problem carefully, dry and run and you will found
out that its just the 2d matrix version of the Dijkstra's algo.
*/
#include <iostream>
#include <vector>
#include <set>
#include <utility>
using namespace std;

const int INF = 1e9 + 7;
vector<vector<int>> nextCellDeltas = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1}};

class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        set<pair<int, pair<int, int>>> pq;

        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> maxEffortAtEachCell(n, vector<int>(m, INF));

        pq.insert({0, {0, 0}});
        maxEffortAtEachCell[0][0] = 0;

        while (!pq.empty())
        {
            auto curNodeIter = pq.begin();
            int maxEffortToCurNode = (*curNodeIter).first;
            int curNodeX = (*curNodeIter).second.first;
            int curNodeY = (*curNodeIter).second.second;

            pq.erase(pq.begin());

            for (int i = 0; i < nextCellDeltas.size(); i++)
            {
                int neibX = curNodeX + nextCellDeltas[i][0];
                int neibY = curNodeY + nextCellDeltas[i][1];

                if (neibX >= 0 && neibX < n && neibY >= 0 && neibY < m)
                {
                    int curEffort = abs(heights[neibX][neibY] - heights[curNodeX][curNodeY]);
                    if ((curEffort < maxEffortAtEachCell[neibX][neibY]) && (maxEffortToCurNode < maxEffortAtEachCell[neibX][neibY]))
                    {
                        int effort = maxEffortToCurNode > curEffort ? maxEffortToCurNode : curEffort;
                        pq.insert({effort, {neibX, neibY}});
                        maxEffortAtEachCell[neibX][neibY] = effort;
                    }
                }
            }
        }

        return maxEffortAtEachCell[n - 1][m - 1];
    }
};

int main()
{
    Solution soln;
    vector<vector<int>> heights = {{1, 2, 2},
                                   {3, 8, 2},
                                   {5, 3, 5}};
    cout
        << soln.minimumEffortPath(heights) << endl;
}