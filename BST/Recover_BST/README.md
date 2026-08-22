# Recover Binary Search Tree

## Problem

You are given the root of a Binary Search Tree (BST) where **exactly two nodes have been swapped by mistake**.

Recover the tree without changing its structure.

The goal is to restore the BST property by swapping the values of the two incorrect nodes.

### Example

Original valid BST:

```text
        3
       / \
      1   4
         /
        2
```

The values `2` and `3` were swapped.

The inorder traversal becomes:

```text
1 → 3 → 2 → 4
```

This is not strictly increasing.

After recovering the tree:

```text
        2
       / \
      1   4
         /
        3
```

Inorder traversal:

```text
1 → 2 → 3 → 4
```

The BST is restored.

---

## Key Observation

A valid BST has an important property:

> Its inorder traversal produces values in strictly increasing order.

For example:

```text
        3
       / \
      1   4
```

Inorder:

```text
1 → 3 → 4
```

If two nodes are swapped, the inorder sequence will contain one or two violations.

A violation occurs when:

```text
current->val <= prev->val
```

For example:

```text
1 → 5 → 3 → 4 → 2 → 6
```

Violations are:

```text
5 > 3
4 > 2
```

These violations allow us to identify the two swapped nodes.

---

## Approach

The solution uses:

* **Inorder Traversal**
* **DFS**
* **Previous Node Tracking**
* **Violation Detection**
* **Swapping Node Values**

We maintain:

```cpp
TreeNode* prev;
```

which stores the previously visited node in inorder traversal.

Whenever:

```cpp
root->val <= prev->val
```

we have found an ordering violation.

The first violation stores:

```text
g1first  = prev
g1second = root
```

The second violation stores:

```text
g2first  = prev
g2second = root
```

At the end, we determine which two nodes need to be swapped.

---

## Why There Can Be One or Two Violations

There are two possible situations.

### Case 1 — Adjacent Nodes Are Swapped

Suppose the correct inorder sequence is:

```text
1 → 2 → 3 → 4
```

If `2` and `3` are swapped:

```text
1 → 3 → 2 → 4
```

There is only one violation:

```text
3 > 2
```

So:

```text
g = 1
```

The two incorrect nodes are:

```text
3 and 2
```

---

### Case 2 — Non-Adjacent Nodes Are Swapped

Suppose the correct inorder sequence is:

```text
1 → 2 → 3 → 4 → 5
```

If `2` and `5` are swapped:

```text
1 → 5 → 3 → 4 → 2
```

There are two violations:

```text
5 > 3
4 > 2
```

The incorrect nodes are:

```text
5 and 2
```

Notice that they are:

```text
first violation → prev
second violation → current
```

Therefore, for two violations we swap:

```cpp
swap(g1first->val, g2second->val);
```

---

## Algorithm

1. Perform an inorder traversal.
2. Keep track of the previously visited node using `prev`.
3. Whenever:

   ```cpp
   root->val <= prev->val
   ```

   a violation is found.
4. For the first violation:

   * Store `prev` as `g1first`.
   * Store `root` as `g1second`.
5. For the second violation:

   * Store `prev` as `g2first`.
   * Store `root` as `g2second`.
6. Count the number of violations.
7. If there is one violation:

   ```cpp
   swap(g1first->val, g1second->val);
   ```
8. If there are two violations:

   ```cpp
   swap(g1first->val, g2second->val);
   ```

---

## Code

```cpp
class Solution {
public:

    void fun(TreeNode* root,
             TreeNode*& prev,
             int& g,
             TreeNode*& g1first,
             TreeNode*& g1second,
             TreeNode*& g2first,
             TreeNode*& g2second) {

        if (root == NULL) {
            return;
        }

        // Inorder: Left
        fun(root->left, prev, g,
            g1first, g1second,
            g2first, g2second);

        // Inorder: Root
        if (prev == NULL) {
            prev = root;
        }
        else {

            // Violation found
            if (root->val <= prev->val) {

                if (g == 0) {
                    g1first = prev;
                    g1second = root;
                }
                else {
                    g2first = prev;
                    g2second = root;
                }

                g++;
            }

            prev = root;
        }

        // Inorder: Right
        fun(root->right, prev, g,
            g1first, g1second,
            g2first, g2second);
    }

    void recoverTree(TreeNode* root) {

        int g = 0;

        TreeNode* g1first;
        TreeNode* g1second;

        TreeNode* g2first;
        TreeNode* g2second;

        TreeNode* prev = NULL;

        fun(root, prev, g,
            g1first, g1second,
            g2first, g2second);

        // One violation
        if (g == 1) {
            swap(g1first->val, g1second->val);
        }
        else {
            // Two violations
            swap(g1first->val, g2second->val);
        }
    }
};
```

---

## Dry Run — One Violation

Consider the incorrect inorder sequence:

```text
1 → 3 → 2 → 4
```

Traversal:

### Visit `1`

```text
prev = 1
```

### Visit `3`

```text
3 > 1
```

No violation.

```text
prev = 3
```

### Visit `2`

```text
2 <= 3
```

Violation found.

Store:

```text
g1first  = 3
g1second = 2
```

Now:

```text
g = 1
```

### Visit `4`

```text
4 > 2
```

No violation.

Since:

```text
g == 1
```

we perform:

```cpp
swap(g1first->val, g1second->val);
```

So:

```text
3 ↔ 2
```

The inorder sequence becomes:

```text
1 → 2 → 3 → 4
```

The BST is restored.

---

## Dry Run — Two Violations

Consider:

```text
1 → 5 → 3 → 4 → 2 → 6
```

### First Violation

Compare:

```text
5 > 3
```

Store:

```text
g1first  = 5
g1second = 3
```

### Second Violation

Compare:

```text
4 > 2
```

Store:

```text
g2first  = 4
g2second = 2
```

Now:

```text
g = 2
```

The swapped nodes are:

```text
5 and 2
```

So:

```cpp
swap(g1first->val, g2second->val);
```

The inorder sequence becomes:

```text
1 → 2 → 3 → 4 → 5 → 6
```

The BST is restored.

---

## Understanding the Four Pointers

Your solution uses four pointers:

```cpp
TreeNode* g1first;
TreeNode* g1second;
TreeNode* g2first;
TreeNode* g2second;
```

They represent the nodes around the two possible violations.

### First Violation

```text
g1first  = previous node
g1second = current node
```

### Second Violation

```text
g2first  = previous node
g2second = current node
```

For example:

```text
1 → 5 → 3 → 4 → 2 → 6
    ↑   ↑       ↑   ↑
    │   │       │   │
   g1f g1s     g2f g2s
```

The actual swapped nodes are:

```text
g1first = 5
g2second = 2
```

---

## Why We Swap `g1first` and `g2second`

For two violations:

```text
a → x → c → d → b
```

where:

```text
a < x
x > c
c < d
d > b
```

The two swapped values are:

```text
x and b
```

The first violation gives us:

```text
g1first = x
```

The second violation gives us:

```text
g2second = b
```

Therefore:

```cpp
swap(g1first->val, g2second->val);
```

---

## Why We Only Swap Values

The problem asks us to recover the BST without changing its structure.

Therefore, we don't modify:

```cpp
root->left
root->right
```

We only exchange:

```cpp
node1->val
node2->val
```

For example:

```cpp
swap(g1first->val, g2second->val);
```

The tree structure remains exactly the same.

---

## Complexity

Let `n` be the number of nodes in the tree.

### Time Complexity

```text
O(n)
```

Every node is visited exactly once during the inorder traversal.

The final swap takes:

```text
O(1)
```

Therefore, the overall complexity is:

```text
O(n)
```

### Space Complexity

```text
O(h)
```

where `h` is the height of the tree.

This comes from the recursive call stack.

For a balanced tree:

```text
O(log n)
```

For a skewed tree:

```text
O(n)
```

No extra array is used to store the inorder traversal.

---

## Important Edge Cases

### Empty Tree

If:

```text
root = NULL
```

there are no nodes to recover.

The implementation should ideally handle this case explicitly if required.

### Single Node

```text
    1
```

There is no possible violation.

### Adjacent Swapped Nodes

There is usually:

```text
1 violation
```

Example:

```text
1 → 3 → 2 → 4
```

Swap:

```text
3 ↔ 2
```

### Non-Adjacent Swapped Nodes

There are usually:

```text
2 violations
```

Example:

```text
1 → 5 → 3 → 4 → 2 → 6
```

Swap:

```text
5 ↔ 2
```

---

## Key Concepts

* Binary Search Tree
* Inorder Traversal
* DFS
* Recursion
* Previous Node Tracking
* Violation Detection
* Swapping Node Values
* BST Properties
* Constant Extra Space Approach

---

## Pattern

```text
              BST
               ↓
       Inorder Traversal
               ↓
      Strictly Increasing?
               ↓
       Find Violations
          ↙         ↘
       1st          2nd
        ↓             ↓
   first = prev   second = current
        ↓             ↓
        └──────┬──────┘
               ↓
       Identify Swapped Nodes
               ↓
          Swap Values
               ↓
          Recover BST
```

---

## Takeaway

The most important observation is:

> **A valid BST has a strictly increasing inorder traversal.**

When exactly two nodes are swapped, the inorder traversal contains **one or two ordering violations**.

The key pattern is:

```cpp
if (root->val <= prev->val) {
    // violation
}
```

For one violation:

```cpp
swap(g1first->val, g1second->val);
```

For two violations:

```cpp
swap(g1first->val, g2second->val);
```

This allows the BST to be recovered **without modifying the tree's structure** and without storing the entire inorder traversal.
