# Symmetric Tree

## Overview

This solution checks whether a binary tree is **symmetric around its center**.

A tree is symmetric if its left subtree is a mirror image of its right subtree.

The solution uses **recursion** to compare two subtrees simultaneously.

## Approach

The helper function `fun()` receives two nodes:

```cpp
fun(root1, root2)
```

It checks whether these two nodes are mirror images.

### Steps

1. If both nodes are `NULL`, they are symmetric.
2. If only one node is `NULL`, the structure is not symmetric.
3. If their values are different, the tree is not symmetric.
4. Compare:

   * Left child of `root1` with right child of `root2`
   * Right child of `root1` with left child of `root2`
5. Both comparisons must return `true`.

The key recursive calls are:

```cpp
bool v1 = fun(root1->left, root2->right);
bool v2 = fun(root1->right, root2->left);
```

## Example

Consider:

```text
        1
       / \
      2   2
     / \ / \
    3  4 4  3
```

The tree is symmetric because:

```text
Left subtree          Right subtree

    2                     2
   / \                   / \
  3   4                 4   3
```

The comparisons are:

```text
root1->left  ↔ root2->right
root1->right ↔ root2->left
```

Both sides match.

## Base Cases

### Both nodes are NULL

```cpp
if(root1 == NULL && root2 == NULL) {
    return true;
}
```

There is nothing left to compare, so they are symmetric.

### Only one node is NULL

```cpp
if(root1 == NULL || root2 == NULL) {
    return false;
}
```

This means the two subtrees have different structures.

### Values are different

```cpp
if(root1->val != root2->val) {
    return false;
}
```

Mirror nodes must contain the same value.

## Recursive Comparison

The most important idea is that we **do not compare corresponding children**.

Instead, we compare mirror positions:

```text
root1                    root2
  |                        |
 left  ----------------> right
 right -----------------> left
```

Therefore:

```cpp
fun(root1->left, root2->right);
fun(root1->right, root2->left);
```

## Complexity

Let `n` be the number of nodes in the tree.

* **Time Complexity:** `O(n)`

  * Each node is visited and compared at most once.

* **Space Complexity:** `O(h)`

  * `h` is the height of the tree due to the recursive call stack.
  * Balanced tree: `O(log n)`
  * Skewed tree: `O(n)`

## Key Pattern

```text
Binary Tree
     ↓
Compare two subtrees
     ↓
Mirror comparison
     ↓
left ↔ right
right ↔ left
     ↓
Recursive solution
```

## Important Concept

For a symmetric tree, the left and right subtrees must be **mirror images**, not identical trees.

For example:

```text
        1
       / \
      2   2
     /     \
    3       3
```

is symmetric because the `3` nodes occur at mirror positions.

The main idea to remember is:

> **Compare the left subtree of one side with the right subtree of the other side.**
