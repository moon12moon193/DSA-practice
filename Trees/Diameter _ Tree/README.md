# Diameter of Binary Tree

## Problem

Given the root of a binary tree, return the **length of the diameter** of the tree.

The **diameter** is the length of the longest path between any two nodes in the tree.

The path does not necessarily have to pass through the root.

> The length of a path is measured by the **number of edges** between the nodes.

### Example

```text
        1
       / \
      2   3
     / \
    4   5
```

The longest path is:

```text
4 → 2 → 1 → 3
```

This path contains:

```text
3 edges
```

Therefore:

```text
Output: 3
```

---

## Approach

This solution uses **Depth-First Search (DFS)** with recursion.

For every node, we calculate the height of its left and right subtrees.

The longest path passing through the current node is:

```text
left height + right height
```

We keep track of the maximum value found in `res`.

At the same time, the recursive function returns the height of the current subtree:

```text
1 + max(left, right)
```

---

## Algorithm

For every node:

1. Recursively calculate the height of the left subtree.
2. Recursively calculate the height of the right subtree.
3. Calculate the path passing through the current node:

   ```text
   left + right
   ```
4. Update the maximum diameter:

   ```text
   res = max(res, left + right)
   ```
5. Return the height of the current subtree:

   ```text
   1 + max(left, right)
   ```

---

## Code

```cpp
class Solution {
public:

    int fun(TreeNode* root, int& sum, int& res) {

        if (root == NULL) {
            return 0;
        }

        // Height of left subtree
        int left = fun(root->left, sum, res);

        // Height of right subtree
        int right = fun(root->right, sum, res);

        // Diameter passing through current node
        sum = left + right;

        // Update maximum diameter
        res = max(res, sum);

        // Return height of current subtree
        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {

        int sum = 0;
        int res = INT_MIN;

        fun(root, sum, res);

        return res;
    }
};
```

---

## Understanding the Height

The function returns:

```cpp
return 1 + max(left, right);
```

This represents the **height of the current subtree in terms of nodes**.

For example:

```text
        1
       /
      2
     /
    3
```

At node `3`:

```text
left = 0
right = 0

height = 1
```

At node `2`:

```text
left = 1
right = 0

height = 2
```

At node `1`:

```text
left = 2
right = 0

height = 3
```

So the recursive function returns the height of each subtree.

---

## Calculating the Diameter

At every node, we calculate:

```cpp
sum = left + right;
```

Why?

Because the longest path passing through the current node consists of:

```text
left subtree
     ↓
 current node
     ↓
right subtree
```

The number of edges in this path is:

```text
left height + right height
```

### Example

```text
        1
       / \
      2   3
     / \
    4   5
```

At node `2`:

```text
left = 1
right = 1

diameter through 2 = 1 + 1 = 2
```

At node `1`:

```text
left = 2
right = 1

diameter through 1 = 2 + 1 = 3
```

Therefore:

```text
res = 3
```

---

## Why `left + right` Represents Edges

The recursive function returns **height in terms of nodes**, but the diameter is required in **edges**.

Consider:

```text
    2
   / \
  4   5
```

The left height is:

```text
1
```

The right height is:

```text
1
```

The path is:

```text
4 → 2 → 5
```

There are `2` edges:

```text
4 → 2
2 → 5
```

And:

```text
left + right
= 1 + 1
= 2
```

So `left + right` directly gives the number of edges.

---

## Important Concept: Diameter Does Not Have to Pass Through Root

A common mistake is to assume that the diameter always passes through the root.

Consider:

```text
        1
       /
      2
     / \
    4   5
   / \
  6   7
```

The longest path may be completely inside the left subtree:

```text
6 → 4 → 2 → 5
```

Therefore, we must calculate the diameter at **every node** and keep the maximum:

```cpp
res = max(res, sum);
```

---

## Dry Run

Consider:

```text
        1
       / \
      2   3
     / \
    4   5
```

### Node 4

```text
left = 0
right = 0

sum = 0
res = 0

height = 1
```

### Node 5

```text
left = 0
right = 0

sum = 0
res = 0

height = 1
```

### Node 2

```text
left = 1
right = 1

sum = 1 + 1
    = 2

res = 2

height = 1 + max(1, 1)
      = 2
```

### Node 3

```text
left = 0
right = 0

sum = 0
res = 2

height = 1
```

### Node 1

```text
left = 2
right = 1

sum = 2 + 1
    = 3

res = 3
```

Final answer:

```text
3
```

---

## Complexity

Let `n` be the number of nodes in the binary tree.

### Time Complexity

```text
O(n)
```

Every node is visited exactly once.

### Space Complexity

```text
O(h)
```

where `h` is the height of the tree.

This is the space required by the recursive call stack.

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

The diameter should be:

```text
0
```

**Note:** With the current implementation, `res` is initialized to `INT_MIN`, so an empty tree would return `INT_MIN`.

A safer implementation would initialize:

```cpp
int res = 0;
```

This correctly handles the empty tree.

### Single Node

```text
    1
```

There are no edges.

Therefore:

```text
Output: 0
```

---

## Small Improvement to the Code

You can simplify the implementation because `sum` is only used to store the current node's diameter and does not need to be passed by reference.

A cleaner version is:

```cpp
class Solution {
public:

    int fun(TreeNode* root, int& res) {

        if (root == NULL) {
            return 0;
        }

        int left = fun(root->left, res);
        int right = fun(root->right, res);

        res = max(res, left + right);

        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {

        int res = 0;

        fun(root, res);

        return res;
    }
};
```

This version directly calculates:

```cpp
res = max(res, left + right);
```

and avoids the unnecessary `sum` variable.

---

## Key Concepts

* Binary Tree
* DFS
* Recursion
* Tree Height
* Diameter
* Postorder Traversal
* Divide and Conquer
* Recursive Call Stack

---

## Pattern

```text
                  Node
                   ↓
          ┌────────┴────────┐
          ↓                 ↓
    Left Subtree       Right Subtree
          ↓                 ↓
      left height       right height
          └────────┬────────┘
                   ↓
            left + right
                   ↓
          Update Diameter
                   ↓
        1 + max(left, right)
                   ↓
          Return Height
```

---

## Takeaway

The key idea is to calculate **height and diameter together** during a postorder DFS traversal.

For every node:

```text
left  = height of left subtree
right = height of right subtree
```

The diameter passing through that node is:

```text
left + right
```

And the height returned to its parent is:

```text
1 + max(left, right)
```

The most important pattern to remember is:

```cpp
res = max(res, left + right);
return 1 + max(left, right);
```

This **"calculate answer while returning height"** pattern is extremely useful for many binary-tree problems.
