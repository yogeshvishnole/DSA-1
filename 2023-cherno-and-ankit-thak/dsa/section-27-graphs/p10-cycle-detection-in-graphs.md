### What is a cycle in a graph?

A **cycle** in a graph is a path that starts and ends at the same vertex, and all edges and vertices (except the starting/ending vertex) are unique in that path.

---

### Cycle in an Undirected Graph:

In an **undirected graph**, a cycle is present if, during a traversal (DFS or BFS), you encounter a node that you have already visited and it is not the parent of the current node.

#### Example:

```
A -- B
|    |
C -- D
```

Here, `A-B-D-C-A` forms a cycle.

### Cycle in a Directed Graph:

In a **directed graph**, a cycle exists if there is a path starting from a vertex that eventually leads back to itself following the direction of edges.

#### Example:

```
A → B → C → A
```

This forms a cycle `A → B → C → A`.

---

### Cycle Detection Algorithms

#### 1. Cycle Detection in an Undirected Graph:

- **DFS Approach:**
    - Keep track of visited nodes.
    - For each node, when visiting its neighbors, if a neighbor is already visited **and it is not the parent**, then there is a cycle.

- **Union-Find (Disjoint Set Union - DSU) Approach:**
    - Detects a cycle by grouping nodes and checking if two nodes belong to the same group before connecting them.
    - If they are already in the same group, a cycle exists.

#### 2. Cycle Detection in a Directed Graph:

- **DFS with Recursion Stack Approach:**
    - Maintain two arrays:
        - `visited[]` – marks nodes already visited.
        - `recStack[]` – keeps track of nodes in the current recursion stack.
    - If a node is revisited and is still in the recursion stack, then a cycle is found.


- **Kahn's Algorithm (Topological Sort):**
    - A **directed graph has a cycle if and only if topological sorting is not possible** (i.e., all nodes are not covered during sorting).
    - It is a BFS-based approach using in-degrees.

---

### Key Difference in Detection:

| Undirected Graph                         | Directed Graph                          |
|------------------------------------------|----------------------------------------|
| Use **DFS + parent check** or **Union-Find** | Use **DFS + recursion stack** or **Kahn’s Algorithm** |
| A back-edge to any node (other than parent) is a cycle | A back-edge to any node already in the current DFS path (recStack) is a cycle |
| Simpler to detect | Slightly more complex due to directionality |