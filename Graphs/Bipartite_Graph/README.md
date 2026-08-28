# Bipartite Graph

## 📌 Overview

A **bipartite graph** is a graph whose vertices can be divided into two different groups such that **no two adjacent vertices belong to the same group**.

We can check whether a graph is bipartite by assigning one of two colors to every vertex.

```text
Color 0 → Group 1
Color 1 → Group 2
```

For every edge:

```text
u ─── v
```

`u` and `v` must have different colors.

This implementation uses **DFS (Depth-First Search)** and **2-coloring** to determine whether the graph is bipartite.

---

## 🧠 Approach

The algorithm follows these steps:

1. Create a `colours` array and initialize every vertex with `-1`.

   * `-1` means the vertex has not been colored yet.
2. Start DFS from an uncolored vertex.
3. Assign the current vertex a color (`0` or `1`).
4. Visit all its neighbors.
5. If a neighbor is uncolored:

   * Assign it the opposite color.
   * Continue DFS.
6. If a neighbor is already colored:

   * Check whether it has the **same color** as the current vertex.
7. If two adjacent vertices have the same color, the graph is **not bipartite**.
8. The outer loop ensures that disconnected components are also checked.

---

## 🎨 Two-Coloring Concept

Suppose we have:

```text
0 ─── 1
|     |
|     |
3 ─── 2
```

We can color it like:

```text
0 → Color 0
1 → Color 1
2 → Color 0
3 → Color 1
```

So every edge connects vertices having different colors.

Therefore, the graph is bipartite.

---

## 🔍 How DFS Works

Initially:

```text
colours = [-1, -1, -1, -1]
```

Start DFS from node `0`:

```text
0 → Color 0
```

Then visit its neighbor:

```text
1 → Color 1
```

Then:

```text
2 → Color 0
```

And so on.

The coloring alternates:

```text
0 → 1 → 0 → 1
```

where `0` and `1` represent the two groups.

---

## 💻 Implementation

```cpp
class Solution {
public:

    void dfs(vector<vector<int>>& graph,
             int colour,
             vector<int>& colours,
             int node,
             bool& res) {

        colours[node] = colour;

        for (int i = 0; i < graph[node].size(); i++) {

            int neighbour = graph[node][i];

            // Neighbor is already colored
            // and has the same color
            if (colours[neighbour] != -1 &&
                colours[neighbour] == colour) {

                res = false;
            }

            // Neighbor is not colored
            if (colours[neighbour] == -1) {

                dfs(graph,
                    1 - colour,
                    colours,
                    neighbour,
                    res);
            }
        }

        return;
    }

    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();

        bool res = true;

        // -1 means not colored
        vector<int> colours(n, -1);

        int colour = 0;

        // Check every component
        for (int i = 0; i < n; i++) {

            if (colours[i] == -1) {

                dfs(graph,
                    colour,
                    colours,
                    i,
                    res);
            }
        }

        return res;
    }
};
```

---

## 🔑 Important Part of the Code

### `colours[node] = colour`

This assigns a color to the current node.

```cpp
colours[node] = colour;
```

---

### `1 - colour`

This switches between the two colors.

```text
colour = 0

1 - 0 = 1
```

and:

```text
colour = 1

1 - 1 = 0
```

Therefore:

```cpp
dfs(graph, 1 - colour, colours, neighbour, res);
```

always gives the neighbor the opposite color.

---

## ⚠️ Detecting a Conflict

This condition checks whether two connected vertices have the same color:

```cpp
if (colours[neighbour] != -1 &&
    colours[neighbour] == colour) {

    res = false;
}
```

For example:

```text
0(Color 0) ─── 1(Color 0)
```

Both connected vertices have the same color, so:

```text
❌ Not Bipartite
```

---

## 🔗 Handling Disconnected Graphs

A graph may contain multiple disconnected components:

```text
Component 1:

0 ─── 1


Component 2:

2 ─── 3
```

Starting DFS only from node `0` would not check nodes `2` and `3`.

That's why we use:

```cpp
for (int i = 0; i < n; i++) {

    if (colours[i] == -1) {
        dfs(graph, colour, colours, i, res);
    }
}
```

This starts DFS for every unvisited component.

---

## ⏱️ Complexity

Let:

* `V` = number of vertices
* `E` = number of edges

### Time Complexity

```text
O(V + E)
```

Each vertex is visited once and each edge is examined during DFS.

### Space Complexity

```text
O(V)
```

Space is used for:

* `colours` array
* DFS recursion stack

The graph itself is already provided as input.

---

## 🧩 Key Concepts

* Graph
* Bipartite Graph
* DFS
* Graph Coloring
* 2-Coloring
* Connected Components
* Recursion
* Cycle/Conflict Detection

---

## 📝 Key Idea to Remember

The easiest way to remember the algorithm is:

```text
Color current node
       ↓
Give opposite color to neighbors
       ↓
Continue DFS
       ↓
If an edge connects same-colored nodes
       ↓
Not Bipartite
```

### In short:

> **Bipartite Graph using DFS = 2 Colors + Opposite Colors + Conflict Detection**
