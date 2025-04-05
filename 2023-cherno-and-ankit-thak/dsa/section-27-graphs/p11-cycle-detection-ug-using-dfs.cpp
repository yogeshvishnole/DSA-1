/*
cycle detection in undirected graph using the Depth First Search
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

bool isCycle(unordered_map<int, vector<int>> &graph)
{

    int n = graph.size();
    if (graph.empty())
    {
        return false;
    }
    int firstElement = (*(graph.begin())).first;
    vector<int> visited(n + 1, 0);

    stack<int>
        s;
    s.push(firstElement);
    visited[firstElement] = 1;
    int parent = -1;

    while (!s.empty())
    {
        int curVertex = s.top();
        s.pop();

        for (auto nbr : graph[curVertex])
        {
            if (!visited[nbr])
            {
                visited[nbr] = 1;
                s.push(nbr);
            }
            else
            {
                if (nbr != parent)
                {
                    return true;
                }
            }
        }
        parent = curVertex;
    }
    return false;
}

int main()
{

    // this is cyclic graph, try drawing it on piece of paper
    unordered_map<int, vector<int>> cyclicGraph;

    cyclicGraph[1] = {2, 3};
    cyclicGraph[2] = {1, 4};
    cyclicGraph[3] = {1, 4};
    cyclicGraph[4] = {2, 3};

    cout << isCycle(cyclicGraph) << endl;

    // below is non cyclic graph

    unordered_map<int, vector<int>> nonCyclicGraph;

    nonCyclicGraph[1] = {2};
    nonCyclicGraph[2] = {1, 3};
    nonCyclicGraph[3] = {2, 4};
    nonCyclicGraph[4] = {3};

    cout << isCycle(nonCyclicGraph) << endl;
}
