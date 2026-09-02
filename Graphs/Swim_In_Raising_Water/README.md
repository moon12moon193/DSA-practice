# 🌊 Swim in Rising Water

## 📌 Problem

You are given an `n x n` grid where:

```text
grid[i][j]
```

represents the elevation of the cell `(i, j)`.

At time `t`, you can enter a cell only if:

```text
grid[i][j] <= t
```

You start at the top-left cell `(0, 0)` and need to reach the bottom-right cell `(n-1, n-1)`.

Return the **minimum time** required to reach the destination.

---

## 💡 Approach

This solution uses:

1. **Binary Search** on the possible answer.
2. **BFS** to check whether the destination can be reached for a particular time.

### Why Binary Search?

Suppose we choose a time `guess`.

We can ask:

> Can we reach the destination using only cells whose elevation is `<= guess`?

There are only two possibilities:

* If we **can reach** the destination, then `guess` might be the answer or we might be able to use an even smaller time.
* If we **cannot reach** the destination, we need more time.

This gives us a monotonic condition:

```text
Cannot reach → Cannot reach → Can reach → Can reach → Can reach
```

Therefore, binary search can be used to find the minimum valid time.

---

## 🔍 BFS Check

For every `guess`, BFS starts from:

```cpp
(0, 0)
```

A neighboring cell `(r, c)` is added to the queue only when:

```cpp
guess >= grid[r][c]
```

and it has not already been visited.

```cpp
if (isValid(r, c, n, m) &&
    vis[r][c] == false &&
    guess >= grid[r][c]) {

    q.push({r, c});
    vis[r][c] = true;
}
```

If BFS reaches:

```cpp
(n - 1, m - 1)
```

then the current `guess` is sufficient.

---

## 🧠 Algorithm

### Step 1: Find Search Range

The minimum possible time is the elevation of the starting cell:

```cpp
int low = grid[0][0];
```

The maximum possible time is the maximum elevation present in the grid:

```cpp
int high = maximum value in grid;
```

---

### Step 2: Binary Search

Calculate the middle value:

```cpp
int guess = low + (high - low) / 2;
```

Then run BFS.

### If BFS succeeds:

```cpp
ans = guess;
high = guess - 1;
```

We found a possible answer, so try to find a smaller one.

### If BFS fails:

```cpp
low = guess + 1;
```

We need more time.

---

## 📝 Example

Consider:

```text
grid = [
    [0, 2],
    [1, 3]
]
```

Possible times:

```text
Time = 1

0   X
1   X

Cannot reach destination.
```

So we increase the time.

```text
Time = 2

0   2
1   X

Still cannot reach destination.
```

Try:

```text
Time = 3

0   2
1   3

Destination is reachable.
```

Therefore:

```text
Answer = 3
```

---

## 💻 Code

```cpp
class Solution {
public:

    bool isValid(int row, int col, int n, int m) {
        if (row < 0 || row >= n || col < 0 || col >= m) {
            return false;
        }
        return true;
    }

    bool bfs(vector<vector<int>> grid, int x[4], int y[4],
             int n, int m, int guess) {

        vector<vector<bool>> vis(n);

        for (int i = 0; i < n; i++) {
            vector<bool> t(m, false);
            vis[i] = t;
        }

        queue<pair<int, int>> q;

        q.push({0, 0});
        vis[0][0] = true;

        while (!q.empty()) {

            pair<int, int> p = q.front();
            q.pop();

            int row = p.first;
            int col = p.second;

            if (row == n - 1 && col == m - 1) {
                return true;
            }

            for (int k = 0; k < 4; k++) {

                int r = row + x[k];
                int c = col + y[k];

                if (isValid(r, c, n, m) &&
                    vis[r][c] == false &&
                    guess >= grid[r][c]) {

                    q.push({r, c});
                    vis[r][c] = true;
                }
            }
        }

        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int low = grid[0][0];
        int high = INT_MIN;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                high = max(high, grid[i][j]);
            }
        }

        int ans = 0;

        int x[4] = {-1, 1, 0, 0};
        int y[4] = {0, 0, -1, 1};

        while (low <= high) {

            int guess = low + (high - low) / 2;

            if (bfs(grid, x, y, n, m, guess)) {

                ans = guess;
                high = guess - 1;

            } else {

                low = guess + 1;
            }
        }

        return ans;
    }
};
```

---

## ⏱️ Complexity

Let the grid contain `n × m` cells.

### BFS

Each cell is visited at most once:

```text
O(n × m)
```

### Binary Search

The search range contains values from the minimum elevation to the maximum elevation.

Therefore:

```text
O(log(maxElevation))
```

BFS is performed for every binary-search step.

### Overall Time Complexity

```text
O(n × m × log(maxElevation))
```

### Space Complexity

The visited array and BFS queue require:

```text
O(n × m)
```

Therefore:

```text
Space = O(n × m)
```

---

## 🔑 Key Concepts

This problem is useful for understanding:

* Binary Search on Answer
* Breadth First Search (BFS)
* Grid Traversal
* Visited Arrays
* Monotonic Conditions
* 4-Directional Movement
* Combining Binary Search with Graph Traversal

---

## 🎯 Important Pattern

The most important idea is:

```text
Binary Search
      ↓
Guess an answer
      ↓
Can I achieve this answer?
      ↓
      BFS
      ↓
Yes → search smaller
No  → search larger
```

This is a common **Binary Search on Answer** pattern.

Instead of directly calculating the answer, we repeatedly ask:

> **"Is this value possible?"**

and use binary search to find the smallest possible value.
