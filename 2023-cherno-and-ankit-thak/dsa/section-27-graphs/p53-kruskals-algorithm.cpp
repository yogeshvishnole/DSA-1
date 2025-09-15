/*
Why Exists ?
To find the minimum spanning tree of a graph.

It is exaclty the same approach that I think by myself for finding the MST of graph i.e.(my
approach)-
I myself find an approach to draw the MST that is -
1. write all the edge weights in ascending order.
2. start from start of that ascending weight sorted list pick the first edge, if that is
not causing cycle take that, if causing cycle move to next edge and when all the nodes are
covered in the tree means all visited stop at that point and you will see that the MST has
been drawn.

Implementation -

1. Sort the edges in ascending order.
2. create a disjoin set union datastructure.
3. go over the sorted edge list and see if doing union by adding edge if the nodes belong to
same component if yes dont add that edge to MST otherwise add it to the MST edges list.


*/

#include <iostream>
#include <algorithm>
#include "p52-disjoint-set-datastructure.cpp"
using namespace std;

class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> &edges)
    {
        sort(edges.begin(), edges.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[2] < b[2]; });
        // here only we need mst weight thats why I will not maintain the mst edges list
        // or lets maintain but we have no usage for it

        vector<vector<int>> mstEdges;
        int mstWeight = 0;

        DisjointSet ds(V);

        for (int i = 0; i < edges.size(); i++)
        {
            // check if nodes are already connected and also insert do their union if not
            if (ds.unionBySize(edges[i][0], edges[i][1]))
            {
                continue;
            }
            mstEdges.push_back(edges[i]);
            mstWeight += edges[i][2];
        }
        return mstWeight;
    }
};

int main() {}