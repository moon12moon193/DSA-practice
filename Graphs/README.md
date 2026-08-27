# Graph Data Structure

This folder contains my practice and implementation of **Graph Data Structures** using C++.

The goal is to understand how graphs work, learn different ways to represent them, and practice important graph traversal and algorithmic techniques.

---

## 📌 Topics Covered

### 1. Graph Basics

* What is a Graph?
* Vertices (Nodes)
* Edges
* Degree of a Vertex
* Directed Graph
* Undirected Graph
* Weighted Graph
* Unweighted Graph
* Connected and Disconnected Graphs
* Cyclic and Acyclic Graphs
* Path and Cycle

### 2. Graph Representation

* Adjacency Matrix
* Adjacency List
* Edge List
* Weighted Graph Representation

### 3. Graph Traversal

* Breadth First Search (BFS)
* Depth First Search (DFS)
* Iterative DFS
* Recursive DFS
* Visited Array

### 4. Connectivity

* Connected Components
* Checking whether a graph is connected
* Counting connected components

### 5. Cycle Detection

* Cycle detection in undirected graphs
* Cycle detection using BFS
* Cycle detection using DFS
* Cycle detection in directed graphs
* Recursion Stack

### 6. Topological Sorting

* Concept of Topological Ordering
* DFS-based approach
* BFS-based approach
* Indegree
* Kahn's Algorithm
* Detecting cycles using Topological Sort

### 7. Shortest Path

* Shortest path in an unweighted graph
* Shortest path using BFS
* Single-source shortest path
* Dijkstra's Algorithm
* Bellman-Ford Algorithm

### 8. Minimum Spanning Tree

* Spanning Tree
* Minimum Spanning Tree (MST)
* Prim's Algorithm
* Kruskal's Algorithm
* Disjoint Set Union (DSU)

### 9. Advanced Graph Concepts

* Bipartite Graph
* Bipartite Graph Checking
* Union Find
* Strongly Connected Components
* Bridges
* Articulation Points

---

## 🧠 Important Concepts

While solving graph problems, I will focus on understanding:

* How to represent a graph
* When to use BFS vs DFS
* How the `visited` array works
* How to handle disconnected graphs
* How to detect cycles
* How to calculate indegree
* How queues and stacks are used in graph algorithms
* How priority queues are used in shortest-path algorithms
* How DSU works
* Time and space complexity of graph algorithms

---

## ⚙️ Common C++ Structures

### Adjacency List

```cpp
vector<vector<int>> adj(n);
```

For an undirected graph:

```cpp
adj[u].push_back(v);
adj[v].push_back(u);
```

For a directed graph:

```cpp
adj[u].push_back(v);
```

### Visited Array

```cpp
vector<bool> visited(n, false);
```

### Queue for BFS

```cpp
queue<int> q;
```

### Stack for Iterative DFS

```cpp
stack<int> st;
```

---

## 🔄 Graph Traversal Pattern

### BFS

```text
Start Node
    ↓
Put node into Queue
    ↓
Mark as Visited
    ↓
Remove node from Queue
    ↓
Visit its Neighbors
    ↓
Add Unvisited Neighbors
    ↓
Repeat
```

### DFS

```text
Start Node
    ↓
Mark as Visited
    ↓
Visit a Neighbor
    ↓
Continue Deeper
    ↓
Backtrack
    ↓
Repeat
```

---

## ⏱️ Complexity

For a graph with:

* `V` = number of vertices
* `E` = number of edges

Common graph traversal algorithms such as BFS and DFS generally take:

**Time:** `O(V + E)`

**Space:** `O(V + E)` when considering the graph representation and auxiliary data structures.

---

## 📂 Folder Structure

```text
Graph/
│
├── README.md
│
├── Basics/
│
├── Representation/
│
├── BFS/
│
├── DFS/
│
├── Cycle Detection/
│
├── Topological Sort/
│
├── Shortest Path/
│
├── Minimum Spanning Tree/
│
└── Advanced/
```

---

## 🎯 Learning Goals

By completing this section, I aim to:

* Understand graph fundamentals
* Implement graphs from scratch
* Become comfortable with BFS and DFS
* Understand graph traversal patterns
* Solve graph-based DSA problems
* Analyze graph algorithms using time and space complexity
* Build a strong foundation for advanced graph algorithms

---

## 📝 Progress

* [ ] Graph Basics
* [ ] Graph Representation
* [ ] BFS
* [ ] DFS
* [ ] Connected Components
* [ ] Cycle Detection
* [ ] Topological Sort
* [ ] Shortest Path
* [ ] Minimum Spanning Tree
* [ ] DSU
* [ ] Bipartite Graph
* [ ] Advanced Graph Algorithms

---

## 💻 Language

**C++**

---

## 🚀 Goal

Build a strong understanding of **Graph Data Structures and Algorithms** and become confident enough to recognize and solve different graph patterns in coding interviews and competitive programming.
