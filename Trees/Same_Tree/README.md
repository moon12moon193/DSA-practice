# Same Tree

## Overview

This solution checks whether two binary trees are **identical**.

Two binary trees are considered the same when:

1. They have the same structure.
2. Corresponding nodes contain the same values.

The solution uses **recursion** to compare both trees node by node.

## Approach

The function `isSameTree()` compares two nodes `p` and `q`.

### Steps

1. If both nodes are `NULL`, return `true`.
2. If only one node is `NULL`, return `false`.
3. If their values are different, return `false`.
4. Recursively compare their left subtrees.
5. Recursively compare their right subtrees.
6. Both subtree comparisons must be `true`.

The recursive calls are:

```cpp
bool v1 = isSameTree(p->left, q->left);
bool v2 = isSameTree(p->right, q->right);
```

Unlike the **Symmetric Tree** problem, here we compare corresponding children:

```text
p                    q
│                    │
left  ─────────────> left
right ─────────────> right
```

## Base Cases

### Both Nodes Are NULL

```cpp
if(p == NULL && q == NULL) {
    return true;
}
```

If both nodes are empty at the same position, they match.

### Only One Node Is NULL

```cpp
if(p == NULL || q == NULL) {
    return false;
}
```

If one tree has a node while the other does not, their structures are different.

### Values Are Different

```cpp
if(p->val != q->val) {
    return false;
}
```

Corresponding nodes must contain the same value.

## Example

Tree `p`:

```text
        1
       / \
      2   3
```

Tree `q`:

```text
        1
       / \
      2   3
```

Both structure and values match:

```text
1 == 1
├── 2 == 2
└── 3 == 3
```

Therefore:

```text
true
```

### Example of Different Trees

Tree `p`:

```text
        1
       / \
      2   3
```

Tree `q`:

```text
        1
       / \
      2   4
```

The root and left subtree match, but:

```text
3 != 4
```

Therefore:

```text
false
```

## Key Difference from Symmetric Tree

For **Same Tree**, compare corresponding positions:

```text
left  ↔ left
right ↔ right
```

For **Symmetric Tree**, compare mirror positions:

```text
left  ↔ right
right ↔ left
```

This distinction is very important when solving binary-tree recursion problems.

## Complexity

Let `n` be the number of nodes being compared.

* **Time Complexity:** `O(n)`

  * Each corresponding node is visited at most once.

* **Space Complexity:** `O(h)`

  * `h` is the height of the tree due to the recursive call stack.
  * Balanced tree: `O(log n)`
  * Skewed tree: `O(n)`

## Key Pattern

```text
Two Binary Trees
       ↓
Compare corresponding nodes
       ↓
Check values
       ↓
Compare left ↔ left
Compare right ↔ right
       ↓
Both must match
```

## Important Concept

The three main checks form the foundation of recursive tree comparison:

```cpp
if(p == NULL && q == NULL)
    return true;

if(p == NULL || q == NULL)
    return false;

if(p->val != q->val)
    return false;
```

After these checks, recursively compare the left and right subtrees.
