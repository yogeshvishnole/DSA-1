/*

Prims Algorithm -> Greedy approach(select the minimum weight edges, as we know that the node
will be there in mst 100%)

Purpose -> To find the minimum spanning tree of a undirected weighted graph.

What is spanning tree ?
The tree form of a given undirected weighted graph of n nodes with exactly n-1 edges in such
a manner that each node is reachable from every other node.

Then what is minimum spanning tree (MST) ?
A graph can have multiple spanning trees, the spanning tree whose sum of weights of edges is
minimum is called as minimum spanning tree.

Striver gives a graphs and ask to draw the MST of that graph, then while solving that
I myself find an approach to draw the MST that is -
1. write all the edge weights in ascending order.
2. start from start of that ascending weight sorted list pick the first edge, if that is
not causing cycle take that, if causing cycle move to next edge and when all the nodes are
covered in the tree means all visited stop at that point and you will see that the MST has
been drawn.

Prims algorithm is just better written approach for above approach using the priority queue
and visited array.

Setup for prims -
1.Create a priority queue with element as trio of
<weight,node,parent>
2. push any node as source node with weight 0 and parent as -1 in priority queue.
3. Create a visited array, all non visited initially means all 0.
4.Create a vector for storing the MST edges.
5.loop until pq is not empty, put the popped out element in mst edges <parent,node>, if node
is not already visited.
6. then traverse the popped out node neighbours and put them in queue if not visited.

Lets implement -
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> &edges)
    {
        // lets first create the graph
        vector<vector<pair<int, int>>> graph(V, vector<pair<int, int>>());

        for (int i = 0; i < edges.size(); i++)
        {
            graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            graph[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }

        // create a priority queue
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, -1}});

        vector<int> visited(V, 0);

        vector<vector<int>> mstEdges;

        while (!pq.empty())
        {
            auto el = pq.top();
            int weight = el.first;
            int curNode = el.second.first;
            int curNodeParent = el.second.second;
            pq.pop();

            if (!visited[curNode])
            {
                vector<int> mstEdge;
                mstEdge.push_back(curNodeParent);
                mstEdge.push_back(curNode);
                mstEdge.push_back(weight);
                mstEdges.push_back(mstEdge);
                visited[curNode] = 1;
            }
            else
            {
                continue;
            }

            // loop over the neighbours
            for (auto neib : graph[curNode])
            {
                int neibNode = neib.first;
                int neibDist = neib.second;

                if (!visited[neibNode])
                {
                    pq.push({neibDist, {neibNode, curNode}});
                }
            }
        }

        int mstWeight = 0;

        for (int i = 0; i < mstEdges.size(); i++)
        {
            mstWeight += mstEdges[i][2];
        }

        return mstWeight;
    }
};

int mian() {}