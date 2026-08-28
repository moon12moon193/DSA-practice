# Shortest Path in an Unweighted Graph

## 📌 Overview

This solution finds the shortest distance between a source vertex and a destination vertex in an **unweighted, undirected graph**.

Since every edge has the same weight (`1`), **Breadth-First Search (BFS)** is used. BFS explores the graph level by level, so the first time a vertex is reached, it is reached through the shortest possible path.

---

## 🧠 Approach

The solution follows these steps:

1. Convert the edge list into an **adjacency list**.
2. Create a `visited` array to keep track of visited vertices.
3. Use a queue to perform **BFS**.
4. Store each node in the queue along with its current distance from the source.
5. When an unvisited neighbor is found:

   * Mark it as visited.
   * Add it to the queue.
   * Increase its distance by `1`.
6. Store the calculated distance for every visited node.
7. Return the distance of the destination vertex.
8. If the destination cannot be reached, return `-1`.

---

## 🔹 Graph Representation

The input is given as an edge list:

```cpp
vector<vector<int>> edges
```

Each edge contains two vertices:

```text
[u, v]
```

Because the graph is undirected, both connections are added:

```cpp
adj[u].push_back(v);
adj[v].push_back(u);
```

For example:

```text
Edges:
0 -- 1
1 -- 2
2 -- 3
```

The adjacency list becomes:

```text
0 → 1
1 → 0, 2
2 → 1, 3
3 → 2
```

---

## 🔹 BFS

A queue stores:

```cpp
{node, distance}
```

Initially:

```cpp
q.push({src, 0});
```

This means the source has distance `0`.

When visiting a neighbor:

```cpp
q.push({neighbour, desc + 1});
```

The distance increases by one because every edge has the same weight.

---

## 🔹 Why BFS?

BFS visits vertices according to their distance from the source:

```text
Distance 0 → Source

Distance 1 → Direct neighbors

Distance 2 → Neighbors of neighbors

Distance 3 → Next level
```

Therefore, the first time a node is visited, BFS has found the shortest path to that node.

This makes BFS ideal for finding shortest paths in an **unweighted graph**.

---

## 💻 Implementation

```cpp
class Solution {
public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {

        int n = edges.size();

        // Build adjacency list
        vector<vector<int>> adj(V);

        for (int i = 0; i < n; i++) {
            vector<int> e = edges[i];

            int src = e[0];
            int desti = e[1];

            adj[src].push_back(desti);
            adj[desti].push_back(src);
        }

        // Visited array
        vector<bool> vis(V, false);

        // Distance array
        vector<int> res(V, 0);

        // BFS queue: {node, distance}
        queue<pair<int, int>> q;

        q.push({src, 0});
        vis[src] = true;

        while (!q.empty()) {

            pair<int, int> p = q.front();
            q.pop();

            int node = p.first;
            int desc = p.second;

            res[node] = desc;

            for (int i = 0; i < adj[node].size(); i++) {

                int neighbour = adj[node][i];

                if (vis[neighbour] == false) {

                    q.push({neighbour, desc + 1});
                    vis[neighbour] = true;
                }
            }
        }

        // Destination was not reached
        if (res[dest] == 0) {
            return -1;
        }

        return res[dest];
    }
};
```

---

## ⏱️ Complexity

Let:

* `V` = number of vertices
* `E` = number of edges

### Time Complexity

Building the adjacency list:

```text
O(E)
```

BFS traversal:

```text
O(V + E)
```

Overall:

```text
O(V + E)
```

### Space Complexity

Adjacency list:

```text
O(V + E)
```

Visited array:

```text
O(V)
```

Distance array:

```text
O(V)
```

Queue:

```text
O(V)
```

Overall:

```text
O(V + E)
```

---

## ⚠️ Important Edge Case

There is one issue with using:

```cpp
vector<int> res(V, 0);
```

and later checking:

```cpp
if (res[dest] == 0)
    return -1;
```

The source itself has distance `0`, so if:

```text
src == dest
```

the code would incorrectly return `-1`.

A safer approach is to initialize distances with `-1`:

```cpp
vector<int> res(V, -1);
```

Then:

```cpp
res[src] = 0;
```

and at the end:

```cpp
return res[dest];
```

This naturally returns:

* `0` if source and destination are the same.
* The shortest distance if the destination is reachable.
* `-1` if the destination is unreachable.

---

## 🎯 Key Concept

> **BFS gives the shortest path in an unweighted graph because it explores nodes level by level.**

Remember:

```text
Unweighted Graph → BFS
Weighted Graph   → Dijkstra / Bellman-Ford (depending on weights)
```

The most important pattern to remember is:

```cpp
queue<pair<int, int>> q;

q.push({src, 0});
vis[src] = true;

while (!q.empty()) {

    auto [node, distance] = q.front();
    q.pop();

    for (int neighbour : adj[node]) {

        if (!vis[neighbour]) {

            vis[neighbour] = true;

            q.push({neighbour, distance + 1});
        }
    }
}
```

This pattern is useful for many **shortest-distance problems on unweighted graphs**.
