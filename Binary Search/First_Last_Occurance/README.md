# Find First and Last Position of Element in Sorted Array (LeetCode 34)

## Problem

Given a sorted array of integers `nums` in **non-decreasing order** and an integer `target`, return the **first** and **last** positions of `target` in the array.

If the target is not present, return:

```cpp
[-1, -1]
```

You must design an algorithm with **O(log n)** time complexity.

---

## Example 1

**Input**

```cpp
nums = [5,7,7,8,8,10]
target = 8
```

**Output**

```cpp
[3,4]
```

### Explanation

The value `8` appears from index `3` to index `4`.

---

## Example 2

**Input**

```cpp
nums = [5,7,7,8,8,10]
target = 6
```

**Output**

```cpp
[-1,-1]
```

### Explanation

The target `6` does not exist in the array.

---

## Example 3

**Input**

```cpp
nums = []
target = 0
```

**Output**

```cpp
[-1,-1]
```

---

# Intuition

Since the array is sorted, Binary Search can be used.

However, a normal Binary Search stops as soon as it finds the target.

In this problem, we need:

- the **leftmost (first)** occurrence
- the **rightmost (last)** occurrence

Therefore, perform **two separate Binary Searches**:

1. One to find the first occurrence.
2. Another to find the last occurrence.

---

# Approach

## Step 1: Find the First Occurrence

Perform Binary Search.

Whenever the target is found:

- Store the current index.
- Continue searching on the **left side**.

```cpp
high = mid - 1;
```

This ensures that if another occurrence exists earlier, it will be found.

---

## Step 2: Find the Last Occurrence

Reset the search boundaries.

Again perform Binary Search.

Whenever the target is found:

- Store the current index.
- Continue searching on the **right side**.

```cpp
low = mid + 1;
```

This ensures the last occurrence is found.

---

## Step 3: Return the Result

If the target never appears,

the initialized values remain

```cpp
[-1, -1]
```

Otherwise,

return

```cpp
[firstOccurrence, lastOccurrence]
```

---

# Dry Run

### Input

```text
nums = [5,7,7,8,8,10]
target = 8
```

---

## First Binary Search (First Position)

### Iteration 1

```text
low = 0
high = 5

mid = 2

nums[mid] = 7
```

Move right.

```text
low = 3
```

---

### Iteration 2

```text
low = 3
high = 5

mid = 4

nums[mid] = 8
```

Store answer.

```text
first = 4
```

Continue searching left.

```text
high = 3
```

---

### Iteration 3

```text
low = 3
high = 3

mid = 3

nums[mid] = 8
```

Update answer.

```text
first = 3
```

Continue left.

Loop ends.

Final first position:

```text
3
```

---

## Second Binary Search (Last Position)

Reset

```text
low = 0
high = 5
```

---

### Iteration 1

```text
mid = 2

nums[mid] = 7
```

Move right.

---

### Iteration 2

```text
mid = 4

nums[mid] = 8
```

Store answer.

```text
last = 4
```

Continue searching right.

```text
low = 5
```

Loop finishes.

Final last position:

```text
4
```

---

Final result

```text
[3,4]
```

---

# Why Two Binary Searches?

A standard Binary Search stops immediately after finding the target.

Example:

```text
nums = [2,4,4,4,6]
```

It may return:

```text
2
```

or

```text
3
```

depending on where it first lands.

But the problem specifically asks for:

- First occurrence
- Last occurrence

So after finding the target, we **continue searching** instead of stopping.

- Search left to find the first occurrence.
- Search right to find the last occurrence.

---

# Complexity Analysis

### Time Complexity

- First Binary Search: **O(log n)**
- Second Binary Search: **O(log n)**

Overall:

```text
O(log n)
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
    vector<int> searchRange(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;

        vector<int> res(2, -1);

        // Find First Occurrence
        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] < target) {
                low = mid + 1;
            }
            else if (nums[mid] > target) {
                high = mid - 1;
            }
            else {
                res[0] = mid;
                high = mid - 1;
            }
        }

        // Reset Search Range
        low = 0;
        high = nums.size() - 1;

        // Find Last Occurrence
        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] < target) {
                low = mid + 1;
            }
            else if (nums[mid] > target) {
                high = mid - 1;
            }
            else {
                res[1] = mid;
                low = mid + 1;
            }
        }

        return res;
    }
};
```

---

# Key Takeaways

- A single Binary Search cannot always find the **first** or **last** occurrence of a repeated element.
- Use **two Binary Searches**:
  - Move **left** after finding the target to locate the first occurrence.
  - Move **right** after finding the target to locate the last occurrence.
- Initialize the answer as `[-1, -1]` to handle the case where the target is absent.
- The solution runs in **O(log n)** time with **O(1)** extra space.
