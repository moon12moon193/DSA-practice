# Zigzag Level Order Traversal — Binary Tree

## Overview

This solution performs a **Zigzag Level Order Traversal** of a binary tree using **Breadth-First Search (BFS)** and a queue.

Unlike normal level order traversal, the direction changes at every level:

* First level → left to right
* Second level → right to left
* Third level → left to right
* And so on

## Approach

1. If the root is `NULL`, return an empty result.
2. Create a queue and insert the root node.
3. Use `levelOrder` to keep track of the current traversal direction.
4. For every level:

   * Get the number of nodes using `levelSize`.
   * Create a vector of size `levelSize`.
   * Use two pointers:

     * `first` starts from the beginning.
     * `last` starts from the end.
5. If the current level is left-to-right, store values using `first`.
6. If the current level is right-to-left, store values using `last`.
7. Add the children of every node to the queue.
8. Add the completed level to the result.
9. Toggle the direction using:

```cpp
levelOrder = 1 - levelOrder;
```

## Why `vector<int> ans(levelSize)`?

The vector must already contain `levelSize` elements because the solution directly accesses positions using indices:

```cpp
ans[first] = t->val;
```

and:

```cpp
ans[last] = t->val;
```

Creating it as:

```cpp
vector<int> ans(levelSize);
```

allocates the required positions before assigning values.

## Example

For the tree:

```text
        3
       / \
      9   20
         /  \
        15   7
```

The traversal is:

```text
[
    [3],
    [20, 9],
    [15, 7]
]
```

### Level-by-Level

```text
Level 1 → [3]       left → right
Level 2 → [20, 9]   right → left
Level 3 → [15, 7]   left → right
```

## Data Structures Used

* **Queue** — performs BFS traversal.
* **Vector** — stores values for each level.
* **Two indices (`first`, `last`)** — control the direction in which values are placed.

## Complexity

Let `n` be the number of nodes in the tree.

* **Time Complexity:** `O(n)`

  * Every node is visited exactly once.

* **Space Complexity:** `O(n)`

  * The queue can contain up to `O(n)` nodes.
  * The result also requires `O(n)` space.

## Key Pattern

```text
Binary Tree
     ↓
    BFS
     ↓
   Queue
     ↓
Process one level at a time
     ↓
Change direction after every level
```

## Important Concept

The queue always processes nodes from **left to right**, but the `ans` vector controls how their values are stored.

For example, when traversing right-to-left:

```text
Queue:       9   20
             ↓   ↓
ans index:   1   0

Result:     [20, 9]
```

This allows the solution to perform zigzag traversal without changing the actual BFS queue order.
