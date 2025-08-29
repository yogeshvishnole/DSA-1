/*

Why is Bellman Ford Algorithm ?
Bellman Ford Algorithm is for the same purpose as that of Djikstra's algorithm
i.e. to calculate the shortest path of all the nodes from the src to the
destination but in a graph with negative edges. Bellman Ford Algorithm also
helps us to detect the negative path cycles in the graph ( a cycle which decreases
the distances of the nodes in each loop and we stuck in an infinite cycle,
basically we cant find shortest path from src to all nodes in a graph with the
negative cycle).

Bellman Ford Algorithm Working -
Relax all the edges (n-1) times sequentially.
Reason for it -> Since in a graph of n nodes , in worst case you will take n-1
edges to reach from the first to the last, thereby we iterate for n-1 iterations.
If you dont understood, read further.

What is relaxation?
if there is and edge as from node u to v with weight w, then relaxation of the
edge means -
if(dist[u] + w < dist[v]){
  dist[v] = dist[u]+w;
}
you will do this relaxation for all the edges, again and again for n-1 times.
By the above snippet of relaxation you can easily understood why n-1 times.
lets say the edge from src with dist=0 is at the end of edges sequence,
only value of src neibpur gets updated in first iteration and other nodes
distances will remain infinity and they will get updated in later iterations.
and till the n-1 iteration all nodes distances get updated to the shortest
distance because - Read the below very carefully now -
Reason for it -> Since in a graph of n nodes , in worst case you will take n-1
edges to reach from the first to the last, thereby we iterate for n-1 iterations.
If you dont understood, read further.

If not understood watch the striver video again, that may also not help
think by yourself in very depth.

Negative Path Cycle Detection -
Now after (n-1)th iteration, do one more nth iteration if the distances also get
decreased in the nth iteration means there is negative cycle in the graph,intution
because shortest distance between two nodes can not have more than n-1 edges
it is decreasing in nth iteration because of cycle of negative weight, think about
it it is simple and easy-pizzy.

NOTE :- Bellman Ford ALgorithm only works for directed graphs, if you have given
an undirected graph then convert it to directed graph for applying the Bellman Ford
algorithm.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
    {
        const int INF = 1e8;
        // lets first build the directed graph
        vector<vector<pair<int, int>>> graph(V, vector<pair<int, int>>());

        for (int i = 0; i < edges.size(); i++)
        {
            graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }

        vector<int> minDist(V, INF);

        // assign minDist as 0 for the src
        minDist[src] = 0;

        // n-1 times relaxations of all the edges
        for (int i = 0; i < V - 1; i++)
        {
            for (int j = 0; j < edges.size(); j++)
            {
                int newDist = minDist[edges[j][0]] == INF ? INF : minDist[edges[j][0]] + edges[j][2];
                if (minDist[edges[j][1]] > newDist)
                {
                    minDist[edges[j][1]] = newDist;
                }
            }
        }

        for (int j = 0; j < edges.size(); j++)
        {
            int newDist = minDist[edges[j][0]] + edges[j][2];
            if (minDist[edges[j][1]] > newDist)
            {
                if (minDist[edges[j][1]] == INF)
                    continue;
                vector<int>().swap(minDist);
                minDist.push_back(-1);
            }
        }

        return minDist;
    }
};

int main(int argc, char *argv)
{
    Solution soln;
    int V = 5;
    vector<vector<int>> edges = {
        {1, 3, 2},
        {4, 3, -1},
        {2, 4, 1},
        {1, 2, 1},
        {0, 1, 5}};
    int src = 0;

    vector<int> ans = soln.bellmanFord(V, edges, src);

    for (auto el : ans)
    {
        cout << el << " ";
    }

    cout << endl;
}
