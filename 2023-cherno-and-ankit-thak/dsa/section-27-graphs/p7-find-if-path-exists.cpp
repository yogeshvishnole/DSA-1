/*
1971. Find if Path Exists in Graph

There is a bi-directional graph with n vertices, where each vertex is labeled
from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D
integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional
edge between vertex ui and vertex vi. Every vertex pair is connected by at most
one edge, and no vertex has an edge to itself.
You want to determine if there is a valid path that exists from vertex source
to vertex destination.
Given edges and the integers n, source, and destination, return true if there
is a valid path from source to destination, or false otherwise.



Example 1:


Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
Output: true
Explanation: There are two paths from vertex 0 to vertex 2:
- 0 → 1 → 2
- 0 → 2
Example 2:


Input: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5
Output: false
Explanation: There is no path from vertex 0 to vertex
*/

/*
Approach do the graph traversal either using theh BFS or DFS algorithm if the
visted[destination] is not 0 means, you can reach if it is 0 after traversal
means destination is not reachable from the source.

NOTE :- Dont use adjacency list on leetcode it is giving TLE, because they
might design some test cases to hit the collision causing the heap error etc
 */

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

bool isPath(vector<vector<int>> &graph, int source, int destination)
{
    int n = graph.size();
    vector<int> visited(n + 1, 0);
    queue<int> q;
    q.push(source);
    visited[source] = 1;

    while (!q.empty())
    {
        int curVertex = q.front();
        q.pop();

        for (int nbr : graph[curVertex])
        {
            if (!visited[nbr])
            {
                visited[nbr] = 1;
                q.push(nbr);
            }
        }
    }
    return visited[destination];
}

int main()
{

        // Example 1

    int n = 6;
    vector<vector<int>>
        edges = {{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}};
    // Example 2
    //     int n = 3;
    // vector<vector<int>>
    //     edges = {{0, 1}, {1, 2}, {2, 0}};
    vector<vector<int>> graph(n);
    for (int i = 0; i < edges.size(); i++)
    {
        int a = edges[i][0], b = edges[i][1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    cout << "Ans: " << isPath(graph, 0, 5) << endl;
}