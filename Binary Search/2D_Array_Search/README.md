# Search a 2D Matrix (LeetCode 74)

## Problem

You are given an `m × n` integer matrix with the following properties:

- Each row is sorted in **ascending order**.
- The first integer of each row is greater than the last integer of the previous row.

Given an integer `target`, return **`true`** if the target exists in the matrix; otherwise, return **`false`**.

You must solve the problem in **O(log(m × n))** time.

---

## Example 1

**Input**

```cpp
matrix = [
  [1,3,5,7],
  [10,11,16,20],
  [23,30,34,60]
]

target = 3
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
  [1,3,5,7],
  [10,11,16,20],
  [23,30,34,60]
]

target = 13
```

**Output**

```cpp
false
```

---

# Intuition

Since:

- Every row is sorted.
- The first element of each row is greater than the last element of the previous row.

The entire matrix behaves like one sorted array.

Instead of flattening the matrix, this solution performs **two Binary Searches**:

1. Find the row that could contain the target.
2. Perform Binary Search within that row.

This achieves the required logarithmic time complexity.

---

# Approach

## Step 1: Handle Empty Matrix

If the matrix is empty,

```cpp
return false;
```

---

## Step 2: Find the Candidate Row

Perform Binary Search on the **first element of every row**.

Initialize:

```cpp
low = 0;
high = row - 1;
```

During Binary Search:

- If the first element of the current row is greater than the target, search above.
- Otherwise, store the current row as a possible answer and continue searching below.

```cpp
if(matrix[mid][0] > target)
    high = mid - 1;
else
{
    res = mid;
    low = mid + 1;
}
```

After the search:

- `res` stores the last row whose first element is less than or equal to the target.
- If `res == -1`, the target cannot exist in the matrix.

---

## Step 3: Binary Search Within the Selected Row

Now search only inside the candidate row.

Initialize:

```cpp
low2 = 0;
high2 = col - 1;
```

Compare the middle element with the target:

- If equal, return `true`.
- If smaller, search right.
- If larger, search left.

---

## Step 4: Return the Result

If Binary Search finishes without finding the target,

```cpp
return false;
```

---

# Dry Run

### Input

```text
matrix =
[
 [1,3,5,7],
 [10,11,16,20],
 [23,30,34,60]
]

target = 16
```

---

## First Binary Search (Find Row)

### Initial State

```text
low = 0
high = 2
```

---

### Iteration 1

```text
mid = 1

matrix[1][0] = 10
```

Since

```text
10 <= 16
```

Store

```text
res = 1
```

Search lower rows.

```text
low = 2
```

---

### Iteration 2

```text
mid = 2

matrix[2][0] = 23
```

Since

```text
23 > 16
```

Search above.

```text
high = 1
```

Loop ends.

Candidate row:

```text
1
```

---

## Second Binary Search (Within Row)

Search in

```text
[10,11,16,20]
```

### Iteration 1

```text
mid = 1

value = 11
```

Since

```text
11 < 16
```

Move right.

---

### Iteration 2

```text
mid = 2

value = 16
```

Target found.

Return

```text
true
```

---

# Why Find the Row First?

Because every row starts with a value larger than the last value of the previous row.

Example:

```text
[
 [1,3,5],
 [8,9,10],
 [15,18,20]
]
```

If the target is

```text
9
```

it **cannot** be in:

```text
[1,3,5]
```

or

```text
[15,18,20]
```

So Binary Search is first used to locate the only possible row, reducing the search space significantly.

---

# Complexity Analysis

### Time Complexity

Finding the row:

```text
O(log m)
```

Searching inside the row:

```text
O(log n)
```

Overall:

```text
O(log m + log n)
```

which is equivalent to:

```text
O(log(m × n))
```

---

### Space Complexity

Only a few extra variables are used.

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

        int row = matrix.size();
        int col = matrix[0].size();

        // Find the candidate row
        int low = 0;
        int high = row - 1;
        int res = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (matrix[mid][0] > target) {

                high = mid - 1;

            } else {

                res = mid;
                low = mid + 1;
            }
        }

        if (res == -1) {
            return false;
        }

        // Search inside the selected row
        int low2 = 0;
        int high2 = col - 1;

        while (low2 <= high2) {

            int mid2 = low2 + (high2 - low2) / 2;

            if (matrix[res][mid2] == target) {

                return true;

            } else if (matrix[res][mid2] < target) {

                low2 = mid2 + 1;

            } else {

                high2 = mid2 - 1;
            }
        }

        return false;
    }
};
```

---

# Key Takeaways

- Treat the matrix as a collection of sorted rows rather than flattening it.
- Use Binary Search twice:
  - First to identify the only possible row containing the target.
  - Second to search within that row.
- If no valid row is found (`res == -1`), the target cannot exist.
- The solution runs in **O(log m + log n)** time and uses **O(1)** extra space.
```
