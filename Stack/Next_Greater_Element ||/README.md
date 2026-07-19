# Next Greater Element II (LeetCode 503)

## Problem

Given a **circular integer array** `nums`, return an array `answer` where:

- `answer[i]` is the **next greater element** of `nums[i]`.
- If no greater element exists, return `-1` for that position.

Since the array is **circular**, after reaching the last element, the search continues from the beginning of the array.

---

## Example 1

**Input**

```cpp
nums = [1,2,1]
```

**Output**

```cpp
[2,-1,2]
```

### Explanation

- Next greater element of **1** is **2**.
- **2** has no greater element.
- The last **1** wraps around to the beginning and finds **2**.

---

## Example 2

**Input**

```cpp
nums = [1,2,3,4,3]
```

**Output**

```cpp
[2,3,4,-1,4]
```

---

# Intuition

For every element, we need to find the **first greater element on its right**.

Because the array is **circular**, after reaching the last index, we continue searching from the beginning.

A brute-force solution checks every element against all others, resulting in **O(n²)** time.

A **Monotonic Decreasing Stack** allows us to solve the problem in **O(n)** time.

---

# Approach

## Step 1: Simulate a Circular Array

Instead of physically duplicating the array, traverse it **twice**.

Loop from

```cpp
2 * n - 1
```

to

```cpp
0
```

Access the actual index using

```cpp
i % n
```

This wraps the index back to the beginning.

Example

```
n = 3

Indices visited

5 4 3 2 1 0

Modulo

2 1 0 2 1 0
```

---

## Step 2: Maintain a Monotonic Decreasing Stack

The stack stores **indices** of elements.

Before processing the current element,

remove every element from the stack that is

```
<= current element
```

because those elements can never be the next greater element.

```cpp
while (!s.empty() && nums[s.top()] <= nums[i % n]) {
    s.pop();
}
```

---

## Step 3: Find the Next Greater Element

After removing smaller elements,

- If the stack is not empty,
- The top of the stack contains the next greater element.

```cpp
res[i % n] = nums[s.top()];
```

---

## Step 4: Push the Current Index

Push the current index onto the stack.

```cpp
s.push(i % n);
```

This element may become the next greater element for upcoming indices.

---

# Dry Run

### Input

```
nums = [1,2,1]
```

Length

```
n = 3
```

Traverse from index

```
5 → 0
```

### Iteration Summary

| i | Actual Index (`i % n`) | Stack | Result |
|---|-------------------------|-------|--------|
| 5 | 2 | 1 | -1 |
| 4 | 1 | 2 | -1 |
| 3 | 0 | 2,1 | 2 |
| 2 | 2 | 2,1 | 2 |
| 1 | 1 | 2 | -1 |
| 0 | 0 | 2,1 | 2 |

Final answer

```
[2,-1,2]
```

---

# Why Traverse Twice?

Suppose

```
nums = [5,3,4]
```

For

```
4
```

the next greater element is

```
5
```

which is **before** it in the array.

Without traversing the array twice,

```
5
```

would never be considered.

Using

```cpp
i % n
```

makes the traversal circular without creating a new array.

---

# Why Use a Monotonic Stack?

The stack always keeps elements in **strictly decreasing order**.

Example

```
Stack

8
6
4
```

When processing

```
7
```

remove

```
6
4
```

because neither can be the next greater element for future values.

This ensures every element is pushed and popped at most once.

---

# Complexity Analysis

### Time Complexity

Each index is pushed and popped at most once.

```
O(n)
```

---

### Space Complexity

The stack stores at most `n` indices.

```
O(n)
```

---

# C++ Solution

```cpp
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();

        vector<int> res(n, -1);

        stack<int> s;

        for (int i = 2 * n - 1; i >= 0; i--) {

            while (!s.empty() && nums[s.top()] <= nums[i % n]) {
                s.pop();
            }

            if (!s.empty()) {
                res[i % n] = nums[s.top()];
            }

            s.push(i % n);
        }

        return res;
    }
};
```

---

# Key Takeaways

- The array is **circular**, so traverse it **twice** using `i % n`.
- Use a **Monotonic Decreasing Stack** to efficiently find the next greater element.
- Remove all elements from the stack that are smaller than or equal to the current element.
- The top of the stack (if it exists) is the next greater element.
- Each element is pushed and popped at most once, resulting in an **O(n)** time solution with **O(n)** extra space.
