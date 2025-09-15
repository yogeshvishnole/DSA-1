/*
NOTE:- very useful for, Is nodes connected queries in dynamically growing
graphs.

My Questions -

What is DisjointSet or DisjoinSet-Union DataStructure  ?
Why it is used ?

How to make it ?
Union By Rank ?
Union By Size ?

Find parent ?

Path compression ?

Above are my questions, the answer of claude for above questions -

What is Disjoint Set Data Structure?

A Disjoint Set, also known as Union-Find or Disjoint Set Union (DSU), is a data structure that
keeps track of a set of elements partitioned into disjoint (non-overlapping) subsets.
It supports two primary operations:

Find: Determine which subset a particular element belongs to
Union: Join two subsets into a single subset

Why is it used?

Disjoint Set is particularly useful for:

Connected Components: Finding connected components in graphs or either finding, if two
nodes belong to the same component or not.(if they are connected).
Cycle Detection: Detecting cycles in undirected graphs
Minimum Spanning Tree: Kruskal's algorithm uses Union-Find
Network Connectivity: Determining if two nodes are connected
Percolation Problems: Modeling systems like water flow through porous materials
Image Processing: Connected component labeling
Social Networks: Finding friend groups or communities

Key Concepts Explained

Union By Rank

Idea: Always attach the tree with smaller rank (depth) under the root of the tree with larger
rank
Rank: The upper bound on the height of the tree
Why it works: Keeps trees relatively flat, preventing degenerate chains
Time Complexity: O(α(n)) per operation with path compression

Union By Size

Idea: Always attach the smaller tree under the root of the larger tree
Size: The actual number of nodes in the tree
Why it works: Ensures the depth doesn't grow too quickly
Time Complexity: O(α(n)) per operation with path compression

Both strategies achieve similar performance, with union by size being slightly more intuitive.

Find Parent (with Path Compression)
Path compression is a crucial optimization that flattens the tree structure:

Without path compression: Finding parent requires traversing up the tree (can be O(n))
With path compression: During find operation, make every node point directly to the root
Result: Future find operations become nearly constant time

The path compression happens during the find operation by updating each node's parent to point
directly to the root.
Time Complexity Summary

Without optimizations: O(n) per operation
With union by rank/size only: O(log n) per operation
With path compression only: O(log n) amortized per operation
With both optimizations: O(α(n)) per operation, where α is the inverse Ackermann function
(practically constant)

Space Complexity
O(n) for storing parent array and rank/size arrays.

*/

#include <iostream>
#include <vector>
using namespace std;

class DisjointSet
{
    vector<int> parent, rank, size;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);

        for (int i = 0; i < parent.size(); i++)
        {
            parent[i] = i;
        }
    }

    int findUlParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findUlParent(parent[node]);
    }

    bool unionByRank(int u, int v)
    {
        int u_ulp = findUlParent(u);
        int v_ulp = findUlParent(v);
        if (v_ulp == u_ulp)
            return true;

        if (rank[u_ulp] < rank[v_ulp])
        {
            parent[u_ulp] = v_ulp;
        }
        else if (rank[u_ulp] > rank[v_ulp])
        {
            parent[v_ulp] = u_ulp;
        }
        else
        {
            parent[v_ulp] = u_ulp;
            rank[u_ulp]++;
        }

        return false;
    }

    bool unionBySize(int u, int v)
    {
        int u_ulp = findUlParent(u);
        int v_ulp = findUlParent(v);

        if (v_ulp == u_ulp)
            return true;

        if (size[u_ulp] < size[v_ulp])
        {
            parent[u_ulp] = v_ulp;
            size[v_ulp]++;
        }
        else
        {
            parent[v_ulp] = u_ulp;
            size[u_ulp]++;
        }
        return false;
    }
};

// int main()
// {
//     DisjointSet ds(7);
//     ds.unionBySize(1, 2);
//     ds.unionBySize(2, 3);
//     ds.unionBySize(4, 5);
//     ds.unionBySize(6, 7);
//     ds.unionBySize(5, 6);

//     if (ds.findUlParent(3) == ds.findUlParent(7))
//     {
//         cout << "Connected" << endl;
//     }
//     else
//     {
//         cout << "Not Connected" << endl;
//     }
//     cout << endl;

//     ds.unionByRank(3, 7);

//     if (ds.findUlParent(3) == ds.findUlParent(7))
//     {
//         cout << "Connected" << endl;
//     }
//     else
//     {
//         cout << "Not Connected" << endl;
//     }
//     cout << endl;
// }