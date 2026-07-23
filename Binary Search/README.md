# Binary Search

## Overview

This folder contains solutions to **Binary Search** problems solved as part of my **Data Structures & Algorithms (DSA)** learning journey.

The goal of this section is to build a strong understanding of the **Binary Search** technique and learn how to efficiently solve problems involving sorted data, search spaces, and optimization.

Each problem in this folder includes:

- ✅ Clean and optimized C++ solution
- ✅ Step-by-step explanation
- ✅ Intuition behind the approach
- ✅ Dry run with examples
- ✅ Time and Space Complexity analysis
- ✅ Well-documented `README.md`

---

# What is Binary Search?

**Binary Search** is an efficient searching algorithm that works on **sorted data**.

Instead of checking every element one by one, Binary Search repeatedly divides the search space into two halves and eliminates the half that cannot contain the target.

This reduces the search time significantly compared to linear search.

Example:

```
Array: [2, 5, 8, 12, 16, 23, 38]

Target = 16

Step 1:
Middle = 12

Since 16 > 12
Search the right half.

Step 2:
Middle = 23

Since 16 < 23
Search the left half.

Step 3:
Middle = 16

Target Found.
```

---

# How Binary Search Works

1. Start with two pointers:
   - `left = 0`
   - `right = n - 1`

2. Find the middle element.

```cpp
int mid = left + (right - left) / 2;
```

3. Compare the middle element with the target.

- If equal → Target found.
- If target is smaller → Search the left half.
- If target is larger → Search the right half.

4. Repeat until the search space becomes empty.

---

# Why Use

```cpp
mid = left + (right - left) / 2;
```

instead of

```cpp
mid = (left + right) / 2;
```

Because when `left` and `right` are very large,

```cpp
left + right
```

can overflow the integer range.

The safer formula avoids this issue while producing the same result.

---

# Common Binary Search Patterns

This folder contains problems based on concepts such as:

- Classic Binary Search
- First Occurrence
- Last Occurrence
- Lower Bound
- Upper Bound
- Search Insert Position
- Search in Rotated Sorted Array
- Peak Element
- Minimum in Rotated Sorted Array
- Binary Search on Answer
- Search Space Reduction
- Monotonic Functions
- Finding Boundaries
- Searching in 2D Matrices
- Binary Search on Arrays
- Binary Search on Integers
- Binary Search on Floating Point Values

---

# Skills Developed

By solving Binary Search problems, I am improving my understanding of:

- Efficient searching techniques
- Divide and conquer strategy
- Identifying sorted properties
- Recognizing monotonic conditions
- Reducing time complexity
- Boundary handling
- Preventing integer overflow
- Binary Search on Answer problems
- Writing optimized C++ implementations

---

# When to Use Binary Search?

Binary Search is useful when:

- The data is sorted.
- The search space can be divided into two parts.
- A monotonic property exists.
- You need to find the first or last occurrence of an element.
- You need to search for a minimum or maximum valid answer.
- You are asked to optimize a brute-force solution by reducing the search space.

---

# Complexity Focus

While solving Binary Search problems, I focus on:

- Correctly identifying the search space.
- Choosing appropriate boundary conditions.
- Avoiding infinite loops.
- Preventing integer overflow while calculating the middle index.
- Converting brute-force solutions into logarithmic-time solutions.
- Recognizing problems where Binary Search can be applied even when searching over answers instead of array elements.

---

# Learning Goal

The objective of this folder is to master **Binary Search** and its various patterns commonly asked in coding interviews.

By practicing progressively challenging problems, I aim to develop the ability to recognize Binary Search opportunities, design efficient solutions, and confidently solve interview-level questions.

I will continue updating this folder as I solve more Binary Search problems and explore advanced search techniques.

---

## Time Complexity

| Operation | Complexity |
|-----------|-----------:|
| Binary Search | **O(log n)** |
| Space Complexity (Iterative) | **O(1)** |
| Space Complexity (Recursive) | **O(log n)** (Call Stack) |

---

## Language

**C++**

---

## Repository

**DSA Practice**
