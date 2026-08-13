# Level Order Traversal — Binary Tree

## Overview

This solution performs a **Level Order Traversal** of a binary tree using a **Breadth-First Search (BFS)** approach.

The tree is traversed **level by level**, from left to right, and each level is stored as a separate vector.

## Approach

1. If the root is `NULL`, return an empty result.
2. Create a queue and insert the root node.
3. Continue processing while the queue is not empty.
4. Store the number of nodes currently in the queue as `levelSize`.
5. Process exactly `levelSize` nodes to complete the current level.
6. Add each node's value to a temporary vector.
7. Push its left and right children into the queue if they exist.
8. Add the completed level to the result.
9. Repeat until all nodes have been processed.

## Data Structures Used

* **Queue** — stores nodes that need to be processed.
* **Vector** — stores the values of each level and the final result.

## Complexity

Let `n` be the number of nodes in the binary tree.

* **Time Complexity:** `O(n)` — every node is visited exactly once.
* **Space Complexity:** `O(n)` — the queue and result can contain up to `O(n)` elements.

## Key Concept

The important idea is to use:

```cpp
int levelSize = q.size();
```

This captures the number of nodes belonging to the **current level**. Processing exactly `levelSize` nodes allows us to separate the traversal into individual levels.

## Example

For a tree:

```text
        3
       / \
      9   20
         /  \
        15   7
```

The level order traversal is:

```text
[
    [3],
    [9, 20],
    [15, 7]
]
```

## Pattern

**Binary Tree → BFS → Queue → Level-by-Level Traversal**

This pattern is useful for many binary-tree problems involving levels, minimum depth, maximum depth, right/left views, and other level-based operations.
