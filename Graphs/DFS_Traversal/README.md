# Graph DFS — Adjacency List Traversal

This folder contains my practice of **Depth First Search (DFS)** on a graph represented using an **Adjacency List** in C++.

The implementation starts traversal from vertex `0` and recursively explores every unvisited neighboring vertex.

---

## 📌 Concepts Used

* Depth First Search (DFS)
* Recursion
* Adjacency List
* Visited Array
* Graph Traversal
* Recursive Backtracking

---

## 🧠 What Is DFS?

**Depth First Search (DFS)** is a graph traversal technique where we:

1. Start from a vertex.
2. Mark it as visited.
3. Visit one unvisited neighbor.
4. Continue going deeper.
5. When there are no more unvisited neighbors, backtrack.
6. Continue until all reachable vertices are visited.

The basic idea is:

```text
Start
  ↓
Visit node
  ↓
Visit an unvisited neighbor
  ↓
Go deeper
  ↓
Continue...
  ↓
No unvisited neighbor
  ↓
Backtrack
```

---

## 🗺️ Graph Representation

The graph is represented using an adjacency list:

```cpp
vector<vector<int>>& adj
```

For example:

```text
0 → 1, 2
1 → 0, 3
2 → 0
3 → 1
```

Here, `adj[node]` contains all the neighbors of that node.

---

## 👀 Visited Array

A visited array is used to keep track of which vertices have already been visited.

```cpp
vector<bool> vis(n, false);
```

Initially:

```text
false → Not visited
true  → Visited
```

When DFS reaches a node:

```cpp
vis[node] = true;
```

This prevents the same node from being visited repeatedly.

---

## 🔄 Recursive DFS Function

The recursive function is:

```cpp
void fun(
    vector<vector<int>>& adj,
    vector<int>& res,
    int node,
    vector<bool>& vis
)
```

It receives:

* `adj` → adjacency list
* `res` → stores DFS traversal
* `node` → current vertex
* `vis` → visited array

---

## 📥 Step 1: Store the Current Node

When DFS reaches a node:

```cpp
res.push_back(node);
```

This stores the node in the traversal result.

---

## 👁️ Step 2: Mark the Node Visited

```cpp
vis[node] = true;
```

Now the node will not be processed again.

---

## 🔎 Step 3: Explore Neighbors

We go through every neighbor of the current node:

```cpp
for (int i = 0; i < adj[node].size(); i++) {
    int neighbour = adj[node][i];

    if (vis[neighbour] == false) {
        fun(adj, res, neighbour, vis);
    }
}
```

The important part is:

```cpp
if (vis[neighbour] == false)
```

We only perform DFS on an **unvisited neighbor**.

---

## 🌳 How Recursion Works

Suppose the traversal starts at:

```text
0
```

and the graph looks like:

```text
0
├── 1
│   └── 3
└── 2
```

DFS goes approximately like:

```text
0
 ↓
1
 ↓
3
 ↓
Backtrack
 ↓
2
```

The recursion automatically handles the backtracking.

---

## 🔙 What Is Backtracking Here?

Consider:

```cpp
fun(adj, res, neighbour, vis);
```

When this function is called, the current function pauses.

The new function explores deeper.

Once that function finishes, execution returns to the previous function and continues checking the remaining neighbors.

For example:

```text
fun(0)
  ↓
fun(1)
  ↓
fun(3)
  ↓
return to fun(1)
  ↓
return to fun(0)
  ↓
visit next neighbor
```

This is why recursion is very natural for DFS.

---

## 🚀 Starting the DFS

The traversal starts from vertex `0`:

```cpp
int node = 0;
fun(adj, res, node, vis);
```

So the first node processed is always:

```text
0
```

---

## 🧩 Complete Algorithm

```text
1. Create an empty result vector.
        ↓
2. Create a visited array.
        ↓
3. Start DFS from node 0.
        ↓
4. Add current node to result.
        ↓
5. Mark current node visited.
        ↓
6. Check all its neighbors.
        ↓
7. If a neighbor is unvisited,
   recursively call DFS.
        ↓
8. Continue until all reachable nodes are visited.
        ↓
9. Return the traversal result.
```

---

## ⚠️ Why Do We Need the Visited Array?

Graphs can contain cycles.

For example:

```text
0 → 1
↑   ↓
└── 2
```

Without a visited array, DFS could repeatedly travel:

```text
0 → 1 → 2 → 0 → 1 → 2 → ...
```

This could cause infinite recursion.

The visited array stops this behavior.

---

## ⏱️ Time Complexity

Let:

* `V` = number of vertices
* `E` = number of edges

Each vertex is visited once, and each adjacency-list entry is processed once.

Therefore:

```text
Time Complexity = O(V + E)
```

---

## 💾 Space Complexity

The visited array requires:

```text
O(V)
```

The result vector stores:

```text
O(V)
```

The recursive call stack can also reach:

```text
O(V)
```

in the worst case.

Therefore:

```text
Space Complexity = O(V)
```

excluding the input adjacency list.

---

## 🧠 Key Takeaways

* DFS explores a graph deeply before moving to another branch.
* DFS can be implemented using recursion.
* An adjacency list provides the neighbors of each node.
* A visited array prevents repeated visits.
* Recursion automatically provides the backtracking behavior.
* `res` stores the order in which nodes are visited.
* DFS traversal has a time complexity of `O(V + E)`.

---

## 🔥 Pattern to Remember

Whenever you need to perform recursive DFS on an adjacency list, remember this pattern:

```text
DFS(node)
   ↓
Mark node visited
   ↓
Store/process node
   ↓
For every neighbor
   ↓
If neighbor is unvisited
   ↓
DFS(neighbor)
```

### C++ Template

```cpp
void dfs(int node,
         vector<vector<int>>& adj,
         vector<bool>& vis) {

    vis[node] = true;

    for (int neighbour : adj[node]) {

        if (!vis[neighbour]) {
            dfs(neighbour, adj, vis);
        }
    }
}
```

This pattern will be useful for many Graph DSA problems involving **traversal, connectivity, components, and cycle detection**.
