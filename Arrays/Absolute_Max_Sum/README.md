# LeetCode 1749 - Maximum Absolute Sum of Any Subarray

## Problem

Given an integer array `nums`, return the **maximum absolute sum** of any (possibly non-empty) subarray.

The **absolute sum** of a subarray is:

\[
|sum|
\]

where `sum` is the total of all elements in that subarray.

---

## Key Observation

The absolute value can become large in two situations:

- The subarray has a **very large positive sum**.
- The subarray has a **very large negative sum**.

For example,

```
nums = [2, -5, 1]
```

Possible subarray sums are

```
[2]         = 2
[-5]        = -5
[1]         = 1
[2,-5]      = -3
[-5,1]      = -4
[2,-5,1]    = -2
```

Absolute values

```
2, 5, 1, 3, 4, 2
```

Maximum absolute sum = **5**.

Therefore, instead of only finding the maximum subarray sum, we must also track the **minimum subarray sum**.

---

# Idea

At every index, maintain two states.

## 1. `maxSum`

Represents:

> Maximum subarray sum ending at the current index.

This is the standard Kadane's Algorithm state.

Possible choices:

- Extend the previous maximum subarray.
- Extend the previous minimum subarray.
- Start a new subarray.

Transition

```cpp
maxSum = max(maxSum + nums[i],
             minSum + nums[i],
             nums[i]);
```

---

## 2. `minSum`

Represents:

> Minimum subarray sum ending at the current index.

Possible choices:

- Extend the previous minimum subarray.
- Extend the previous maximum subarray.
- Start a new subarray.

Transition

```cpp
minSum = min(previousMax + nums[i],
             previousMin + nums[i],
             nums[i]);
```

Tracking the minimum sum is important because a very negative sum may produce the largest absolute value.

---

## Updating the Answer

At every index,

```
Answer = max(
    Answer,
    abs(maxSum),
    abs(minSum)
)
```

The final answer is the largest absolute value encountered.

---

# Dry Run

Input

```
nums = [1, -3, 2, 3, -4]
```

| Index | Value | maxSum | minSum | Result |
|------:|------:|-------:|-------:|-------:|
| 0 | 1 | 1 | 1 | 1 |
| 1 | -3 | -2 | -3 | 3 |
| 2 | 2 | 2 | -1 | 3 |
| 3 | 3 | 5 | 2 | 5 |
| 4 | -4 | 1 | -4 | 5 |

Final Answer

```
5
```

---

# Algorithm

1. Initialize

```cpp
maxSum = nums[0];
minSum = nums[0];
result = abs(nums[0]);
```

2. Traverse the array.

3. Compute

```cpp
v1 = previousMax + nums[i];
v2 = previousMin + nums[i];
v3 = nums[i];
```

4. Update

```cpp
maxSum = max(v1, max(v2, v3));

minSum = min(v1, min(v2, v3));
```

5. Update the answer.

---

# Complexity Analysis

### Time Complexity

```
O(n)
```

Single traversal of the array.

### Space Complexity

```
O(1)
```

Only a few variables are used.



---

# Key Takeaways

- The maximum absolute sum can come from either:
  - the largest positive subarray sum, or
  - the most negative subarray sum.
- `maxSum` stores the maximum subarray sum ending at the current index.
- `minSum` stores the minimum subarray sum ending at the current index.
- At every index, update both states and keep the maximum of their absolute values.
- This solution extends Kadane's Algorithm by simultaneously tracking both the maximum and minimum subarray sums while maintaining **O(n)** time and **O(1)** extra space.
