/*
    Strongly connected components only applied for directed graphs.

    Two types  of interview questions -
    1. Figure out the number of SCC's
    2. Print the SCC

    What is a stongly connected component ?
    What is an SCC?

    A Strongly Connected Component (SCC) is a subgraph where every vertex is reachable
    from every other vertex.

    Example: If A → B and B → A, then {A, B} form an SCC.

    Think about SCCs as “groups” connected by edges in a condensed DAG (Directed Acyclic Graph):
    If there’s an edge from SCC A → SCC B, then all nodes in A will finish after nodes in B in the
    DFS.

    KosaRaju's(Indian Scientist) Algorithm ->

    1. Sort the vertexes in descending order of their finishing time by running a DFS.
    2. Transpose the graph(reverse the direction of the vertices)
    3. now run the DFS on the vertexes in that order(finishing time descending order)
    4. The components you will get are the SCC's in the direction/order exactly in
       the given graph.

*/

#include <iostream>
#include <vector>
#include <stack>
#include <utility>
using namespace std;

class Solution
{
public:
    int kosaraju(vector<vector<int>> &adj)
    {
        // lets run the dfs
        int n = adj.size();

        vector<int> visited(n, 0);

        stack<int> sortStack;

        for (int i = 0; i < n; i++)
        {
            if (visited[i])
                continue;
            stack<pair<int, int>> dfsStack;
            dfsStack.push({i, 0});
            visited[i] = 1;

            while (!dfsStack.empty())
            {
                int curNode = dfsStack.top().first;
                int curNeibIndex = dfsStack.top().second;

                if (curNeibIndex < adj[curNode].size())
                {
                    int neibNode = adj[curNode][curNeibIndex];
                    dfsStack.top().second++;
                    if (!visited[neibNode])
                    {

                        visited[neibNode] = 1;
                        dfsStack.push({neibNode, 0});
                    }
                }
                else
                {
                    sortStack.push(curNode);
                    dfsStack.pop();
                }
            }
        }

        // transpose the graph
        vector<vector<int>> transposeGraph(n, vector<int>());

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                transposeGraph[adj[i][j]].push_back(i);
            }
        }

        visited.assign(n, 0);

        int numberOfSCC = 0;
        while (!sortStack.empty())
        {
            int curNode = sortStack.top();
            sortStack.pop();

            if (visited[curNode])
                continue;

            numberOfSCC++;

            stack<int> dfsStack;
            dfsStack.push(curNode);
            visited[curNode] = 1;

            while (!dfsStack.empty())
            {
                int topNode = dfsStack.top();
                dfsStack.pop();

                for (auto neibNode : transposeGraph[topNode])
                {
                    if (!visited[neibNode])
                    {
                        visited[neibNode] = 1;
                        dfsStack.push(neibNode);
                    }
                }
            }
        }

        return numberOfSCC;
    }
};

int main()
{
    vector<vector<int>> adj = {
        {2, 3}, // 0 -> 2, 3
        {0},    // 1 -> 0
        {1},    // 2 -> 1
        {4},    // 3 -> 4
        {}      // 4 -> (no outgoing edges)
    };
    Solution soln;
    soln.kosaraju(adj);
}