# Graph BFS — Adjacency List Traversal

This folder contains my practice of **Breadth First Search (BFS)** on a graph represented using an **Adjacency List** in C++.

The implementation starts traversal from vertex `0` and uses a **Queue** to visit nodes level by level.

---

## 📌 Concepts Used

* Breadth First Search (BFS)
* Queue
* Adjacency List
* Visited Array
* Graph Traversal
* Level-by-Level Traversal

---

## 🧠 What Is BFS?

**Breadth First Search (BFS)** is a graph traversal technique that explores nodes level by level.

Instead of going as deep as possible like DFS, BFS first visits all immediate neighbors before moving to the next level.

The basic idea is:

```text
Start Node
    ↓
Visit all immediate neighbors
    ↓
Visit neighbors of those nodes
    ↓
Continue level by level
```

---

## 📦 Why Do We Use a Queue?

BFS uses a **Queue** because a queue follows:

```text
FIFO
First In → First Out
```

For example:

```text
Queue:

Front → [1] [2] [3] ← Back
```

Node `1` will be processed first.

This naturally gives BFS its level-by-level behavior.

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

`adj[node]` contains all the neighbors of that node.

---

## 👀 Visited Array

We use a visited array:

```cpp
vector<bool> vis(n, false);
```

Initially:

```text
false → Node has not been visited
true  → Node has been visited
```

When a node is added to the queue:

```cpp
vis[node] = true;
```

This prevents the same node from being added multiple times.

---

## 🚀 Starting BFS

The traversal starts from node `0`:

```cpp
int node = 0;
```

Then the starting node is passed to the BFS function:

```cpp
fun(adj, node, vis, q, res);
```

---

## 📥 Adding a Node to the Queue

At the beginning:

```cpp
q.push(node);
vis[node] = true;
```

This means:

1. Put the starting node into the queue.
2. Mark it as visited.

---

## 🔄 Main BFS Loop

The BFS continues while the queue is not empty:

```cpp
while (!q.empty()) {
```

Inside the loop:

```cpp
int value = q.front();
q.pop();
```

We:

1. Look at the front node.
2. Remove it from the queue.

Then store it in the result:

```cpp
res.push_back(value);
```

---

## 🔎 Exploring Neighbors

After removing a node, we examine all of its neighbors:

```cpp
for (int i = 0; i < adj[value].size(); i++) {

    int neighbour = adj[value][i];

    if (vis[neighbour] == false) {
        vis[neighbour] = true;
        q.push(neighbour);
    }
}
```

For every neighbor:

* Check whether it is visited.
* If not visited, mark it visited.
* Add it to the queue.

---

## ⚠️ Why Mark Visited Before Pushing?

This is an important detail:

```cpp
vis[neighbour] = true;
q.push(neighbour);
```

We mark the node as visited **when adding it to the queue**, not when removing it.

Why?

Suppose two different nodes are connected to the same neighbor.

Without marking it immediately, both nodes could add that neighbor to the queue.

By marking it as soon as it enters the queue, we guarantee that it is added only once.

---

## 🌳 How BFS Traverses

Suppose the graph has this structure:

```text
        0
       / \
      1   2
     / \
    3   4
```

BFS starting from `0` works like:

```text
Queue: [0]

Process 0
Queue: [1, 2]

Process 1
Queue: [2, 3, 4]

Process 2
Queue: [3, 4]

Process 3
Queue: [4]

Process 4
Queue: []
```

The traversal happens level by level:

```text
Level 0 → 0
Level 1 → 1, 2
Level 2 → 3, 4
```

---

## 🧩 Complete Algorithm

```text
1. Create an empty result vector.
        ↓
2. Create a queue.
        ↓
3. Create a visited array.
        ↓
4. Start from node 0.
        ↓
5. Add node to queue.
        ↓
6. Mark node visited.
        ↓
7. While queue is not empty:
        ↓
8. Remove front node.
        ↓
9. Add it to result.
        ↓
10. Visit all its neighbors.
        ↓
11. If a neighbor is unvisited:
        ↓
12. Mark it visited.
        ↓
13. Add it to queue.
        ↓
14. Repeat.
```

---

## 🆚 BFS vs DFS

| BFS                                         | DFS                                        |
| ------------------------------------------- | ------------------------------------------ |
| Uses Queue                                  | Usually uses Recursion/Stack               |
| Level-by-level                              | Goes deep first                            |
| FIFO                                        | LIFO behavior                              |
| Good for shortest path in unweighted graphs | Good for connectivity and deep exploration |
| Uses queue                                  | Uses call stack or explicit stack          |

A simple way to remember:

```text
BFS → Queue
DFS → Stack / Recursion
```

---

## ⏱️ Time Complexity

Let:

* `V` = number of vertices
* `E` = number of edges

Each vertex is visited once and each edge/adjacency entry is processed.

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

The queue can contain up to:

```text
O(V)
```

The result vector also contains up to:

```text
O(V)
```

Therefore, the auxiliary space used by BFS is:

```text
Space Complexity = O(V)
```

excluding the input adjacency list and output result.

---

## 🧠 Key Takeaways

* BFS uses a **Queue**.
* Queue follows **FIFO**.
* BFS explores nodes level by level.
* An adjacency list stores the neighbors.
* A visited array prevents repeated processing.
* Mark a node visited when adding it to the queue.
* Remove nodes using `q.front()` and `q.pop()`.
* BFS traversal takes `O(V + E)` time.

---

## 🔥 Pattern to Remember

Whenever you need to perform BFS on an adjacency list, remember:

```text
Start Node
    ↓
Mark Visited
    ↓
Push into Queue
    ↓
while Queue is not Empty
    ↓
Pop Front
    ↓
Process Node
    ↓
Check Neighbors
    ↓
If Unvisited
    ↓
Mark Visited
    ↓
Push into Queue
```

### C++ Template

```cpp
void bfs(int start,
         vector<vector<int>>& adj,
         vector<bool>& vis) {

    queue<int> q;

    q.push(start);
    vis[start] = true;

    while (!q.empty()) {

        int node = q.front();
        q.pop();

        for (int neighbour : adj[node]) {

            if (!vis[neighbour]) {
                vis[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
}
```

This BFS pattern is one of the most important foundations for Graph DSA, especially for **shortest paths, connected components, level traversal, and multi-source BFS**.
