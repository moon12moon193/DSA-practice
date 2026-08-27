# Graph Representation — Adjacency List

This folder contains my practice of representing a graph using an **Adjacency List** in C++.

The implementation takes the number of vertices and a list of edges, then converts the edge representation into an adjacency list.

---

## 📌 Concepts Used

* Graph representation
* Vertices and edges
* Undirected graph
* Adjacency List
* `vector<vector<int>>`
* `pair<int, int>`
* Traversing an edge list

---

## 🧠 What Is an Adjacency List?

An adjacency list stores the neighbors of every vertex.

For example, if the edges are:

```text
0 — 1
0 — 2
1 — 3
```

The adjacency list will look like:

```text
0 → 1, 2
1 → 0, 3
2 → 0
3 → 1
```

Each vertex has a list containing the vertices directly connected to it.

---

## 🏗️ Creating the Adjacency List

First, we create an empty vector for every vertex:

```cpp
vector<vector<int>> adj(V);
```

If:

```text
V = 4
```

Initially:

```text
adj[0] → {}
adj[1] → {}
adj[2] → {}
adj[3] → {}
```

So there are `V` separate lists.

---

## 🔗 Processing Edges

Each edge is stored as a pair:

```cpp
pair<int, int> e = edges[i];
```

For example:

```text
e = {0, 2}
```

Then:

```cpp
int src = e.first;
int dest = e.second;
```

So:

```text
src  = 0
dest = 2
```

---

## ↔️ Adding an Undirected Edge

Because the graph is **undirected**, an edge between `src` and `dest` means both vertices are connected to each other.

Therefore, we add:

```cpp
adj[src].push_back(dest);
adj[dest].push_back(src);
```

For:

```text
src = 0
dest = 2
```

we get:

```text
adj[0] → 2
adj[2] → 0
```

This is the most important part to remember for an undirected graph.

---

## 🗺️ Visual Representation

Suppose we have:

```text
0 — 1
|   |
2 — 3
```

The adjacency list becomes:

```text
0 → 1, 2
1 → 0, 3
2 → 0, 3
3 → 1, 2
```

Each edge appears twice because the graph is undirected.

---

## 💡 Why Use an Adjacency List?

An adjacency list is useful because it stores only the connections that actually exist.

For a graph with many vertices but relatively few edges, it is much more memory-efficient than an adjacency matrix.

It is also very useful for:

* BFS
* DFS
* Cycle Detection
* Connected Components
* Shortest Path
* Topological Sort
* Other graph algorithms

---

## 📊 Adjacency List Structure

The declaration:

```cpp
vector<vector<int>> adj(V);
```

can be understood as:

```text
vector
  ↓
contains V vectors
  ↓
each vector stores neighbors
```

For example:

```text
adj
│
├── adj[0] → neighbors of 0
├── adj[1] → neighbors of 1
├── adj[2] → neighbors of 2
└── adj[3] → neighbors of 3
```

---

## 🔄 Algorithm

```text
Start
  ↓
Create V empty lists
  ↓
Go through every edge
  ↓
Extract source and destination
  ↓
Add destination to source's list
  ↓
Add source to destination's list
  ↓
Repeat for all edges
  ↓
Return adjacency list
```

---

## ⏱️ Time Complexity

Let:

* `V` = number of vertices
* `E` = number of edges

Creating the adjacency list:

```text
O(V)
```

Processing all edges:

```text
O(E)
```

Therefore:

```text
Time Complexity = O(V + E)
```

---

## 💾 Space Complexity

The adjacency list contains:

* `V` lists
* `2E` entries for an undirected graph

Therefore:

```text
Space Complexity = O(V + E)
```

---

## ⚠️ Important Difference: Directed vs Undirected

### Undirected Graph

Add the edge in both directions:

```cpp
adj[src].push_back(dest);
adj[dest].push_back(src);
```

### Directed Graph

Add the edge only from source to destination:

```cpp
adj[src].push_back(dest);
```

So always check whether the graph is **directed or undirected** before building the adjacency list.

---

## 🧠 Key Takeaways

* A graph consists of vertices and edges.
* An adjacency list stores the neighbors of each vertex.
* `vector<vector<int>>` is commonly used to implement it in C++.
* `pair<int,int>` can represent an edge.
* In an undirected graph, every edge is stored in both directions.
* Adjacency lists are especially useful for graph traversal algorithms.
* The overall complexity is `O(V + E)`.

---

## 🚀 Pattern to Remember

When you receive:

```text
Number of vertices
+
List of edges
```

and need to create an adjacency list:

```text
Create V empty vectors
        ↓
For every edge (u, v)
        ↓
adj[u].push_back(v)
        ↓
If undirected:
adj[v].push_back(u)
```

This adjacency-list pattern will be used repeatedly throughout Graph DSA.
