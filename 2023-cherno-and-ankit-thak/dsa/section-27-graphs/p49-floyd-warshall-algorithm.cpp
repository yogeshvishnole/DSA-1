/*
Why FLoyd Warshall Algorithm ?
Its a multisource shortest path algorithm and gives us shortest path from
each node to every node + it also worked for the graphs with the negative edges.

Working -
Its simply a brute force approach to find the shortest path from each node to
every node, understand its working and you will see its just uses the
dynamic programming memoization technique to store the pre computed values.

first create a cost matrix based on the primitive or trivially know values or in
terms of DP say base conditions.
Then pick each vertex and go via that vertex to every node and update the cost
matrix.

The cost matrix after the final stage will give us the shortest path between the
node i and node j.

dp equation for the question is (it is quite intuitive) -
dp[i][j] = min(dp[i][j],dp[i][k] + dp[k][j])

Negative path cycle detection via the floyd warshall -
If after calculating the final matrix with answers, if the diagonal contains
the negative weights means less than 0, it means graph contains negative path
cycles, because node can reach to itself only in 0 distance.


NOTE :- Floyd Warshall ALgorithm only works for directed graphs, if you have given
an undirected graph then convert it to directed graph for applying the Floyd
Warshall algorithm.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void floydWarshall(vector<vector<int>> &dist)
    {
        const int INF = 1e8;
        int numOfNodes = dist.size();

        // loop over the via node
        for (int via = 0; via < numOfNodes; via++)
        {
            for (int i = 0; i < numOfNodes; i++)
            {
                for (int j = 0; j < numOfNodes; j++)
                {
                    int newDist = (dist[i][via] < INF ? dist[i][via] : INF) + (dist[via][j] < INF ? dist[via][j] : INF);

                    dist[i][j] = min(dist[i][j], newDist);
                }
            }
        }
    }
};