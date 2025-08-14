/*
Why Set Over Priority Queue ?
Why one should use set our priority queue, there is no changes in time complexity
but set will prevent some extra iteration because in queue we have to traverse the
priority queue/ queue elements even after the shorter distance varaiant of same node
is already traversed, but in sets we just override that element when we get a shorter
dist for the same element and removal is not possible in queues.

Why Priority Queue Over Queue ?
In a queue, since edges with smaller distances are not guaranteed to be picked first, 
you may end up exploring more paths, which increases the running time of the algorithm.

Time Complexity = ElogV

Where E = total number of edges and
V = total number of nodes

Derivation of time complexity -

At max while loop of BFS will go through all the nodes.abort

so tc = V*(complexity of logic inside the loop (ltc))(ltc = loop time complexity)

lets calculate the ltc -
since we are looping over all the adjacents lets assume each node is connected to each node
its a dense graph then ltc = log(heapsize)(for deletion from queue) + (V-1) log(heapsize)
ltc = log(heapsize)(1+V-1)
ltc = V*log(heapsize);

so, tc = V*(V*log(heapsize))
    If we took the worst case then the heapsize will be equal to the V square (each
     node is pushing every other node into the queue).
     tc = Vsquare * log(Vsqare)
     Since log(Vsquare) = 2logV = logV (remove the constant)
     and Vsquare = E number of edges in worst case(if each node is connected to every 
     other node)
     tc = ElogV
*/

#include <iostream>
#include <set>
#include <vector>
using namespace std;

const int INF = 1e9 + 7;

vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
{

    // make a adjlist
    vector<vector<pair<int, int>>> adjList(V, vector<pair<int, int>>());

    for (int i = 0; i < edges.size(); i++)
    {
        adjList[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        adjList[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }

    set<pair<int, int>> distNodeSet;
    vector<int> distance(V, INF);
    distance[src] = 0;

    distNodeSet.insert({0, src});

    while (!distNodeSet.empty())
    {
        int curDist = (*distNodeSet.begin()).first;
        int curNode = (*distNodeSet.begin()).second;
        distNodeSet.erase({curDist, curNode});

        int neibCount = adjList[curNode].size();
        for (int i = 0; i < neibCount; i++)
        {
            int curNeib = adjList[curNode][i].first;
            int neibCurDist = distance[curNeib];
            int neibDist = adjList[curNode][i].second;
            int newEstDist = distance[curNode] + neibDist;

            if (neibCurDist > newEstDist)
            {
                if (distance[curNeib] != INF)
                {
                    distNodeSet.erase({distance[curNeib], curNeib});
                }
                distance[curNeib] = newEstDist;
                distNodeSet.insert({newEstDist, curNeib});
            }
        }
    }

    return distance;
}

int main()
{
}