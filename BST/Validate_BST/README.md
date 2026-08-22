# Validate Binary Search Tree

## Problem

Given the root of a binary tree, determine whether it is a **valid Binary Search Tree (BST)**.

A valid BST follows these rules:

* Every value in the **left subtree** is strictly smaller than the node's value.
* Every value in the **right subtree** is strictly greater than the node's value.
* Both left and right subtrees must also be valid BSTs.

### Example — Valid BST

```text
        2
       / \
      1   3
```

Inorder traversal:

```text
1 → 2 → 3
```

The values are strictly increasing, so the tree is a valid BST.

### Example — Invalid BST

```text
        5
       / \
      1   4
         / \
        3   6
```

The value `3` is in the right subtree of `5`, but:

```text
3 < 5
```

Therefore, the tree is not a valid BST.

---

## Key Observation

One of the most important properties of a Binary Search Tree is:

> **An inorder traversal of a valid BST produces values in strictly increasing order.**

For example:

```text
        4
       / \
      2   6
     / \ / \
    1  3 5  7
```

Inorder traversal:

```text
1 → 2 → 3 → 4 → 5 → 6 → 7
```

Since the values are strictly increasing, the tree is a valid BST.

Therefore, we can validate the BST by performing an **inorder traversal** and comparing each node with the previous node.

---

## Approach

This solution uses:

* **DFS**
* **Inorder Traversal**
* **Recursion**
* **Previous Node Tracking**

We maintain:

```cpp
TreeNode* prev
```

which points to the previously visited node in inorder traversal.

For every current node:

```cpp
if (root->val <= prev->val)
```

then the inorder sequence is not strictly increasing, meaning the tree is not a valid BST.

---

## Algorithm

1. Perform an inorder traversal.
2. Recursively visit the left subtree.
3. Process the current node.
4. Compare the current node with `prev`.
5. If:

   ```text
   current value <= previous value
   ```

   the BST is invalid.
6. Update:

   ```cpp
   prev = root;
   ```
7. Recursively visit the right subtree.
8. Return the final value of `ans`.

---

## Code

```cpp
class Solution {
public:

    void fun(TreeNode* root, TreeNode*& prev, bool& ans) {

        if (root == NULL) {
            return;
        }

        // Traverse left subtree
        fun(root->left, prev, ans);

        // Check current node
        if (prev == NULL) {
            prev = root;
        }
        else {

            if (root->val <= prev->val) {
                ans = false;
            }

            prev = root;
        }

        // Traverse right subtree
        fun(root->right, prev, ans);
    }

    bool isValidBST(TreeNode* root) {

        TreeNode* prev = NULL;
        bool ans = true;

        fun(root, prev, ans);

        return ans;
    }
};
```

---

## Understanding Inorder Traversal

Inorder traversal follows:

```text
Left → Root → Right
```

For a BST, this produces:

```text
Smallest → ... → Largest
```

Consider:

```text
        5
       / \
      3   7
     / \ / \
    2  4 6  8
```

Inorder traversal:

```text
2 → 3 → 4 → 5 → 6 → 7 → 8
```

Every value is greater than the previous value.

Therefore:

```text
BST = Valid
```

---

## How `prev` Works

Initially:

```cpp
TreeNode* prev = NULL;
```

During inorder traversal:

### First Node

Suppose the first node is `2`.

Since:

```cpp
prev == NULL
```

we set:

```cpp
prev = root;
```

Now:

```text
prev = 2
```

### Next Node

Suppose the next node is `3`.

We check:

```text
3 <= 2?
```

No.

So:

```cpp
prev = root;
```

Now:

```text
prev = 3
```

### Next Node

Suppose the next node is `4`.

```text
4 <= 3?
```

No.

So:

```text
prev = 4
```

This continues throughout the inorder traversal.

---

## Detecting an Invalid BST

Consider:

```text
        5
       / \
      1   4
         / \
        3   6
```

Inorder traversal is:

```text
1 → 5 → 3 → 4 → 6
```

Notice:

```text
5 → 3
```

is decreasing.

When processing `3`:

```cpp
if (root->val <= prev->val)
```

becomes:

```text
3 <= 5
```

which is true.

Therefore:

```cpp
ans = false;
```

The tree is invalid.

---

## Why We Use `<=` Instead of `<`

The BST requires **strictly increasing** values during inorder traversal.

Therefore, duplicate values are not allowed.

Consider:

```text
        2
       / \
      1   2
```

Inorder traversal:

```text
1 → 2 → 2
```

The second `2` is not greater than the previous `2`.

Therefore:

```text
2 <= 2
```

is true, and the tree is invalid.

That's why we use:

```cpp
root->val <= prev->val
```

instead of:

```cpp
root->val < prev->val
```

---

## Why `prev` Is Passed by Reference

The function receives:

```cpp
TreeNode*& prev
```

This means the pointer itself is passed by reference.

All recursive calls share the same `prev` pointer.

For example:

```text
Inorder:
1 → 2 → 3 → 4
```

The pointer changes as:

```text
prev = 1
prev = 2
prev = 3
prev = 4
```

This allows every node to be compared with the node immediately before it in inorder traversal.

---

## Complexity

Let `n` be the number of nodes in the tree.

### Time Complexity

```text
O(n)
```

Every node is visited once.

### Space Complexity

```text
O(h)
```

where `h` is the height of the tree.

The space is used by the recursive call stack.

For a balanced tree:

```text
O(log n)
```

For a completely skewed tree:

```text
O(n)
```

---

## Edge Cases

### Empty Tree

```text
root = NULL
```

An empty tree is considered a valid BST.

Output:

```text
true
```

### Single Node

```text
    5
```

There are no ordering violations.

Output:

```text
true
```

### Duplicate Values

```text
        5
       / \
      3   5
```

Inorder:

```text
3 → 5 → 5
```

Not strictly increasing.

Output:

```text
false
```

---

## Important Improvement

Your solution correctly finds the answer, but after finding an invalid pair, it continues traversing the remaining tree.

You can optimize it by stopping early:

```cpp
if (!ans) {
    return;
}
```

For example:

```cpp
class Solution {
public:

    void fun(TreeNode* root, TreeNode*& prev, bool& ans) {

        if (root == NULL || !ans) {
            return;
        }

        fun(root->left, prev, ans);

        if (prev != NULL && root->val <= prev->val) {
            ans = false;
            return;
        }

        prev = root;

        fun(root->right, prev, ans);
    }

    bool isValidBST(TreeNode* root) {

        TreeNode* prev = NULL;
        bool ans = true;

        fun(root, prev, ans);

        return ans;
    }
};
```

This version stops as soon as a violation is found.

---

## Key Concepts

* Binary Search Tree
* Inorder Traversal
* DFS
* Recursion
* Previous Node Tracking
* Strictly Increasing Sequence
* Pass by Reference
* Tree Validation

---

## Pattern

```text
             Binary Tree
                  ↓
           Inorder Traversal
                  ↓
        Left → Root → Right
                  ↓
       Compare with previous
                  ↓
       current <= previous?
             ↙         ↘
           Yes          No
            ↓            ↓
         Invalid      Update prev
```

The core condition is:

```cpp
if (root->val <= prev->val) {
    ans = false;
}
```

---

## Takeaway

The key observation for this problem is:

> **A valid BST produces a strictly increasing sequence during inorder traversal.**

Therefore, instead of checking every node against an entire range of possible values, we simply keep track of the **previously visited node**.

The most important pattern to remember is:

```cpp
fun(root->left, prev, ans);

if (prev != NULL && root->val <= prev->val) {
    ans = false;
}

prev = root;

fun(root->right, prev, ans);
```

This **Inorder + Previous Node** technique is a very useful pattern for BST validation and other BST-related problems.
