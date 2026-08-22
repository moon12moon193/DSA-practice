# Path Sum

## Problem

Given the root of a binary tree and an integer `targetSum`, determine whether the tree has a **root-to-leaf path** such that the sum of all node values along that path equals `targetSum`.

A **leaf node** is a node that has no left or right child.

### Example

```text
Input:
        5
       / \
      4   8
     /   / \
    11  13  4
   /  \      \
  7    2      1

targetSum = 22

Output:
true
```

Explanation:

```text
5 → 4 → 11 → 2

5 + 4 + 11 + 2 = 22
```

---

## Approach

The solution uses **Depth-First Search (DFS)** with recursion.

We maintain a variable `sum` that stores the current sum of the nodes along the path.

### Steps

1. Start from the root node.
2. Add the current node's value to `sum`.
3. Check whether the current node is a leaf.
4. If it is a leaf:

   * Compare `sum` with `targetSum`.
   * If they are equal, a valid path exists.
5. Recursively traverse the left and right subtrees.
6. Before returning from the function, subtract the current node's value from `sum`.

The subtraction is important because `sum` is passed by reference. It performs **backtracking**, restoring the sum to what it was before visiting the current node.

---

## Code

```cpp
class Solution {
public:

    void fun(TreeNode* root, int targetSum, int &sum, bool &res) {

        if (root == NULL) {
            return;
        }

        sum = sum + root->val;

        // Check if current node is a leaf
        if (root->left == NULL && root->right == NULL) {

            if (sum == targetSum) {
                res = true;
            }
        }

        // Traverse left subtree
        fun(root->left, targetSum, sum, res);

        // Traverse right subtree
        fun(root->right, targetSum, sum, res);

        // Backtracking
        sum = sum - root->val;

        return;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {

        int sum = 0;
        bool res = false;

        fun(root, targetSum, sum, res);

        return res;
    }
};
```

---

## Why Backtracking Is Needed

The variable `sum` is passed by reference:

```cpp
int &sum
```

Therefore, all recursive calls use the same `sum` variable.

For example:

```text
        5
       / \
      4   8
```

When traversing the left side:

```text
sum = 5
sum = 5 + 4 = 9
```

After finishing the left subtree, we must restore:

```text
sum = 9 - 4 = 5
```

Now we can correctly traverse the right subtree:

```text
sum = 5 + 8 = 13
```

This process is called **backtracking**.

---

## Complexity

Let `n` be the number of nodes in the binary tree.

### Time Complexity

```text
O(n)
```

Each node is visited at most once.

### Space Complexity

```text
O(h)
```

where `h` is the height of the tree.

This space is used by the recursive call stack.

* Balanced tree: `O(log n)`
* Skewed tree: `O(n)`

---

## Key Concepts

* Binary Tree
* Recursion
* Depth-First Search (DFS)
* Root-to-Leaf Path
* Backtracking
* Recursion Stack
* Tree Traversal

---

## Important Edge Cases

### Empty Tree

```text
root = NULL
```

There is no root-to-leaf path, so the answer is:

```text
false
```

### Single Node

```text
root = 5
targetSum = 5
```

The root itself is a leaf.

```text
Output: true
```

### Negative Values

The tree can contain negative values, so we cannot assume that increasing the sum always moves us closer to the target.

---

## LeetCode

**Problem:** Path Sum
**Difficulty:** Easy
**Topic:** Binary Tree / DFS / Recursion

### Pattern

```text
Root-to-Leaf Path
        ↓
     DFS
        ↓
Maintain Current Sum
        ↓
Check at Leaf
        ↓
    Backtrack
```

---

## Takeaway

The main idea is to maintain the **sum of the current root-to-node path** while performing DFS. When a leaf is reached, compare the path sum with `targetSum`. Since the sum variable is shared through recursion, **backtracking** is used to restore its previous value before exploring another branch.
