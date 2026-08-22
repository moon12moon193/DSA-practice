# Binary Search Tree (BST)

## Overview

A **Binary Search Tree (BST)** is a type of binary tree where each node follows a specific ordering property.

For every node:

```text
Values in Left Subtree < Node Value < Values in Right Subtree
```

Example:

```text
        8
       / \
      4   12
     / \  / \
    2   6 10 14
```

Here:

* Values smaller than `8` are on the left.
* Values greater than `8` are on the right.
* The same rule is recursively applied to every subtree.

---

## Basic Structure

A BST node can be represented as:

```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};
```

Each node contains:

```text
        Node
       /    \
    Left    Right
```

---

# BST Property

The most important rule is:

```text
Left Subtree < Root < Right Subtree
```

For example:

```text
        10
       /  \
      5    15
     / \   / \
    2   7 12 20
```

For node `10`:

```text
Left side  → 2, 5, 7
Right side → 12, 15, 20
```

Therefore, the BST property is maintained.

---

# Searching in a BST

BSTs allow us to eliminate one entire subtree at every step.

Suppose we want to search for `12`:

```text
        10
       /  \
      5    15
          /
         12
```

Start at `10`:

```text
12 > 10
```

So move right.

At `15`:

```text
12 < 15
```

So move left.

We find `12`.

### General logic

```text
target == root
        ↓
      Found

target < root
        ↓
   Search Left

target > root
        ↓
  Search Right
```

---

# Inorder Traversal

One of the most important properties of a BST is that **inorder traversal produces values in sorted order**.

For:

```text
        8
       / \
      4   12
     / \  / \
    2   6 10 14
```

Inorder traversal:

```text
2 → 4 → 6 → 8 → 10 → 12 → 14
```

Therefore:

```text
BST + Inorder Traversal = Sorted Order
```

This property is extremely useful when working with BSTs.

---

# Insertion

When inserting a new value:

1. Start from the root.
2. Compare the value with the current node.
3. If it is smaller, move left.
4. If it is greater, move right.
5. Continue until an empty position is found.
6. Insert the new node there.

Example:

Insert `7`:

```text
        10
       /
      5
     /
    2
```

Since:

```text
7 > 5
```

move right:

```text
        10
       /
      5
       \
        7
```

---

# Deletion

Deleting a node from a BST requires handling three cases.

### Case 1 — Leaf Node

The node has no children.

```text
    5
   /
  2
```

Removing `2` is straightforward.

---

### Case 2 — One Child

The node has only one child.

```text
    5
     \
      7
       \
        9
```

When removing `7`, its child can take its position.

---

### Case 3 — Two Children

The node has both left and right children.

```text
        8
       / \
      4   12
```

A common approach is to replace the node with:

* **Inorder successor** — smallest value in the right subtree.
* Or **inorder predecessor** — largest value in the left subtree.

The BST property must remain valid after deletion.

---

# Minimum and Maximum

The BST structure makes finding minimum and maximum values simple.

### Minimum

Keep moving left:

```text
root → left → left → left
```

The leftmost node contains the minimum value.

### Maximum

Keep moving right:

```text
root → right → right → right
```

The rightmost node contains the maximum value.

---

# Successor and Predecessor

### Inorder Successor

The successor of a node is the next greater value in sorted order.

It can often be found using the node's right subtree.

### Inorder Predecessor

The predecessor is the next smaller value in sorted order.

It can often be found using the node's left subtree.

Understanding these concepts is important for advanced BST operations.

---

# Recursive BST Pattern

Many BST operations can be implemented recursively.

A general structure looks like:

```cpp
TreeNode* solve(TreeNode* root, int target) {

    if (root == NULL) {
        return NULL;
    }

    if (target < root->val) {
        return solve(root->left, target);
    }

    if (target > root->val) {
        return solve(root->right, target);
    }

    return root;
}
```

The important idea is that the BST property tells us **which subtree we need to explore**.

---

# Iterative BST Pattern

BST operations can also be implemented without recursion.

General search pattern:

```cpp
TreeNode* curr = root;

while (curr != NULL) {

    if (target == curr->val) {
        return curr;
    }

    if (target < curr->val) {
        curr = curr->left;
    } else {
        curr = curr->right;
    }
}

return NULL;
```

---

# Balanced vs Skewed BST

The performance of a BST depends heavily on its shape.

### Balanced BST

```text
        8
       / \
      4   12
     / \  / \
    2  6 10 14
```

The height is relatively small.

Search can be approximately:

```text
O(log n)
```

### Skewed BST

```text
1
 \
  2
   \
    3
     \
      4
       \
        5
```

This behaves similarly to a linked list.

Search can become:

```text
O(n)
```

---

# Complexity

Let `n` be the number of nodes and `h` be the height of the BST.

| Operation |  Average | Worst Case |
| --------- | -------: | ---------: |
| Search    | O(log n) |       O(n) |
| Insert    | O(log n) |       O(n) |
| Delete    | O(log n) |       O(n) |
| Minimum   | O(log n) |       O(n) |
| Maximum   | O(log n) |       O(n) |

The worst case occurs when the BST becomes heavily skewed.

---

# Important BST Concepts

While learning BSTs, focus on:

* BST ordering property
* Searching
* Insertion
* Deletion
* Minimum and maximum
* Inorder successor
* Inorder predecessor
* Recursive implementation
* Iterative implementation
* Inorder traversal
* Tree height
* Balanced vs skewed trees

---

# BST Mental Model

The most important idea to remember is:

```text
              Root
             /    \
        Smaller   Greater
          /          \
     Smaller       Greater
```

Whenever you receive a target value, compare it with the current node:

```text
target < root->val
        ↓
      LEFT

target > root->val
        ↓
     RIGHT

target == root->val
        ↓
      FOUND
```

This is what makes a BST more efficient than an ordinary binary tree for many ordered operations.

---

# Learning Progression

A good progression for learning BSTs is:

```text
Binary Tree Basics
        ↓
BST Properties
        ↓
Searching
        ↓
Insertion
        ↓
Minimum / Maximum
        ↓
Inorder Traversal
        ↓
Successor / Predecessor
        ↓
Deletion
        ↓
Recursive BST Techniques
        ↓
Iterative BST Techniques
        ↓
Advanced BST Concepts
```

---

## Key Takeaways

* A BST is an ordered binary tree.
* Smaller values go to the **left**.
* Greater values go to the **right**.
* Inorder traversal of a valid BST gives **sorted values**.
* BST operations can be implemented using recursion or iteration.
* A balanced BST provides approximately `O(log n)` search, insertion, and deletion.
* A skewed BST can degrade to `O(n)`.
* Always use the BST ordering property to decide which subtree to explore.
