# Lowest Common Ancestor of a Binary Tree

## Overview

This solution finds the **Lowest Common Ancestor (LCA)** of two given nodes `p` and `q` in a binary tree.

The Lowest Common Ancestor is the **lowest node in the tree that has both `p` and `q` as descendants**. A node can also be considered a descendant of itself.

This solution uses **postorder traversal** with recursion.

## Approach

The helper function `fun()` returns how many of the target nodes (`p` and `q`) are found in the current subtree.

For every node, we calculate:

```text
left  → number of targets found in left subtree
right → number of targets found in right subtree
self  → 1 if current node is p or q
```

Then:

```cpp
int total = left + right + self;
```

If:

```cpp
total == 2
```

then both target nodes have been found within the current subtree.

The first node where this happens is the **Lowest Common Ancestor**.

## Step-by-Step

For every node:

### 1. Base Case

If the current node is `NULL`:

```cpp
if (root == NULL) {
    return 0;
}
```

There are no target nodes in an empty subtree.

### 2. Search the Left Subtree

```cpp
int left = fun(root->left, p, q, ans);
```

This returns how many target nodes were found on the left.

### 3. Search the Right Subtree

```cpp
int right = fun(root->right, p, q, ans);
```

This returns how many target nodes were found on the right.

### 4. Check the Current Node

```cpp
int self = 0;

if (root == p || root == q) {
    self = 1;
}
```

If the current node is one of the target nodes, contribute `1`.

### 5. Calculate Total

```cpp
int total = left + right + self;
```

Possible values are:

```text
0 → neither p nor q found
1 → one of p or q found
2 → both p and q found
```

### 6. Identify the LCA

```cpp
if (total == 2 && ans == NULL) {
    ans = root;
}
```

When a subtree contains both target nodes, the current node can be their LCA.

The condition:

```cpp
ans == NULL
```

is important because we want the **first/lowest node encountered during postorder traversal** where both targets are present.

## Example

Consider:

```text
          3
         / \
        5   1
       / \ / \
      6  2 0  8
        / \
       7   4
```

Suppose:

```text
p = 5
q = 1
```

At node `3`:

```text
left subtree  → contains 5
right subtree → contains 1
self          → 0
```

Therefore:

```text
total = 1 + 1 + 0
      = 2
```

So:

```text
LCA = 3
```

### Another Example

If:

```text
p = 5
q = 4
```

Then node `5` contains both targets in its subtree:

```text
      5
     / \
    6   2
       / \
      7   4
```

Therefore:

```text
LCA = 5
```

This also demonstrates that **a node can be the ancestor of itself**.

## Why Postorder Traversal?

The solution needs information from both children before deciding whether the current node is the LCA.

Therefore, the order is:

```text
Left subtree
     ↓
Right subtree
     ↓
Current node
```

This is **postorder traversal**.

## Visualization of the Logic

```text
                 root
                /    \
               /      \
          left subtree  right subtree
              ↓             ↓
          find p/q       find p/q
               \          /
                \        /
                 \      /
                  ↓    ↓
                total == 2
                     ↓
                  LCA found
```

## Role of `ans`

The variable:

```cpp
TreeNode*& ans
```

is passed by **reference** so that the recursive function can modify the original `ans` pointer.

Initially:

```cpp
TreeNode* ans = NULL;
```

When the LCA is found:

```cpp
ans = root;
```

The value is then available in `lowestCommonAncestor()`.

## Complexity

Let `n` be the number of nodes in the tree.

* **Time Complexity:** `O(n)`

  * Every node is visited once.

* **Space Complexity:** `O(h)`

  * `h` is the height of the tree because of the recursive call stack.
  * Balanced tree: `O(log n)`
  * Skewed tree: `O(n)`

## Key Pattern

```text
Binary Tree
     ↓
Postorder Traversal
     ↓
Check Left
     ↓
Check Right
     ↓
Check Current Node
     ↓
Count p and q
     ↓
When count == 2 → LCA
```

## Important Concept

The main idea is:

> **For every subtree, count how many of the two target nodes it contains. The lowest node whose subtree contains both targets is the Lowest Common Ancestor.**

The three values:

```cpp
left + right + self
```

allow us to determine whether `p` and `q` are present in the current subtree.
