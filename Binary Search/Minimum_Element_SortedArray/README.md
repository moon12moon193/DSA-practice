# Find Minimum in Rotated Sorted Array (LeetCode 153)

## Problem

Suppose an array sorted in **ascending order** is rotated at an unknown pivot.

Given the rotated sorted array `nums` containing **unique elements**, return the **minimum element**.

You must design an algorithm with **O(log n)** time complexity.

---

## Example 1

**Input**

```cpp
nums = [3,4,5,1,2]
```

**Output**

```cpp
1
```

### Explanation

The original sorted array was:

```text
[1,2,3,4,5]
```

After rotation, the minimum element becomes `1`.

---

## Example 2

**Input**

```cpp
nums = [4,5,6,7,0,1,2]
```

**Output**

```cpp
0
```

---

## Example 3

**Input**

```cpp
nums = [11,13,15,17]
```

**Output**

```cpp
11
```

### Explanation

The array is not rotated, so the first element is the minimum.

---

# Intuition

A rotated sorted array consists of **two sorted parts**.

The minimum element is the point where the rotation occurs.

Instead of searching every element, Binary Search helps identify which half contains the minimum.

- If the array is already sorted, the first element is the answer.
- Otherwise:
  - If `nums[mid]` is greater than the last element, the minimum lies in the **right half**.
  - Otherwise, the minimum lies in the **left half**, including `mid`.

---

# Approach

## Step 1: Check if the Array is Already Sorted

If the last element is greater than the first element,

```cpp
nums[n - 1] > nums[0]
```

then the array has not been rotated.

Return

```cpp
nums[0]
```

---

## Step 2: Initialize Binary Search

```cpp
low = 0;
high = n - 1;
```

---

## Step 3: Find the Middle Element

Calculate the middle index safely.

```cpp
int mid = low + (high - low) / 2;
```

---

## Step 4: Decide the Search Direction

### Case 1: Mid is in the Left Sorted Portion

If

```cpp
nums[mid] > nums[n - 1]
```

the minimum must be on the **right**.

Move

```cpp
low = mid + 1;
```

---

### Case 2: Mid is in the Right Sorted Portion

Otherwise,

`mid` could be the minimum.

Store it.

```cpp
res = nums[mid];
```

Continue searching on the left.

```cpp
high = mid - 1;
```

---

## Step 5: Return the Result

After Binary Search completes,

return

```cpp
res
```

---

# Dry Run

### Input

```text
nums = [4,5,6,7,0,1,2]
```

---

### Initial State

```text
low = 0
high = 6
last = 2
```

---

### Iteration 1

```text
mid = 3

nums[mid] = 7
```

Since

```text
7 > 2
```

the minimum is on the right.

```text
low = 4
```

---

### Iteration 2

```text
low = 4
high = 6

mid = 5

nums[mid] = 1
```

Since

```text
1 <= 2
```

store

```text
res = 1
```

Search left.

```text
high = 4
```

---

### Iteration 3

```text
low = 4
high = 4

mid = 4

nums[mid] = 0
```

Store

```text
res = 0
```

Move left.

```text
high = 3
```

Loop ends.

Return

```text
0
```

---

# Why Compare with the Last Element?

The last element helps determine which sorted portion `mid` belongs to.

- If

```cpp
nums[mid] > nums[n - 1]
```

then `mid` lies in the **left sorted portion**, so the minimum must be further right.

- Otherwise,

`mid` lies in the **right sorted portion**, where the minimum exists.

This observation allows Binary Search to eliminate half of the search space in each iteration.

---

# Complexity Analysis

### Time Complexity

Binary Search halves the search space in every iteration.

```text
O(log n)
```

where `n` is the size of the array.

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
    int findMin(vector<int>& nums) {

        int n = nums.size();
        int res = -1;

        if (nums[n - 1] > nums[0]) {
            return nums[0];
        }

        int low = 0;
        int high = n - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[n - 1]) {

                low = mid + 1;

            } else {

                res = nums[mid];
                high = mid - 1;
            }
        }

        return res;
    }
};
```

---

# Key Takeaways

- A rotated sorted array consists of two sorted portions, with the minimum element marking the rotation point.
- If the array is already sorted, the first element is the minimum.
- Compare `nums[mid]` with the **last element** to determine which portion `mid` belongs to.
- If `nums[mid] > nums[n - 1]`, search the right half; otherwise, store `nums[mid]` as a candidate answer and search the left half.
- The solution runs in **O(log n)** time with **O(1)** extra space.
