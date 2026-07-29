# Kth Smallest Element in a Sorted Matrix (LeetCode 378)

## Problem

You are given an `n × n` matrix where:

- Each row is sorted in **ascending order**.
- Each column is sorted in **ascending order**.

Return the **kᵗʰ smallest element** in the matrix.

Note that it is the **kᵗʰ smallest element in the sorted order**, not the kᵗʰ distinct element.

---

## Example 1

**Input**

```cpp
matrix = [
  [1,5,9],
  [10,11,13],
  [12,13,15]
]

k = 8
```

**Output**

```cpp
13
```

### Explanation

The sorted order of all elements is:

```text
1, 5, 9, 10, 11, 12, 13, 13, 15
```

The 8ᵗʰ smallest element is:

```text
13
```

---

## Example 2

**Input**

```cpp
matrix = [
  [-5]
]

k = 1
```

**Output**

```cpp
-5
```

---

# Intuition

Instead of searching for an **index**, we search for the **answer (value)**.

The smallest possible answer is:

```cpp
matrix[0][0]
```

The largest possible answer is:

```cpp
matrix[n - 1][n - 1]
```

For every candidate value `mid`, count how many elements in the matrix are **less than or equal to `mid`**.

- If fewer than `k` elements are `≤ mid`, the answer must be larger.
- Otherwise, `mid` could be the answer, so try to find a smaller valid value.

This is an example of **Binary Search on the Answer**.

---

# Approach

## Step 1: Define the Search Space

The minimum value in the matrix is:

```cpp
low = matrix[0][0];
```

The maximum value is:

```cpp
high = matrix[n - 1][n - 1];
```

---

## Step 2: Count Elements Less Than or Equal to `mid`

Use the helper function:

```cpp
CalcSmallerNums(mid, matrix)
```

Start from the **bottom-left corner**.

Initialize:

```cpp
row = n - 1;
col = 0;
```

At each step:

- If

```cpp
matrix[row][col] <= mid
```

then every element above it in the same column is also `<= mid`.

So add:

```cpp
row + 1
```

to the count and move right.

Otherwise,

move upward.

This counts all elements `<= mid` in **O(n)** time.

---

## Step 3: Perform Binary Search

Compute

```cpp
mid = low + (high - low) / 2;
```

Count how many elements are `<= mid`.

### Case 1

If

```cpp
count < k
```

the answer is larger.

```cpp
low = mid + 1;
```

---

### Case 2

Otherwise,

`mid` is a possible answer.

Store it.

```cpp
res = mid;
```

Search for a smaller valid value.

```cpp
high = mid - 1;
```

---

## Step 4: Return the Result

After Binary Search completes,

`res` stores the kᵗʰ smallest element.

---

# Dry Run

### Input

```text
matrix =
[
 [1,5,9],
 [10,11,13],
 [12,13,15]
]

k = 8
```

---

### Initial State

```text
low = 1
high = 15
```

---

### Iteration 1

```text
mid = 8
```

Elements `<= 8`

```text
1, 5
```

Count

```text
2
```

Since

```text
2 < 8
```

Search right.

```text
low = 9
```

---

### Iteration 2

```text
mid = 12
```

Elements `<= 12`

```text
1,5,9,10,11,12
```

Count

```text
6
```

Still

```text
6 < 8
```

Move right.

```text
low = 13
```

---

### Iteration 3

```text
mid = 14
```

Elements `<= 14`

```text
1,5,9,10,11,12,13,13
```

Count

```text
8
```

Since

```text
8 >= 8
```

Store

```text
res = 14
```

Search left.

```text
high = 13
```

---

### Iteration 4

```text
mid = 13
```

Count of elements `<= 13`

```text
8
```

Store

```text
res = 13
```

Move left.

Loop ends.

Return

```text
13
```

---

# Why Start from the Bottom-Left Corner?

At the bottom-left corner:

- Every element **above** is smaller.
- Every element **to the right** is larger.

If

```cpp
matrix[row][col] <= mid
```

then the entire column above that element is also `<= mid`.

Therefore,

```cpp
count += row + 1;
```

and move right.

Otherwise,

move upward.

This counts all valid elements in **O(n)** time instead of scanning the whole matrix.

---

# Complexity Analysis

### Time Complexity

Binary Search over the value range:

```text
O(log(maxValue - minValue))
```

Each Binary Search iteration counts elements in:

```text
O(n)
```

Overall:

```text
O(n × log(maxValue - minValue))
```

---

### Space Complexity

Only a few variables are used.

```text
O(1)
```

---

# C++ Solution

```cpp
class Solution {
public:

    int CalcSmallerNums(int mid, vector<vector<int>>& matrix) {

        int count = 0;
        int row = matrix.size() - 1;
        int col = 0;

        while (row >= 0 && col < matrix[0].size()) {

            if (matrix[row][col] <= mid) {

                count += row + 1;
                col++;

            } else {

                row--;
            }
        }

        return count;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {

        int low = matrix[0][0];
        int high = matrix[matrix.size() - 1][matrix[0].size() - 1];
        int res = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int count = CalcSmallerNums(mid, matrix);

            if (count < k) {

                low = mid + 1;

            } else {

                res = mid;
                high = mid - 1;
            }
        }

        return res;
    }
};
```

---

# Key Takeaways

- This problem uses **Binary Search on the Answer**, where the search space is the range of matrix values rather than indices.
- For each candidate value `mid`, efficiently count how many elements are less than or equal to `mid`.
- Starting from the **bottom-left corner** allows counting in **O(n)** time by eliminating rows or columns at each step.
- If fewer than `k` elements are `<= mid`, search larger values; otherwise, record `mid` as a candidate answer and search for a smaller valid value.
- The overall time complexity is **O(n × log(maxValue − minValue))** with **O(1)** extra space.
