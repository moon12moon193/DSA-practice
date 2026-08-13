# Invert Binary Tree

## Overview

This solution **inverts a binary tree** by swapping the left and right children of every node.

After inversion, the tree becomes a mirror image of the original tree.

## Approach

The solution uses **recursion**:

1. If the current node is `NULL`, return.
2. Swap the left and right children of the current node.
3. Recursively invert the left subtree.
4. Recursively invert the right subtree.
5. Return the root.

The important operation is:

```cpp
swap(root->left, root->right);
```

This is performed for every node in the tree.

## Example

Original tree:

```text
        4
       / \
      2   7
     / \ / \
    1  3 6  9
```

After inversion:

```text
        4
       / \
      7   2
     / \ / \
    9  6 3  1
```

## How Recursion Works

For each node:

```text
Swap children
     ↓
Invert left subtree
     ↓
Invert right subtree
```

For example, starting from:

```text
    4
   / \
  2   7
```

First swap:

```text
    4
   / \
  7   2
```

Then recursively invert the subtrees of `7` and `2`.

## Base Case

```cpp
if(root == NULL) {
    return;
}
```

When recursion reaches a missing child, there is nothing to invert, so the function stops.

## Data Structures Used

No additional data structure is required.

The solution uses:

* **Recursion**
* **Tree nodes**
* `swap()` to exchange child pointers

## Complexity

Let `n` be the number of nodes in the tree.

* **Time Complexity:** `O(n)`

  * Every node is visited exactly once.

* **Space Complexity:** `O(h)`

  * `h` is the height of the tree.
  * This space is used by the recursive call stack.
  * For a balanced tree: `O(log n)`
  * For a completely skewed tree: `O(n)`

## Key Pattern

```text
Binary Tree
     ↓
 Recursion
     ↓
Swap left & right
     ↓
Recursively process both subtrees
```

## Important Concept

The tree is inverted **in-place**. No new tree is created.

The original child pointers are simply exchanged:

```cpp
swap(root->left, root->right);
```

This makes the solution both simple and memory efficient.
