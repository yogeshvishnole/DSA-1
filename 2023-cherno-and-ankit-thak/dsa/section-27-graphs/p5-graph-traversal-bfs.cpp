/*
What is Breadth-First Traversal (BFS) in Graphs?
Breadth-First Traversal (also called Breadth-First Search, BFS) is an algorithm
used to visit all the vertices of a graph (or nodes of a tree) in breadthward
motion. That means it visits all the nodes level by level (i.e., all neighbors
of a node are visited before moving to the next level of neighbors).

How BFS Works:
Starting Point:
Begin at a selected node (called the "source" node).

Queue Data Structure:
BFS uses a queue to keep track of nodes to visit next.

Visited Tracking:
A visited list or set is used to ensure each node is visited only once (to
prevent infinite loops in cyclic graphs).

Process:

Enqueue the starting node and mark it as visited.
While the queue is not empty:
Dequeue a node.
Visit all of its unvisited adjacent nodes (neighbors).
Mark each neighbor as visited and enqueue them.
Steps Example:
For graph:

mathematica
Copy
Edit
A -- B -- D
|    |
C -- E
Start at A:

Queue: [A], Visited: {A}
Dequeue A -> neighbors B and C
Queue: [B, C], Visited: {A, B, C}
Dequeue B -> neighbors D and E
Queue: [C, D, E], Visited: {A, B, C, D, E}
Continue until queue is empty.
Order of traversal:
A -> B -> C -> D -> E

Characteristics:
Finds the shortest path in an unweighted graph.
Can be used to detect cycles.
Time complexity: O(V + E) (V = vertices, E = edges)
Space complexity: O(V) for visited list + queue.

why queue datastructure is used ?
ChatGPT said:
Great question! The queue is key to how BFS works. Here’s why a queue is used in BFS:

Reason for using a queue:
BFS is all about visiting nodes level by level, or breadth-first. The queue helps manage this order.

Core idea: First-In-First-Out (FIFO)
A queue follows the FIFO principle — the first node added is the first node removed. This perfectly matches how BFS should work:

When you visit a node, you explore all its immediate neighbors before moving on to the next level.
Neighbors get enqueued in the order they are discovered.
By dequeuing nodes in FIFO order, you ensure you are processing nodes layer by layer, maintaining the breadth-first approach.
What would happen without a queue?
If you used a stack (LIFO), you'd get Depth-First Search (DFS) behavior instead — it would go deep into one branch before backtracking.
Without any data structure, you’d lose track of which node to process next and may not properly explore the graph level by level.
Visualization
Imagine standing at node A, and A has neighbors B and C:

You enqueue B and C.
Then you dequeue B and explore B's neighbors.
After that, you dequeue C and explore C's neighbors.
The queue ensures that B is fully processed before C, maintaining the correct order of levels.



*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

void bfs(unordered_map<int, vector<int>> &graph, int source)
{
    int n = graph.size();
    vector<int> visited(n + 1, 0);

    queue<int> q;
    q.push(source);
    visited[source] = 1;

    while (!q.empty())
    {
        int curVertex = q.front();
        q.pop();
        cout << curVertex << " ";

        for (int nbr : graph[curVertex])
        {
            if (!visited[nbr])
            {
                q.push(nbr);
                visited[nbr] = 1;
            }
        }
    }
}

int main()
{

    vector<vector<int>> edgeList = {
        {1, 0},
        {0, 5},
        {0, 2},
        {3, 2},
        {3, 4}};

    unordered_map<int, vector<int>> graph;

    for (int i = 0; i < edgeList.size(); i++)
    {
        int a = edgeList[i][0], b = edgeList[i][1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bfs(graph, 0);
}