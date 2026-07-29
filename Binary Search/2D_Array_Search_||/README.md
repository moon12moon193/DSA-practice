# Search a 2D Matrix II (LeetCode 240)

## Problem

You are given an `m × n` integer matrix where:

- Each row is sorted in **ascending order** from left to right.
- Each column is sorted in **ascending order** from top to bottom.

Given an integer `target`, return **`true`** if the target exists in the matrix; otherwise, return **`false`**.

---

## Example 1

**Input**

```cpp
matrix = [
  [1,4,7,11,15],
  [2,5,8,12,19],
  [3,6,9,16,22],
  [10,13,14,17,24],
  [18,21,23,26,30]
]

target = 5
```

**Output**

```cpp
true
```

---

## Example 2

**Input**

```cpp
matrix = [
  [1,4,7,11,15],
  [2,5,8,12,19],
  [3,6,9,16,22],
  [10,13,14,17,24],
  [18,21,23,26,30]
]

target = 20
```

**Output**

```cpp
false
```

---

# Intuition

Unlike **LeetCode 74**, the rows are sorted and the columns are sorted independently.

The matrix cannot be treated as one completely sorted array.

Instead, start from the **bottom-left corner**:

- Everything **above** is smaller.
- Everything **to the right** is larger.

This property allows us to eliminate either one row or one column after every comparison.

---

# Approach

## Step 1: Handle Empty Matrix

If the matrix is empty,

```cpp
return false;
```

---

## Step 2: Start from the Bottom-Left Corner

Initialize:

```cpp
row = matrix.size() - 1;
col = 0;
```

The bottom-left element is a good starting point because:

- Moving **up** decreases values.
- Moving **right** increases values.

---

## Step 3: Compare with the Target

While the current position is inside the matrix:

```cpp
while(row >= 0 && col < matrix[0].size())
```

### Case 1: Target Found

If

```cpp
matrix[row][col] == target
```

return

```cpp
true;
```

---

### Case 2: Current Value is Smaller

If

```cpp
matrix[row][col] < target
```

the target must be on the **right**, because every element above is even smaller.

Move right.

```cpp
col++;
```

---

### Case 3: Current Value is Larger

If

```cpp
matrix[row][col] > target
```

the target must be **above**, because every element to the right is even larger.

Move up.

```cpp
row--;
```

---

## Step 4: Target Not Found

If the search moves outside the matrix,

return

```cpp
false;
```

---

# Dry Run

### Input

```text
matrix =
[
 [1,4,7,11,15],
 [2,5,8,12,19],
 [3,6,9,16,22],
 [10,13,14,17,24],
 [18,21,23,26,30]
]

target = 16
```

---

### Initial Position

```text
row = 4
col = 0

value = 18
```

Since

```text
18 > 16
```

Move up.

```text
row = 3
```

---

### Next Position

```text
value = 10
```

Since

```text
10 < 16
```

Move right.

```text
col = 1
```

---

### Next Position

```text
value = 13
```

Since

```text
13 < 16
```

Move right.

```text
col = 2
```

---

### Next Position

```text
value = 14
```

Since

```text
14 < 16
```

Move right.

```text
col = 3
```

---

### Next Position

```text
value = 17
```

Since

```text
17 > 16
```

Move up.

```text
row = 2
```

---

### Next Position

```text
value = 16
```

Target found.

Return

```text
true
```

---

# Why Start from the Bottom-Left Corner?

At the bottom-left corner:

- Everything **above** is smaller.
- Everything **to the right** is larger.

This gives a clear direction after every comparison.

For example:

```text
      →
Smaller   Larger

↑
Smaller
```

So:

- If the current value is too small, move **right**.
- If the current value is too large, move **up**.

Each move eliminates an entire row or an entire column.

---

# Complexity Analysis

### Time Complexity

In the worst case, each step removes one row or one column.

Maximum moves:

```text
m + n
```

Therefore,

```text
O(m + n)
```

where:

- `m` = number of rows
- `n` = number of columns

---

### Space Complexity

Only two pointers are used.

```text
O(1)
```

---

# C++ Solution

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        if (matrix.empty()) {
            return false;
        }

        int row = matrix.size() - 1;
        int col = 0;

        while (row >= 0 && col < matrix[0].size()) {

            if (matrix[row][col] == target) {

                return true;

            } else if (matrix[row][col] < target) {

                col++;

            } else {

                row--;
            }
        }

        return false;
    }
};
```

---

# Key Takeaways

- In this problem, each row and each column is sorted independently, so Binary Search on the entire matrix is not applicable.
- Start from the **bottom-left corner** (or equivalently, the **top-right corner**) because each comparison gives a definite direction to move.
- If the current value is smaller than the target, move **right**.
- If the current value is larger than the target, move **up**.
- Each move eliminates an entire row or column, resulting in **O(m + n)** time and **O(1)** extra space.
