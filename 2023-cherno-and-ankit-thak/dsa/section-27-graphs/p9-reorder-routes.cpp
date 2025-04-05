/*
Leetcode link - https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/

*/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

// Soultion using the BFS and adjacency matrix - Giving memory limit exceeded on leetcode.
class Solution
{
public:
    int minReorder(int n, vector<vector<int>> &connections)
    {

        vector<vector<int>> graph(n, vector<int>(n, 0));

        for (int i = 0; i < connections.size(); i++)
        {
            graph[connections[i][0]][connections[i][1]] = 1;
        }

        queue<int> q;
        vector<int> visited(n);

        q.push(0);
        visited[0] = 1;

        int ans = 0;

        while (!q.empty())
        {

            int curNode = q.front();
            q.pop();

            for (int j = 0; j < n; j++)
            {

                if (visited[j])
                {
                    continue;
                }

                if (graph[j][curNode])
                {
                    visited[j] = 1;
                    q.push(j);
                }
                else if (graph[curNode][j])
                {
                    ans++;
                    visited[j] = 1;
                    q.push(j);
                }
            }
        }

        return ans;
    }
};

// Solution using the DFS(using stack not recursion) and adjacency list - Passing on leetcode.

class Solution2
{
public:
    int minReorder(int n, vector<vector<int>> &connections)
    {

        vector<vector<int>> forward_edges(n), backward_edges(n);

        for (int i = 0; i < connections.size(); i++)
        {
            forward_edges[connections[i][0]].push_back(connections[i][1]);
            backward_edges[connections[i][1]].push_back(connections[i][0]);
        }

        stack<int> s;
        vector<int> visited(n, 0);

        s.push(0);
        visited[0] = 1;

        int ans = 0;

        while (!s.empty())
        {

            int curNode = s.top();
            s.pop();

            for (int nbr : forward_edges[curNode])
            {
                if (!visited[nbr])
                {
                    ans++;
                    s.push(nbr);
                    visited[nbr] = 1;
                }
            }
            for (int nbr : backward_edges[curNode])
            {
                if (!visited[nbr])
                {
                    s.push(nbr);
                    visited[nbr] = 1;
                }
            }
        }

        return ans;
    }
};

// Using the BFS and adjacenct list - working on leetcode HAHAHA...
class Solution3
{
public:
    int minReorder(int n, vector<vector<int>> &connections)
    {

        vector<vector<int>> forward_edges(n), backward_edges(n);

        for (int i = 0; i < connections.size(); i++)
        {
            forward_edges[connections[i][0]].push_back(connections[i][1]);
            backward_edges[connections[i][1]].push_back(connections[i][0]);
        }

        queue<int> q;
        vector<int> visited(n, 0);

        q.push(0);
        visited[0] = 1;

        int ans = 0;

        while (!q.empty())
        {

            int curNode = q.front();
            q.pop();

            for (int nbr : forward_edges[curNode])
            {
                if (!visited[nbr])
                {
                    ans++;
                    q.push(nbr);
                    visited[nbr] = 1;
                }
            }
            for (int nbr : backward_edges[curNode])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = 1;
                }
            }
        }

        return ans;
    }
};