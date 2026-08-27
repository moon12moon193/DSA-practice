# Graph DFS — Grid Traversal

This folder contains my practice of **Depth First Search (DFS)** on a 2D grid using C++.

The main idea is to treat the grid as a graph where each cell can be considered a node, and neighboring cells are connected.

---

## 📌 Concepts Used

* Graph traversal
* Depth First Search (DFS)
* 2D Grid Traversal
* Connected Components
* Visited Matrix
* Recursion
* Direction Arrays
* Boundary Checking

---

## 🧠 Core Idea

The grid contains two types of cells:

```text
'1' → Land
'0' → Water
```

Every connected group of `'1'` cells represents one separate component.

We traverse the entire grid and whenever we find an unvisited `'1'`, we start a DFS from that cell.

That DFS visits all connected `'1'` cells.

After completing one DFS traversal, we increment the result.

---

## 🗺️ Movement in the Grid

From every cell, we can move in four directions:

```text
        Up
        ↑
Left ← Cell → Right
        ↓
       Down
```

These movements are stored using two arrays:

```cpp
int x[4] = {-1, 1, 0, 0};
int y[4] = {0, 0, -1, 1};
```

The combinations represent:

```text
(-1, 0) → Up
( 1, 0) → Down
( 0,-1) → Left
( 0, 1) → Right
```

This avoids writing four separate conditions.

---

## 🔍 Boundary Checking

Before accessing a neighboring cell, we need to make sure that the position is inside the grid.

```cpp
bool isValid(int row, int col, int n, int m) {
    if (row < 0 || row >= n || col < 0 || col >= m) {
        return false;
    }

    return true;
}
```

This prevents accessing invalid positions such as:

```text
row = -1
col = -1
row = n
col = m
```

---

## 👀 Visited Matrix

A separate matrix is used to keep track of cells that have already been visited.

```cpp
vector<vector<bool>> vis(n, vector<bool>(m, 0));
```

Initially:

```text
0 → Not visited
1 → Visited
```

When DFS enters a cell:

```cpp
vis[i][j] = 1;
```

This prevents visiting the same cell repeatedly.

---

## 🌳 DFS Approach

The DFS function follows this process:

```text
Start at a cell
      ↓
Mark it visited
      ↓
Check all 4 neighbors
      ↓
Is the neighbor inside the grid?
      ↓
Is it '1'?
      ↓
Has it not been visited?
      ↓
Run DFS on that neighbor
```

The important part is:

```cpp
if (isValid(row, col, n, m) &&
    grid[row][col] == '1' &&
    vis[row][col] == 0) {

    dfs(row, col, vis, grid, n, m, x, y);
}
```

---

## 🔄 Complete Traversal Logic

The outer loops visit every cell:

```cpp
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {

        if (grid[i][j] == '1' && vis[i][j] == 0) {
            dfs(i, j, vis, grid, n, m, x, y);
            res++;
        }
    }
}
```

Whenever an unvisited land cell is found:

1. Start DFS.
2. DFS visits the entire connected component.
3. Increment `res`.

Therefore, each DFS call represents **one connected component**.

---

## 🧩 Why Do We Need `vis`?

Consider:

```text
1 1
1 1
```

Starting from the first cell, DFS can reach every other cell.

Without `vis`, DFS could keep moving between already visited cells:

```text
A → B → A → B → A → ...
```

This can cause infinite recursion.

The visited matrix prevents this.

---

## 🧠 Important Pattern

This solution demonstrates a very important graph pattern:

> **Count connected components using DFS.**

The same pattern can be applied to many problems involving:

* Grids
* Networks
* Groups
* Regions
* Connected nodes
* Graph components

---

## ⏱️ Time Complexity

Let:

* `n` = number of rows
* `m` = number of columns

Every cell is visited at most once.

For every visited cell, we check 4 directions.

Therefore:

```text
Time Complexity = O(n × m)
```

---

## 💾 Space Complexity

The visited matrix requires:

```text
O(n × m)
```

DFS recursion can also use stack space depending on the size of the connected component.

Worst case:

```text
O(n × m)
```

Therefore:

```text
Space Complexity = O(n × m)
```

---

## 📚 Key Takeaways

* A 2D grid can be treated as a graph.
* Each cell can act as a node.
* Adjacent cells act like connected nodes.
* DFS can be used to explore connected components.
* A visited matrix prevents repeated traversal.
* Direction arrays make grid traversal cleaner.
* Boundary checking prevents invalid memory access.
* Every new DFS traversal represents a new connected component.

---

## 🚀 Pattern to Remember

When you see a **2D grid + connected cells + need to explore/count groups**, think:

```text
Grid
 ↓
Visited Matrix
 ↓
Direction Array
 ↓
Boundary Check
 ↓
DFS / BFS
 ↓
Connected Components
```

This is one of the most important patterns to learn before moving deeper into Graph DSA.
