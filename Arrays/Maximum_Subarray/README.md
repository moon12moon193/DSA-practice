# Maximum Subarray (Kadane's Algorithm)

## Problem

Given an integer array `nums`, find the **contiguous subarray** with the largest sum and return its sum.

A subarray must contain at least one element.

---

## Intuition

At every index, there are only two choices:

1. **Start a new subarray** from the current element.
2. **Extend the previous subarray** by including the current element.

We always choose the option that gives the larger sum.

To solve this efficiently, we maintain:

- **Current Maximum (`currMax`)** – Maximum sum of a subarray ending at the current index.
- **Global Maximum (`GlobalMax`)** – Maximum subarray sum found so far.

---

## Approach

1. Initialize both `currMax` and `GlobalMax` with the first element.
2. Traverse the array starting from the second element.
3. For each element:
   - Either start a new subarray using the current element.
   - Or extend the previous subarray.
4. Update the current maximum.
5. Update the global maximum if needed.
6. Return the global maximum.

---

## Algorithm

1. Initialize:
   - `currMax = nums[0]`
   - `GlobalMax = nums[0]`

2. Traverse the array from index `1`.

3. For each element:
   - `v1 = nums[i]`
   - `v2 = currMax + nums[i]`
   - `currMax = max(v1, v2)`
   - `GlobalMax = max(GlobalMax, currMax)`

4. Return `GlobalMax`.





---

## Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## Key Takeaways

- At each index, decide whether to **start a new subarray** or **continue the existing one**.
- `currMax` represents the maximum sum of a subarray **ending at the current index**.
- `GlobalMax` stores the largest subarray sum found during the traversal.
- This algorithm is known as **Kadane's Algorithm** and solves the problem in linear time with constant extra space.
