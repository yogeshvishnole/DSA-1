/*

Approach 1 - BFS always gives the minimum distance between the two nodes.
tricks and techniques -
1. for getting the levels, instead of looping over
all the queue elements inside the outer while loop, loop over the
current queue elements inside the while loop at that time all the
nodes at the current level get traversed so you can increment the level
variable, it is pretty versatile trick.
2. From 1 based x,y coordinates to 2D matrix indices formula
i = N-y;
j = x-1;

Approach 2 - concept is same, but I am thinking to store the complete
matrix as graph in adjacency list beforeHand, but as you can see in
current soln it is not needed.


Geeks for geeks link -https://www.geeksforgeeks.org/problems/steps-by-knight5927/1
Or search on internet steps by knight
*/
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution
{

    int helper(int src_i, int src_j, int target_i, int target_j, int N)
    {

        vector<vector<int>> nbrConstant = {
            {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}};

        vector<vector<int>> visited(N, vector<int>(N, 0));

        queue<pair<int, int>> q;
        q.push(make_pair(src_i, src_j));
        visited[src_i][src_j] = 1;

        int level = 0;

        while (!q.empty())
        {

            int qSize = q.size();

            while (qSize > 0)
            {

                pair<int, int> curNode = q.front();
                q.pop();

                if (curNode.first == target_i && curNode.second == target_j)
                {
                    return level;
                }

                for (int i = 0; i < nbrConstant.size(); i++)
                {

                    int curnbr_i = curNode.first + nbrConstant[i][0];
                    int curnbr_j = curNode.second + nbrConstant[i][1];

                    if (
                        curnbr_i >= 0 && curnbr_j >= 0 &&
                        curnbr_i < N && curnbr_j < N && visited[curnbr_i][curnbr_j] == 0)
                    {
                        q.push(make_pair(curnbr_i, curnbr_j));
                        visited[curnbr_i][curnbr_j] = 1;
                    }
                }
                qSize--;
            }

            level++;
        }

        return -1;
    }

public:
    // Function to find out minimum steps Knight needs to reach target position.
    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
    {

        int src_i = N - KnightPos[1];
        int src_j = KnightPos[0] - 1;
        int target_i = N - TargetPos[1];
        int target_j = TargetPos[0] - 1;

        return helper(src_i, src_j, target_i, target_j, N);
    }
};