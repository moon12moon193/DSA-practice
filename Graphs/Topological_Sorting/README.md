# Topological Sort

## 📌 Overview

Topological Sort is a linear ordering of the vertices of a **Directed Acyclic Graph (DAG)** such that for every directed edge:

```text
u → v
```

vertex `u` appears before vertex `v` in the ordering.

This implementation uses **Kahn's Algorithm**, which is based on **BFS (Breadth-First Search)** and indegree values.

---

## 🧠 Approach

The algorithm works as follows:

1. Create an **adjacency list** for the directed graph.
2. Calculate the **indegree** of every vertex.

   * Indegree = number of incoming edges to a vertex.
3. Put all vertices having `indegree = 0` into a queue.
4. Process vertices from the queue:

   * Remove a vertex.
   * Add it to the result.
   * Visit all its neighboring vertices.
   * Decrease their indegree by `1`.
   * If a neighbor's indegree becomes `0`, add it to the queue.
5. Continue until the queue becomes empty.
6. The resulting array contains the topological ordering.

---

## 🔍 Example

Consider the directed graph:

```text
0 → 1
0 → 2
1 → 3
2 → 3
```

### Indegree

```text
Vertex:    0  1  2  3
Indegree:  0  1  1  2
```

Initially, vertex `0` has indegree `0`, so it is added to the queue.

Processing:

```text
Queue: [0]

Process 0
Result: [0]

Queue: [1, 2]

Process 1
Result: [0, 1]

Process 2
Result: [0, 1, 2]

Process 3
Result: [0, 1, 2, 3]
```

One possible topological ordering is:

```text
0 1 2 3
```

Another valid ordering could be:

```text
0 2 1 3
```

Multiple valid topological orderings can exist.

---

## 💻 Implementation

```cpp
class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adj(V);
        vector<int> indegrees(V, 0);

        // Build adjacency list and calculate indegrees
        for (int i = 0; i < edges.size(); i++) {
            vector<int> p = edges[i];

            int src = p[0];
            int dest = p[1];

            adj[src].push_back(dest);
            indegrees[dest]++;
        }

        queue<int> q;
        vector<int> res;

        // Add vertices with indegree 0
        for (int i = 0; i < indegrees.size(); i++) {
            if (indegrees[i] == 0) {
                q.push(i);
            }
        }

        // Kahn's Algorithm
        while (!q.empty()) {

            int value = q.front();
            q.pop();

            res.push_back(value);

            for (int i = 0; i < adj[value].size(); i++) {

                int neighbour = adj[value][i];

                indegrees[neighbour]--;

                if (indegrees[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }

        return res;
    }
};
```

---

## ⏱️ Complexity

Let:

* `V` = number of vertices
* `E` = number of edges

### Time Complexity

```text
O(V + E)
```

Each vertex is processed once, and every edge is visited once.

### Space Complexity

```text
O(V + E)
```

Space is used for:

* Adjacency list
* Indegree array
* Queue
* Result array

---

## ⚠️ Important Condition

Topological sorting is only possible for a **DAG (Directed Acyclic Graph)**.

If the graph contains a cycle, a complete topological ordering cannot be produced.

For example:

```text
0 → 1
↑   ↓
└── 2
```

Here:

```text
0 → 1 → 2 → 0
```

forms a cycle.

In Kahn's Algorithm, the number of vertices in `res` will be less than `V` when a cycle exists.

```cpp
if (res.size() != V) {
    // Cycle exists
}
```

---

## 🔑 Key Concepts

* Directed Graph
* DAG
* Adjacency List
* Indegree
* Queue
* BFS
* Kahn's Algorithm
* Topological Ordering
* Cycle Detection

---

## 📝 Important Idea to Remember

The main idea behind Kahn's Algorithm is:

```text
Find nodes with no dependencies
        ↓
Put them in queue
        ↓
Remove/process them
        ↓
Remove their outgoing edges
        ↓
Find new nodes with no dependencies
        ↓
Repeat
```

In short:

> **Topological Sort using Kahn's Algorithm = Indegree + Queue + BFS**
