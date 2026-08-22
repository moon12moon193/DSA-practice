# Sum Root to Leaf Numbers

## Problem

You are given the root of a binary tree where each node contains a digit from `0` to `9`.

Each root-to-leaf path represents a number formed by concatenating the digits along that path.

Return the **total sum of all root-to-leaf numbers**.

### Example

```text
        1
       / \
      2   3
```

The root-to-leaf paths are:

```text
1 → 2  = 12
1 → 3  = 13
```

Therefore:

```text
12 + 13 = 25
```

Output:

```text
25
```

---

## Approach

The solution uses **Depth-First Search (DFS)** with **recursion and backtracking**.

We maintain two variables:

* `sum` → represents the number formed by the current root-to-node path.
* `total` → stores the sum of all root-to-leaf numbers.

At every node, we update `sum` using:

```cpp
sum = sum * 10 + root->val;
```

For example, if the current number is `12` and the next node contains `3`:

```text
12 × 10 + 3 = 123
```

When we reach a leaf node, the complete number is added to `total`.

---

## Algorithm

1. Start DFS from the root.
2. If the current node is `NULL`, return.
3. Update the current number:

   ```cpp
   sum = sum * 10 + root->val;
   ```
4. If the current node is a leaf:

   * Add `sum` to `total`.
5. Recursively traverse the left subtree.
6. Recursively traverse the right subtree.
7. Backtrack by removing the last digit:

   ```cpp
   sum = sum / 10;
   ```

---

## Code

```cpp
class Solution {
public:

    void fun(TreeNode* root, int &sum, int &total) {

        if (root == NULL) {
            return;
        }

        // Add current digit to the number
        sum = sum * 10 + root->val;

        // If leaf, add the complete number to total
        if (root->left == NULL && root->right == NULL) {
            total = total + sum;
        }

        // Traverse left subtree
        fun(root->left, sum, total);

        // Traverse right subtree
        fun(root->right, sum, total);

        // Backtracking: remove last digit
        sum = sum / 10;

        return;
    }

    int sumNumbers(TreeNode* root) {

        int total = 0;
        int sum = 0;

        fun(root, sum, total);

        return total;
    }
};
```

---

## Understanding `sum = sum * 10 + root->val`

This is the most important part of the solution.

Suppose the path is:

```text
1 → 2 → 3
```

Initially:

```text
sum = 0
```

Visit `1`:

```text
sum = 0 * 10 + 1
sum = 1
```

Visit `2`:

```text
sum = 1 * 10 + 2
sum = 12
```

Visit `3`:

```text
sum = 12 * 10 + 3
sum = 123
```

Therefore, the path represents the number:

```text
123
```

---

## Backtracking

Because `sum` is passed by reference:

```cpp
int &sum
```

all recursive calls use the same variable.

Therefore, after finishing a subtree, we need to restore the previous value.

We do this using:

```cpp
sum = sum / 10;
```

For example:

```text
Path: 1 → 2 → 3

sum = 123
```

After finishing node `3`:

```text
sum = 123 / 10
sum = 12
```

Now the algorithm can explore another branch from node `2`.

### Visual Representation

```text
          1
         / \
        2   4
       /
      3
```

While traversing the left path:

```text
1 → 2 → 3

sum = 1
sum = 12
sum = 123
```

After finishing `3`:

```text
sum = 123 / 10
sum = 12
```

Then the algorithm can correctly explore the right subtree.

---

## Why `total` Is Passed by Reference

The variable:

```cpp
int &total
```

is also passed by reference.

This allows every recursive call to update the same `total`.

For example:

```text
Path 1 → 2 = 12

total = 12
```

Then another path:

```text
Path 1 → 3 = 13

total = 12 + 13
      = 25
```

Finally:

```text
return total;
```

returns the sum of all root-to-leaf numbers.

---

## Complexity

Let `n` be the number of nodes in the binary tree.

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

This space is used by the recursive call stack.

For a balanced tree:

```text
O(log n)
```

For a completely skewed tree:

```text
O(n)
```

---

## Important Edge Cases

### Empty Tree

```text
root = NULL
```

There are no root-to-leaf numbers.

Output:

```text
0
```

### Single Node

```text
    5
```

The only root-to-leaf number is:

```text
5
```

Output:

```text
5
```

### Multiple Paths

```text
        4
       / \
      9   0
     / \
    5   1
```

Numbers are:

```text
495
491
40
```

Therefore:

```text
495 + 491 + 40 = 1026
```

---

## Key Concepts

* Binary Tree
* DFS
* Recursion
* Backtracking
* Root-to-Leaf Traversal
* Pass by Reference
* Constructing Numbers
* Tree Traversal

---

## Pattern

```text
             Binary Tree
                  ↓
                 DFS
                  ↓
       Build Number While Traversing
                  ↓
        sum = sum * 10 + digit
                  ↓
              Reach Leaf
                  ↓
          Add sum to total
                  ↓
             Backtracking
                  ↓
           sum = sum / 10
```

---

## Takeaway

The key idea is to **build the number while traversing from root to leaf**.

At every node:

```cpp
sum = sum * 10 + root->val;
```

When a leaf is reached, the complete number is added to `total`.

Because `sum` is passed by reference, we use:

```cpp
sum = sum / 10;
```

to remove the last digit during backtracking and correctly explore the next path.
