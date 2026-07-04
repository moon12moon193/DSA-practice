# LeetCode 918 - Maximum Sum Circular Subarray

## Problem

Given a **circular integer array** `nums`, return the **maximum possible sum of a non-empty subarray**.

In a circular array:

- The last element is connected to the first element.
- A subarray may wrap from the end of the array to the beginning.

---

## Understanding the Problem

There are **two possible types of maximum subarrays**.

### 1. Normal (Non-Circular) Subarray

The subarray lies completely inside the array.

Example:

```
[5, -3, 5]
```

Possible subarrays:

```
[5]
[-3]
[5]
[5, -3]
[-3, 5]
[5, -3, 5]
```

This is exactly the problem solved by **Kadane's Algorithm**.

---

### 2. Circular Subarray

A subarray can wrap around the array.

Example:

```
[5, -3, 5]
```

The circular subarray is

```
5      5
↑      ↑
```

which has a sum of

```
5 + 5 = 10
```

---

## Key Observation

Instead of directly finding the circular subarray, think about **what is excluded**.

For

```
[5, -3, 5]
```

The circular subarray

```
5 + 5
```

is obtained by removing

```
[-3]
```

Therefore,

```
Circular Sum =
Total Array Sum
-
Minimum Subarray Sum
```

---

## Why Minimum Subarray?

Suppose

```
Total Sum = 20
```

### Excluding a Positive Subarray

```
20 - 8 = 12
```

The answer becomes smaller.

### Excluding a Negative Subarray

```
20 - (-6) = 26
```

The answer becomes larger.

Therefore, to maximize the circular sum, we remove the **minimum-sum subarray**.

---

## Dynamic Programming States

We maintain four variables.

### 1. `CurrmaxiSum`

Represents

> Maximum subarray sum ending at the current index.

Transition

```cpp
CurrmaxiSum = max(CurrmaxiSum + nums[i], nums[i]);
```

---

### 2. `globalMax`

Represents

> Maximum subarray sum found so far.

Transition

```cpp
globalMax = max(globalMax, CurrmaxiSum);
```

---

### 3. `CurrminSum`

Represents

> Minimum subarray sum ending at the current index.

Transition

```cpp
CurrminSum = min(CurrminSum + nums[i], nums[i]);
```

---

### 4. `globalMin`

Represents

> Minimum subarray sum found so far.

Transition

```cpp
globalMin = min(globalMin, CurrminSum);
```

---

## Circular Sum Formula

```
Circular Sum = Total Sum - globalMin
```

---

## Edge Case

Consider

```
[-3, -2, -3]
```

### Total Sum

```
-8
```

### Maximum Subarray

```
[-2]

Sum = -2
```

### Minimum Subarray

```
[-3, -2, -3]

Sum = -8
```

Applying the circular formula

```
-8 - (-8) = 0
```

This means we removed the **entire array**, leaving an empty subarray.

However, the problem requires the chosen subarray to be **non-empty**.

Therefore, this result is invalid.

### How to Detect This Case

If every element is negative,

```
globalMax < 0
```

So,

```cpp
if(globalMax < 0)
    return globalMax;
```

Otherwise,

```
Answer = max(globalMax, Total Sum - globalMin)
```

---

## Dry Run

### Input

```
nums = [5, -3, 5]
```

### Total Sum

```
7
```

| Index | Value | CurrmaxiSum | globalMax | CurrminSum | globalMin |
|------:|------:|------------:|----------:|-----------:|----------:|
| 0 | 5 | 5 | 5 | 5 | 5 |
| 1 | -3 | 2 | 5 | -3 | -3 |
| 2 | 5 | 7 | 7 | 2 | -3 |

### Normal Maximum

```
7
```

### Circular Maximum

```
7 - (-3) = 10
```

Final Answer

```
10
```

---

## Algorithm

1. Compute the total array sum.
2. Use Kadane's algorithm to find the maximum subarray sum.
3. Use reverse Kadane's algorithm to find the minimum subarray sum.
4. If every element is negative, return `globalMax`.
5. Otherwise, return

```cpp
max(globalMax, totalSum - globalMin)
```

---

## Complexity Analysis

### Time Complexity

```
O(n)
```

Only one traversal of the array.

### Space Complexity

```
O(1)
```

Only a few variables are used.

---


## Key Takeaways

- The maximum subarray can be:
  - **Normal (non-circular)** → Found using Kadane's algorithm.
  - **Circular (wrapping around)** → Found using `totalSum - minimumSubarraySum`.
- The circular solution works because a wrapped subarray is equivalent to taking the entire array and excluding one contiguous middle subarray.
- To maximize the remaining sum, exclude the **minimum-sum subarray**.
- If all elements are negative, the circular formula becomes invalid because it removes the entire array, leaving an empty subarray.
- Always compare:
  - `globalMax`
  - `totalSum - globalMin`
  and handle the all-negative edge case separately.
