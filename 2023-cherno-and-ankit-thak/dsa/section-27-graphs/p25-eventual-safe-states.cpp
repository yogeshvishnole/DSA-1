/*
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool eventualSafeNodesHelper(vector<int> adj[], vector<int> &visited, vector<int> &ans, int source)
{
    visited[source] = true;
    bool isSafe = true;

    for (int neib : adj[source])
    {
        if (!visited[neib])
        {
            isSafe = isSafe && eventualSafeNodesHelper(adj, visited, ans, neib);
        }
        else
        {
            if (adj[neib].size() != 0 && !(visited[neib] == 2))
            {

                isSafe = false;
            }
        }
    }
    if (isSafe)
    {
        visited[source] = 2;
    }
    return isSafe;
}

vector<int> eventualSafeNodes(int V, vector<int> adj[])
{
    vector<int> visited(V, 0);
    vector<int> ans;

    for (int i = 0; i < visited.size(); i++)
    {
        if (!visited[i])
        {
            eventualSafeNodesHelper(adj, visited, ans, i);
        }
    }
    for (int i = 0; i < visited.size(); i++)
    {
        if (visited[i] == 2)
            ans.push_back(i);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{

    vector<int> adj[] = {{3},
                         {0, 4},
                         {0, 1, 3, 4},
                         {4},
                         {}};
    vector<int> ans = eventualSafeNodes(5, adj);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}
