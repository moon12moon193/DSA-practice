# Hash Map

## Overview

This folder contains solutions to **Hash Map** problems solved as part of my **Data Structures & Algorithms (DSA)** learning journey.

The goal of this section is to develop a strong understanding of the **Hash Map** data structure and learn how it can be used to solve problems efficiently by providing **constant-time average lookup, insertion, and deletion** operations.

Each problem in this folder includes:

- ✅ Clean and optimized C++ solution
- ✅ Step-by-step explanation
- ✅ Intuition behind the approach
- ✅ Dry run with examples
- ✅ Time and Space Complexity analysis
- ✅ Well-documented `README.md`

---

# What is a Hash Map?

A **Hash Map** is a data structure that stores data in the form of **key-value pairs**.

Each key is mapped to a value using a **hash function**, allowing fast access to stored data without traversing the entire collection.

Unlike arrays, elements are accessed using **keys** instead of indices.

Example:

```
Key      Value
--------------
Apple      5
Banana     8
Orange     3
```

Searching for `"Banana"` directly returns its associated value.

---

# C++ Hash Map

In C++, the STL provides the **`unordered_map`** container.

```cpp
unordered_map<KeyType, ValueType> mp;
```

Example:

```cpp
unordered_map<string, int> marks;

marks["Ali"] = 95;
marks["Sara"] = 89;
```

---

# Basic Operations

| Operation | Description | Average Time |
|-----------|-------------|--------------|
| `insert` | Add a key-value pair | O(1) |
| `find` | Search for a key | O(1) |
| `erase` | Remove a key | O(1) |
| `operator[]` | Access or update a value | O(1) |
| `count` | Check if a key exists | O(1) |
| `size` | Number of key-value pairs | O(1) |
| `empty` | Check whether the map is empty | O(1) |

> **Note:** In the worst case (many hash collisions), operations can degrade to **O(n)**, but the average case is **O(1)**.

---

# Common Hash Map Patterns

This folder contains problems based on concepts such as:

- Frequency Counting
- Counting Occurrences
- Prefix Sum with Hash Map
- Duplicate Detection
- Two-Pass and One-Pass Hashing
- Lookup Optimization
- Character Frequency
- String Processing
- Array Frequency Problems
- Pair and Sum Problems
- Grouping Elements
- Index Mapping
- Sliding Window with Hash Map
- Hashing + Prefix Sum
- Counting Distinct Elements

---

# Skills Developed

By solving Hash Map problems, I am improving my understanding of:

- Fast searching using keys
- Frequency counting techniques
- Optimizing brute-force solutions
- Prefix sum hashing
- Efficient data storage
- Handling duplicate elements
- Combining Hash Maps with other data structures
- Writing optimized C++ solutions

---

# When to Use a Hash Map?

A Hash Map is useful when a problem involves:

- Fast lookup of values
- Counting frequencies
- Tracking visited elements
- Finding duplicates
- Storing key-value relationships
- Prefix sum optimization
- Grouping data
- Caching computed results
- Reducing nested loops
- Optimizing time complexity

---

# Complexity Focus

While solving Hash Map problems, I focus on:

- Replacing nested loops with constant-time lookups
- Choosing the appropriate key-value representation
- Optimizing both time and space complexity
- Combining hashing with techniques like Prefix Sum, Sliding Window, Two Pointers, and Sorting when required

---

# Learning Goal

The objective of this folder is to master the use of **Hash Maps** for solving interview-style coding problems efficiently.

By understanding common hashing patterns and practicing a variety of problems, I aim to recognize when hashing can transform a brute-force solution into an optimal one.

I will continue updating this folder as I solve more Hash Map problems and explore advanced hashing techniques.

---

## Language

**C++**

---

## Repository

**DSA Practice**
