# Surrounded Regions

## 📌 Overview

This problem involves a 2D board containing two types of cells:

```text
'O' and 'X'
```

The goal is to identify regions of `'O'` that are **completely surrounded by `'X'`** and convert those surrounded `'O'` cells into `'X'`.

An `'O'` region should **not** be converted if it is connected to the boundary of the board.

This implementation uses **DFS (Depth-First Search)** to find all `'O'` cells connected to the boundary.

---

## 🧠 Main Idea

Instead of searching for surrounded regions directly, we use the opposite approach:

> **Any `'O'` connected to the boundary cannot be surrounded.**

So we:

1. Traverse all `'O'` cells on the first row.
2. Traverse all `'O'` cells on the last row.
3. Traverse all `'O'` cells on the first column.
4. Traverse all `'O'` cells on the last column.
5. Run DFS from every boundary `'O'`.
6. Temporarily mark every reachable `'O'` as `'#'`.
7. Traverse the entire board:

   * `'#'` → change back to `'O'`
   * Remaining `'O'` → change to `'X'`

---

## 🔍 Example

Consider:

```text
X X X X
X O O X
X X O X
X O X X
```

The `'O'` at the bottom is connected to the boundary:

```text
X X X X
X O O X
X X O X
X O X X
      ↑
   boundary
```

Therefore, it must remain `'O'`.

The other `'O'` cells are completely surrounded and should be converted:

```text
X X X X
X X X X
X X X X
X O X X
```

---

## 🚀 Step-by-Step Approach

### 1. Define Four Directions

The DFS needs to explore the four adjacent cells:

```cpp
int x[4] = {-1, 1, 0, 0};
int y[4] = {0, 0, -1, 1};
```

These represent:

```text
        Up
        (-1,0)

Left (0,-1)   Right (0,1)

        Down
        (1,0)
```

---

### 2. Check Valid Coordinates

The `isValid()` function ensures that we don't access cells outside the board.

```cpp
bool isValid(int row, int col, int n, int m) {
    if (row < 0 || row >= n || col < 0 || col >= m) {
        return false;
    }
    return true;
}
```

A coordinate is valid when:

```text
0 <= row < n
0 <= col < m
```

---

### 3. DFS from Boundary `'O'`

When we find an `'O'` on the boundary, we start DFS.

```cpp
dfs(board, 0, i, x, y, n, m);
```

The DFS marks every connected `'O'` as:

```text
'O' → '#'
```

The `'#'` acts as a temporary marker.

```cpp
board[r][c] = '#';
```

---

## 🏃 Why Start DFS from the Boundary?

Consider:

```text
X X X X X
X O O O X
X O X O X
X O O O X
X X X X X
```

The center `X` separates the regions, but all the `'O'` cells are connected to the boundary through their surrounding region.

Therefore, none of these `'O'` cells should be converted.

Starting DFS from boundary `'O'` cells allows us to mark all safe regions.

---

## 🔄 Temporary `'#'` Marker

The algorithm uses `'#'` to remember which `'O'` cells are safe.

For example:

```text
Before DFS:

X X X X
O O X X
X O X X
X X X X
```

After DFS from boundary:

```text
X X X X
# # X X
X # X X
X X X X
```

Here:

```text
# = Safe 'O'
O = Surrounded 'O'
```

Then during the final traversal:

```cpp
if (board[i][j] == '#') {
    board[i][j] = 'O';
}
else if (board[i][j] == 'O') {
    board[i][j] = 'X';
}
```

So:

```text
# → O
O → X
```

---

## 💻 Implementation

```cpp
class Solution {
public:

    bool isValid(int row, int col, int n, int m) {

        if (row < 0 || row >= n ||
            col < 0 || col >= m) {

            return false;
        }

        return true;
    }

    void dfs(vector<vector<char>>& board,
             int r,
             int c,
             int x[4],
             int y[4],
             int n,
             int m) {

        board[r][c] = '#';

        for (int k = 0; k < 4; k++) {

            int row = r + x[k];
            int col = c + y[k];

            if (isValid(row, col, n, m) &&
                board[row][col] == 'O') {

                dfs(board,
                    row,
                    col,
                    x,
                    y,
                    n,
                    m);
            }
        }

        return;
    }

    void solve(vector<vector<char>>& board) {

        int x[4] = {-1, 1, 0, 0};
        int y[4] = {0, 0, -1, 1};

        int n = board.size();
        int m = board[0].size();

        // First Row
        for (int i = 0; i < m; i++) {

            if (board[0][i] == 'O') {

                dfs(board,
                    0,
                    i,
                    x,
                    y,
                    n,
                    m);
            }
        }

        // Last Row
        for (int i = 0; i < m; i++) {

            if (board[n - 1][i] == 'O') {

                dfs(board,
                    n - 1,
                    i,
                    x,
                    y,
                    n,
                    m);
            }
        }

        // First Column
        for (int i = 0; i < n; i++) {

            if (board[i][0] == 'O') {

                dfs(board,
                    i,
                    0,
                    x,
                    y,
                    n,
                    m);
            }
        }

        // Last Column
        for (int i = 0; i < n; i++) {

            if (board[i][m - 1] == 'O') {

                dfs(board,
                    i,
                    m - 1,
                    x,
                    y,
                    n,
                    m);
            }
        }

        // Convert the board
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                if (board[i][j] == '#') {

                    board[i][j] = 'O';

                }
                else if (board[i][j] == 'O') {

                    board[i][j] = 'X';
                }
            }
        }
    }
};
```

---

## ⏱️ Complexity

Let:

* `n` = number of rows
* `m` = number of columns

### Time Complexity

```text
O(n × m)
```

Every cell is visited at most a constant number of times.

### Space Complexity

```text
O(n × m)
```

In the worst case, DFS recursion can visit a large portion of the board.

The board itself is modified in-place, so no separate visited matrix is required.

---

## 🔑 Key Concepts

* 2D Grid
* DFS
* Recursion
* Boundary Traversal
* Connected Components
* Flood Fill
* In-place Modification
* Four-Direction Traversal

---

## 📝 Important Pattern to Remember

The most important idea is:

```text
Don't search for surrounded 'O's directly.

Instead:

Find boundary 'O's
       ↓
Run DFS
       ↓
Mark connected 'O's as '#'
       ↓
Traverse entire board
       ↓
'#' → 'O'
Remaining 'O' → 'X'
```

### ⭐ Key Insight

> **Boundary-connected `'O'` cells are safe. Every other `'O'` can be surrounded and should be converted to `'X'`.**

This is a very useful **DFS on a 2D grid + boundary traversal** pattern that appears in many graph/grid problems.
