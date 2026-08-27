# Graph BFS — Grid Traversal

This folder contains my practice of **Breadth First Search (BFS)** on a 2D grid using C++.

The main concept is to treat each cell as a node and use BFS to process neighboring cells level by level.

---

## 📌 Concepts Used

* Breadth First Search (BFS)
* Queue
* 2D Grid Traversal
* Multi-Source BFS
* Level-by-Level Traversal
* Direction Arrays
* Boundary Checking
* Counting States
* In-place Visited Marking

---

## 🧠 Core Idea

The grid contains three possible states:

```text
0 → Empty cell
1 → Fresh item
2 → Rotten item
```

Every rotten item can affect its neighboring fresh items.

Since the process happens **simultaneously in all directions**, we use **BFS**.

All initially rotten cells are inserted into the queue before starting the BFS.

This makes the approach a **Multi-Source BFS**.

---

## 🌐 Why BFS?

BFS is useful when a process spreads from multiple starting points and we need to calculate the minimum number of levels or steps.

Think of the grid as:

```text
Starting cells
      ↓
Level 1
      ↓
Level 2
      ↓
Level 3
      ↓
...
```

Each BFS level represents one unit of time.

Therefore, every time we finish processing one level, we increase:

```cpp
time++;
```

---

## 🚀 Multi-Source BFS

Instead of starting BFS from only one cell, we add **all starting cells** to the queue:

```cpp
if (grid[i][j] == 2) {
    q.push({i, j});
    grid[i][j] = -1;
}
```

This is important because all initially rotten cells start spreading at the same time.

### General Pattern

```text
Find all starting points
        ↓
Put all of them in Queue
        ↓
Process Queue level by level
        ↓
Visit neighboring cells
        ↓
Update their state
        ↓
Repeat
```

---

## 📊 Tracking Fresh Cells

We maintain a variable:

```cpp
int fresh = 0;
```

Whenever a fresh cell is found:

```cpp
if (grid[i][j] == 1) {
    fresh++;
}
```

Whenever BFS reaches a fresh cell:

```cpp
grid[row][col] = -1;
fresh--;
```

This allows us to know whether all fresh cells have been processed.

---

## ⏱️ Level-by-Level BFS

The current queue size represents all cells belonging to the current time level:

```cpp
int size = q.size();
```

We process exactly those cells:

```cpp
while (size > 0) {
    pair<int, int> value = q.front();
    q.pop();

    size--;

    // Process neighbors
}
```

After processing the complete level:

```cpp
time++;
```

So the structure becomes:

```text
Time = 0
↓
Initial rotten cells

Time = 1
↓
Cells reached from initial cells

Time = 2
↓
Cells reached from previous level

Time = 3
↓
Continue...
```

---

## 🧭 Direction Array

Each cell can move in four directions:

```cpp
int x[4] = {-1, 1, 0, 0};
int y[4] = {0, 0, -1, 1};
```

The directions are:

```text
        Up
        ↑
Left ← Cell → Right
        ↓
       Down
```

This avoids writing separate code for every direction.

---

## 🛡️ Boundary Checking

Before accessing a neighboring cell, we check whether it is inside the grid:

```cpp
bool isValid(int row, int col, int n, int m) {
    if (row < 0 || row >= n || col < 0 || col >= m) {
        return false;
    }

    return true;
}
```

This prevents accessing invalid indexes.

---

## 👀 Visited Handling

A separate `visited` matrix is not required here.

Instead, the grid itself is modified:

```cpp
grid[row][col] = -1;
```

When a cell becomes `-1`, it means:

```text
Already processed / visited
```

This prevents the same cell from being added to the queue multiple times.

---

## 🔄 BFS Condition

A neighboring cell is processed only when:

```cpp
if (isValid(row, col, n, m) && grid[row][col] == 1)
```

This ensures that:

1. The cell is inside the grid.
2. The cell is fresh.
3. It has not already been processed.

---

## 🧩 Complete Algorithm

```text
1. Count all fresh cells.
        ↓
2. Put all initially rotten cells into Queue.
        ↓
3. Mark those cells as visited.
        ↓
4. Start BFS.
        ↓
5. Process one complete level.
        ↓
6. Visit all four neighbors.
        ↓
7. Convert fresh neighbors into processed cells.
        ↓
8. Decrease fresh count.
        ↓
9. Increase time after each level.
        ↓
10. Continue until Queue is empty or no fresh cells remain.
        ↓
11. If fresh cells remain → impossible.
        ↓
12. Otherwise return time.
```

---

## ❗ Why Return `-1`?

After BFS finishes, we check:

```cpp
if (fresh > 0) {
    return -1;
}
```

If fresh cells are still present, they could not be reached by BFS.

This means the grid contains a disconnected region that cannot be affected.

---

## ⏱️ Time Complexity

Let:

* `n` = number of rows
* `m` = number of columns

Every cell is processed at most once.

For each processed cell, we check four directions.

Therefore:

```text
Time Complexity = O(n × m)
```

---

## 💾 Space Complexity

The queue can contain up to `O(n × m)` cells in the worst case.

No separate visited matrix is used because the grid itself stores the visited state.

Therefore:

```text
Space Complexity = O(n × m)
```

---

## 🧠 Key Takeaways

* BFS is useful for level-by-level spreading.
* Multiple starting points can be handled using **Multi-Source BFS**.
* All source nodes should be added to the queue initially.
* Queue size can be used to separate BFS levels.
* Each BFS level can represent one unit of time.
* A visited matrix is not always necessary.
* The input grid can sometimes be modified to mark visited cells.
* Counting remaining target cells helps determine whether the process completed successfully.
* Direction arrays simplify 2D grid traversal.

---

## 🔥 Important Graph Pattern

When you see:

```text
Multiple starting points
        +
Spread to neighboring cells
        +
Minimum time / minimum steps
```

Think:

```text
Multi-Source BFS
```

The general pattern is:

```text
Multiple Sources
       ↓
    Queue
       ↓
   BFS Levels
       ↓
 Neighbor Expansion
       ↓
  Track Distance/Time
```

This is an important pattern to remember for Graph and Grid problems.
