# Binary Search (LeetCode 704)

## Problem

Given a **sorted** integer array `nums` in **ascending order** and an integer `target`, return the **index** of `target` if it exists in the array.

If the target is not present, return **`-1`**.

You must solve the problem with a time complexity of **O(log n)**.

---

## Example 1

**Input**

```cpp
nums = [-1,0,3,5,9,12]
target = 9
```

**Output**

```cpp
4
```

### Explanation

The target `9` is present at index `4`.

---

## Example 2

**Input**

```cpp
nums = [-1,0,3,5,9,12]
target = 2
```

**Output**

```cpp
-1
```

### Explanation

The target `2` does not exist in the array.

---

# Intuition

Since the array is already **sorted**, checking every element one by one is unnecessary.

Instead, we repeatedly compare the target with the **middle element** of the current search range.

- If the middle element is the target, return its index.
- If the target is smaller, search the left half.
- If the target is larger, search the right half.

Each comparison cuts the search space in half, making Binary Search much faster than Linear Search.

---

# Approach

## Step 1: Initialize Search Boundaries

Start with two pointers.

```cpp
low = 0
high = nums.size() - 1
```

These pointers represent the current search range.

---

## Step 2: Find the Middle Element

Calculate the middle index safely.

```cpp
int mid = low + (high - low) / 2;
```

This formula avoids integer overflow.

---

## Step 3: Compare with Target

If

```cpp
nums[mid] == target
```

return

```cpp
mid
```

If

```cpp
nums[mid] < target
```

search the right half.

```cpp
low = mid + 1;
```

Otherwise,

search the left half.

```cpp
high = mid - 1;
```

---

## Step 4: Continue Until Search Space is Empty

Repeat the process while

```cpp
low <= high
```

If the loop finishes without finding the target,

return

```cpp
-1
```

---

# Dry Run

### Input

```text
nums = [-1,0,3,5,9,12]
target = 9
```

---

### Iteration 1

```text
low = 0
high = 5

mid = 2

nums[mid] = 3
```

Since

```text
9 > 3
```

Search the right half.

```text
low = 3
high = 5
```

---

### Iteration 2

```text
low = 3
high = 5

mid = 4

nums[mid] = 9
```

Target found.

Return

```text
4
```

---

# Another Example

### Input

```text
nums = [-1,0,3,5,9,12]
target = 2
```

### Iteration 1

```text
mid = 2

nums[mid] = 3
```

Since

```text
2 < 3
```

Search the left half.

---

### Iteration 2

```text
low = 0
high = 1

mid = 0

nums[mid] = -1
```

Since

```text
2 > -1
```

Search the right half.

---

### Iteration 3

```text
low = 1
high = 1

mid = 1

nums[mid] = 0
```

Since

```text
2 > 0
```

Move right again.

```text
low = 2
high = 1
```

Now

```text
low > high
```

The search space is empty.

Return

```text
-1
```

---

# Why Use

```cpp
mid = low + (high - low) / 2;
```

instead of

```cpp
mid = (low + high) / 2;
```

Because

```cpp
low + high
```

may overflow for very large arrays.

The safer formula computes the same middle index without risking overflow.

---

# Complexity Analysis

### Time Complexity

Each iteration eliminates half of the remaining search space.

```text
O(log n)
```

where `n` is the number of elements in the array.

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
    int search(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] < target) {
                low = mid + 1;
            }
            else if (nums[mid] > target) {
                high = mid - 1;
            }
            else {
                return mid;
            }
        }

        return -1;
    }
};
```

---

# Key Takeaways

- Binary Search works only on **sorted** data.
- Compare the target with the middle element and discard half of the search space after each comparison.
- Use `mid = low + (high - low) / 2` to avoid integer overflow.
- The algorithm runs in **O(log n)** time and **O(1)** extra space.
- Binary Search is one of the most important algorithms for coding interviews due to its efficiency and wide range of applications.
