# Search in Rotated Sorted Array (LeetCode 33)

## Problem

There is an integer array `nums` sorted in ascending order with **distinct values**.

Before being passed to your function, the array is rotated at an unknown pivot.

Given the rotated array `nums` and an integer `target`, return the **index** of `target` if it exists; otherwise, return **`-1`**.

You must design an algorithm with **O(log n)** time complexity.

---

## Example 1

**Input**

```cpp
nums = [4,5,6,7,0,1,2]
target = 0
```

**Output**

```cpp
4
```

### Explanation

The target `0` exists at index `4`.

---

## Example 2

**Input**

```cpp
nums = [4,5,6,7,0,1,2]
target = 3
```

**Output**

```cpp
-1
```

### Explanation

The target is not present in the array.

---

## Example 3

**Input**

```cpp
nums = [1]
target = 0
```

**Output**

```cpp
-1
```

---

# Intuition

Although the array is rotated, it still consists of **two sorted portions**:

- Left sorted portion
- Right sorted portion

Using Binary Search, we first determine **which portion the middle element belongs to** by comparing it with the last element.

Then we check whether the target can lie in that portion. If not, we eliminate it and search the other half.

This allows us to maintain the **O(log n)** time complexity.

---

# Approach

## Step 1: Initialize Binary Search

Start with the full search range.

```cpp
low = 0;
high = nums.size() - 1;
```

---

## Step 2: Find the Middle Element

Compute the middle index safely.

```cpp
int mid = low + (high - low) / 2;
```

---

## Step 3: Check if Target is Found

If

```cpp
nums[mid] == target
```

return

```cpp
mid
```

---

## Step 4: Identify the Sorted Portion

Compare the middle element with the last element.

### Case 1: Mid is in the Left Sorted Portion

```cpp
nums[mid] > nums[n - 1]
```

Now there are two possibilities:

- If the target also belongs to the left sorted portion, continue searching left.
- Otherwise, search the right portion.

Specifically:

- If `nums[mid] < target`

```cpp
low = mid + 1;
```

- Otherwise:

  - If

```cpp
target < nums[0]
```

the target belongs to the right portion.

```cpp
low = mid + 1;
```

  - Else

```cpp
high = mid - 1;
```

---

### Case 2: Mid is in the Right Sorted Portion

Otherwise,

```cpp
nums[mid] <= nums[n - 1]
```

The middle lies in the right sorted portion.

- If `nums[mid] > target`

```cpp
high = mid - 1;
```

- Otherwise:

  - If

```cpp
target > nums[n - 1]
```

the target belongs to the left portion.

```cpp
high = mid - 1;
```

  - Else

```cpp
low = mid + 1;
```

---

## Step 5: Return the Result

If the search space becomes empty,

return

```cpp
-1
```

---

# Dry Run

### Input

```text
nums = [4,5,6,7,0,1,2]
target = 0
```

---

### Iteration 1

```text
low = 0
high = 6

mid = 3

nums[mid] = 7
```

Since

```text
7 > 2
```

`mid` is in the left sorted portion.

Target `0` is less than `nums[0]`, so it must be in the right portion.

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

`mid` is in the right sorted portion.

Since

```text
1 > 0
```

search left.

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

Target found.

Return

```text
4
```

---

# Why Compare with the Last Element?

The last element helps determine which sorted portion the middle element belongs to.

- If

```cpp
nums[mid] > nums[n - 1]
```

then `mid` is in the **left sorted portion**.

- Otherwise,

`mid` is in the **right sorted portion**.

Knowing this allows us to determine whether the target could exist in the current portion or whether we should discard it and search the other half.

---

# Complexity Analysis

### Time Complexity

Each iteration removes half of the remaining search space.

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
        int n = nums.size();

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[n - 1]) {

                if (nums[mid] == target) {
                    return mid;
                }
                else if (nums[mid] < target) {
                    low = mid + 1;
                }
                else {

                    if (target < nums[0]) {
                        low = mid + 1;
                    }
                    else {
                        high = mid - 1;
                    }
                }
            }
            else {

                if (nums[mid] == target) {
                    return mid;
                }
                else if (nums[mid] > target) {
                    high = mid - 1;
                }
                else {

                    if (target > nums[n - 1]) {
                        high = mid - 1;
                    }
                    else {
                        low = mid + 1;
                    }
                }
            }
        }

        return -1;
    }
};
```

---

# Key Takeaways

- A rotated sorted array consists of **two individually sorted portions**.
- Compare `nums[mid]` with the **last element** to determine which portion the middle element belongs to.
- Use the first and last elements to determine whether the target lies in the same sorted portion as `mid`.
- Discard the impossible half in each iteration, preserving the efficiency of Binary Search.
- The algorithm runs in **O(log n)** time with **O(1)** extra space.
