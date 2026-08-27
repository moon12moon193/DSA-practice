# Graph DFS — Cycle Detection in Undirected Graph

This folder contains my practice of **cycle detection in an undirected graph using DFS** in C++.

The approach uses an **Adjacency List**, **Visited Array**, **Recursion**, and a **Parent Node** to determine whether a cycle exists.

---

## 📌 Concepts Used

* Undirected Graph
* Adjacency List
* Depth First Search (DFS)
* Recursion
* Visited Array
* Parent Node
* Cycle Detection
* Connected Components

---

## 🧠 Core Idea

While performing DFS in an undirected graph, we keep track of the **parent** of the current node.

When we encounter a neighbor:

### Case 1: Neighbor is not visited

We continue DFS:

```cpp
dfs(adj, neighbour, node, vis, cycle);
```

The current node becomes the parent of the neighbor.

### Case 2: Neighbor is already visited

If the visited neighbor is **not the parent**, then we have found a cycle.

```cpp
if (vis[neighbour] == true && neighbour != parent) {
    cycle = true;
}
```

This is the key condition for detecting a cycle in an undirected graph using DFS.

---

## 🌐 Why Do We Need the Parent?

Consider a simple connection:

```text
0 — 1
```

When DFS goes:

```text
0 → 1
```

Node `1` sees `0` as an already visited neighbor.

But `0` is the **parent** of `1`.

So this should **not** be considered a cycle.

That's why we check:

```cpp
neighbour != parent
```

---

## 🔄 Cycle Detection Logic

The important pattern is:

```text
Current Node
     ↓
Check Neighbor
     ↓
Is Neighbor Visited?
     ↓
   Yes
     ↓
Is Neighbor the Parent?
   ↙       ↘
 Yes        No
  ↓          ↓
No Cycle   Cycle Found
```

So:

```cpp
visited neighbor + not parent = cycle
```

---

## 🏗️ Building the Adjacency List

The graph is first converted into an adjacency list:

```cpp
vector<vector<int>> adj(V);
```

For every undirected edge:

```cpp
adj[src].push_back(dest);
adj[dest].push_back(src);
```

Both directions are stored because the graph is undirected.

For example:

```text
0 — 1
```

becomes:

```text
0 → 1
1 → 0
```

---

## 👀 Visited Array

We maintain:

```cpp
vector<bool> vis(V, false);
```

Initially:

```text
false → Not visited
true  → Visited
```

When DFS enters a node:

```cpp
vis[node] = true;
```

This prevents repeated traversal.

---

## 🌳 DFS Function

The DFS function contains four important parameters:

```cpp
void dfs(
    vector<vector<int>>& adj,
    int node,
    int parent,
    vector<bool>& vis,
    bool& cycle
)
```

### `adj`

Stores the graph.

### `node`

Represents the current vertex.

### `parent`

Stores the vertex from which we reached the current node.

### `vis`

Tracks visited vertices.

### `cycle`

Stores whether a cycle has been found.

---

## 🔍 Exploring Neighbors

For every neighbor:

```cpp
for (int i = 0; i < adj[node].size(); i++) {
    int neighbour = adj[node][i];
```

We have two possibilities.

### Unvisited Neighbor

```cpp
if (vis[neighbour] == false) {
    dfs(adj, neighbour, node, vis, cycle);
}
```

The current `node` becomes the `parent` of `neighbour`.

### Visited Neighbor

```cpp
if (vis[neighbour] == true && neighbour != parent) {
    cycle = true;
}
```

If the neighbor is already visited and isn't the parent, a cycle exists.

---

## 🧩 Example

Consider:

```text
0
| \
1—2
```

Starting DFS from `0`:

```text
0 → 1 → 2
```

While processing `2`, it finds `0` as an already visited neighbor.

But:

```text
0 != parent of 2
```

Therefore:

```text
Cycle Found
```

---

## 🌍 Handling Disconnected Graphs

A graph may contain multiple disconnected components.

For example:

```text
Component 1:

0 — 1


Component 2:

2 — 3 — 4
```

Starting DFS only from `0` would not visit `2`, `3`, or `4`.

Therefore, we loop through every vertex:

```cpp
for (int i = 0; i < V; i++) {
    if (vis[i] == 0) {
        dfs(adj, i, -1, vis, cycle);
    }
}
```

If a node hasn't been visited, we start a new DFS from it.

This ensures **every connected component** is checked.

---

## 🏁 Why Is Parent Initially `-1`?

For the first node of a DFS traversal, there is no parent.

Therefore:

```cpp
dfs(adj, i, -1, vis, cycle);
```

We use `-1` to represent:

```text
No Parent
```

Since valid vertex indices are normally `0` to `V-1`, `-1` cannot represent a real vertex.

---

## 🔄 Complete Algorithm

```text
1. Create an adjacency list.
        ↓
2. Add every undirected edge in both directions.
        ↓
3. Create a visited array.
        ↓
4. Iterate through every vertex.
        ↓
5. If the vertex is unvisited,
   start DFS.
        ↓
6. Mark current vertex visited.
        ↓
7. Check every neighbor.
        ↓
8. If neighbor is unvisited,
   recursively visit it.
        ↓
9. If neighbor is visited and isn't the parent,
   a cycle exists.
        ↓
10. Continue until all components are checked.
```

---

## ⚠️ Important Point

For an **undirected graph**, simply finding a visited neighbor does **not** always mean there is a cycle.

We must check:

```cpp
neighbour != parent
```

Therefore, remember:

```text
Visited Neighbor
        +
Not Parent
        =
Cycle
```

---

## ⏱️ Time Complexity

Let:

* `V` = number of vertices
* `E` = number of edges

Building the adjacency list takes:

```text
O(V + E)
```

DFS also visits every vertex and processes every edge:

```text
O(V + E)
```

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

The visited array requires:

```text
O(V)
```

The recursive DFS stack can require:

```text
O(V)
```

Therefore, total auxiliary space is:

```text
Space Complexity = O(V + E)
```

including the graph representation.

---

## 🧠 Key Takeaways

* DFS can be used to detect cycles in an undirected graph.
* The **parent node** is essential.
* A visited neighbor is not necessarily a cycle.
* If the visited neighbor is not the parent, a cycle exists.
* A visited array prevents repeated traversal.
* Every disconnected component must be checked.
* The initial DFS node has parent `-1`.
* The overall complexity is `O(V + E)`.

---

## 🔥 Pattern to Remember

For cycle detection in an **undirected graph using DFS**, remember:

```text
DFS(node, parent)
       ↓
Mark node visited
       ↓
Check every neighbor
       ↓
Is neighbor unvisited?
   ↙            ↘
 Yes             No
  ↓               ↓
DFS(neighbor,     Is neighbor
node)             parent?
                ↙       ↘
              Yes        No
               ↓          ↓
          Ignore       Cycle
```

### C++ Template

```cpp
void dfs(
    vector<vector<int>>& adj,
    int node,
    int parent,
    vector<bool>& vis
) {
    vis[node] = true;

    for (int neighbour : adj[node]) {

        if (!vis[neighbour]) {
            dfs(adj, neighbour, node, vis);
        }
        else if (neighbour != parent) {
            // Cycle detected
        }
    }
}
```

This parent-based DFS pattern is a fundamental technique for **undirected graph cycle detection**.
