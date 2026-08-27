# Graph DFS — Cycle Detection in Directed Graph

This folder contains my practice of **cycle detection in a directed graph using DFS** in C++.

The implementation uses two boolean arrays:

* `vis` → keeps track of nodes that have already been visited.
* `path` → keeps track of nodes that are currently present in the active DFS recursion path.

This is different from cycle detection in an undirected graph because a **parent node is not used** here.

---

## 📌 Concepts Used

* Directed Graph
* Adjacency List
* Depth First Search (DFS)
* Recursion
* Visited Array
* Recursion Path Array
* Cycle Detection
* Connected Components
* Backtracking

---

## 🧠 Core Idea

In a directed graph, a cycle exists when during DFS we encounter a node that:

```text
has already been visited
        AND
is still present in the current DFS path
```

The important condition is:

```cpp
if (vis[neighbour] == true && path[neighbour] == true) {
    cycle = true;
}
```

The `path` array is the key concept in this approach.

---

## 🔄 Why Do We Need Two Arrays?

Using only `vis` is not enough.

We need to distinguish between:

```text
Visited at some point
```

and:

```text
Currently being explored in the same DFS path
```

Therefore, we use:

```cpp
vector<bool> vis(V, false);
vector<bool> path(V, false);
```

### `vis`

Answers:

> Have we ever visited this node?

### `path`

Answers:

> Is this node currently part of the active DFS recursion?

---

## 👀 Visited Array

When DFS enters a node:

```cpp
vis[node] = true;
```

Once a node becomes visited, it remains visited.

For example:

```text
false → Not visited
true  → Visited
```

This prevents us from unnecessarily exploring the same node again.

---

## 🛣️ Path Array

When DFS enters a node:

```cpp
path[node] = true;
```

This means:

```text
This node is currently in the active recursion path.
```

When DFS finishes processing that node:

```cpp
path[node] = false;
```

This is extremely important.

It means the node is no longer part of the current DFS path.

---

## 🌳 Understanding the DFS Path

Suppose DFS is currently exploring:

```text
0 → 1 → 2 → 3
```

Then:

```text
vis:
0 = true
1 = true
2 = true
3 = true

path:
0 = true
1 = true
2 = true
3 = true
```

All four nodes are currently in the recursion path.

If `3` points back to `1`:

```text
0 → 1 → 2 → 3
    ↑       |
    └───────┘
```

Then while processing `3`, we find:

```text
1 is visited
AND
1 is still in the current path
```

Therefore, a cycle exists.

---

## 🔥 The Most Important Condition

```cpp
if (vis[neighbour] == true && path[neighbour] == true) {
    cycle = true;
}
```

This can be remembered as:

```text
Visited Neighbor
      +
Currently in DFS Path
      =
Cycle
```

---

## ❓ Why Isn't `vis[neighbour] == true` Enough?

Consider:

```text
0 → 1
```

DFS visits `0`, then `1`.

After finishing `1`:

```text
vis[1] = true
path[1] = false
```

Now if another node later points to `1`, `1` is still visited:

```text
vis[1] = true
```

But:

```text
path[1] = false
```

This does **not** mean a cycle exists.

The node was visited previously, but it is no longer part of the current DFS path.

---

## 🔙 Backtracking

At the end of the DFS function:

```cpp
path[node] = false;
```

This represents backtracking.

For example:

```text
DFS(0)
  ↓
DFS(1)
  ↓
DFS(2)
  ↓
return from 2
  ↓
path[2] = false
  ↓
return from 1
  ↓
path[1] = false
  ↓
return from 0
  ↓
path[0] = false
```

The path array therefore represents the **current recursion chain**, not all previously visited nodes.

---

## 🏗️ Building the Directed Graph

The graph is represented using an adjacency list:

```cpp
vector<vector<int>> adj(V);
```

For every directed edge:

```cpp
adj[src].push_back(dest);
```

Only one direction is stored.

For example:

```text
0 → 1
```

is stored as:

```text
adj[0] → 1
```

We do **not** add:

```cpp
adj[1].push_back(0);
```

because the graph is directed.

---

## 🔄 DFS Process

The DFS function starts with:

```cpp
vis[node] = true;
path[node] = true;
```

Then it checks every neighbor.

### Case 1: Neighbor is already visited and in the current path

```cpp
if (vis[neighbour] && path[neighbour]) {
    cycle = true;
}
```

A cycle has been detected.

### Case 2: Neighbor has not been visited

```cpp
if (!vis[neighbour]) {
    dfs(adj, neighbour, vis, path, cycle);
}
```

We continue DFS.

### After Processing All Neighbors

```cpp
path[node] = false;
```

The node is removed from the active recursion path.

---

## 🌍 Handling Disconnected Graphs

A directed graph can contain multiple disconnected components.

For example:

```text
Component 1:

0 → 1 → 2


Component 2:

3 → 4 → 5
```

Starting DFS only from `0` would never reach `3`.

Therefore, we iterate through every vertex:

```cpp
for (int i = 0; i < V; i++) {
    if (vis[i] == false) {
        dfs(adj, i, vis, path, cycle);
    }
}
```

This ensures every component is checked.

---

## 🧩 Complete Algorithm

```text
1. Create an adjacency list.
        ↓
2. Add directed edges.
        ↓
3. Create visited array.
        ↓
4. Create path array.
        ↓
5. Iterate through every vertex.
        ↓
6. If vertex is unvisited,
   start DFS.
        ↓
7. Mark vertex visited.
        ↓
8. Mark vertex as part of current path.
        ↓
9. Check every neighbor.
        ↓
10. If neighbor is visited
    AND is in current path:
        ↓
      Cycle Found
        ↓
11. If neighbor is unvisited:
        ↓
      Continue DFS
        ↓
12. Remove current node from path.
        ↓
13. Continue until all components are checked.
```

---

## 🆚 Undirected vs Directed Cycle Detection

### Undirected Graph

The common DFS approach uses:

```text
Current Node
     ↓
Parent Node
```

Cycle condition:

```text
Visited Neighbor + Neighbor != Parent
```

### Directed Graph

The DFS approach uses:

```text
Current Node
     ↓
Current Recursion Path
```

Cycle condition:

```text
Visited Neighbor + Neighbor in Current Path
```

### Easy Way to Remember

```text
Undirected → Parent
Directed   → Path
```

---

## ⏱️ Time Complexity

Let:

* `V` = number of vertices
* `E` = number of edges

Every vertex and edge is processed at most once.

Therefore:

```text
Time Complexity = O(V + E)
```

---

## 💾 Space Complexity

The adjacency list requires:

```text
O(V + E)
```

The visited and path arrays require:

```text
O(V)
```

The recursive DFS stack can also reach:

```text
O(V)
```

Therefore:

```text
Space Complexity = O(V + E)
```

including the graph representation.

---

## 🧠 Key Takeaways

* Directed graph cycle detection can be done using DFS.
* A `visited` array tracks whether a node has ever been visited.
* A `path` array tracks whether a node is currently in the DFS recursion path.
* A cycle is detected when we find a neighbor that is both:

  * visited
  * currently in the recursion path
* `path[node] = false` is used during backtracking.
* A parent node is used for undirected graphs, while a recursion path is used for directed graphs.
* Every disconnected component must be checked.
* The overall complexity is `O(V + E)`.

---

## 🔥 Pattern to Remember

For **directed graph cycle detection using DFS**:

```text
DFS(node)
   ↓
vis[node] = true
   ↓
path[node] = true
   ↓
Check every neighbor
   ↓
Is neighbor visited?
   ↙             ↘
 No              Yes
 ↓                ↓
DFS(neighbor)   Is neighbor
                in path?
                ↙      ↘
              No       Yes
               ↓         ↓
            Continue    Cycle
   ↓
path[node] = false
```

### C++ Template

```cpp
void dfs(
    vector<vector<int>>& adj,
    int node,
    vector<bool>& vis,
    vector<bool>& path
) {
    vis[node] = true;
    path[node] = true;

    for (int neighbour : adj[node]) {

        if (vis[neighbour] && path[neighbour]) {
            // Cycle detected
        }

        if (!vis[neighbour]) {
            dfs(adj, neighbour, vis, path);
        }
    }

    path[node] = false;
}
```

This **visited + recursion-path** pattern is one of the most important techniques for detecting cycles in directed graphs.
