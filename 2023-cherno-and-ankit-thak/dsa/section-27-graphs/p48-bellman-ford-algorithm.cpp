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

*/

