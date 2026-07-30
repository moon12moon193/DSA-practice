# Heap

## Overview

A **Heap** is a specialized tree-based data structure that satisfies the **Heap Property**. It is commonly implemented using an array and is one of the most efficient data structures for solving problems involving **minimum/maximum elements**, **priority processing**, and **Top K** queries.

Unlike Binary Search Trees, a Heap only guarantees the relationship between a parent and its children, not the entire tree.

---

# Types of Heap

## 1. Min Heap

In a Min Heap:

- The parent node is always **smaller than or equal to** its children.
- The smallest element is always at the root.

Example:

```text
        2
      /   \
     5     8
    / \   / \
   9  10 12 15
```

Array Representation:

```text
[2, 5, 8, 9, 10, 12, 15]
```

---

## 2. Max Heap

In a Max Heap:

- The parent node is always **greater than or equal to** its children.
- The largest element is always at the root.

Example:

```text
        20
      /    \
     15     18
    / \    / \
   8  10  5   12
```

Array Representation:

```text
[20, 15, 18, 8, 10, 5, 12]
```

---

# Heap Properties

- Complete Binary Tree
- Stored efficiently in an array
- Fast insertion and deletion
- Root always contains the highest-priority element
- Does **not** maintain complete sorting

---

# Array Representation

For an element at index `i`:

```text
Left Child  = 2*i + 1
Right Child = 2*i + 2
Parent      = (i - 1) / 2
```

Example:

```text
Index : 0 1 2 3 4 5 6
Value : 5 8 9 12 15 20 25
```

Tree:

```text
        5
      /   \
     8     9
    / \   / \
  12 15 20 25
```

---

# Common Heap Operations

- Insert an element
- Remove the root element
- Peek at the minimum/maximum element
- Build a Heap
- Heapify
- Heap Sort

---

# Time Complexity

| Operation | Time Complexity |
|-----------|-----------------|
| Insert | O(log n) |
| Delete Root | O(log n) |
| Peek (Top Element) | O(1) |
| Heapify | O(log n) |
| Build Heap | O(n) |
| Heap Sort | O(n log n) |

---

# Space Complexity

| Operation | Space |
|-----------|-------|
| Heap Storage | O(n) |
| Extra Space (Heapify) | O(1) |

---

# C++ Priority Queue

The C++ STL provides Heap functionality through **priority_queue**.

### Max Heap (Default)

```cpp
priority_queue<int> pq;
```

---

### Min Heap

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

---

# Common Functions

```cpp
pq.push(x);      // Insert element
pq.pop();        // Remove top element
pq.top();        // Get top element
pq.empty();      // Check if heap is empty
pq.size();       // Number of elements
```

---

# When to Use a Heap

Use a Heap when you need:

- Maximum or minimum element repeatedly
- Top K largest/smallest elements
- Kth largest/smallest element
- Priority-based processing
- Efficient scheduling
- Merge multiple sorted arrays/lists
- Streaming data problems
- Median of a data stream
- Graph algorithms (Dijkstra's, Prim's)
- Huffman Coding

---

# Topics to Learn

## Beginner

- Introduction to Heap
- Min Heap
- Max Heap
- Complete Binary Tree
- Array Representation
- Priority Queue (STL)

---

## Intermediate

- Insert Operation
- Delete Operation
- Heapify
- Build Heap
- Heap Sort
- Kth Largest Element
- Kth Smallest Element
- Top K Frequent Elements
- K Closest Points
- Merge K Sorted Lists
- Merge K Sorted Arrays

---

## Advanced

- Median Finder
- Sliding Window Median
- IPO Problem
- Task Scheduler
- Meeting Rooms
- Dijkstra's Algorithm
- Prim's Algorithm
- Huffman Coding
- Custom Comparator
- Min-Max Heap
- Indexed Heap

---

# Applications

- CPU Scheduling
- Operating Systems
- Job Scheduling
- Graph Algorithms
- Artificial Intelligence
- Search Engines
- Data Compression
- Event Simulation
- Real-time Systems
- Network Routing

---

# Learning Strategy

1. Understand Complete Binary Trees.
2. Learn Min Heap and Max Heap concepts.
3. Practice `priority_queue` in C++.
4. Learn insertion and deletion manually.
5. Understand Heapify and Build Heap.
6. Solve Kth Largest/Smallest problems.
7. Practice Top K and Priority Queue problems.
8. Learn Heap Sort.
9. Solve graph problems using heaps.
10. Master advanced heap-based interview questions.

---

# Key Takeaways

- A Heap is a **Complete Binary Tree** with a parent-child ordering property.
- The root always stores the highest-priority element (minimum in Min Heap, maximum in Max Heap).
- Most operations run in **O(log n)** time.
- The C++ `priority_queue` implements a Heap efficiently.
- Heaps are ideal for **Top K**, **priority scheduling**, **graph algorithms**, and **streaming data** problems.
- Mastering Heap and `priority_queue` is essential for coding interviews and competitive programming.
